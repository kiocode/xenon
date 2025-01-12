#pragma once

#include <functional>
#include <xenon/models/quickactions/quickactions.hpp>

class UIConfig {
public:
	bool m_bUseUINotification;
	bool m_bUseUIMenu;
	bool m_bUseUIRenderMouse;
	bool m_bUseUIRenderWindows;
	bool m_bUseUIRenderOverlays;
	bool m_bUseUIQuickActions;
	bool m_bUseUIRadar;

	bool m_bWatermark;

	int m_nMouseType = 0;
	ImColor m_cMouse = ImColor(255, 255, 255, 255);

	bool m_bCrosshair;
	int m_nCrosshairType = 0;
	float m_fCrosshair = 10;
	ImColor m_cCrosshair = ImColor(255, 255, 255, 255);

	std::function<void()> m_fnCustomTheme;
	std::function<void()> m_fnCustomNotification;
	std::function<void()> m_fnCustomMenu;
	std::vector<std::function<void()>> m_vFnWindows{};
	std::vector<std::function<void()>> m_vFnOverlays{};
	QuickActions* m_qActions = new QuickActions();
};