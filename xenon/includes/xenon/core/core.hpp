#pragma once

#include <chrono>

#include <xenon/core/di_manager.hpp>
#include <xenon/features/game.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/services/aim_service.hpp>
#include <spdlog/spdlog.h>

class Core {
public:
	DIManager Services;
    std::shared_ptr<Game> GameManager;

    Core() {
        RegisterDefaultServices();
    }

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetErrorLogLevel();

    void UseUpdate();
    void UseAimbot();
    void UseRecoil();

    void SetGameAbsolutePath(std::string path);
    void Run();

private:
    std::string m_strGameAbsolutePath;
    void RegisterDefaultServices();
};
