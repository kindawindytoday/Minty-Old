#include <Windows.h>

#include <optional>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "luahook.h"
#include <chrono>
#define _CRT_SECURE_NO_WARNINGS
#include "../imgui/imgui.h"
#include "logtextbuf.h"


namespace fs = std::filesystem;

void luahookfunc(const char* charLuaScript);

namespace util
{
    template<typename... Args>
    void log(int output_type, const char* fmt, Args... args)
    {
        const char* info_type[] = {"Warning", "Error", "Info"};
        printf("[Minty:%s] ", info_type[output_type]);
        printf(fmt, args...);
        printf("\n");
        log_textbuf.appendf("[Minty:%s] ", info_type[output_type]);
        log_textbuf.appendf(fmt, args...);
        log_textbuf.appendf("\n");
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

