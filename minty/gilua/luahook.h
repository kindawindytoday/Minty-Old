#pragma once
#include <Windows.h>
#define OFFET 0x265CFF0
#include <cstdio>
#include <cstdint>
#include <sstream>
#include <optional>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "pe.h"
#include "scanner.h"
#pragma warning(suppress : 4996)
extern "C" {
#include "../lua/lua.h"
#include "../lua/lualib.h"
#include "../lua/lauxlib.h"
}
#include "util.h"
//#include "luaHook.h"
namespace fs = std::filesystem;
lua_State* gi_L;
HMODULE xlua;
HANDLE main_thread;

auto gi_LL = luaL_newstate();
static bool is_hook_success = false;
static int last_ret_code;
const char* last_tolstr;

using pfn_loadbuffer = int (*)(lua_State*, const char*, size_t, const char*);
pfn_loadbuffer* pp_loadbuffer;
int xluaL_loadbuffer_hook(lua_State* L, const char* chunk, size_t sz, const char* chunkname)
{
    gi_L = L;
    util::log(2,"xluaL_loadbuffer_hook called. Lua ready!","");
    is_hook_success = true;
    util::logdialog("Succesfully hooked. Happy hacking!");
    main_thread = OpenThread(THREAD_ALL_ACCESS, false, GetCurrentThreadId());
    xlua = GetModuleHandleW(L"xlua");
    *pp_loadbuffer = (pfn_loadbuffer)GetProcAddress(xlua, "xluaL_loadbuffer");
    return (*pp_loadbuffer)(L, chunk, sz, chunkname);
}

//std::optional<std::string> read_whole_file(const fs::path& file)
//try
//{
//    std::stringstream buf;
//    std::ifstream ifs(file);
//    if (!ifs.is_open())
//        return std::nullopt;
//    ifs.exceptions(std::ios::failbit);
//    buf << ifs.rdbuf();
//    return buf.str();
//}
//catch (const std::ios::failure&)
//{
//    return std::nullopt;
//}

void exec(const std::string& compiled)
{
    using pfn_pcall = int (*)(lua_State* L, int nargs, int nresults, int errfunc);
    static auto xlua_pcall = (pfn_pcall)GetProcAddress(xlua, "lua_pcall");
    static auto xluaL_loadbuffer = (pfn_loadbuffer)GetProcAddress(xlua, "xluaL_loadbuffer");

    int ret = xluaL_loadbuffer(gi_L, compiled.c_str(), compiled.length(), "GILua");
    if (ret != 0)
    {
        lua_pop(gi_L, 1);
        return;
    }

    ret = xlua_pcall(gi_L, 0, 0, 0);
    if (ret != 0)
    {

        lua_pop(gi_L, 1);
    }
}

//std::optional<fs::path> this_dir()
//{
//    HMODULE mod = NULL;
//    TCHAR path[MAX_PATH]{};
//    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)&this_dir, &mod))
//    {
//        printf("GetModuleHandleEx failed (%i)\n", GetLastError());
//        return std::nullopt;
//    }
//
//    if (!GetModuleFileName(mod, path, MAX_PATH))
//    {
//        printf("GetModuleFileName failed (%i)\n", GetLastError());
//        return std::nullopt;
//    }
//
//    return fs::path(path).remove_filename();
//}


//std::optional<fs::path> get_scripts_folder()
//{
//
//    auto mod_dir = this_dir();
//    if (!mod_dir)
//        return std::nullopt;
//
//    auto scripts_path = mod_dir.value() / "Scripts";
//    if (fs::is_directory(scripts_path))
//        return scripts_path;
//
//    //util::log("Scripts folder not found\n");
//    return std::nullopt;
//}

pfn_loadbuffer* scan_loadbuffer(HMODULE ua)
{
    util::log(2,"Hooking... Attention: if logs stops at this line - you should inject dll before loading into world.","");
    auto il2cpp = util::pe::get_section_by_name(ua, "il2cpp");
    if (il2cpp == NULL)
        il2cpp = util::pe::get_section_by_name(ua, ".text");

    auto rdata = util::pe::get_section_by_name(ua, ".rdata");

    auto str = util::scanner::find_pat((const uint8_t*)"xluaL_loadbuffer", "xxxxxxxxxxxxxxxx", (const uint8_t*)((uint64_t)ua + rdata->VirtualAddress), rdata->Misc.VirtualSize);
    auto ref = util::scanner::find_ref_relative(str, (const uint8_t*)((uint64_t)ua + il2cpp->VirtualAddress), il2cpp->Misc.VirtualSize, true);

    auto a = util::scanner::find_pat((const uint8_t*)"\xE8\x00\x00\x00\x00\x48", "x????x", ref, 0x100);
    a += 8;
    auto off = *(uint32_t*)a;
    pfn_loadbuffer* ptr = (pfn_loadbuffer*)(a + off + 4);

    printf("%p\n", ptr);
    return ptr;
}

std::optional<std::string> compile(lua_State* L, const char* script)
{
    std::ostringstream compiled_script;

    auto writer = [](lua_State* L, const void* p, size_t sz, void* ud) -> int
    {
        auto out = (std::ostringstream*)ud;
        out->write((const char*)p, sz);
        return 0;
    };

    auto ret = luaL_loadstring(L, script);
    last_ret_code = ret;
    last_tolstr = lua_tolstring(L, 1, NULL);

    if (ret != 0)
    {
        std::string result = std::to_string(ret);
        //util::log(1,"compilation failed(%i)", result); // i dont think we need the err code :skull
        //util::log(1,"%s", lua_tolstring(L, 1, NULL));
        util::log(1,"compilation failed: %s", lua_tolstring(L, 1, NULL));
        //util::logdialog(lua_tolstring(L, 1, NULL)); ---- look in util.h; kinda useful but idk how to realise it at loading or how to mek slep
        lua_pop(L, 1);
        return std::nullopt;
    }



    ret = lua_dump(L, writer, &compiled_script, 0);
    if (ret != 0)
    {
        return std::nullopt;
    }

    lua_pop(L, 1);
    return compiled_script.str();
}

void get_gi_L()
{
    HMODULE ua = NULL;
    while ((ua = GetModuleHandleW(L"UserAssembly.dll")) == 0) {
        Sleep(50);
    }
    util::log(2,"FOUND", "");
    pp_loadbuffer = scan_loadbuffer(ua);
    *pp_loadbuffer = xluaL_loadbuffer_hook;

    //util::log("Waiting for Lua...\n","");

    while (!gi_L)
        Sleep(50);

    
    //util::log("L: %p\n", gi_L);

}

DWORD initLua(LPVOID) {
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    
	util::log(2,"Starting", "");
    //auto dir = get_scripts_folder();

    get_gi_L();

    auto state = luaL_newstate();

    //// rsapatch breaks input, restore input mode
   /* SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),
        ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS |
        ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE |
        ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT
    );*/
    return TRUE;

}
