#include <xenon/components/services/ui_service.hpp>

#include <dwmapi.h>
#include <spdlog/spdlog.h>

#include <imgui/imgui_internal.h>
#include <xenon/utility/fonts.h>

#include <xenon/core/system.hpp>
#include <xenon/components/features/radar.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/services/notification_service.hpp>

bool UIService::InitPresent(IDXGISwapChain* pSwapChain) {
	if (!SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&m_pDevice)))
	{
		return false;
	}

	m_pDevice->GetImmediateContext(&m_pContext);
	DXGI_SWAP_CHAIN_DESC sd;
	pSwapChain->GetDesc(&sd);
	m_hWindow = sd.OutputWindow;
	ID3D11Texture2D* pBackBuffer = nullptr;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	m_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pMainRenderTargetView);
	pBackBuffer->Release();

	oWndProc = (WNDPROC)SetWindowLongPtrA(m_hWindow, GWLP_WNDPROC, (LONG_PTR)WndProc);

	return true;
}

void UIService::LoadDefaultFonts()
{
	//ImGui::GetIO().Fonts->AddFontDefault();
	//ImFontConfig font_cfg;
	//font_cfg.GlyphExtraSpacing.x = 1.2f;

	m_pMainFont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&mainFontBytes, sizeof(mainFontBytes), 14, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImFont* notiffont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&boldFontBytes, sizeof(boldFontBytes), 18, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImFont* logo = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&logoBytes, sizeof(logoBytes), 48, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	//ImFont* logo_bigger = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&logoBytes, sizeof(logoBytes), 80, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

	g_pXenon->g_cNotificationService->SetFonts(notiffont, logo);//, logo_bigger);

}

void UIService::RenderDefaultTheme(bool rainbowBorders) {
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.90f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.70f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.60f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 0.60f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.30f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 0.60f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);

	if (rainbowBorders) {
		//colors[ImGuiCol_Border] = ImVec4(Config::m_v4Rainbow.x, Config::m_v4Rainbow.y, Config::m_v4Rainbow.z, 0.5f);
	}
	else {
		colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	}

	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.4f);

	ImGuiStyle& style = ImGui::GetStyle();
	style.WindowPadding = ImVec2(15, 5);
	style.IndentSpacing = 25;
	style.GrabMinSize = 10;
	style.ChildBorderSize = 1;
	style.PopupBorderSize = 1;
	style.WindowRounding = 6;
	style.ChildRounding = 4;
	style.FrameRounding = 3;
	style.PopupRounding = 4;
	style.ScrollbarRounding = 9;
	style.ScrollbarSize = 10;
	style.GrabRounding = 3;
	style.WindowBorderSize = 3;
	style.WindowTitleAlign = ImVec2(0.5, 0.5);
}

