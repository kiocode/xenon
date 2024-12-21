#pragma once

#include <chrono>

#include <spdlog/spdlog.h>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/di_manager.hpp>
#include <xenon/core/external_cheat.hpp>
#include <xenon/core/internal_cheat.hpp>
#include <xenon/features/game.hpp>
#include <xenon/services/aim_service.hpp>

class Builder {
public:
	DIManager Services;
    std::shared_ptr<Game> GameManager;

    Builder() {
        RegisterDefaultServices();
    }

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetErrorLogLevel();

    void UseUpdate();
    void UseAimbot();
    void UseRecoil();

    void SetGameAbsolutePath(std::string path);

    InternalCheat BuildInternal();
    ExternalCheat BuildExternal();

private:
    std::string m_strGameAbsolutePath;
    void RegisterDefaultServices();
};
