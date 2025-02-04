#pragma once

#include <string>
#include <chrono>
#include <dxgi.h>

#include <xenon/utility/vec2.hpp>
#include <spdlog/spdlog.h>

#include <xenon/utility/vec3.hpp>
#include <xenon/core/xenon_core.hpp>
#include <xenon/core/xenon_config.hpp>
#include <xenon/core/xenon_variables.hpp>
#include <xenon/components/component.hpp>

/**
 * @class Game
 * @brief A class responsible for managing game-specific functionality in the Xenon framework.
 *
 * The Game class handles game events, update cycles, and interacts with core components and configurations.
 * It provides event-driven mechanisms and binds UI services for rendering.
 */
class Game {
public:

    /**
     * @brief Constructs a Game instance.
     * @param pXenon A shared pointer to the Xenon core instance.
     * @param pXenonConfigs A shared pointer to the Xenon configuration instance.
     * @param pXenonVariables A shared pointer to the Xenon variables instance.
     * @param pComponents A vector of shared pointers to components used in the game.
     *
     * The constructor initializes the Game instance with core Xenon components and services.
     */
    Game(
        std::shared_ptr<Xenon> pXenon,
        std::shared_ptr<XenonConfig> pXenonConfigs,
        std::shared_ptr<XenonVariables> pXenonVariables,
        std::vector<std::shared_ptr<CComponent>> pComponents
    );

    /**
     * @brief Enables the update cycle for the game.
     *
     * This method triggers the update process of the game, allowing components to be updated accordingly.
     */
    void EnableUpdate();

    /**
     * @brief Registers a callback function for a specific event.
     * @param eventName The name of the event to listen for.
     * @param callback The callback function to be executed when the event is triggered.
     */
    void OnEvent(const std::string& eventName, const std::function<void()>& callback);

    /**
     * @brief Triggers an event, executing all registered callbacks for that event.
     * @param eventName The name of the event to trigger.
     */
    void TriggerEvent(const std::string& eventName);

    /**
     * @brief Registers a callback function for an event that provides a target profile.
     * @param eventName The name of the event to listen for.
     * @param callback The callback function that takes a TargetProfile* argument to process the target.
     */
    void OnEvent(const std::string& eventName, const std::function<void(TargetProfile* target)>& callback);

    /**
     * @brief Triggers an event with a target profile, executing all registered callbacks for that event.
     * @param eventName The name of the event to trigger.
     * @param target The target profile associated with the event.
     */
    void TriggerEvent(const std::string& eventName, TargetProfile* target);

    /**
     * @brief Clears all callbacks associated with a specific event.
     * @param eventName The name of the event whose callbacks should be cleared.
     */
    void ClearEvent(const std::string& eventName);

private:
    /**
     * @brief A map storing event names and their associated callbacks (without target).
     */
    std::unordered_map<std::string, std::vector<std::function<void()>>> updateCallbacks;

    /**
     * @brief A map storing event names and their associated callbacks (with target profile).
     */
    std::unordered_map<std::string, std::vector<std::function<void(TargetProfile* target)>>> updateCurrentTargetCallbacks;

    /**
     * @brief A shared pointer to the Xenon core instance.
     */
    std::shared_ptr<Xenon> m_pXenon;

    /**
     * @brief A shared pointer to the Xenon configuration instance.
     */
    std::shared_ptr<XenonConfig> m_pXenonConfigs;

    /**
     * @brief A shared pointer to the Xenon variables instance.
     */
    std::shared_ptr<XenonVariables> m_pXenonVariables;

    /**
     * @brief A vector of shared pointers to components used in the game.
     */
    std::vector<std::shared_ptr<CComponent>> m_pComponents;

    /**
     * @brief Updates the game state, called during the game loop.
     */
    void Update();

    /**
     * @brief Handles any registered shortcut actions.
     */
    void HandleShortcuts();

    /**
     * @brief A static method to bind the internal SwapChain for DirectX rendering.
     * @param pSwapChain The DXGI SwapChain instance.
     * @param SyncInterval The sync interval for the swap chain.
     * @param Flags The flags used during the binding.
     * @return HRESULT indicating success or failure.
     */
    static HRESULT __stdcall BindForInternal(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

    /**
     * @brief Binds for external rendering.
     */
    void BindForExternal();

    /**
     * @brief A static variable indicating whether the game has been initialized.
     */
    inline static bool m_bInit = false;

    /**
     * @brief A static pointer to the render UI flag.
     */
    inline static bool* m_bRenderUI = nullptr;

    /**
     * @brief A static shared pointer to the UI service.
     */
    inline static std::shared_ptr<UIService> m_pUIService = nullptr;

    /**
     * @brief A static function wrapper for the update function.
     */
    inline static std::function<void()> UpdateWrapper;
};