void UIService::RenderDefaultMenu() {

	if (ImGui::Begin("Default Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground)) {

		//sizing
		float windowWidth = 490;
		ImGui::SetWindowSize(ImVec2(windowWidth, 440));

		//helpers def
		ImVec2 pos = ImGui::GetWindowPos() + ImVec2(5, 5);

		//main rect
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 430), ImColor(29, 40, 54, 255), 6.f, ImDrawFlags_RoundCornersAll);

		//title
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 25), ImColor(29, 40, 54, 255), 6.f, ImDrawFlags_RoundCornersTop);
		ImGui::GetWindowDrawList()->AddText(ImGuiHelper::CenterText(pos, ImVec2(pos.x + 480, pos.y + 25), g_pXenon->g_pSystem->GetAppTitle()->c_str()), ImColor(165, 186, 197, 255), g_pXenon->g_pSystem->GetAppTitle()->c_str());

		//tabs
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::SetCursorPos(ImVec2(5, 35));

		float width = devconsole ? windowWidth / 5 : windowWidth / 4;

		ImGui::BeginGroup();
		{
			if (ImGui::Tabs("Aim", ImVec2(width, 20), m_nSelectedTab == Tabs::AIM, 0)) m_nSelectedTab = Tabs::AIM;
			if (ImGui::Tabs("Visuals", ImVec2(width, 20), m_nSelectedTab == Tabs::VISUALS, 0)) m_nSelectedTab = Tabs::VISUALS;
			if (ImGui::Tabs("Radar", ImVec2(width, 20), m_nSelectedTab == Tabs::RADAR, 0)) m_nSelectedTab = Tabs::RADAR;
			if (ImGui::Tabs("Misc", ImVec2(width, 20), m_nSelectedTab == Tabs::MISC, 0)) m_nSelectedTab = Tabs::MISC;

			if (devconsole)
			{
				if (ImGui::Tabs("Dev", ImVec2(width, 20), m_nSelectedTab == Tabs::DEV, 0)) m_nSelectedTab = Tabs::DEV;
			}
		}
		ImGui::EndGroup();

		// handle subtabs
		switch (m_nSelectedTab)
		{
		case Tabs::AIM:
			ImGui::SetCursorPos(ImVec2(5, 55));
			ImGui::BeginGroup();
			{
				if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::SETTINGS, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
				if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::COLORS, 0)) m_nSelectedSubTab = SubTabs::COLORS;
			}
			ImGui::EndGroup();
			break;
		case Tabs::VISUALS:
			ImGui::SetCursorPos(ImVec2(5, 55));
			ImGui::BeginGroup();
			{
				if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::SETTINGS, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
				if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::COLORS, 0)) m_nSelectedSubTab = SubTabs::COLORS;
			}
			ImGui::EndGroup();
			break;
		case Tabs::RADAR:
			ImGui::SetCursorPos(ImVec2(5, 55));
			ImGui::BeginGroup();
			{
				if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::SETTINGS, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
				if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::COLORS, 0)) m_nSelectedSubTab = SubTabs::COLORS;
			}
			ImGui::EndGroup();
			break;
		case Tabs::MISC:
			ImGui::SetCursorPos(ImVec2(5, 55));
			ImGui::BeginGroup();
			{
				if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::SETTINGS, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
				if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::COLORS, 0)) m_nSelectedSubTab = SubTabs::COLORS;
			}
			ImGui::EndGroup();
			break;
		case Tabs::DEV:
			ImGui::SetCursorPos(ImVec2(5, 55));
			ImGui::BeginGroup();
			{
				if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::SETTINGS, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
				if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, 20), m_nSelectedSubTab == SubTabs::COLORS, 0)) m_nSelectedSubTab = SubTabs::COLORS;
			}
			ImGui::EndGroup();
			break;
		}

		ImGui::PopStyleVar(); // this pops the itemspacing push

		switch (m_nSelectedTab) {
		case Tabs::AIM:

			switch (m_nSelectedSubTab) {

			case SubTabs::SETTINGS: {
				ImGui::SetCursorPos(ImVec2(10, 80));
				ImGui::BeginChild("Settings", ImVec2(470, 345));
				{
					//render funcs
					ImGui::SetCursorPos(ImVec2(10, 10));
					ImGui::BeginGroup();
					{
						ImGui::Checkbox("Silent", &g_pXenonConfigs->g_pAimConfig->m_bSilent);
						ImGui::Checkbox("Visible", &g_pXenonConfigs->g_pAimConfig->m_bVisibleCheck);
						ImGui::Checkbox("Auto scope", &g_pXenonConfigs->g_pAimConfig->m_bAutoScope);
						ImGui::Checkbox("Auto shoot", &g_pXenonConfigs->g_pAimConfig->m_bAutoShoot);
						ImGui::Checkbox("Humanize", &g_pXenonConfigs->g_pAimConfig->m_bHumanize);
						ImGui::Checkbox("No recoil", &g_pXenonConfigs->g_pAimConfig->m_bNoRecoil);
						ImGui::Checkbox("No spread", &g_pXenonConfigs->g_pAimConfig->m_bNoSpread);

						ImGui::Checkbox("Smooth", &g_pXenonConfigs->g_pAimConfig->m_bSmooth);
						if (g_pXenonConfigs->g_pAimConfig->m_bSmooth) {
							ImGui::SliderFloat("Smooth value", &g_pXenonConfigs->g_pAimConfig->m_fSmooth, 5.f, 50.f, "%.0f");
						}

						ImGui::Checkbox("Fov", &g_pXenonConfigs->g_pAimConfig->m_bFov);
						if (g_pXenonConfigs->g_pAimConfig->m_bFov) {
							ImGui::SliderFloat("Fov value", &g_pXenonConfigs->g_pAimConfig->m_fFov, 30.f, 300.f, "%.0f");
						}

						ImGui::Checkbox("Nearest", &g_pXenonConfigs->g_pAimConfig->m_bNearest);
						if (g_pXenonConfigs->g_pAimConfig->m_bNearest
							&& ImGui::SliderFloat("Nearest distance", &g_pXenonConfigs->g_pAimConfig->m_fNearest, 100.f, 1000.f, "%.0f")) {
							g_pXenonConfigs->g_pAimConfig->m_fNearest = round(g_pXenonConfigs->g_pAimConfig->m_fNearest / 100.0f) * 100.0f;
						}
						ImGui::Checkbox("Developer Console", &devconsole);
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			} break;
			case SubTabs::COLORS: {

			} break;
			}

			break;
		case Tabs::VISUALS:

			switch (m_nSelectedSubTab) {

			case SubTabs::SETTINGS: {
				ImGui::SetCursorPos(ImVec2(10, 80));
				ImGui::BeginChild("Settings", ImVec2(470, 365));
				{
					//demo funcs
					static bool checkbox = false;
					static int sliderint = 0;
					static float sliderfloat = 0.f;
					static int combo = 0;
					static const char* multi_items[5] = { "One", "Two", "Three", "Four", "Five" };
					static bool multi_items_count[5];
					static int key = 0;

					//render funcs
					ImGui::SetCursorPos(ImVec2(10, 10));
					ImGui::BeginGroup();
					{
						ImGui::Checkbox("Checkbox", &checkbox);
						ImGui::SliderInt("Slider Int", &sliderint, 0, 100);
						ImGui::SliderFloat("Slider Float", &sliderfloat, 0.f, 100.f, "%.1f");
						ImGui::Combo("Combo", &combo, "Selectable 1\0Selectable 2\0Selectable 3", 3);
						ImGui::MultiCombo("Multicombo", multi_items_count, multi_items, 5);
						ImGui::Keybind("Hotkey", &key);

						//if(ImGui::Button("Test Hotkey", ImVec2(200, 25)))
						//	isEditing = true;
						//ImGuiHelper::RenderHotkeyEditor(&testhotkey, &isEditing);
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			} break;
			case SubTabs::COLORS: {
				ImGui::SetCursorPos(ImVec2(10, 80));
				ImGui::BeginChild("Crosshair", ImVec2(470, 345));
				{
					//render funcs
					ImGui::SetCursorPos(ImVec2(10, 10));
					ImGui::BeginGroup();
					{
						static ImVec4 color = g_pXenonConfigs->g_pUIConfig->m_cCrosshair;

						ImGui::Checkbox("Crosshair", &g_pXenonConfigs->g_pUIConfig->m_bCrosshair);
						if (g_pXenonConfigs->g_pUIConfig->m_bCrosshair)
						{
							if (ImGui::ColorEdit4("Color", (float*)&color)) {
								g_pXenonConfigs->g_pUIConfig->m_cCrosshair = ImColor(color);
							}
							ImGui::Combo("Type", &g_pXenonConfigs->g_pUIConfig->m_nCrosshairType, "Cross\0Circle");
						}

					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			} break;
			}

			break;
		case Tabs::RADAR:

			switch (m_nSelectedSubTab) {

			case SubTabs::SETTINGS: {

				ImGui::SetCursorPos(ImVec2(10, 80));
				ImGui::BeginChild("Settings", ImVec2(470, 365));
				{
					//demo funcs
					static bool checkbox[2];
					static int combo = 0;
					static char input0[64] = "";
					static char input1[64] = "";

					//render funcs
					ImGui::SetCursorPos(ImVec2(10, 10));
					ImGui::BeginGroup();
					{
						if (checkbox[0])
						{
							ImGui::InputText("Pointer or Offset", input0, 64, ImGuiInputTextFlags_ReadOnly);
							ImGui::InputText("Value", input1, 64, ImGuiInputTextFlags_ReadOnly);
						}
						else
						{
							ImGui::InputText("Pointer or Offset", input0, 64);
							ImGui::InputText("Value", input1, 64);
						}
						ImGui::Checkbox("Read-Only", &checkbox[0]);
						ImGui::Checkbox("Loop Command", &checkbox[1]);
						ImGui::Combo("Type", &combo, "Byte\0\r2 Byte\0\r4 Byte\0\rFloat\0Double\0String", 6);
					}
					ImGui::EndGroup();
				}
				ImGui::EndChild();
			} break;
			case SubTabs::COLORS: {

			} break;
			}

			break;
		case Tabs::MISC:
			break;
		case Tabs::DEV:
			break;
		}

	}
	ImGui::End();
}

LRESULT __stdcall UIService::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	std::shared_ptr<UIService> pThis = DIManager::GetInstance().GetService<UIService>();

	//if (pThis->m_bShowMenu && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
	//	return true;

	//if (pThis->m_bShowMenu)
	//	return true;

	if (!DIManager::GetInstance().GetService<System>()->IsInternal() && uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return true;
	}

	if (DIManager::GetInstance().GetService<System>()->IsInternal()) {
		return CallWindowProcA(pThis->oWndProc, hWnd, uMsg, wParam, lParam);
	}
	else {
		return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
}

void UIService::InitExternal() {
	if (CreateWindowUI()) {
		if (CreateDeviceUI()) {
			CreateImGuiUI();
		}
	}
}

void UIService::RenderCrosshair() {
	switch (g_pXenonConfigs->g_pUIConfig->m_nCrosshairType)
	{
	case 0:
		ImGui::GetForegroundDrawList()->AddLine(ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x - g_pXenonConfigs->g_pUIConfig->m_fCrosshair, g_pXenon->g_pSystem->GetScreenCenter().y), ImVec2((g_pXenon->g_pSystem->GetScreenCenter().x - g_pXenonConfigs->g_pUIConfig->m_fCrosshair) + (g_pXenonConfigs->g_pUIConfig->m_fCrosshair * 2), g_pXenon->g_pSystem->GetScreenCenter().y), g_pXenonConfigs->g_pUIConfig->m_cCrosshair, 1.2f);
		ImGui::GetForegroundDrawList()->AddLine(ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, g_pXenon->g_pSystem->GetScreenCenter().y - g_pXenonConfigs->g_pUIConfig->m_fCrosshair), ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, (g_pXenon->g_pSystem->GetScreenCenter().y - g_pXenonConfigs->g_pUIConfig->m_fCrosshair) + (g_pXenonConfigs->g_pUIConfig->m_fCrosshair * 2)), g_pXenonConfigs->g_pUIConfig->m_cCrosshair, 1.2f);
		break;
	case 1:
		ImGui::GetForegroundDrawList()->AddCircle(ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, g_pXenon->g_pSystem->GetScreenCenter().y), g_pXenonConfigs->g_pUIConfig->m_fCrosshair, g_pXenonConfigs->g_pUIConfig->m_cCrosshair, 100, 1.2f);
		break;
	}
}

