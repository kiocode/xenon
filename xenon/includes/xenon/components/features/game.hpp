#pragma once

#include <string>
#include <chrono>
#include <dxgi.h>

#include <xenon/utility/vec2.hpp>
#include <spdlog/spdlog.h>

#include <xenon/utility/vec3.hpp>
#include <xenon/core/xenon_core.hpp>
#include <xenon/core/xenon_configs.hpp>
#include <xenon/core/xenon_variables.hpp>
#include <xenon/components/component.hpp>
#include <xenon/core/di_manager.hpp>

class Game {
public:

    Game(
        std::shared_ptr<Xenon> pXenon,
        std::shared_ptr<XenonConfigs> pXenonConfigs,
        std::shared_ptr<XenonVariables> pXenonVariables,
        std::vector<std::shared_ptr<CComponent>> pComponents
    ) : m_pXenon(pXenon), m_pXenonConfigs(pXenonConfigs), m_pXenonVariables(pXenonVariables), m_pComponents(pComponents) {}

	void EnableUpdate();

    void OnEvent(const std::string& eventName, const std::function<void()>& callback) {
        eventCallbacks[eventName].push_back(callback);
    }

    void TriggerEvent(const std::string& eventName) {
        if (eventCallbacks.find(eventName) != eventCallbacks.end()) {
            for (const auto& callback : eventCallbacks[eventName]) {
                callback();
            }
        }
    }

    void ClearEvent(const std::string& eventName) {
        eventCallbacks.erase(eventName);
    }

private:
    std::unordered_map<std::string, std::vector<std::function<void()>>> eventCallbacks;

    std::shared_ptr<Xenon> m_pXenon;
    std::shared_ptr<XenonConfigs> m_pXenonConfigs;
    std::shared_ptr<XenonVariables> m_pXenonVariables;
    std::vector<std::shared_ptr<CComponent>> m_pComponents;

    bool m_bInit = false;

    void Update();
	void HandleShortcuts(); 

    static HRESULT __stdcall hkPresentWrapper(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
        return DIManager::GetInstance().GetService<Game>()->BindForInternal(pSwapChain, SyncInterval, Flags);
    }
    HRESULT __stdcall BindForInternal(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
    void BindForExternal();

};
