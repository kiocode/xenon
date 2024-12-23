#include <iostream>

#include <xenon/core/internal_cheat.hpp>
#include <kiero/kiero.h>
#include <xenon/core/gui.hpp>

void InternalCheat::Run() {

    spdlog::info("Internal cheat initialized");

    bool mainHkInitialized = false;
    do
    {
        if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
        {
            InitialSetup();
            mainHkInitialized = true;
        }
    } while (!mainHkInitialized);
}

#pragma region InternalCheat:Private

void InternalCheat::InitialSetup() {
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

    // main hook loop
    kiero::bind(8, (void**)&GUI::GetInstance().oPresent, GUI::hkPresentWrapper);
}

#pragma endregion
