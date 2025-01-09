#pragma once

#include <memory>

#include <xenon/configs/game_config.hpp>
#include <spdlog/spdlog.h>
#include <xenon/features/game.hpp>
#include <xenon/models/rendering_hook_types.hpp>
#include <xenon/models/unrealengine_versions.hpp>
#include <xenon/models/unityengine_types.hpp>
#include <xenon/services/notification_service.hpp>

class Cheat {
public:

    Cheat(
        std::shared_ptr<Game> pGame, 
        std::shared_ptr<GameConfig> pGameConfig, 
        std::shared_ptr<UIService> pUiService,
        std::shared_ptr<UIConfig> pUiConfig, 
        std::shared_ptr<System> pSystem,
        std::shared_ptr<NotificationService> pNotificationService
    ) : m_pGame(pGame), m_pGameConfig(pGameConfig), m_pUIService(pUiService), m_pUIConfig(pUiConfig), m_pSystem(pSystem), m_pNotificationService(pNotificationService) { }

    void UseUpdate() {

        m_pGameConfig->m_bUseUpdate = true;

        spdlog::info("Update is enabled");
    }

    void UseUICustom(RenderingHookTypes renderingType) {

        if (!m_pSystem->IsInternal()) {
			spdlog::warn("Rendering hook type is not necessary if the cheat is Internal");;
		}
        
		m_pGameConfig->m_bRenderingType = renderingType;
		m_pGameConfig->m_bUseUICustom = true;

		spdlog::info("Custom UI is enabled");
    }

    void UseUICustom() {

        if (m_pSystem->IsInternal()) {
			spdlog::error("Rendering hook type must be specified if the cheat is Internal");
            return;
		}
        
		m_pGameConfig->m_bUseUICustom = true;

		spdlog::info("Custom UI is enabled");
    }

    void UseAimbot() {

        m_pGameConfig->m_bUseAimbot = true;

        spdlog::info("Aimbot is enabled");
    }

    void UseRecoil() {

        m_pGameConfig->m_bUseRecoil = true;

        spdlog::info("Recoil is enabled");
    }

    void Use2DSpinbot() {

        m_pGameConfig->m_bUse2DSpinbot = true;

        spdlog::info("Spinbot 2D is enabled");
    }

    void Use3DSpinbot() {

        m_pGameConfig->m_bUse3DSpinbot = true;

        spdlog::info("Spinbot 3D is enabled");
    }

    void UseUIRadar() {

        if (!m_pGameConfig->m_bUseUICustom) {
            spdlog::error("UI Radar can only be used with Custom UI");
			return;
		}
        
        m_pUIConfig->m_bUseUIRadar = true;

		spdlog::info("UI Radar is enabled");

    }

    void UseUIMenu() {
        if (!m_pGameConfig->m_bUseUICustom) {
			spdlog::error("UI Menu can only be used with Custom UI");
            return;
        }
        
        m_pUIConfig->m_bUseUIMenu = true;

		spdlog::info("UI Menu is enabled");

    }

    void UseUIRenderWindows() {

        if (!m_pGameConfig->m_bUseUICustom) {
			spdlog::error("UI Custom Draw List can only be used with Custom UI");
            return;
        }

        m_pUIConfig->m_bUseUIRenderWindows = true;

        spdlog::info("UI Custom Draw List of Windows is enabled");

    }

    void UseUIRenderOverlays() {

        if (!m_pGameConfig->m_bUseUICustom) {
			spdlog::error("UI Custom Draw List can only be used with Custom UI");
            return;
        }

        m_pUIConfig->m_bUseUIRenderOverlays = true;

        spdlog::info("UI Custom Draw List of Overlay is enabled");

    }

    void UseUIQuickActions() {

        if (!m_pGameConfig->m_bUseUICustom) {
            spdlog::error("UI Quick Actions can only be used with Custom UI");
            return;
        }

        m_pUIConfig->m_bUseUIQuickActions = true;

        spdlog::info("UI Quick Actions is enabled");

    }

    void UseESPSnapline() {

        if (!m_pGameConfig->m_bUseUICustom) {
			spdlog::error("Snapline ESP can only be used with Custom UI");
			return;
		}

		m_pGameConfig->m_bUseESPSnapline = true;

		spdlog::info("Snapline ESP is enabled");

	}
    
    void UseESPBox2D() {

        if (!m_pGameConfig->m_bUseUICustom) {
            spdlog::error("2D Box ESP can only be used with Custom UI");
            return;
        }

        m_pGameConfig->m_bUseESPBox2D = true;

        spdlog::info("2D Box ESP is enabled");
    }

    void UseESPBox3D() {

        if (!m_pGameConfig->m_bUseUICustom) {
			spdlog::error("3D Box ESP can only be used with Custom UI");
			return;
		}

		m_pGameConfig->m_bUseESPBox3D = true;

		spdlog::info("3D Box ESP is enabled");
	}

    void UseESPSkeleton() {

        if (!m_pGameConfig->m_bUseUICustom) {
            spdlog::error("Skeleton ESP can only be used with Custom UI");
            return;
        }

        m_pGameConfig->m_bUseESPSkeleton = true;

        spdlog::info("Skeleton ESP is enabled");
    }


    // add check if is internal to use it
    void IsUnityEngine(UnityEngineTypes type);
    void IsUnrealEngine(UnrealEngineVersions version);

    void Run();

private:
    std::shared_ptr<Game> m_pGame;
    std::shared_ptr<GameConfig> m_pGameConfig;
    std::shared_ptr<UIService> m_pUIService;
    std::shared_ptr<UIConfig> m_pUIConfig;
    std::shared_ptr<System> m_pSystem;
    std::shared_ptr<NotificationService> m_pNotificationService;

};