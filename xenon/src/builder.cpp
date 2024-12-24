#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>

#include <xenon/core/builder.hpp>
#include <spdlog/spdlog.h>
#include <xenon/configs/aim_config.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/services/lua_service.hpp>

void Builder::SetDebugLogLevel() {
    spdlog::set_level(spdlog::level::debug);
}

void Builder::SetInfoLogLevel() {
    spdlog::set_level(spdlog::level::info);
}

void Builder::SetWarnLogLevel() {
    spdlog::set_level(spdlog::level::warn);
}

void Builder::SetErrorLogLevel() {
    spdlog::set_level(spdlog::level::err);
}

void Builder::RegisterDefaultServices() {

    #pragma region Configurations

    std::shared_ptr<AimConfig> pAimConfig = Services.AddConfiguration<AimConfig>();
    std::shared_ptr<GameConfig> pGameConfig = Services.AddConfiguration<GameConfig>();

    #pragma endregion

    #pragma region Utils

    std::shared_ptr<System> pSystem = Services.AddSingleton<System>();

    #pragma endregion

    #pragma region Services

    std::shared_ptr<LuaService> pLuaService = Services.AddSingleton<LuaService>();
    std::shared_ptr<AimService> pAimService = Services.AddSingleton<AimService>(
        [pSystem, pAimConfig]() {
            return std::make_shared<AimService>(pAimConfig, pSystem);
        }
    );

    #pragma endregion

    #pragma region Features

    std::shared_ptr<Aimbot> pAimbot = Services.AddSingleton<Aimbot>(
        [pAimConfig, pAimService]() {
            return std::make_shared<Aimbot>(pAimConfig, pAimService);
        }
    );

    GameManager = Services.AddSingleton<Game>([pGameConfig, pAimbot, pAimService, pSystem]() {
        return std::make_shared<Game>(pGameConfig, pAimbot, pAimService, pSystem);
    });

    #pragma endregion

}

void Builder::AttachGame(std::string absExePath) {
    std::wstring widePath = std::wstring(absExePath.begin(), absExePath.end());
    m_strGameAbsolutePath = absExePath;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        throw std::runtime_error("Failed to create process snapshot");
    }

    PROCESSENTRY32 processEntry{};
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    bool found = false;

    if (Process32First(snapshot, &processEntry)) {
        do {
            HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processEntry.th32ProcessID);
            if (processHandle) {
                wchar_t exePath[MAX_PATH];
                if (GetModuleFileNameExW(processHandle, nullptr, exePath, MAX_PATH)) {
                    if (_wcsicmp(exePath, widePath.c_str()) == 0) {
                        m_nPid = processEntry.th32ProcessID;

                        std::wstring processName(processEntry.szExeFile, processEntry.szExeFile + strlen(processEntry.szExeFile));
                        m_strProcessName = std::string(processName.begin(), processName.end());

                        found = true;
                        CloseHandle(processHandle);

                        spdlog::info("Attached to process: {}", m_strProcessName);
                        spdlog::debug("PID: {} - Path: {}", m_nPid, absExePath);

                        break;
                    }
                }
                CloseHandle(processHandle);
            }
        } while (Process32Next(snapshot, &processEntry));
    }

    CloseHandle(snapshot);

    if (!found) {
        throw std::runtime_error("Failed to attach to process");
    }
}

InternalCheat Builder::BuildInternal() {
    spdlog::debug("Building internal cheat");
    return InternalCheat(GameManager, Services.GetConfiguration<GameConfig>());
}

ExternalCheat Builder::BuildExternal() {
    spdlog::debug("Building external cheat");
    return ExternalCheat(GameManager, Services.GetConfiguration<GameConfig>());
}