#pragma once

#include <chrono>

#include <spdlog/spdlog.h>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/di_manager.hpp>
#include <xenon/core/cheat.hpp>
#include <xenon/components/features/game.hpp>
#include <xenon/components/services/memory_service.hpp>

class Builder {
public:
    std::shared_ptr<Xenon> xenon;
    std::shared_ptr<XenonConfigs> xenonConfigs;
    std::shared_ptr<XenonVariables> xenonVariables;

    std::shared_ptr<Game> GameManager;

    std::vector<std::shared_ptr<CComponent>> Components;

    Builder(std::string appTitle) : m_strAppTitle(appTitle) {
        RegisterDefaultServices();
    }

    Builder() : Builder("Unknown") {}

    void SetConsoleEnabled() const;
    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetWarnLogLevel();
    void SetErrorLogLevel();

    Cheat Build() const;

private:
    std:: string m_strAppTitle;

    void RegisterDefaultServices();
};
