#include <xenon/core/core.hpp>

#include <spdlog/spdlog.h>
#include <xenon/configs/aim_config.hpp>
#include <xenon/features/aimbot.hpp>

void Core::SetDebugLogLevel() {
    spdlog::set_level(spdlog::level::debug);
}

void Core::SetInfoLogLevel() {
    spdlog::set_level(spdlog::level::info);
}

void Core::SetErrorLogLevel() {
    spdlog::set_level(spdlog::level::err);
}

void Core::RegisterDefaultServices() {
    std::shared_ptr<AimConfig> pAimConfig = Services.AddConfiguration<AimConfig>();
    std::shared_ptr<GameConfig> pGameConfig = Services.AddConfiguration<GameConfig>();

    std::shared_ptr<System> pSystem = Services.AddSingleton<System>([]() {
        return std::make_shared<System>();
    });

    std::shared_ptr<AimService> pAimService = Services.AddSingleton<AimService>(
        [pSystem, pAimConfig]() {
            return std::make_shared<AimService>(pAimConfig, pSystem);
        }   
    );

    std::shared_ptr<Aimbot> pAimbot = Services.AddSingleton<Aimbot>(
        [pAimConfig, pAimService]() {
            return std::make_shared<Aimbot>(pAimConfig, pAimService);
        }
    );

    GameManager = Services.AddSingleton<Game>([pGameConfig, pAimbot, pAimService, pSystem]() {
        return std::make_shared<Game>(pGameConfig, pAimbot, pAimService, pSystem);
    });
}

void Core::UseUpdate() {
    
    Services.GetConfiguration<GameConfig>()->m_bUseUpdate = true;

    spdlog::info("Update is enabled");
}

void Core::UseAimbot() {

    Services.GetConfiguration<GameConfig>()->m_bUseAimbot = true;

    spdlog::info("Aimbot is enabled");
}

void Core::UseRecoil() {

    Services.GetConfiguration<GameConfig>()->m_bUseRecoil = true;

    spdlog::info("Recoil is enabled");
}

void Core::SetGameAbsolutePath(std::string path) {
    m_strGameAbsolutePath = path;
}

void Core::Run() {
    //std::thread t([this]() { m_pGame->Update(); });
    //t.detach();
    GameManager->Update();
}
