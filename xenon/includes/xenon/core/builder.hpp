#pragma once

#include <chrono>

#include <spdlog/spdlog.h>
#include <xenon/utility/vec2.hpp>
#include <xenon/components/features/game.hpp>
#include <xenon/components/services/memory_service.hpp>
#include <xenon/core/cheat.hpp>

class Builder {
public:

    std::shared_ptr<Xenon> xenon;

    std::shared_ptr<XenonConfig> xenonConfig;

    std::shared_ptr<XenonVariables> xenonVariables;

    std::shared_ptr<Game> GameManager;

    std::vector<std::shared_ptr<CComponent>> components;

    Builder(std::string appTitle) : m_strAppTitle(appTitle) {
        RegisterDefaultComponents();
    }

    Builder() : Builder("Unknown") {}

    void SetConsoleEnabled() const;

    void SetDebugLogLevel();

    void SetInfoLogLevel();

    void SetWarnLogLevel();

    void SetErrorLogLevel();

    Cheat Build() const;

private:

    std::string m_strAppTitle;

    void RegisterDefaultComponents();

};
