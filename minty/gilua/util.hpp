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

    std::optional<fs::path> this_dir()
    {
        HMODULE mod = NULL;
        TCHAR path[MAX_PATH]{};
        if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)&this_dir, &mod)) //lpcwstr
        {
            printf("GetModuleHandleEx failed (%i)\n", GetLastError());
            return std::nullopt;
        }

        if (!GetModuleFileName(mod, path, MAX_PATH))
        {
            printf("GetModuleFileName failed (%i)\n", GetLastError());
            return std::nullopt;
        }

        return fs::path(path).remove_filename();
    }

    std::optional<std::string> read_whole_file(const fs::path& file)
    try
    {
        std::stringstream buf;
        std::ifstream ifs(file);
        if (!ifs.is_open())
            return std::nullopt;
        ifs.exceptions(std::ios::failbit);
        buf << ifs.rdbuf();
        return buf.str();
    }
    catch (const std::ios::failure&)
    {
        return std::nullopt;
    }

    std::vector<std::string> split(const std::string& s, char delim)
    {
        std::vector<std::string> result;
        std::stringstream ss(s);
        std::string item;

        while (std::getline(ss, item, delim))
        {
            if (!item.empty())
                result.push_back(item);
        }

        return result;
    }
}