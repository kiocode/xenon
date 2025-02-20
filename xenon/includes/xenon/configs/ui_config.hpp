#pragma once

#include <functional>
#include <vector>
#include <xenon/models/quickactions/quickactions.hpp>

class UIConfig {
public:

    int m_nMouseType = 0;

    ImColor m_cMouse = ImColor(255, 255, 255, 255);

    int m_nCrosshairType = 0;

    float m_fCrosshair = 10;

    ImColor m_cCrosshair = ImColor(255, 255, 255, 255);

    ImColor m_cMenuBg = ImColor(19, 54, 52, 255);
    ImColor m_cMenuBgFor = ImColor(20, 77, 73, 255);
    ImColor m_cMenuBgFor2 = ImColor(23, 97, 92, 255);
    ImColor m_cMenuOff = ImColor(16, 115, 81, 255);
    ImColor m_cMenuAccent = ImColor(24, 173, 122, 255);

    std::function<void()> m_fnCustomTheme;

    std::function<void()> m_fnCustomNotification;

    std::function<void()> m_fnCustomMenu;

    std::vector<std::function<void()>> m_vFnWindows{};

    std::vector<std::function<void()>> m_vFnOverlays{};

    QuickActions* m_qActions = new QuickActions();
};