void UIService::RenderFov() {
	ImGui::GetForegroundDrawList()->AddCircle(ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, g_pXenon->g_pSystem->GetScreenCenter().y), g_pXenonConfigs->g_pAimConfig->m_fFov, g_pXenonConfigs->g_pAimConfig->m_cFov, 360);
}

void UIService::RenderMouse() {
	switch (g_pXenonConfigs->g_pUIConfig->m_nMouseType) {
	case 0:
		ImGui::GetForegroundDrawList()->AddCircleFilled(ImGui::GetMousePos(), 4, g_pXenonConfigs->g_pUIConfig->m_cMouse);
		break;
	case 1:
		ImGuiHelper::DrawOutlinedTextForeground(ImGuiHelper::g_pGameFont, ImVec2(g_pXenon->g_pSystem->GetMousePos().x, g_pXenon->g_pSystem->GetMousePos().y), 13.0f, g_pXenonConfigs->g_pUIConfig->m_cMouse, false, "X");
		break;
	case 2:
		if (!ImGui::GetIO().MouseDrawCursor) {
			ImGui::GetIO().MouseDrawCursor = true;
		}
		break;
	}
}

void UIService::RenderDefaultUIQuickActions() {


	if (ImGui::Begin("QuickActions", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground)) {

		float width = 490;
		float height = 440;
		float padding = 5;

		ImGui::SetWindowSize(ImVec2(width, height));

		ImVec2 pos = ImGui::GetWindowPos() + ImVec2(padding, padding);

		//main rect
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 430), ImColor(29, 40, 54, 255), 6.f, ImDrawFlags_RoundCornersAll);

		//title
		const char* title = "Quick Actions";
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 25), ImColor(29, 40, 54, 255), 6.f, ImDrawFlags_RoundCornersTop);
		ImGui::GetWindowDrawList()->AddText(ImGuiHelper::CenterText(pos, ImVec2(pos.x + 480, pos.y + 25), title), ImColor(165, 186, 197, 255), title);

		ImGui::SetCursorPos(ImVec2(15, 40));
		ImGui::BeginGroup();
		{
			int buttonWidth = 100;
			int buttonHeight = 30;

			for (const auto& action : g_pXenonConfigs->g_pUIConfig->m_qActions->GetComponents()) {
				action->Render();
			}
		}
		ImGui::EndGroup();

		ImGui::End();

	}

}

