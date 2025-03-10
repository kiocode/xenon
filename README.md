# Xenon Framework - C++ Game Hacking Framework

**Xenon** is a powerful and flexible C++ framework designed for creating game cheats, both internal and external. It provides a modular architecture that allows developers to easily implement features like ESP, Aimbot, Radar, and more. Xenon supports multiple game engines, including Unreal Engine and Unity, and is designed to be universal, meaning it can be adapted to various games with minimal changes.

This README provides an overview of the framework, examples of how to create projects using Xenon, and a comparison between internal and external cheats, as well as support for Unreal Engine and Unity.

### NOTE: A complete documentation is under elaboration.
---

## Table of Contents
1. [Introduction](#introduction)
2. [Internal vs External Cheats](#internal-vs-external-cheats)
3. [Supported Game Engines](#supported-game-engines)
4. [Getting Started](#getting-started)
   - [Internal Cheat Example](#internal-cheat-example)
   - [External Cheat Example](#external-cheat-example)
   - [Automatic DLL Injection](#automatic-dll-injection)
5. [Configuration and Customization](#configuration-and-customization)
6. [Contributing](#contributing)
7. [License](#license)

---

## Introduction

Xenon is designed to simplify the process of creating game cheats by providing a set of reusable components and utilities. It abstracts low-level details, allowing developers to focus on implementing game-specific logic. The framework supports both **internal** (DLL injection) and **external** (standalone application) cheats, and it can be adapted to work with different game engines.

Key Features:
- **Modular Design**: Easily add or remove features like ESP, Aimbot, Radar, etc.
- **Universal Compatibility**: Works with Unreal Engine, Unity, and other engines.
- **Customizable UI**: Built-in support for ImGui for creating in-game overlays.
- **Memory Management**: Provides utilities for reading/writing game memory.
- **Event-Driven Architecture**: Hook into game events like updates or rendering.
- **Automatic DLL Injection**: Built-in system for injecting DLLs into game processes (work in progress but functional in many cases).

---

## Internal vs External Cheats

### Internal Cheats
Internal cheats are implemented as DLLs that are injected into the game process. They have direct access to the game's memory and functions, making them powerful but also more detectable by anti-cheat systems.

**Pros**:
- Direct access to game memory and functions.
- Easier to implement complex features like ESP or Aimbot.

**Cons**:
- Higher risk of detection by anti-cheat systems.
- Requires DLL injection, which can be more complex to set up.

**Example**:
```cpp
#include <Windows.h>
#include "basic_ue.hpp"
#include <xenon/xenon.hpp>

DWORD WINAPI MainThread(LPVOID lpReserved) {
    Builder builder("Internal Cheat Example");
    std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
    // ... (setup configurations and features)
    Cheat cheat = builder.Build();
    cheat.Run();
    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    }
    return TRUE;
}
```

### External Cheats
External cheats run as standalone applications and interact with the game process through memory reading/writing. They are generally safer from detection but may have limited functionality compared to internal cheats.

**Pros**:
- Lower risk of detection.
- Easier to develop and debug.

**Cons**:
- Limited access to game memory and functions.
- May require more effort to implement complex features.

**Example**:
```cpp
#include <windows.h>
#include <xenon/xenon.hpp>

int main() {
    Builder builder("External Cheat Example");
    builder.xenon->g_pSystem->IsInternal(false);
    // ... (setup configurations and features)
    Cheat cheat = builder.Build();
    cheat.Run();
    return 0;
}
```

---

## Supported Game Engines

### Unreal Engine
Xenon provides built-in support for Unreal Engine games. ([Check this example project](https://github.com/kiocode/xenon/tree/main/example-ohd-internal))

**Example**:
```cpp
pSystem->IsUnrealEngine(UnrealEngineVersion::UE4);
pSystem->m_fnW2S3D = [](Vec3 pos) {
    SDK::FVector2D screenPos;
    SDK::FVector unrealPos(pos.x, pos.z, pos.y);
    if (UE::m_pMyController->ProjectWorldLocationToScreen(unrealPos, &screenPos, false)) {
        return Vec2(screenPos.X, screenPos.Y);
    }
    return Vec2(-99, -99);
};
```

### Unity
Xenon can also be adapted to work with Unity games, though it requires additional setup to access Unity-specific data structures. Xenon has a custom IL2CPP Resolver integration, improved to avoid crashes when getting targets.

**Example**:
```cpp
pSystem->IsUnityEngine(true);
// Unity-specific memory reading/writing logic goes here.
//..
Cheat cheat = builder.Build();
cheat.Run();

if (IL2CPP::Initialize(true)) {
  spdlog::info("Il2Cpp initialize success.");
}
else {
  spdlog::error("Il2Cpp initialize failed.");
  Sleep(300);
  exit(0);
}
if (!cheat.FetchSDK()) return FALSE;
```

---

## Getting Started

### Internal Cheat Example
Below is an example of an internal cheat for an Unreal Engine game:

```cpp
#include <Windows.h>
#include <xenon/xenon.hpp>

DWORD WINAPI MainThread(LPVOID lpReserved) {
    Builder builder("Internal Cheat Example");
    std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
    std::shared_ptr<EspConfig> pEspConfig = builder.xenonConfig->g_pEspConfig;

    pSystem->IsInternal(true);
    pSystem->IsUnrealEngine(UnrealEngineVersion::UE4); // check your game
    pSystem->SetGameDimension(GameDimension::DIM_3D);
    pSystem->SetRenderingType(RenderingType::DX11); 

    builder.SetInfoLogLevel();
    builder.SetConsoleEnabled();

    pEspConfig->m_nLimitDistance = 10000;
    pEspConfig->m_fHealthBarWidth = 40;

    builder.GameManager->OnEvent("Update", [pGameVariables]() {
        // Update game variables and targets,
	// so there you can get players in any way you need in any game
    });

    Cheat cheat = builder.Build();
    cheat.UseUICustom(RenderingHookType::KIERO);
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
```

### External Cheat Example
Below is an example of an external cheat for a 2D game:

```cpp
#include <windows.h>
#include <xenon/xenon.hpp>

int main() {
    Builder builder("External Cheat Example");
    builder.xenon->g_pSystem->IsInternal(false);
    builder.SetConsoleEnabled();
    builder.SetInfoLogLevel();

    builder.xenon->g_pSystem->SetGameDimension(GameDimension::DIM_2D);

    builder.xenon->g_cMemoryService->AttachGame("Your\\Game\\Path.exe");
    uintptr_t serverAddr = builder.xenon->g_cMemoryService->ReadPointer(offsets.staticServerAddr);
    uintptr_t clientAddr = builder.xenon->g_cMemoryService->ReadPointer(offsets.staticClientAddr);

    if (!serverAddr || !clientAddr) {
        spdlog::error("Failed to find server or client address");
        return 1;
    }

    builder.GameManager->OnEvent("Update", [builder]() {
        // Update game variables and targets
    });

    Cheat cheat = builder.Build();
    cheat.UseUICustom();
    cheat.UseUIMenu();
    cheat.Run();

    return 0;
}
```

### Automatic DLL Injection
Xenon includes a built-in system for automatic DLL injection into game processes. This feature is still a work in progress but is functional in many cases.

**Example**:
```cpp
#include <spdlog/spdlog.h>
#include <xenon/xenon.hpp>
#include <xenon/components/services/injection_service.hpp>

void Inject(std::string dllPath, std::string exePath, std::string launchOptions) {
    Builder builder("Custom Injector");
    builder.SetDebugLogLevel();

    spdlog::info("Game Path: {}", exePath);
    spdlog::info("DLL Path: {}", dllPath);

    HANDLE hProcess, hThread;
    if (!builder.xenon->g_cInjectionService->OpenGame(&hProcess, &hThread, exePath, launchOptions)) {
        spdlog::error("Failed to open game process.");
        system("pause");
        return;
    }

    builder.xenon->g_cInjectionService->Inject(hProcess, dllPath, InjectionType::LoadLibraryDLL);

    Sleep(3000);
    ResumeThread(hThread);
    CloseHandle(hProcess);
}

int main() {
    // Example usage:
    Inject("E:\\Projects\\xenon\\example-redmatch2-internal\\build\\example-redmatch2-internal.dll", 
           "D:\\Steam\\steamapps\\common\\Redmatch 2\\Redmatch 2.exe", "");

    //Inject("E:\\Projects\\xenon\\example-amongus-internal\\build\\example-amongus-internal.dll", 
    //       "D:\\Among Us\\Among Us.exe", "");

    return 0;
}
```

---

## Configuration and Customization

Xenon is highly customizable. You can configure features like ESP, Aimbot, and Radar through the `Builder` class. For example:

```cpp
std::shared_ptr<AimConfig> pAimConfig = builder.xenonConfig->g_pAimConfig;
pAimConfig->m_fDistanceScale = 0.06f;
pAimConfig->m_nLimitDistance = 100000;

std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
pUIConfig->m_qActions->AddSlider("Distance Scale", &pAimConfig->m_fDistanceScale, 0.001, 2);
```

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=kiocode/xenon-cheats&type=Date)](https://star-history.com/#kiocode/xenon-cheats&Date)

## Star History

<a href="https://star-history.com/#kiocode/xenon-cheats&Date">
 <picture>
   <source media="(prefers-color-scheme: dark)" srcset="https://api.star-history.com/svg?repos=kiocode/xenon-cheats&type=Date&theme=dark" />
   <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/svg?repos=kiocode/xenon-cheats&type=Date" />
   <img alt="Star History Chart" src="https://api.star-history.com/svg?repos=kiocode/xenon-cheats&type=Date" />
 </picture>
</a>

---

## Contributing

Contributions are welcome! Please read the [CONTRIBUTING.md](https://github.com/kiocode/xenon/blob/main/CONTRIBUTING.md) file for details on how to contribute to the project.

---

## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/kiocode/xenon/blob/main/LICENSE.md) file for details.

---

For more information, visit the [Xenon GitHub repository](https://github.com/kiocode/xenon).
