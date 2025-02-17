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

/**
 * @class CUIService
 * @brief A service for managing and rendering the user interface (UI) in the game.
 *
 * The CUIService class handles all aspects of the user interface, including initialization,
 * rendering, and interaction with the user. It integrates with DirectX 11 and ImGui to provide
 * a graphical interface for controlling various features of the game.
 */
class CUIService : public CComponent {
public:

    /**
     * @brief Initializes the CUIService.
     *
     * This function sets up essential pointers and resources required for the UI, including
     * setting flags to show the menu and associating system variables.
     */
    void Init() override {
        m_bShowMenu = &g_pXenonVariables->g_bShowMenu;
        m_pSystem = g_pXenon->g_pSystem;
        m_pOWndProc = &oWndProc;
    }

    Hotkey testhotkey; ///< A hotkey for testing purposes.
    bool isEditing = false; ///< Flag indicating if the UI is currently being edited.

    Present oPresent = NULL; ///< Original Present function for swapping buffers.
    WNDPROC oWndProc = NULL; ///< Original Window procedure function.

    /**
     * @brief Initializes the DirectX Present function.
     * @param pSwapChain The swap chain used for rendering.
     * @return True if initialization was successful, false otherwise.
     */
    bool InitPresent(IDXGISwapChain* pSwapChain);

    /**
     * @brief Initializes external resources for the UI.
     */
    void InitExternal();

    /**
     * @brief Updates the UI based on the current frame.
     */
    void UpdateUI();

    /**
     * @brief Destroys all UI-related resources.
     */
    void Destroy();

    /**
     * @brief Begins the rendering process for the UI.
     */
    void BeginRenderUI();

    /**
     * @brief Ends the rendering process for the UI.
     */
    void EndRenderUI();

    /**
     * @brief Opens the UI menu.
     */
    void SetMenuOpen();

    /**
     * @brief Closes the UI menu.
     */
    void SetMenuClose();

    /**
     * @brief Creates the ImGui-based UI.
     */
    void CreateImGuiUI();

    /**
     * @brief Renders the crosshair on the screen.
     */
    void RenderCrosshair();

    /**
     * @brief Renders the field of view (FOV) indicator on the screen.
     */
    void RenderFov();

    void RenderEnabledCheats();

    /**
     * @brief Updates the UI for each frame.
     */
    void Update() override;

private:

    HWND m_hWindow = NULL; ///< The window handle.
    WNDCLASSEXW m_wClass{}; ///< The window class information.
    IDXGISwapChain* m_pSwapChain = nullptr; ///< The DirectX swap chain used for rendering.
    D3D_FEATURE_LEVEL m_dLevel{}; ///< The Direct3D feature level.

    ID3D11Device* m_pDevice = nullptr; ///< The Direct3D device.
    ID3D11DeviceContext* m_pContext = nullptr; ///< The Direct3D device context.
    ID3D11RenderTargetView* m_pMainRenderTargetView = nullptr; ///< The render target view.

    ID3D11DepthStencilState* m_pNoDepthStencilState = nullptr; ///< The depth stencil state with no depth.
    ID3D11DepthStencilState* m_pDefaultDepthStencilState = nullptr; ///< The default depth stencil state.

    ImFont* m_pMainFont = nullptr; ///< Font used for rendering the UI.
    ImFont* m_pBiggerMainFont = nullptr; ///< Font used for rendering the UI.
    int m_nSelectedTab = 0; ///< The currently selected tab in the menu.
    int m_nSelectedSubTab = 0; ///< The currently selected sub-tab in the menu.

    bool m_bDevTab = false; ///< Flag for showing or hiding the developer console.

    /**
     * @brief Window procedure function for handling window messages.
     * @param hWnd The window handle.
     * @param uMsg The message identifier.
     * @param wParam Additional message information.
     * @param lParam Additional message information.
     * @return The result of processing the message.
     */
    static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    /**
     * @brief Initializes the depth stencil states for the UI.
     */
    void InitializeDepthStencilStates();

    /**
     * @brief Loads the default fonts for the UI.
     */
    void LoadDefaultFonts();

    /**
     * @brief Creates the UI window.
     * @return True if the window creation was successful, false otherwise.
     */
    bool CreateWindowUI();

    /**
     * @brief Creates the device for rendering the UI.
     * @return True if the device creation was successful, false otherwise.
     */
    bool CreateDeviceUI();

    /**
     * @brief Renders the default UI theme.
     * @param rainbowBorders If true, rainbow-colored borders are applied.
     */
    void RenderDefaultTheme(bool rainbowBorders);

    /**
     * @brief Renders quick actions in the default UI.
     */
    void RenderDefaultUIQuickActions();

    /**
     * @brief Renders the default menu of the UI.
     */
    void RenderDefaultMenu();

    /**
     * @brief Renders the mouse cursor.
     */
    void RenderMouse();

    /**
     * @brief Resets the UI device.
     */
    void ResetDeviceUI();

    /**
     * @brief Destroys the UI window.
     */
    void DestroyWindowUI();

    /**
     * @brief Destroys the UI device.
     */
    void DestroyDeviceUI();

    /**
     * @brief Destroys the ImGui UI resources.
     */
    void DestroyImGuiUI();

    inline static bool* m_bShowMenu = nullptr; ///< Flag indicating if the menu should be shown.
    inline static std::shared_ptr<System> m_pSystem = nullptr; ///< Pointer to the system object.
    inline static WNDPROC* m_pOWndProc = nullptr; ///< Pointer to the original window procedure.
};
