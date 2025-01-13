#pragma once

#include <memory>
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_opengl2.h>
#include <imgui/imgui_impl_opengl3.h>

#include <xenon/core/system.hpp>
#include <xenon/core/di_manager.hpp>
#include <xenon/models/hotkey.hpp>
#include <xenon/utility/imgui_helper.hpp>
#include <xenon/features/radar.hpp>
#include <xenon/features/waypoints.hpp>
#include <xenon/services/notification_service.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/configs/ui_config.hpp>
#include <xenon/configs/waypoints_config.hpp>

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

enum Tabs {
    AIM = 0,
    VISUALS,
    RADAR,
    MISC,
    DEV,
    NUM_TABS
};

enum SubTabs {
	SETTINGS = 0,
    COLORS,
};

class UIService {
public:

    UIService(
        std::shared_ptr<UIConfig> pConfigs,
        std::shared_ptr<System> pSystem,
        std::shared_ptr<AimConfig> pAimConfigs,
        std::shared_ptr<WaypointsConfig> pWaypointsConfig,
        std::shared_ptr<Radar> pRadar,
        std::shared_ptr<NotificationService> pNotificationService,
        std::shared_ptr<Waypoints> pWaypoints
    ) : m_pConfigs(pConfigs), 
        m_pSystem(pSystem), 
        m_pAimConfigs(pAimConfigs), 
        m_pWaypointsConfig(pWaypointsConfig),
        m_pWaypoints(pWaypoints),
        m_pRadar(pRadar), 
        m_pNotificationService(pNotificationService) {}

    Hotkey testhotkey;
    bool isEditing = false;

	Present oPresent = NULL;
    inline static WNDPROC oWndProc = NULL;
    bool m_bShowMenu = false;

    bool InitPresent(IDXGISwapChain* pSwapChain);

    void InitExternal();
    void Update();
    void Destroy();

    void BeginRenderUI();
    void EndRenderUI();

    void SetMenuOpen();
    void SetMenuClose();

    void CreateImGuiUI();

private:
    std::shared_ptr<UIConfig> m_pConfigs;
    std::shared_ptr<System> m_pSystem;
    std::shared_ptr<AimConfig> m_pAimConfigs;
    std::shared_ptr<Radar> m_pRadar;
    std::shared_ptr<NotificationService> m_pNotificationService;
    std::shared_ptr<WaypointsConfig> m_pWaypointsConfig;
    std::shared_ptr<Waypoints> m_pWaypoints;

    HWND m_hWindow = NULL;

    WNDCLASSEXW m_wClass{};
    IDXGISwapChain* m_pSwapChain = nullptr;
    D3D_FEATURE_LEVEL m_dLevel;

    ID3D11Device* m_pDevice = NULL;
    ID3D11DeviceContext* m_pContext = NULL;
    ID3D11RenderTargetView* m_pMainRenderTargetView = nullptr;

    #pragma region menu vars

    ImFont* mainfont;
    int m_nSelectedTab = 0;
    int m_nSelectedSubTab = 0;

    bool devconsole = false;

    #pragma endregion

    static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void LoadDefaultFonts();

    bool CreateWindowUI();
    bool CreateDeviceUI();

    void RenderDefaultTheme(bool rainbowBorders);

    void RenderDefaultUIQuickActions();
    void RenderDefaultMenu();
    void RenderCrosshair();
    void RenderFov();
    void RenderMouse();

    void ResetDeviceUI();
    void DestroyWindowUI();
    void DestroyDeviceUI();
    void DestroyImGuiUI();

};