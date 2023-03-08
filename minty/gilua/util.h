#pragma once
#include <Windows.h>

#include <optional>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "luahook.h"

namespace fs = std::filesystem;

void luahookfunc(const char* charLuaScript);

namespace util
{
    template<typename... Args>
    void log(const char* fmt, Args... args)
    {
        printf("[Minty] ");
        printf(fmt, args...);
    }
    template<typename... Args>
    void logdialog(const char* fmt, Args... args)
    {
        const char* errordialogformat = "CS.LAMLMFNDPHJ.HAFGEFPIKFK(\"Minty\",\"%s\")";
        char errordialogtext[256];
        snprintf(errordialogtext, sizeof(errordialogtext), errordialogformat, fmt);
        luahookfunc(errordialogtext);
        printf(errordialogtext);
    }
}

