#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <kiero/kiero.h>
#include "../xenon/libs/kiero/kiero.h"
#include <xenon/core/gui.hpp>
#include <xenon/core/builder.hpp>


DWORD WINAPI MainThread(LPVOID lpReserved)
{

	Builder core;
	core.SetDebugLogLevel();

    InternalCheat cheat = core.BuildInternal();

    cheat.Run();

	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
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

