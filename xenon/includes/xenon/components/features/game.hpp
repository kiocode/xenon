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

class Game {
public:

    Game(
        std::shared_ptr<Xenon> pXenon,
        std::shared_ptr<XenonConfig> pXenonConfigs,
        std::shared_ptr<XenonVariables> pXenonVariables,
        std::vector<std::shared_ptr<CComponent>> pComponents
    ) : m_pXenon(pXenon), m_pXenonConfigs(pXenonConfigs), m_pXenonVariables(pXenonVariables), m_pComponents(pComponents) {
        m_bRenderUI = &m_pXenonVariables->g_bRenderUI;
        m_pUIService = m_pXenon->g_cUIService;
        UpdateWrapper = std::bind(&Game::Update, this);
    }

	void EnableUpdate();

    void OnEvent(const std::string& eventName, const std::function<void()>& callback) {
        updateCallbacks[eventName].push_back(callback);
    }

    void TriggerEvent(const std::string& eventName) {
        if (updateCallbacks.find(eventName) != updateCallbacks.end()) {
            for (const auto& callback : updateCallbacks[eventName]) {
                callback();
            }
        }
    }

    void OnEvent(const std::string& eventName, const std::function<void(TargetProfile* target)>& callback) {
        updateCurrentTargetCallbacks[eventName].push_back(callback);
    }

    void TriggerEvent(const std::string& eventName, TargetProfile* target) {
        if (updateCurrentTargetCallbacks.find(eventName) != updateCurrentTargetCallbacks.end()) {
            for (const auto& callback : updateCurrentTargetCallbacks[eventName]) {
                callback(target);
            }
        }
    }

    void ClearEvent(const std::string& eventName) {
        updateCallbacks.erase(eventName);
        updateCurrentTargetCallbacks.erase(eventName);
    }

private:
    std::unordered_map<std::string, std::vector<std::function<void()>>> updateCallbacks;
    std::unordered_map<std::string, std::vector<std::function<void(TargetProfile* target)>>> updateCurrentTargetCallbacks;

    std::shared_ptr<Xenon> m_pXenon;
    std::shared_ptr<XenonConfig> m_pXenonConfigs;
    std::shared_ptr<XenonVariables> m_pXenonVariables;
    std::vector<std::shared_ptr<CComponent>> m_pComponents;

    void Update();
	void HandleShortcuts(); 

    static HRESULT __stdcall BindForInternal(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
    void BindForExternal();

    inline static bool m_bInit = false;
    inline static bool* m_bRenderUI = nullptr;
    inline static std::shared_ptr<UIService> m_pUIService = nullptr;
    inline static std::function<void()> UpdateWrapper;
};
