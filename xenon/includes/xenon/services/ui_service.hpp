#pragma once

#include <memory>
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>

#include <xenon/core/system.hpp>
#include <xenon/core/di_manager.hpp>
#include <xenon/configs/aim_config.hpp>
#include <xenon/models/hotkey.hpp>
#include <xenon/configs/ui_config.hpp>
#include <xenon/utility/imgui_helper.hpp>
#include <xenon/features/radar.hpp>
#include <xenon/services/notification_service.hpp>

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

class UIService {
public:

    UIService(
        std::shared_ptr<UIConfig> pConfigs, 
        std::shared_ptr<System> pSystem, 
        std::shared_ptr<AimConfig> pAimConfigs,
        std::shared_ptr<Radar> pRadar,
        std::shared_ptr<NotificationService> pNotificationService
    ) : m_pConfigs(pConfigs), m_pSystem(pSystem), m_pAimConfigs(pAimConfigs), m_pRadar(pRadar), m_pNotificationService(pNotificationService) {}

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

    HWND m_hWindow = NULL;

    WNDCLASSEXW m_wClass{};
    IDXGISwapChain* m_pSwapChain = nullptr;
    D3D_FEATURE_LEVEL m_dLevel;

    ID3D11Device* m_pDevice = NULL;
    ID3D11DeviceContext* m_pContext = NULL;
    ID3D11RenderTargetView* m_pMainRenderTargetView = nullptr;

    bool m_bMouse = 0;
    int m_nMouseType = 0;
    ImColor m_cMouse = ImColor(255, 255, 255, 255);

    int m_nCrosshairType = 0;
    float m_fCrosshairSize = 10;
    ImColor m_cCrosshair = ImColor(255, 255, 255, 255);

    #pragma region shitty vars

    ImDrawList* drawlist;
    ImVec2 pos;
    ImFont* mainfont;
    int tabs = 0;
    int subtabs = 0;
    //int notifs = 0;
    //int notiftype = 0;

    //int notifpressed = 0;
    //float anim = 0;
    //float resizeanim = 0;
    //float logomove = 0;
    //float finalresize = 0;
    //float closeanim = 0;
    //bool shouldmove = true;
    //bool shouldresize = true;
    //bool logoshouldmove = true;
    //bool finalresizeshouldmove = true;
    //bool closemove = true;

    bool devconsole = false;

    #pragma endregion

    ImVec2 CenterText(ImVec2 min, ImVec2 max, const char* text) {
        return min + (max - min) / 2.0f - ImGui::CalcTextSize(text) / 2.0f;
    }

    //HRESULT __stdcall BindForInternal(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
    static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void LoadDefaultFonts();

    bool CreateWindowUI();
    bool CreateDeviceUI();

    void RenderDefaultTheme(bool rainbowBorders);
    void RenderDefaultUI();
    void RenderDefaultUIQuickActions();
    void RenderDefaultMenu();
    void RenderDefaultRadar();
    void RenderBottomCenterNotification();
    void RenderTopLeftNotification();
    void RenderCrosshair();
    void RenderFov();
    void RenderMouse();

    void ResetDeviceUI();
    void DestroyWindowUI();
    void DestroyDeviceUI();
    void DestroyImGuiUI();

};