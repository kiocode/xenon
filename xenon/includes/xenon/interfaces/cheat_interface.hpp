#pragma once

#include <memory>

#include <xenon/configs/game_config.hpp>
#include <spdlog/spdlog.h>

class Cheat {
public:
    virtual void Run() = 0;

    void UseUpdate() {

        m_pGameConfig->m_bUseUpdate = true;

        spdlog::info("Update is enabled");
    }

    void UseAimbot() {

        m_pGameConfig->m_bUseAimbot = true;

        spdlog::info("Aimbot is enabled");
    }

    void UseRecoil() {

        m_pGameConfig->m_bUseRecoil = true;

        spdlog::info("Recoil is enabled");
    }

protected:
    explicit Cheat(std::shared_ptr<GameConfig> gameConfig) : m_pGameConfig(gameConfig) {}

private:
    std::shared_ptr<GameConfig> m_pGameConfig;
};