void UIService::Update() {

	if (g_pXenonVariables->g_bShowMenu) {

		if (g_pXenonConfigs->g_pUIConfig->m_bUseUIRenderMouse) {
			RenderMouse();
		}

		//if (g_pXenonConfigs->g_pUIConfig->m_fnCustomTheme) {
		//	g_pXenonConfigs->g_pUIConfig->m_fnCustomTheme();
		//}
		//else {
		//	RenderDefaultTheme(false);
		//}

		if (g_pXenonConfigs->g_pUIConfig->m_bUseUIMenu) {
			if (g_pXenonConfigs->g_pUIConfig->m_fnCustomMenu) {
				g_pXenonConfigs->g_pUIConfig->m_fnCustomMenu();
			}
			else {
				RenderDefaultMenu();
			}
		}

		if (g_pXenonConfigs->g_pUIConfig->m_bUseUIRenderWindows) {
			for (auto& fn : g_pXenonConfigs->g_pUIConfig->m_vFnWindows) {
				fn();
			}
		}

		if (g_pXenonConfigs->g_pUIConfig->m_bUseUIQuickActions && g_pXenonConfigs->g_pUIConfig->m_qActions->GetSize() > 0) {
			RenderDefaultUIQuickActions();
		}

	}

	if (g_pXenonConfigs->g_pUIConfig->m_bUseUIRenderOverlays) {
		for (auto& fn : g_pXenonConfigs->g_pUIConfig->m_vFnOverlays) {
			fn();
		}
	}

	//if (g_pXenonConfigs->g_pUIConfig->m_fnCustomNotification) {
	//	g_pXenonConfigs->g_pUIConfig->m_fnCustomNotification();
	//}
	//else {
	//	RenderTopLeftNotification();
	//}

	if (g_pXenonConfigs->g_pUIConfig->m_bWatermark)
	{
		ImColor color = ImColor(255, 255, 255, 255); // or rainbow

		ImGuiHelper::DrawOutlinedText(m_pMainFont, ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, g_pXenon->g_pSystem->GetScreenResolution().y - 20), 13.0f, color, true, g_pXenon->g_pSystem->GetAppTitle()->c_str());
		ImGuiHelper::DrawOutlinedText(m_pMainFont, ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, 5), 13.0f, color, true, "[ %.1f FPS ]", ImGui::GetIO().Framerate);
	}

	g_pXenon->g_cNotificationService->RenderNotifications();

}

