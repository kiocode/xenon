#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <kiero/kiero.h>
#include "../xenon/libs/kiero/kiero.h"
#include <xenon/core/gui.hpp>

void InitialSetup()
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	SetConsoleTitle("Universal");
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
	std::cout << "\n*******************************************************************************" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	std::cout << R"(  
     __  __     __     ______     ______     ______     _____     ______    
    /\ \/ /    /\ \   /\  __ \   /\  ___\   /\  __ \   /\  __-.  /\  ___\    
    \ \  _'-.  \ \ \  \ \ \/\ \  \ \ \____  \ \ \/\ \  \ \ \/\ \ \ \  __\   
     \ \_\ \_\  \ \_\  \ \_____\  \ \_____\  \ \_____\  \ \____-  \ \_____\    
      \/_/\/_/   \/_/   \/_____/   \/_____/   \/_____/   \/____/   \/_____/
    )" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
	std::cout << "\n*******************************************************************************\n" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);

	// main loop
	kiero::bind(8, (void**)&GUI::GetInstance().oPresent, GUI::hkPresentWrapper);

}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	bool mainHkInitialized = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			InitialSetup();
			mainHkInitialized = true;
		}
		else
		{
			MessageBoxA(NULL, "Kiero initialization failed", "Debug", MB_OK);
		}
	} while (!mainHkInitialized);

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

