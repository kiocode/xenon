#include <windows.h>
#include <dwmapi.h>
#include <d3d11.h>

#define IMGUI_DEFINE_MATH_OPERATORS

#include <imgui/imgui_impl_dx11.h>
#include <imgui/imgui_impl_win32.h>

class ui {
public:

	HWND window = nullptr;
	WNDCLASSEXW wc{};

	bool isRunning = true;
	bool isMenuOpen = false;

	POINTS position = { };

	ID3D11Device* device = nullptr;
	ID3D11DeviceContext* device_context = nullptr;
	IDXGISwapChain* swap_chain = nullptr;
	ID3D11RenderTargetView* render_target_view = nullptr;
	D3D_FEATURE_LEVEL level;

	void CreateHUIWindow() noexcept;
	void DestroyHUIWindow() noexcept;

	bool CreateUIDevice() noexcept;
	void ResetUIDevice() noexcept;
	void DestroyUIDevice() noexcept;

	void CreateUIImGui() noexcept;
	void DestroyUIImGui() noexcept;

	void BeginRenderUI() noexcept;
	void EndRenderUI() noexcept;
	void RenderUI() noexcept;

    void SetMenuOpen() noexcept;
    void SetMenuClose() noexcept;
private:

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

    bool showMenu = false;

    ImVec2 CenterText(ImVec2 min, ImVec2 max, const char* text) {
        return min + (max - min) / 2.0f - ImGui::CalcTextSize(text) / 2.0f;
    }

};