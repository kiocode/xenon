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

void Builder::UseUpdate() {
    
    Services.GetConfiguration<GameConfig>()->m_bUseUpdate = true;

    spdlog::info("Update is enabled");
}

void Builder::UseAimbot() {

    Services.GetConfiguration<GameConfig>()->m_bUseAimbot = true;

    spdlog::info("Aimbot is enabled");
}

void Builder::UseRecoil() {

    Services.GetConfiguration<GameConfig>()->m_bUseRecoil = true;

    spdlog::info("Recoil is enabled");
}

void Builder::SetGameAbsolutePath(std::string path) {
    m_strGameAbsolutePath = path;
}

InternalCheat Builder::BuildInternal() {
    spdlog::info("Building internal cheat");
    return InternalCheat(GameManager);
}

ExternalCheat Builder::BuildExternal() {
    spdlog::info("Building external cheat");
    return ExternalCheat(GameManager);
}