#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>

#include <cstdio>
#include <cstdint>
#include <sstream>
#include <optional>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "..\lua\lua.hpp"
#include "scanner.hpp"
#include "pe.hpp"
#include "util.hpp"
#include "luahook.h"

namespace fs = std::filesystem;

lua_State* gi_L;
HMODULE xlua;
HANDLE main_thread;

using pfn_loadbuffer = int (*)(lua_State*, const char*, size_t, const char*);
pfn_loadbuffer* pp_loadbuffer;
int xluaL_loadbuffer_hook(lua_State* L, const char* chunk, size_t sz, const char* chunkname)
{
    gi_L = L;
    main_thread = OpenThread(THREAD_ALL_ACCESS, false, GetCurrentThreadId());
    xlua = GetModuleHandleW(L"xlua");
    *pp_loadbuffer = (pfn_loadbuffer)GetProcAddress(xlua, "xluaL_loadbuffer");
    return (*pp_loadbuffer)(L, chunk, sz, chunkname);
}

pfn_loadbuffer* scan_loadbuffer(HMODULE ua)
{
    util::log("Scanning... ");
    auto il2cpp = util::pe::get_section_by_name(ua, "il2cpp");
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

void get_gi_L()
{
    HMODULE ua = NULL;
    while ((ua = GetModuleHandleW(L"UserAssembly.dll")) == 0)
        Sleep(50);

    pp_loadbuffer = scan_loadbuffer(ua);
    *pp_loadbuffer = xluaL_loadbuffer_hook;

    util::log("Waiting for Lua...\n");

    while (!gi_L)
        Sleep(50);

    util::log("L: %p\n", gi_L);
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
    if (ret != 0)
    {
        util::log("compilation failed(%i)\n", ret);
        util::log("%s\n", lua_tolstring(L, 1, NULL));
        lua_pop(L, 1);
        return std::nullopt;
    }

    ret = lua_dump(L, writer, &compiled_script, 0);
    if (ret != 0)
    {
        util::log("lua_dump failed(%i)\n", ret);
        return std::nullopt;
    }

    lua_pop(L, 1);
    return compiled_script.str();
}

void exec(const std::string& compiled)
{
    using pfn_pcall = int (*)(lua_State* L, int nargs, int nresults, int errfunc);
    static auto xlua_pcall = (pfn_pcall)GetProcAddress(xlua, "lua_pcall");
    static auto xluaL_loadbuffer = (pfn_loadbuffer)GetProcAddress(xlua, "xluaL_loadbuffer");

    int ret = xluaL_loadbuffer(gi_L, compiled.c_str(), compiled.length(), "GILua");
    if (ret != 0)
    {
        util::log("loading failed(%i)\n", ret);
        util::log("%s\n", lua_tolstring(gi_L, 1, NULL));
        lua_pop(gi_L, 1);
        return;
    }

    ret = xlua_pcall(gi_L, 0, 0, 0);
    if (ret != 0)
    {
        util::log("execution failed(%i)\n", ret);
        util::log("%s\n", lua_tolstring(gi_L, 1, NULL));
        lua_pop(gi_L, 1);
    }
}

//void load_lua_file(lua_State* L, const fs::path& file)
void load_lua_file(lua_State* L, const char* script)
{
    /*auto name = file.filename().string();
    util::log("loading %s\n", name.c_str());

    auto script = util::read_whole_file(file);
    if (!script)
    {
        util::log("Failed reading file %s\n", name.c_str());
        return;
    }*/

    //auto compiled = compile(L, script.value().c_str());
    auto compiled = compile(L, script);
    if (!compiled)
        return;

    // execute on the right thread or some functions will crash
    auto copy = new std::string(compiled.value());
    auto execute = [](ULONG_PTR compiled)
    {
        auto str = (const std::string*)compiled;
        exec(*str);
        delete str;
    };
    QueueUserAPC(execute, main_thread, (ULONG_PTR)copy);
}

//void load_luas_from_dir(lua_State* L, const fs::path& dir)
//{
//    for (const auto& entry : fs::directory_iterator{ dir })
//    {
//        if (entry.is_regular_file() && entry.path().extension() == ".lua")
//        {
//            load_lua_file(L, entry);
//        }
//    }
//}

//std::optional<fs::path> get_scripts_folder()
//{
//    auto mod_dir = util::this_dir();
//    if (!mod_dir)
//        return std::nullopt;
//
//    auto scripts_path = mod_dir.value() / "Scripts";
//    if (fs::is_directory(scripts_path))
//        return scripts_path;
//
//    util::log("Scripts folder not found\n");
//    return std::nullopt;
//}

//void command_loop(lua_State* L, fs::path& scripts)
//{
//    util::log("Type 'loadall' to load all scripts\n");
//    util::log("Type 'load <filename> ...' to load specific scripts\n");
//
//    while (true)
//    {
//        std::string input;
//        std::getline(std::cin, input);
//        auto cmd = util::split(input, ' ');
//        if (cmd.empty())
//            continue;
//        auto nargs = cmd.size() - 1;
//
//        if (cmd[0] == "loadall")
//        {
//            load_luas_from_dir(L, scripts);
//        }
//        else if (cmd[0] == "load")
//        {
//            for (int i = 0; i < nargs; i++)
//            {
//                auto file = scripts / cmd[i+1];
//                file.replace_extension(".lua");
//                if (fs::is_regular_file(file))
//                    load_lua_file(L, file);
//                else
//                    util::log("File %s not found\n", file.string().c_str());
//            }
//        }
//        else
//            util::log("Invalid command!\n");
//    }
//}

DWORD start(LPVOID)
{
    AllocConsole();
    FILE* pConsoleIn = nullptr;
    FILE* pConsoleOut = nullptr;
    FILE* pConsoleErr = nullptr;
    freopen_s(&pConsoleIn, "CONIN$", "r", stdin);
    freopen_s(&pConsoleOut, "CONOUT$", "w", stdout);
    freopen_s(&pConsoleErr, "CONOUT$", "w", stderr);

    util::log("GILua by azzu\n");

    /*auto dir = get_scripts_folder();
    if (!dir)
        return 0;*/

    get_gi_L();

    auto state = luaL_newstate();

    // rsapatch breaks input, restore input mode
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE),
        ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS |
        ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE |
        ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT
        );

    /*command_loop(state, dir.value());*/

    return 0;
}