#pragma once

#include <memory>

#include <xenon/configs/game_config.hpp>
#include <spdlog/spdlog.h>
#include <xenon/features/game.hpp>


enum class UnityEngineType {
    IL2CPP,
    Mono
};

enum class UnrealEngineVersion {
    UE3,
    UE4,
    UE5
};


class Cheat {
public:

    Cheat(
        std::shared_ptr<Game> game, 
        std::shared_ptr<GameConfig> gameConfig, 
        std::shared_ptr<UIService> UIService, 
        std::shared_ptr<System> system
    ) : m_pGameConfig(gameConfig), m_pGame(game), m_pUIService(UIService), m_pSystem(system) { }

    void UseUpdate() {

        m_pGameConfig->m_bUseUpdate = true;

        spdlog::info("Update is enabled");
    }

    void UseCustomUI() {
        
		m_pGameConfig->m_bUseCustomUI = true;

		spdlog::info("Custom UI is enabled");
    }

    void UseAimbot() {

        m_pGameConfig->m_bUseAimbot = true;

        spdlog::info("Aimbot is enabled");
    }

    void UseRecoil() {

        m_pGameConfig->m_bUseRecoil = true;

        spdlog::info("Recoil is enabled");
    }

    void Use2DSpinbot() {

        m_pGameConfig->m_bUse2DSpinbot = true;

        spdlog::info("Spinbot 2D is enabled");
    }

    void Use3DSpinbot() {

        m_pGameConfig->m_bUse3DSpinbot = true;

        spdlog::info("Spinbot 3D is enabled");
    }

    void IsUnityEngine(UnityEngineType type);
    void IsUnrealEngine(UnrealEngineVersion version);

    void Run();

private:
    std::shared_ptr<Game> m_pGame;
    std::shared_ptr<GameConfig> m_pGameConfig;
    std::shared_ptr<UIService> m_pUIService;
    std::shared_ptr<System> m_pSystem;

};