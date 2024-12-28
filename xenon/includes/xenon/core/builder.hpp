#pragma once

#include <chrono>

#include <spdlog/spdlog.h>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/di_manager.hpp>
#include <xenon/core/cheat.hpp>
#include <xenon/features/game.hpp>
#include <xenon/services/aim_service.hpp>
#include <xenon/services/memory_service.hpp>

class Builder {
public:
    DIManager* Services;
    std::shared_ptr<MemoryService> MemoryManager;
    std::shared_ptr<Game> GameManager;
    std::shared_ptr<System> SystemVariables;

    Builder() {
        Services = &DIManager::GetInstance();
        RegisterDefaultServices();
    }

    Builder(std::string appTitle) : m_strAppTitle(appTitle) {
        Services = &DIManager::GetInstance();
        RegisterDefaultServices();
    }

    void SetConsoleEnabled() const;
    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetWarnLogLevel();
    void SetErrorLogLevel();

    Cheat Build();

private:
    std:: string m_strAppTitle;

    void RegisterDefaultServices();
};
