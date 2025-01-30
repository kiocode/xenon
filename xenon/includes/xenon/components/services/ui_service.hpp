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

#include <xenon/components/component.hpp>
#include <xenon/core/system.hpp>

#include <xenon/models/hotkey.hpp>
#include <xenon/utility/imgui_helper.hpp>

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

class UIService : public CComponent {
public:

    void Init() override {
        m_bShowMenu = &g_pXenonVariables->g_bShowMenu;
        m_pSystem = g_pXenon->g_pSystem;
        m_pOWndProc = &oWndProc;
    }

    Hotkey testhotkey;
    bool isEditing = false;

	Present oPresent = NULL;
    WNDPROC oWndProc = NULL;

    bool InitPresent(IDXGISwapChain* pSwapChain);

    void InitExternal();
    void UpdateUI();
    void Destroy();

    void BeginRenderUI();
    void EndRenderUI();

    void SetMenuOpen();
    void SetMenuClose();

    void CreateImGuiUI();

    void RenderCrosshair();
    void RenderFov();
    
    void Update() override;

private:

    HWND m_hWindow = NULL;

    WNDCLASSEXW m_wClass{};
    IDXGISwapChain* m_pSwapChain = nullptr;
    D3D_FEATURE_LEVEL m_dLevel{};

    ID3D11Device* m_pDevice = nullptr;
    ID3D11DeviceContext* m_pContext = nullptr;
    ID3D11RenderTargetView* m_pMainRenderTargetView = nullptr;

    ID3D11DepthStencilState* m_pNoDepthStencilState = nullptr;
    ID3D11DepthStencilState* m_pDefaultDepthStencilState = nullptr;

    #pragma region menu vars

    ImFont* m_pMainFont = nullptr;
    int m_nSelectedTab = 0;
    int m_nSelectedSubTab = 0;

    bool devconsole = false;

    #pragma endregion

    static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void InitializeDepthStencilStates();

    void LoadDefaultFonts();

    bool CreateWindowUI();
    bool CreateDeviceUI();

    void RenderDefaultTheme(bool rainbowBorders);

    void RenderDefaultUIQuickActions();
    void RenderDefaultMenu();
    void RenderMouse();

    void ResetDeviceUI();
    void DestroyWindowUI();
    void DestroyDeviceUI();
    void DestroyImGuiUI();


    inline static bool* m_bShowMenu = nullptr;
    inline static std::shared_ptr<System> m_pSystem = nullptr;
    inline static WNDPROC* m_pOWndProc = nullptr;
};