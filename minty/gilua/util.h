

#include <Windows.h>

#include <optional>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "luahook.h"
#include <chrono>
#define _CRT_SECURE_NO_WARNINGS

namespace fs = std::filesystem;

void luahookfunc(const char* charLuaScript);

namespace util
{
    //template<typename... Args>
    void log(const char* fmt, std::string args)
    {
        printf("[Minty] ");
        printf(fmt, args);
    }

    void logdialog(const char* fmt)
    {
        const char* errordialogformat = "CS.LAMLMFNDPHJ.HAFGEFPIKFK(\"%s\",\"Minty\")";
        char errordialogtext[256];
        snprintf(errordialogtext, sizeof(errordialogtext), errordialogformat, fmt);
        luahookfunc(errordialogtext);
        printf(errordialogtext);
    }
}

