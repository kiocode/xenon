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

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) {
    return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline ImVec2 operator/(const ImVec2& lhs, float rhs) {
    return ImVec2(lhs.x / rhs, lhs.y / rhs);
}

inline ImVec2 operator*(const ImVec2& lhs, float rhs) {
	return ImVec2(lhs.x * rhs, lhs.y * rhs);
}

inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) {
	return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y);
}


class UIService {
public:

    UIService(std::shared_ptr<System> pSystem, std::shared_ptr<AimConfig> pAimConfigs) : m_pSystem(pSystem), m_pAimConfigs(pAimConfigs) {}

	Present oPresent = NULL;
    bool m_bShowMenu = false;

    //static HRESULT __stdcall hkPresentWrapper(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
    //    return DIManager::GetInstance().GetService<UIService>()->hkPresent(pSwapChain, SyncInterval, Flags);
    //}

    //static LRESULT __stdcall WndProcWrapper(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    //    return GetInstance().WndProc(hWnd, uMsg, wParam, lParam);
    //}

    bool InitPresent(IDXGISwapChain* pSwapChain);

    void Init();
    void Update();
    void Destroy();

    void SetMenuOpen();
    void SetMenuClose();

    void CreateImGuiUI();

private:
    std::shared_ptr<System> m_pSystem;
    std::shared_ptr<AimConfig> m_pAimConfigs;

    HWND m_hWindow = NULL;

    WNDCLASSEXW m_wClass{};
    IDXGISwapChain* m_pSwapChain = nullptr;
    D3D_FEATURE_LEVEL m_dLevel;

    WNDPROC m_oWndProc = NULL;
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
    ImFont* notiffont;
    ImFont* logo;
    ImFont* logo_bigger;
    int tabs = 0;
    int subtabs = 0;
    int notifs = 0;
    int notiftype = 0;
    static inline int notify_select = 0;
    const char* notify_items[2]{ "Circle", "Line" };

    char notiftitle[64] = "Hello Mercy";
    char notifdesc[64] = "This is a super cool description";
    char notifsecondtitle[64] = "I completely ran out of ideas apologies";
    int notifpressed = 0;
    float anim = 0;
    float resizeanim = 0;
    float logomove = 0;
    float finalresize = 0;
    float closeanim = 0;
    bool shouldmove = true;
    bool shouldresize = true;
    bool logoshouldmove = true;
    bool finalresizeshouldmove = true;
    bool closemove = true;

    bool devconsole = false;

    #pragma endregion

    ImVec2 CenterText(ImVec2 min, ImVec2 max, const char* text) {
        return min + (max - min) / 2.0f - ImGui::CalcTextSize(text) / 2.0f;
    }

    //HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
    static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void LoadFonts();

    void RenderDefaultUI();
    void RenderDefaultNotifications();
    void RenderDefaultMenu();
    void RenderDefaultRadar();

    bool CreateWindowUI();
    void DestroyWindowUI();
    bool CreateDeviceUI();
    void ResetDeviceUI();
    void DestroyDeviceUI();
    void DestroyImGuiUI();
    void BeginRenderUI();
    void EndRenderUI();

    void RenderCrosshair();
    void RenderFov();
    void RenderMouse();

};