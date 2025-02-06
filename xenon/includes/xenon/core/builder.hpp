#pragma once

#include <chrono>

#include <spdlog/spdlog.h>
#include <xenon/utility/vec2.hpp>
#include <xenon/core/cheat.hpp>
#include <xenon/components/features/game.hpp>
#include <xenon/components/services/memory_service.hpp>

/**
 * @class Builder
 * @brief Handles the initialization and configuration of the Xenon framework.
 *
 * The Builder class is responsible for managing core components,
 * logging levels, and game-related services. It also provides
 * functionalities to register default components and build the cheat instance.
 */
class Builder {
public:
    /**
     * @brief Shared pointer to the Xenon framework instance.
     */
    std::shared_ptr<Xenon> xenon;

    /**
     * @brief Shared pointer to the Xenon configuration settings.
     */
    std::shared_ptr<XenonConfig> xenonConfig;

    /**
     * @brief Shared pointer to Xenon global variables.
     */
    std::shared_ptr<XenonVariables> xenonVariables;

    /**
     * @brief Shared pointer to the game manager component.
     */
    std::shared_ptr<Game> GameManager;

    /**
     * @brief Vector containing all registered components.
     */
    std::vector<std::shared_ptr<CComponent>> components;

    /**
     * @brief Constructor that initializes the Builder with a specified application title.
     * @param appTitle The title of the application.
     */
    Builder(std::string appTitle) : m_strAppTitle(appTitle) {
        RegisterDefaultComponents();
    }

    /**
     * @brief Default constructor that initializes the Builder with an "Unknown" title.
     */
    Builder() : Builder("Unknown") {}

    /**
     * @brief Enables the console for debugging output.
     */
    void SetConsoleEnabled() const;

    /**
     * @brief Sets the logging level to Debug.
     */
    void SetDebugLogLevel();

    /**
     * @brief Sets the logging level to Info.
     */
    void SetInfoLogLevel();

    /**
     * @brief Sets the logging level to Warning.
     */
    void SetWarnLogLevel();

    /**
     * @brief Sets the logging level to Error.
     */
    void SetErrorLogLevel();

    /**
     * @brief Builds and returns an instance of the Cheat class.
     * @return A fully configured Cheat instance.
     */
    Cheat Build() const;

private:
    /**
     * @brief The title of the application.
     */
    std::string m_strAppTitle;

    /**
     * @brief Registers the default components required by the framework.
     */
    void RegisterDefaultComponents();
};
