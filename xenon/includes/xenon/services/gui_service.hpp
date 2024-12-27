#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>

#define IMGUI_DEFINE_MATH_OPERATORS

#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

class UIService {
public:
    static UIService& GetInstance() {
        static UIService instance;
        return instance;
    }

	Present oPresent = NULL;
	bool init = false;

    static HRESULT __stdcall hkPresentWrapper(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
        return GetInstance().hkPresent(pSwapChain, SyncInterval, Flags);
    }

    static LRESULT __stdcall WndProcWrapper(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        return GetInstance().WndProc(hWnd, uMsg, wParam, lParam);
    }

    void Init();
    void Update();
    void Destroy();

    bool showMenu = false;

    void SetMenuOpen();
    void SetMenuClose();
private:

    HWND window = NULL;

    WNDCLASSEXW wc{};
    IDXGISwapChain* pSwapChain = nullptr;
    D3D_FEATURE_LEVEL level;

    WNDPROC oWndProc = NULL;
    ID3D11Device* pDevice = NULL;
    ID3D11DeviceContext* pContext = NULL;
    ID3D11RenderTargetView* mainRenderTargetView = nullptr;
    bool HkPresentInitialized = false;

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

    ImVec2 CenterText(ImVec2 min, ImVec2 max, const char* text) {
        return min + (max - min) / 2.0f - ImGui::CalcTextSize(text) / 2.0f;
    }

    HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
    LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void LoadFonts();

    void RenderUI();

    bool CreateWindowUI();
    void DestroyWindowUI();
    bool CreateDeviceUI();
    void ResetDeviceUI();
    void DestroyDeviceUI();
    void CreateImGuiUI();
    void DestroyImGuiUI();
    void BeginRenderUI();
    void EndRenderUI();


    UIService() = default;
    ~UIService() = default;

    UIService(const UIService&) = delete;
    UIService& operator=(const UIService&) = delete;
};