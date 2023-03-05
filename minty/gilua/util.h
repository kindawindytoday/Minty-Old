#pragma once
#include <Windows.h>

#include <optional>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

namespace util
{
    template<typename... Args>
    void log(const char* fmt, Args... args)
    {
        printf("[GILua] ");
        printf(fmt, args...);
    }

}