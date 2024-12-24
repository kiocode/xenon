#pragma once

#include <chrono>

#include <spdlog/spdlog.h>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/di_manager.hpp>
#include <xenon/core/external_cheat.hpp>
#include <xenon/core/internal_cheat.hpp>
#include <xenon/features/game.hpp>
#include <xenon/services/aim_service.hpp>
#include <xenon/services/memory_service.hpp>

class Builder {
public:
	DIManager Services;
    std::shared_ptr<MemoryService> MemoryManager;
    std::shared_ptr<Game> GameManager;

    Builder() {
        RegisterDefaultServices();
    }

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetWarnLogLevel();
    void SetErrorLogLevel();

    InternalCheat BuildInternal();
    ExternalCheat BuildExternal();

private:

    void RegisterDefaultServices();
};
