#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	Builder builder("Demo internal");
    builder.SystemVariables->IsInternal(true);
    builder.SetDebugLogLevel();
    builder.SetConsoleEnabled();

    Cheat cheat = builder.Build();
    
    cheat.UseUICustom();
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

