#pragma once

#include <Windows.h>

#include <cstdio>
#include <cstdint>
#include <sstream>
#include <optional>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "..\lua\lua.hpp"
//#include "scanner.hpp"
//#include "pe.hpp"
//#include "util.hpp"

#ifndef HOOK_H
#define HOOK_H

inline int xluaL_loadbuffer_hook(lua_State* L, const char* chunk, size_t sz, const char* chunkname);

//pfn_loadbuffer* scan_loadbuffer(HMODULE ua);

inline void get_gi_L();

inline std::optional<std::string> compile(lua_State* L, const char* script);

inline void exec(const std::string& compiled);

inline void load_lua_file(lua_State* L, const char* script);

inline DWORD start(LPVOID);

#endif