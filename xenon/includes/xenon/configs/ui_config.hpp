#pragma once

#include <functional>
#include <vector>
#include <xenon/models/quickactions/quickactions.hpp>

/**
 * @class UIConfig
 * @brief Configuration settings for the user interface.
 *
 * This class provides customizable options for UI elements such as
 * mouse appearance, crosshair settings, themes, notifications, and menus.
 */
class UIConfig {
public:
    /**
     * @brief Type identifier for the custom mouse cursor.
     */
    int m_nMouseType = 0;

    /**
     * @brief Color of the mouse cursor.
     */
    ImColor m_cMouse = ImColor(255, 255, 255, 255);

    /**
     * @brief Type identifier for the crosshair style.
     */
    int m_nCrosshairType = 0;

    /**
     * @brief Size of the crosshair.
     */
    float m_fCrosshair = 10;

    /**
     * @brief Color of the crosshair.
     */
    ImColor m_cCrosshair = ImColor(255, 255, 255, 255);

    /**
     * @brief Custom function for defining a UI theme.
     */
    std::function<void()> m_fnCustomTheme;

    /**
     * @brief Custom function for handling notifications.
     */
    std::function<void()> m_fnCustomNotification;

    /**
     * @brief Custom function for rendering the menu.
     */
    std::function<void()> m_fnCustomMenu;

    /**
     * @brief A collection of functions for rendering UI windows.
     */
    std::vector<std::function<void()>> m_vFnWindows{};

    /**
     * @brief A collection of functions for rendering UI overlays.
     */
    std::vector<std::function<void()>> m_vFnOverlays{};

    /**
     * @brief Quick actions handler for UI interactions.
     */
    QuickActions* m_qActions = new QuickActions();
};
