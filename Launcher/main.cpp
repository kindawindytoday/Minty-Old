#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <optional>
#include <fstream>
#include <commdlg.h>
#define _CRT_SECURE_NO_WARNINGS
#include "../minty/json/json.hpp"


//#include "../minty/gilua/util.h"
//#include "../minty/gilua/luahook.h"

namespace fs = std::filesystem;

//std::ifstream f("cfg.json");

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
        //luahookfunc(errordialogtext);
        printf(errordialogtext);
    }
}

bool InjectStandard(HANDLE hTarget, const char* dllpath)
{
    LPVOID loadlib = GetProcAddress(GetModuleHandle(L"kernel32"), "LoadLibraryA");

    LPVOID dllPathAddr = VirtualAllocEx(hTarget, NULL, strlen(dllpath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (dllPathAddr == NULL)
    {
        std::cout << "Failed allocating memory in the target process. GetLastError(): " << GetLastError() << "\n";
        return false;
    }

    if (!WriteProcessMemory(hTarget, dllPathAddr, dllpath, strlen(dllpath) + 1, NULL))
    {
        std::cout << "Failed writing to process. GetLastError(): " << GetLastError() << "\n";
        return false;
    }

    HANDLE hThread = CreateRemoteThread(hTarget, NULL, NULL, (LPTHREAD_START_ROUTINE)loadlib, dllPathAddr, NULL, NULL);
    if (hThread == NULL)
    {
        std::cout << "Failed to create a thread in the target process. GetLastError(): " << GetLastError() << "\n";
        return false;
    }

    WaitForSingleObject(hThread, INFINITE);

    DWORD exit_code = 0;
    GetExitCodeThread(hThread, &exit_code);

    VirtualFreeEx(hTarget, dllPathAddr, 0, MEM_RELEASE);
    CloseHandle(hThread);

    if (exit_code == 0)
    {
        std::cout << "LoadLibrary failed.\n";
        return false;
    }
    return true;
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

std::optional<fs::path> this_dir()
{
    HMODULE mod = NULL;
    TCHAR path[MAX_PATH]{};
    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)&this_dir, &mod))
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

int main()
{
    nlohmann::json cfg;


    auto current_dir = this_dir();
    if (!current_dir)
        return 0;

    auto dll_path = current_dir.value() / "Minty.dll";
    if (!fs::is_regular_file(dll_path))
    {
        printf("Minty.dll not found\n");
        system("pause");
        return 0;
    }
    std::string exe_path;
    fs::path settings_path = fs::current_path() / "minty";

    /*std::ifstream ifs("cfg.json");
    ifs >> cfg;*/

    //f >> cfg;
    std::ifstream settings_file(settings_path);
    // Check if the settings file exists
    if (!fs::exists(settings_path)) {
        std::ofstream settings_file(settings_path);
        if (settings_file.is_open()) {
            // Write the executable path to the settings file
            cfg["exec_path"] = exe_path;
            settings_file << cfg.dump(4) << std::endl;
            settings_file.close();
        }
        else {
            std::cout << "Error: Unable to create config file." << std::endl;
            return 1;
        }
    }

    settings_file >> cfg;

    auto settings = read_whole_file(settings_path);
    if (!settings)
    {
        printf("Failed reading config\n");
        system("pause");
        return 0;
    }

    //std::string exe_path;
    //std::getline(std::stringstream(settings.value()), exe_path);
    std::cout << exe_path << std::endl;
    exe_path = cfg["exec_path"];
    std::cout << exe_path << std::endl;
    if (!fs::is_regular_file(exe_path))
    {
        std::cout << "File path in settings.exe invalid" << std::endl;
        std::cout << "Please select your Game Executable" << std::endl;
        /* printf("Target executable not found\n");
         system("pause");*/
        OPENFILENAMEA ofn{};
        char szFile[260]{};
        ZeroMemory(&ofn, sizeof(ofn));
        ofn.lStructSize = sizeof(ofn);
        ofn.lpstrFile = szFile;
        ofn.lpstrFile[0] = '\0';
        ofn.hwndOwner = NULL;
        ofn.nMaxFile = sizeof(szFile);
        ofn.lpstrFilter = "Executable Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0";
        ofn.nFilterIndex = 1;
        ofn.lpstrTitle = "Select Executable File";
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

        if (GetOpenFileNameA(&ofn))
        {
            std::string(exe_path) = ofn.lpstrFile;
            std::ofstream settings_file("minty", std::ios_base::out);
            if (settings_file.is_open()) {
                /*settings_file << exe_path << std::endl;
                settings_file.close();*/
                cfg["exec_path"] = exe_path;
                settings_file << cfg.dump(4) << std::endl;
                settings_file.close();
            }
            else {
                std::cout << "Error: Unable to open settings file." << std::endl;
                return 1;
            }
        }
        else {
            std::cout << "Error: Unable to open file dialog." << std::endl;
            return 1;
        }

        exe_path = cfg["exec_path"];
        PROCESS_INFORMATION proc_info{};
        STARTUPINFOA startup_info{};
        CreateProcessA(exe_path.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startup_info, &proc_info);

        InjectStandard(proc_info.hProcess, dll_path.string().c_str());
        ResumeThread(proc_info.hThread);
        CloseHandle(proc_info.hThread);
        CloseHandle(proc_info.hProcess);
        return 0;
    }

    PROCESS_INFORMATION proc_info{};
    STARTUPINFOA startup_info{};
    CreateProcessA(exe_path.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startup_info, &proc_info);
    //CreateProcessA(exe_path.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startup_info, &proc_info);

    InjectStandard(proc_info.hProcess, dll_path.string().c_str());
    ResumeThread(proc_info.hThread);
    CloseHandle(proc_info.hThread);
    CloseHandle(proc_info.hProcess);
    return 0;
}