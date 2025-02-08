#pragma once

#include <memory>

#include <spdlog/spdlog.h>

#include <xenon/models/enums/rendering_hook_type.hpp>
#include <xenon/models/enums/unrealengine_version.hpp>
#include <xenon/models/enums/unityengine_type.hpp>
#include <xenon/components/features/game.hpp>
#include <xenon/components/services/notification_service.hpp>

#include <xenon/core/system.hpp>

#include <xenon/core/xenon_config.hpp>
#include <xenon/core/xenon_variables.hpp>
#include <xenon/core/xenon_core.hpp>

class Cheat {
public:

    Cheat(
        std::shared_ptr<Xenon> pXenon,
        std::shared_ptr<XenonVariables> pXenonVariables,
        std::shared_ptr<Game> pGame
    ) : m_pXenon(pXenon), m_pXenonVariables(pXenonVariables), m_pGame(pGame) { }

    void UseUpdate() {

        m_pXenonVariables->g_bUpdate = true;

        spdlog::info("Update is enabled");
    }

    void UseUICustom(RenderingHookType renderingType) {

        if (!m_pXenon->g_pSystem->IsInternal()) {
            spdlog::warn("Rendering hook type is not necessary if the cheat is External");;
        }

        m_pXenonVariables->g_renderingType = renderingType;
        m_pXenonVariables->g_bRenderUI = true;

        spdlog::info("Custom UI is enabled");
    }

    void UseUICustom() {

        if (m_pXenon->g_pSystem->IsInternal()) {
            spdlog::error("Rendering hook type must be specified if the cheat is Internal");
            return;
        }

        m_pXenonVariables->g_bRenderUI = true;

        spdlog::info("Custom UI is enabled");
    }

    void UseAimbot() {

        m_pXenonVariables->g_bAimbot = true;

        spdlog::info("Aimbot is enabled");
    }

    void UseNoRecoil() {

        m_pXenonVariables->g_bNoRecoil = true;

        spdlog::info("Recoil is enabled");
    }

    void Use2DSpinbot() {

        m_pXenonVariables->g_bSpinbot2D = true;

        spdlog::info("Spinbot 2D is enabled");
    }

    void Use3DSpinbot() {

        m_pXenonVariables->g_bSpinbot3D = true;

        spdlog::info("Spinbot 3D is enabled");
    }

    void UseUIRadar() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("UI Radar can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bRadar = true;

        spdlog::info("UI Radar is enabled");

    }

    void UseUIMenu() {
        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("UI Menu can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bMenu = true;

        spdlog::info("UI Menu is enabled");

    }

    void UseUIRenderMouse() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("UI Custom Draw List can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bRenderMouse = true;

        spdlog::info("UI Custom Draw List of Mouse is enabled");
    }

    void UseUIRenderWindows() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("UI Custom Draw List can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bRenderWindows = true;

        spdlog::info("UI Custom Draw List of Windows is enabled");

    }

    void UseUIRenderOverlays() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("UI Custom Draw List can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bRenderOverlays = true;

        spdlog::info("UI Custom Draw List of Overlay is enabled");

    }

    void UseUIQuickActions() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("UI Quick Actions can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bRenderQuickActions = true;

        spdlog::info("UI Quick Actions is enabled");

    }

    void UseESPSnapline() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("Snapline ESP can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bSnapline = true;

        spdlog::info("Snapline ESP is enabled");

    }

    void UseESPBox2D() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("2D Box ESP can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bBox2D = true;

        spdlog::info("2D Box ESP is enabled");
    }

    void UseESPBox3D() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("3D Box ESP can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bBox3D = true;

        spdlog::info("3D Box ESP is enabled");
    }

    void UseESPSkeleton() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("Skeleton ESP can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bSkeleton = true;

        spdlog::info("Skeleton ESP is enabled");
    }

    void UseESPHealthBar() {

        if (!m_pXenonVariables->g_bRenderUI) {
            spdlog::error("Health Bar ESP can only be used with Custom UI");
            return;
        }

        m_pXenonVariables->g_bHealthBar = true;

        spdlog::info("Health Bar ESP is enabled");
    }

    void Run();

private:
    std::shared_ptr<Xenon> m_pXenon;
    std::shared_ptr<XenonVariables> m_pXenonVariables;
    std::shared_ptr<Game> m_pGame;

    bool FetchSDK() const {

        m_pXenon->g_pSystem->g_pUnityBase = (intptr_t)GetModuleHandle(NULL);
        if (m_pXenon->g_pSystem->g_pUnityBase == 0) {
            //spdlog::error("Failed to get base address");
            return false;
        }

        m_pXenon->g_pSystem->g_pUnityGameAssembly = (intptr_t)GetModuleHandle("GameAssembly.dll");
        if (m_pXenon->g_pSystem->g_pUnityGameAssembly == 0) {
            //spdlog::error("Failed to get GameAssembly address");
            return false;
        }

        m_pXenon->g_pSystem->g_pUnityPlayer = (intptr_t)GetModuleHandle("UnityPlayer.dll");
        if (m_pXenon->g_pSystem->g_pUnityPlayer == 0) {
            //spdlog::error("Failed to get UnityPlayer address");
            return false;
        }

        return true;

    }
};