void UIService::Destroy() {
	DestroyImGuiUI();
	DestroyDeviceUI();
	DestroyWindowUI();
}

bool UIService::CreateWindowUI()
{

	m_wClass.cbSize = sizeof(WNDCLASSEX);
	m_wClass.style = CS_CLASSDC;
	m_wClass.lpfnWndProc = WndProc;
	m_wClass.cbClsExtra = 0;
	m_wClass.cbWndExtra = 0;
	m_wClass.hInstance = GetModuleHandle(nullptr);
	m_wClass.hIcon = 0;
	m_wClass.hCursor = 0;
	m_wClass.hbrBackground = 0;
	m_wClass.lpszMenuName = 0;
	m_wClass.lpszClassName = L"overlay";
	m_wClass.hIconSm = 0;

	if (!m_wClass.hInstance) {
		spdlog::error("GetModuleHandle failed with error: {}", GetLastError());
		return false;
	}

	if (!RegisterClassExW(&m_wClass)) {
		spdlog::error("RegisterClassExW failed with error: {}", GetLastError());
		return false;
	}

	//std::wstring wideWindowTitle = std::wstring(g_pXenon->g_pSystem->GetAppTitle()->begin(), g_pXenon->g_pSystem->GetAppTitle()->end());

	m_hWindow = CreateWindowExW(
		WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED,
		m_wClass.lpszClassName,
		L"xenon",//wideWindowTitle.c_str(),
		WS_POPUP,
		0, 0, static_cast<int>(g_pXenon->g_pSystem->GetScreenResolution().x), static_cast<int>(g_pXenon->g_pSystem->GetScreenResolution().y),
		nullptr, nullptr, m_wClass.hInstance, nullptr
	);

	if (!m_hWindow) {
		spdlog::error("CreateWindowExW failed with error: {}", GetLastError());
		return false;
	}

	SetLayeredWindowAttributes(m_hWindow, RGB(0, 0, 0), BYTE(255), LWA_ALPHA);
	{
		RECT client_area{};
		GetClientRect(m_hWindow, &client_area);

		RECT window_area{};
		GetWindowRect(m_hWindow, &window_area);

		POINT diff{};
		ClientToScreen(m_hWindow, &diff);

		const MARGINS margins{
			window_area.left + (diff.x - window_area.left),
			window_area.top + (diff.y - window_area.top),
			client_area.right,
			client_area.bottom
		};

		DwmExtendFrameIntoClientArea(m_hWindow, &margins);
	}

	ShowWindow(m_hWindow, SW_SHOWDEFAULT);
	UpdateWindow(m_hWindow);

	SetCursor(LoadCursor(nullptr, IDC_ARROW));

	return true;

}

