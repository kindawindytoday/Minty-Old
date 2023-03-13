#include <Windows.h>
#include <iostream>
#include <filesystem>
#include <optional>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

#include "../minty/gilua/util.h"
//#include "../minty/gilua/luahook.h"

namespace fs = std::filesystem;

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

int main()
{
    auto current_dir = this_dir();
    if (!current_dir)
        return 0;

    auto dll_path = current_dir.value() / "Minty.dll";
    if (!fs::is_regular_file(dll_path))
    {
        printf("GILua.dll not found\n");
        system("pause");
        return 0;
    }

    auto settings_path = current_dir.value() / "settings.txt";
    if (!fs::is_regular_file(settings_path))
    {
        printf("settings.txt not found\n");
        system("pause");
        return 0;
    }

    auto settings = read_whole_file(settings_path);
    if (!settings)
    {
        printf("Failed reading settings.txt\n");
        system("pause");
        return 0;
    }

    std::string exe_path;
    std::getline(std::stringstream(settings.value()), exe_path);
    if (!fs::is_regular_file(exe_path))
    {
        printf("Target executable not found\n");
        system("pause");
        return 0;
    }

    PROCESS_INFORMATION proc_info{};
    STARTUPINFOA startup_info{};
    CreateProcessA(exe_path.c_str(), NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &startup_info, &proc_info);

    InjectStandard(proc_info.hProcess, dll_path.string().c_str());
    ResumeThread(proc_info.hThread);
    CloseHandle(proc_info.hThread);
    CloseHandle(proc_info.hProcess);
    return 0;
}