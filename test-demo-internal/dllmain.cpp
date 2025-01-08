#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <Windows.h>
#include <psapi.h>
#include <vector>
#include <cstdio>
#include <stdexcept>

uintptr_t FindPattern(const char* module_name, const char* pattern) {
    HMODULE module_handle = GetModuleHandleA(module_name);
    if (!module_handle) throw std::runtime_error("Module not found.");

    MODULEINFO module_info = {};
    if (!GetModuleInformation(GetCurrentProcess(), module_handle, &module_info, sizeof(module_info))) {
        throw std::runtime_error("Unable to retrieve module information.");
    }

    uintptr_t module_base = reinterpret_cast<uintptr_t>(module_info.lpBaseOfDll);
    uintptr_t module_size = static_cast<uintptr_t>(module_info.SizeOfImage);

    std::vector<int> byte_pattern;
    const char* current = pattern;
    while (*current) {
        if (*current == '?') {
            byte_pattern.push_back(-1);
            if (*(current + 1) == '?') ++current;
        }
        else {
            byte_pattern.push_back(std::strtoul(current, nullptr, 16));
        }
        current += 2;
    }

    for (uintptr_t i = module_base; i < module_base + module_size - byte_pattern.size(); ++i) {
        bool found = true;
        for (size_t j = 0; j < byte_pattern.size(); ++j) {
            if (byte_pattern[j] != -1 && *reinterpret_cast<uint8_t*>(i + j) != static_cast<uint8_t>(byte_pattern[j])) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }

    return 0;
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	Builder builder("Demo internal");
    builder.SystemVariables->IsInternal(true);
    builder.SetDebugLogLevel();
    builder.SetConsoleEnabled();

    Cheat cheat = builder.Build();
    
    cheat.UseUICustom(RenderingTypes::DIRECTX11);
    cheat.UseUIMenu();
    
    cheat.Run();
 

	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dReasonForCall, LPVOID lpReserved)
{
    switch (dReasonForCall)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