void UIService::DestroyWindowUI()
{
	DestroyWindow(m_hWindow);
	UnregisterClassW(m_wClass.lpszClassName, m_wClass.hInstance);
}

bool UIService::CreateDeviceUI() {
	DXGI_SWAP_CHAIN_DESC sd{};
	sd.BufferDesc.RefreshRate.Numerator = 60U;
	sd.BufferDesc.RefreshRate.Denominator = 1U;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.SampleDesc.Count = 1U;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.BufferCount = 2U;
	sd.OutputWindow = m_hWindow;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	constexpr D3D_FEATURE_LEVEL levels[2]{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_0
	};

	HRESULT hr = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0U,
		levels,
		2U,
		D3D11_SDK_VERSION,
		&sd,
		&m_pSwapChain,
		&m_pDevice,
		&m_dLevel,
		&m_pContext
	);

	if (FAILED(hr)) {
		spdlog::error("D3D11CreateDeviceAndSwapChain failed with HRESULT: {}", hr);
		return false;
	}

	ID3D11Texture2D* back_buffer{ nullptr };
	m_pSwapChain->GetBuffer(0U, IID_PPV_ARGS(&back_buffer));

	if (back_buffer) {
		m_pDevice->CreateRenderTargetView(back_buffer, nullptr, &m_pMainRenderTargetView);
		back_buffer->Release();
		return true;
	}
	return false;

}

void UIService::SetMenuOpen() {

	SetWindowLongW(m_hWindow, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT);

}

void UIService::SetMenuClose() {

	SetWindowLongW(m_hWindow, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED);

}

void UIService::ResetDeviceUI()
{

	switch (g_pXenon->g_pSystem->GetRenderingType()) {
	case RenderingTypes::DX11:
		ImGui_ImplDX11_InvalidateDeviceObjects();
		break;
	case RenderingTypes::OPENGL2:
		ImGui_ImplOpenGL2_DestroyDeviceObjects();
		break;
	case RenderingTypes::OPENGL3:
		ImGui_ImplOpenGL3_DestroyDeviceObjects();
		break;
	}

	DestroyDeviceUI();

	switch (g_pXenon->g_pSystem->GetRenderingType()) {
	case RenderingTypes::DX11:
		ImGui_ImplDX11_CreateDeviceObjects();
		break;
	case RenderingTypes::OPENGL2:
		ImGui_ImplOpenGL2_CreateDeviceObjects();
		break;
	case RenderingTypes::OPENGL3:
		ImGui_ImplOpenGL3_CreateDeviceObjects();
		break;
	}

}

void UIService::DestroyDeviceUI()
{
	if (m_pDevice)
	{
		m_pDevice->Release();
		m_pDevice = nullptr;
	}

	if (m_pSwapChain)
	{
		m_pSwapChain->Release();
		m_pSwapChain = nullptr;
	}
}

