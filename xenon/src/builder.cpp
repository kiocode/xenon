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

    MemoryManager = Services.AddSingleton<MemoryService>();
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

InternalCheat Builder::BuildInternal() {
    spdlog::debug("Building internal cheat");
    return InternalCheat(GameManager, Services.GetConfiguration<GameConfig>());
}

ExternalCheat Builder::BuildExternal() {
    spdlog::debug("Building external cheat");
    return ExternalCheat(GameManager, Services.GetConfiguration<GameConfig>());
}