void UIService::CreateImGuiUI()
{
	InitializeDepthStencilStates();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(m_hWindow);

	if (g_pXenon->g_pSystem->IsInternal()) {

		switch (g_pXenon->g_pSystem->GetRenderingType()) {
		case RenderingTypes::DX11:
			ImGui_ImplDX11_Init(m_pDevice, m_pContext);
			break;
		case RenderingTypes::OPENGL2:
			ImGui_ImplOpenGL2_Init();
			break;
		case RenderingTypes::OPENGL3:
			ImGui_ImplOpenGL3_Init();
			break;
		}
	}
	else {
		ImGui_ImplDX11_Init(m_pDevice, m_pContext);
	}


	LoadDefaultFonts();
}

void UIService::DestroyImGuiUI()
{

	switch (g_pXenon->g_pSystem->GetRenderingType()) {
	case RenderingTypes::DX11:
		ImGui_ImplDX11_Shutdown();
		break;
	case RenderingTypes::OPENGL2:
		ImGui_ImplOpenGL2_Shutdown();
		break;
	case RenderingTypes::OPENGL3:
		ImGui_ImplOpenGL3_Shutdown();
		break;
	}

	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	if (m_pSwapChain) {
		m_pSwapChain->Release();
	}

	if (m_pContext) {
		m_pContext->Release();
	}

	if (m_pDevice) {
		m_pDevice->Release();
	}

	if (m_pMainRenderTargetView) {
		m_pMainRenderTargetView->Release();
	}

}

void UIService::BeginRenderUI()
{

	if (g_pXenon->g_pSystem->IsInternal()) {
		switch (g_pXenon->g_pSystem->GetRenderingType()) {
		case RenderingTypes::DX11:
			ImGui_ImplDX11_NewFrame();
			break;
		case RenderingTypes::OPENGL2:
			ImGui_ImplOpenGL2_NewFrame();
			break;
		case RenderingTypes::OPENGL3:
			ImGui_ImplOpenGL3_NewFrame();
			break;
		}
	}
	else {
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE)) {

			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				//isRunning = !isRunning;
				return;
			}
		}

		ImGui_ImplDX11_NewFrame();

	}

	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	m_pContext->OMSetDepthStencilState(m_pNoDepthStencilState, 0);

}

void UIService::InitializeDepthStencilStates() {
	D3D11_DEPTH_STENCIL_DESC noDepthStencilDesc = {};
	noDepthStencilDesc.DepthEnable = FALSE;
	noDepthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
	noDepthStencilDesc.DepthFunc = D3D11_COMPARISON_ALWAYS;
	noDepthStencilDesc.StencilEnable = FALSE;

	HRESULT hr = m_pDevice->CreateDepthStencilState(&noDepthStencilDesc, &m_pNoDepthStencilState);
	if (FAILED(hr)) {
		return;
	}

	D3D11_DEPTH_STENCIL_DESC defaultDepthStencilDesc = {};
	defaultDepthStencilDesc.DepthEnable = TRUE;
	defaultDepthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	defaultDepthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
	defaultDepthStencilDesc.StencilEnable = FALSE;

	hr = m_pDevice->CreateDepthStencilState(&defaultDepthStencilDesc, &m_pDefaultDepthStencilState);
	if (FAILED(hr)) {
		return;
	}
}

void UIService::EndRenderUI()
{
	m_pContext->OMSetDepthStencilState(m_pDefaultDepthStencilState, 0);

	ImGui::EndFrame();

	ImGui::Render();

	m_pContext->OMSetRenderTargets(1U, &m_pMainRenderTargetView, nullptr);
	if (!g_pXenon->g_pSystem->IsInternal()) {
		constexpr float color[4] = { 0.f, 0.f, 0.f, 0.f };
		m_pContext->ClearRenderTargetView(m_pMainRenderTargetView, color);
	}

	if (g_pXenon->g_pSystem->IsInternal()) {

		switch (g_pXenon->g_pSystem->GetRenderingType()) {
		case RenderingTypes::DX11:
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
			break;
		case RenderingTypes::OPENGL2:
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
			break;
		case RenderingTypes::OPENGL3:
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			break;
		}

	}
	else {
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	if (!g_pXenon->g_pSystem->IsInternal()) m_pSwapChain->Present(1U, 0U);
}
