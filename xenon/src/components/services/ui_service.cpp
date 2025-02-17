#include <xenon/components/services/ui_service.hpp>

#include <dwmapi.h>
#include <spdlog/spdlog.h>

#include <imgui/imgui_internal.h>
#include <xenon/utility/fonts.h>

#include <xenon/core/system.hpp>
#include <xenon/components/features/radar.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/services/notification_service.hpp>

void CUIService::Update() {

	if (g_pXenonVariables->g_bCrosshair) {
		RenderCrosshair();
	}

	if (g_pXenonVariables->g_bFov) {
		RenderFov();
	}

	if (g_pXenonVariables->g_bRenderEnabledCheats) {
		RenderEnabledCheats();
	}

	if (g_pXenonVariables->g_bRenderUI) {
		UpdateUI();
	}
}

bool CUIService::InitPresent(IDXGISwapChain* pSwapChain) {
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

void CUIService::LoadDefaultFonts()
{
	//ImGui::GetIO().Fonts->AddFontDefault();
	//ImFontConfig font_cfg;
	//font_cfg.GlyphExtraSpacing.x = 1.2f;

	m_pMainFont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&mainFontBytes, sizeof(mainFontBytes), 14, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	m_pBiggerMainFont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&mainFontBytes, sizeof(mainFontBytes), 23, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImFont* notiffont = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&boldFontBytes, sizeof(boldFontBytes), 18, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImFont* logo = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&logoBytes, sizeof(logoBytes), 48, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	//ImFont* logo_bigger = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(&logoBytes, sizeof(logoBytes), 80, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

	g_pXenon->g_cNotificationService->SetFonts(notiffont, logo);//, logo_bigger);

}

void CUIService::RenderDefaultTheme(bool rainbowBorders) {
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

void CUIService::RenderDefaultMenu() {

	if (ImGui::Begin("Default Menu", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground)) {

		//sizing
		float windowWidth = 500;
		ImGui::SetWindowSize(ImVec2(windowWidth, 440));

		//helpers def
		ImVec2 pos = ImGui::GetWindowPos() + ImVec2(5, 5);

		//main rect
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + windowWidth - 10, pos.y + 430), g_pXenonConfigs->g_pUIConfig->m_cMenuBg, 6.f, ImDrawFlags_RoundCornersAll);

		//title
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + windowWidth - 10, pos.y + 25), g_pXenonConfigs->g_pUIConfig->m_cMenuBg, 6.f, ImDrawFlags_RoundCornersTop);
		ImGui::GetWindowDrawList()->AddText(ImGuiHelper::CenterText(pos, ImVec2(pos.x + windowWidth - 10, pos.y + 25), g_pXenon->g_pSystem->GetAppTitle()->c_str()), g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenon->g_pSystem->GetAppTitle()->c_str());

		//tabs
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.2f, 0.2f, 1.f));         
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.3f, 0.3f, 1.f));  
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.4f, 0.4f, 0.4f, 1.f));   

		ImGui::SetCursorPos(ImVec2(5, 35));

		float width = m_bDevTab ? windowWidth / 5 : windowWidth / 4;

		float tabHeight = 20;
		ImGui::BeginGroup();
		{
			if (ImGui::Tabs("Aim", ImVec2(width, tabHeight), m_nSelectedTab == Tabs::AIM, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedTab = Tabs::AIM;
			if (ImGui::Tabs("Visuals", ImVec2(width, tabHeight), m_nSelectedTab == Tabs::VISUALS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedTab = Tabs::VISUALS;
			if (ImGui::Tabs("Radar", ImVec2(width, tabHeight), m_nSelectedTab == Tabs::RADAR, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedTab = Tabs::RADAR;
			if (ImGui::Tabs("Misc", ImVec2(width, tabHeight), m_nSelectedTab == Tabs::MISC, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedTab = Tabs::MISC;

			if (m_bDevTab)
			{
				if (ImGui::Tabs("Dev", ImVec2(width, tabHeight), m_nSelectedTab == Tabs::DEV, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedTab = Tabs::DEV;
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
					if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::SETTINGS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
					if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::COLORS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::COLORS;
				}
				ImGui::EndGroup();
				break;
			case Tabs::VISUALS:
				ImGui::SetCursorPos(ImVec2(5, 55));
				ImGui::BeginGroup();
				{
					if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::SETTINGS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
					if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::COLORS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::COLORS;
				}
				ImGui::EndGroup();
				break;
			case Tabs::RADAR:
				ImGui::SetCursorPos(ImVec2(5, 55));
				ImGui::BeginGroup();
				{
					if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::SETTINGS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
					if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::COLORS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::COLORS;
				}
				ImGui::EndGroup();
				break;
			case Tabs::MISC:
				ImGui::SetCursorPos(ImVec2(5, 55));
				ImGui::BeginGroup();
				{
					if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::SETTINGS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
					if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::COLORS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::COLORS;
				}
				ImGui::EndGroup();
				break;
			case Tabs::DEV:
				ImGui::SetCursorPos(ImVec2(5, 55));
				ImGui::BeginGroup();
				{
					if (ImGui::Tabs("Settings", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::SETTINGS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::SETTINGS;
					if (ImGui::Tabs("Colors", ImVec2(windowWidth / 2, tabHeight), m_nSelectedSubTab == SubTabs::COLORS, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor2, 0)) m_nSelectedSubTab = SubTabs::COLORS;
				}
				ImGui::EndGroup();
				break;
		}

		ImGui::PopStyleColor(3);
		ImGui::PopStyleVar(); // this pops the itemspacing push

		ImGui::PushStyleColor(ImGuiCol_ChildBg, g_pXenonConfigs->g_pUIConfig->m_cMenuBgFor.Value);

		switch (m_nSelectedTab) {
			case Tabs::AIM:

				switch (m_nSelectedSubTab) {

					case SubTabs::SETTINGS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Aim Settings", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								//ImGui::Checkbox("Silent", &g_pXenonVariables->g_bSilent);
								//ImGui::Checkbox("Visible", &g_pXenonVariables->g_bVisibleCheck);
								//ImGui::Checkbox("Auto scope", &g_pXenonVariables->g_bAutoScope);
								//ImGui::Checkbox("Auto shoot", &g_pXenonVariables->g_bAutoShoot);
								ImGui::Checkbox("Crosshair", &g_pXenonVariables->g_bCrosshair, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								if (g_pXenonVariables->g_bCrosshair) {
									ImGui::Combo("Crossair Type", &g_pXenonConfigs->g_pUIConfig->m_nCrosshairType, "Cross\0Circle");
								}
								ImGui::Checkbox("No recoil", &g_pXenonVariables->g_bNoRecoil, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Spinbot 2D", &g_pXenonVariables->g_bSpinbot2D, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Spinbot 3D", &g_pXenonVariables->g_bSpinbot3D, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Aimbot", &g_pXenonVariables->g_bAimbot, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								if (g_pXenonVariables->g_bAimbot) {
									ImGui::Indent(10);

									ImGui::Combo("Aim To", &g_pXenonConfigs->g_pAimConfig->m_nAimTo, "Head\0Body\0Feet");

									ImGui::Checkbox("Nearest", &g_pXenonVariables->g_bNearest, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									if (g_pXenonVariables->g_bNearest) {
										g_pXenonVariables->g_bFov = false;

										ImGui::Indent(10);

										ImGui::SliderInt("Nearest distance", &g_pXenonConfigs->g_pAimConfig->m_nNearest, 1, 5000);

										ImGui::Indent(-10);
									}

									ImGui::Checkbox("Fov", &g_pXenonVariables->g_bFov, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									if (g_pXenonVariables->g_bFov) {
										g_pXenonVariables->g_bNearest = false;

										ImGui::Indent(10);

										ImGui::SliderFloat("Fov size", &g_pXenonConfigs->g_pAimConfig->m_fFov, 30.f, 300.f, "%.0f");

										ImGui::Indent(-10);
									}
									ImGui::Checkbox("Humanize", &g_pXenonVariables->g_bHumanize, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									//ImGui::Checkbox("No spread", &g_pXenonVariables->g_bNoSpread);

									ImGui::Checkbox("Smooth", &g_pXenonVariables->g_bSmooth, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									if (g_pXenonVariables->g_bSmooth) {
										ImGui::Indent(10);

										ImGui::SliderFloat("Smooth value", &g_pXenonConfigs->g_pAimConfig->m_fSmooth, 5.f, 50.f, "%.0f");
										
										ImGui::Indent(-10);
									}

									ImGui::Indent(-10);

								}
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
					case SubTabs::COLORS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Aim Colors", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								ImGui::ColorEdit4("Fov Color", (float*)&g_pXenonConfigs->g_pAimConfig->m_cFov, ImGuiColorEditFlags_NoInputs);

							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
				}

				break;
			case Tabs::VISUALS:

				switch (m_nSelectedSubTab) {

					case SubTabs::SETTINGS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Visuals Settings", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								ImGui::Checkbox("ESP", &g_pXenonVariables->g_bEsp, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								if (g_pXenonVariables->g_bEsp) {
									ImGui::Indent(10);

									ImGui::Checkbox("Healthbar", &g_pXenonVariables->g_bHealthBar, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									ImGui::Checkbox("Snapline", &g_pXenonVariables->g_bSnapline, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									if (g_pXenonVariables->g_bSnapline) {
										ImGui::Indent(10);

										ImGui::Combo("Snapline Start", &g_pXenonConfigs->g_pEspConfig->m_nSnaplineTypeStart, "Center\0Top\0Bottom");
										ImGui::Combo("Snapline End", &g_pXenonConfigs->g_pEspConfig->m_nSnaplineTypeEnd, "Head\0Body\0Feet");

										ImGui::Indent(-10);
									}
									ImGui::Checkbox("Box 2D", &g_pXenonVariables->g_bBox2D, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									if (g_pXenonVariables->g_bBox2D) {
										ImGui::Indent(10);

										ImGui::Combo("Box 2D Type", &g_pXenonConfigs->g_pEspConfig->m_nBox2DType, "Normal\0Cornered");
										ImGui::Checkbox("Box 2D Distance", &g_pXenonConfigs->g_pEspConfig->m_bDistanceInBox, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
										ImGui::Checkbox("Box 2D Name", &g_pXenonConfigs->g_pEspConfig->m_bNameInBox, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);

										ImGui::Indent(-10);
									}
									ImGui::Checkbox("Box 3D", &g_pXenonVariables->g_bBox3D, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									if (g_pXenonVariables->g_bBox3D) {
										ImGui::Indent(10);

										ImGui::Checkbox("Box 3D Distance", &g_pXenonConfigs->g_pEspConfig->m_bDistanceInBox, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
										ImGui::Checkbox("Box 3D Name", &g_pXenonConfigs->g_pEspConfig->m_bNameInBox, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);

										ImGui::Indent(-10);
									}
									ImGui::Checkbox("Skeleton", &g_pXenonVariables->g_bSkeleton, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);

									ImGui::Indent(-10);
								}

							}
							ImGui::EndGroup();

						}
						ImGui::EndChild();
					} break;
					case SubTabs::COLORS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Visuals Colors", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{

								ImGui::ColorEdit4("Snapline", (float*)&g_pXenonConfigs->g_pEspConfig->m_cSnapline, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Box2D", (float*)&g_pXenonConfigs->g_pEspConfig->m_cBox2D, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Box2D Distance", (float*)&g_pXenonConfigs->g_pEspConfig->m_cBox2DDistance, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Box2D Name", (float*)&g_pXenonConfigs->g_pEspConfig->m_cBox2DName, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Box3D", (float*)&g_pXenonConfigs->g_pEspConfig->m_cBox3D, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Box3D Distance", (float*)&g_pXenonConfigs->g_pEspConfig->m_cBox3DDistance, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Box3D Name", (float*)&g_pXenonConfigs->g_pEspConfig->m_cBox3DName, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Healthbar Background", (float*)&g_pXenonConfigs->g_pEspConfig->m_cHealthBarBg, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Healthbar Foreground", (float*)&g_pXenonConfigs->g_pEspConfig->m_cHealthBarFilled, ImGuiColorEditFlags_NoInputs);
								ImGui::ColorEdit4("Healthbar Text", (float*)&g_pXenonConfigs->g_pEspConfig->m_cHealthBarText, ImGuiColorEditFlags_NoInputs);

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
						ImGui::BeginChild("Radar Settings", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								ImGui::Checkbox("Radar", &g_pXenonVariables->g_bRadar, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								if (g_pXenonVariables->g_bRadar) {
									ImGui::Indent(10);

									ImGui::Checkbox("Show Targets Name", &g_pXenonConfigs->g_pRadarConfig->m_bTargetsName, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
									ImGui::SliderFloat("Size", &g_pXenonConfigs->g_pRadarConfig->m_fSize, 0.f, 500.f, "%.0f");
									ImGui::SliderFloat("Zoom", &g_pXenonConfigs->g_pRadarConfig->m_fZoom, 0.3f, 50.f, "%.1f");
									ImGui::SliderFloat("Targets Size", &g_pXenonConfigs->g_pRadarConfig->m_fTargetsSize, 0.f, 100.f, "%.0f");
									ImGui::SliderFloat("Local Size", &g_pXenonConfigs->g_pRadarConfig->m_fLocalSize, 0.f, 100.f, "%.0f");
									
									ImGui::Indent(-10);
								}
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
					case SubTabs::COLORS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Radar Colors", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
				}

				break;
			case Tabs::MISC:

				switch (m_nSelectedSubTab) {

					case SubTabs::SETTINGS: {

						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Misc Settings", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								ImGui::Checkbox("Watermark", &g_pXenonVariables->g_bWatermark, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								if (ImGui::Button("Set Waypoint")) {
									if (g_pXenon->g_pSystem->Is3DGame()) {
										g_pXenon->g_cWaypoints->SetWaypoint("Waypoint", g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D, ImColor(255,255,255));
									}
									else {
										g_pXenon->g_cWaypoints->SetWaypoint("Waypoint", g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D, ImColor(255,255,255));
									}
								}								
								ImGui::Checkbox("Render Notifications", &g_pXenonVariables->g_bNotifications, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Render Mouse", &g_pXenonVariables->g_bRenderMouse, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								if (g_pXenonVariables->g_bRenderMouse) {
									ImGui::Combo("Mouse Type", &g_pXenonConfigs->g_pUIConfig->m_nMouseType, "Dot\0Cross");
								}
								ImGui::Checkbox("Render UI Windows", &g_pXenonVariables->g_bRenderWindows, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Render UI Overlays", &g_pXenonVariables->g_bRenderOverlays, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Developer Tab", &m_bDevTab, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
					case SubTabs::COLORS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Misc Colors", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								ImGui::ColorEdit4("Crossair", (float*)&g_pXenonConfigs->g_pUIConfig->m_cCrosshair, ImGuiColorEditFlags_NoInputs);
							
								ImGui::ColorEdit4("Mouse", (float*)&g_pXenonConfigs->g_pUIConfig->m_cMouse, ImGuiColorEditFlags_NoInputs);
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
	
					} break;
				}

				break;
			case Tabs::DEV:
				switch (m_nSelectedSubTab) {

					case SubTabs::SETTINGS: {

						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Dev Settings", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
								ImGui::Combo("Mouse Input Mode", &g_pXenonConfigs->g_pAimConfig->m_nMouseInputMode, "SendInput\0SetCursorPos\0PostMessage\0MoveMouse");
								ImGui::SliderFloat("Radar Default Scale", &g_pXenonConfigs->g_pRadarConfig->m_fDefaultScale, 0.f, 10000.f, "%.0f");
								ImGui::Checkbox("Lua Editor", &g_pXenonVariables->g_bLuaEditor, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
								ImGui::Checkbox("Render UI Quick Actions", &g_pXenonVariables->g_bRenderQuickActions, g_pXenonConfigs->g_pUIConfig->m_cMenuBg, g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, g_pXenonConfigs->g_pUIConfig->m_cMenuOff);
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
					case SubTabs::COLORS: {
						ImGui::SetCursorPos(ImVec2(10, 80));
						ImGui::BeginChild("Dev Colors", ImVec2(windowWidth - 20, 350));
						{
							//render funcs
							ImGui::SetCursorPos(ImVec2(10, 10));
							ImGui::BeginGroup();
							{
							}
							ImGui::EndGroup();
						}
						ImGui::EndChild();
					} break;
				}

				break;
		}

		ImGui::PopStyleColor();
	}
	ImGui::End();
}


LRESULT __stdcall CUIService::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (*m_bShowMenu && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	if (*m_bShowMenu)
		return true;

	if (!m_pSystem->IsInternal() && uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return true;
	}

	if (m_pSystem->IsInternal()) {
		return CallWindowProcA(*m_pOWndProc, hWnd, uMsg, wParam, lParam);
	}
	else {
		return DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
}

void CUIService::InitExternal() {
	if (CreateWindowUI()) {
		if (CreateDeviceUI()) {
			CreateImGuiUI();
		}
	}
}
void CUIService::RenderEnabledCheats() {

	ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x - 110, 10), ImGuiCond_Always);
	ImGui::SetNextWindowSize(ImVec2(100, 0));

	ImGui::Begin("Enabled Cheats", nullptr,
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoBringToFrontOnFocus |
		ImGuiWindowFlags_NoScrollbar |
		ImGuiWindowFlags_NoScrollWithMouse |
		ImGuiWindowFlags_NoBackground);

	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
	ImGui::PushFont(m_pBiggerMainFont);

	if (g_pXenonVariables->g_bAimbot) {
		ImGui::Text("Aimbot");
	}
	if (g_pXenonVariables->g_bSpinbot2D || g_pXenonVariables->g_bSpinbot3D) {
		ImGui::Text("Spinbot");
	}
	if (g_pXenonVariables->g_bSnapline) {
		ImGui::Text("Snapline");
	}
	if (g_pXenonVariables->g_bBox2D || g_pXenonVariables->g_bBox3D) {
		ImGui::Text("Box");
	}
	if (g_pXenonVariables->g_bSkeleton) {
		ImGui::Text("Skeleton");
	}
	if (g_pXenonVariables->g_bRadar) {
		ImGui::Text("Radar");
	}
	if (g_pXenonVariables->g_bNoRecoil) {
		ImGui::Text("No Recoil");
	}
	if (g_pXenonVariables->g_bCrosshair) {
		ImGui::Text("Crosshair");
	}

	ImGui::PopFont();
	ImGui::PopStyleColor();
	ImGui::End();
}


void CUIService::RenderCrosshair() {
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

void CUIService::RenderFov() {
	ImGui::GetForegroundDrawList()->AddCircle(ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, g_pXenon->g_pSystem->GetScreenCenter().y), g_pXenonConfigs->g_pAimConfig->m_fFov, g_pXenonConfigs->g_pAimConfig->m_cFov, 360);
}

void CUIService::RenderMouse() {
	switch (g_pXenonConfigs->g_pUIConfig->m_nMouseType) {
	case 0:
		ImGui::GetForegroundDrawList()->AddCircleFilled(ImGui::GetMousePos(), 4, g_pXenonConfigs->g_pUIConfig->m_cMouse);
		break;
	case 1:
		ImGuiHelper::DrawOutlinedTextForeground(m_pMainFont, ImVec2(g_pXenon->g_pSystem->GetMousePos().x, g_pXenon->g_pSystem->GetMousePos().y), 13.0f, g_pXenonConfigs->g_pUIConfig->m_cMouse, false, "X");
		break;
	case 2:
		if (!ImGui::GetIO().MouseDrawCursor) {
			ImGui::GetIO().MouseDrawCursor = true;
		}
		break;
	}
}

void CUIService::RenderDefaultUIQuickActions() {


	if (ImGui::Begin("QuickActions", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground)) {

		float width = 490;
		float height = 440;
		float padding = 5;

		ImGui::SetWindowSize(ImVec2(width, height));

		ImVec2 pos = ImGui::GetWindowPos() + ImVec2(padding, padding);

		//main rect
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 430), g_pXenonConfigs->g_pUIConfig->m_cMenuBg, 6.f, ImDrawFlags_RoundCornersAll);

		//title
		const char* title = "Quick Actions";
		ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 25), g_pXenonConfigs->g_pUIConfig->m_cMenuBg, 6.f, ImDrawFlags_RoundCornersTop);
		ImGui::GetWindowDrawList()->AddText(ImGuiHelper::CenterText(pos, ImVec2(pos.x + 480, pos.y + 25), title), g_pXenonConfigs->g_pUIConfig->m_cMenuAccent, title);

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

void CUIService::UpdateUI() {

	if (g_pXenonVariables->g_bShowMenu) {

		if (g_pXenonVariables->g_bRenderMouse) {
			RenderMouse();
		}

		//if (g_pXenonConfigs->g_pUIConfig->m_fnCustomTheme) {
		//	g_pXenonConfigs->g_pUIConfig->m_fnCustomTheme();
		//}
		//else {
		//	RenderDefaultTheme(false);
		//}

		if (g_pXenonVariables->g_bMenu) {
			if (g_pXenonConfigs->g_pUIConfig->m_fnCustomMenu) {
				g_pXenonConfigs->g_pUIConfig->m_fnCustomMenu();
			}
			else {
				RenderDefaultMenu();
			}
		}

		if (g_pXenonVariables->g_bRenderWindows) {
			for (auto& fn : g_pXenonConfigs->g_pUIConfig->m_vFnWindows) {
				fn();
			}
		}

		if (g_pXenonVariables->g_bRenderQuickActions && g_pXenonConfigs->g_pUIConfig->m_qActions->GetSize() > 0) {
			RenderDefaultUIQuickActions();
		}

	}

	if (g_pXenonVariables->g_bRenderOverlays) {
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

	if (g_pXenonVariables->g_bWatermark)
	{
		ImColor color = ImColor(255, 255, 255, 255); // or rainbow

		ImGuiHelper::DrawOutlinedText(m_pMainFont, ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, g_pXenon->g_pSystem->GetScreenResolution().y - 20), 13.0f, color, true, g_pXenon->g_pSystem->GetAppTitle()->c_str());
		ImGuiHelper::DrawOutlinedText(m_pMainFont, ImVec2(g_pXenon->g_pSystem->GetScreenCenter().x, 5), 13.0f, color, true, "[ %.1f FPS ]", ImGui::GetIO().Framerate);
	}

	g_pXenon->g_cNotificationService->RenderNotifications();

}

void CUIService::Destroy() {
	DestroyImGuiUI();
	DestroyDeviceUI();
	DestroyWindowUI();
}

bool CUIService::CreateWindowUI()
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

	// Ottieni il titolo come std::string
	std::string appTitle = *g_pXenon->g_pSystem->GetAppTitle();

	int size_needed = MultiByteToWideChar(CP_UTF8, 0, appTitle.c_str(), -1, nullptr, 0);
	if (size_needed <= 0) {
		spdlog::error("MultiByteToWideChar failed with error: {}", GetLastError());
		return false;	
	}

	std::wstring wideWindowTitle(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, appTitle.c_str(), -1, &wideWindowTitle[0], size_needed);

	m_hWindow = CreateWindowExW(
		WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED,
		m_wClass.lpszClassName,
		wideWindowTitle.c_str(),
		WS_POPUP,
		0, 0,
		static_cast<int>(g_pXenon->g_pSystem->GetScreenResolution().x),
		static_cast<int>(g_pXenon->g_pSystem->GetScreenResolution().y),
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

void CUIService::DestroyWindowUI()
{
	DestroyWindow(m_hWindow);
	UnregisterClassW(m_wClass.lpszClassName, m_wClass.hInstance);
}

bool CUIService::CreateDeviceUI() {
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

void CUIService::SetMenuOpen() {

	SetWindowLongW(m_hWindow, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT);

}

void CUIService::SetMenuClose() {

	SetWindowLongW(m_hWindow, GWL_EXSTYLE, WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED);

}

void CUIService::ResetDeviceUI()
{

	switch (g_pXenon->g_pSystem->GetRenderingType()) {
	case RenderingType::DX11:
		ImGui_ImplDX11_InvalidateDeviceObjects();
		break;
	case RenderingType::OPENGL2:
		ImGui_ImplOpenGL2_DestroyDeviceObjects();
		break;
	case RenderingType::OPENGL3:
		ImGui_ImplOpenGL3_DestroyDeviceObjects();
		break;
	}

	DestroyDeviceUI();

	switch (g_pXenon->g_pSystem->GetRenderingType()) {
	case RenderingType::DX11:
		ImGui_ImplDX11_CreateDeviceObjects();
		break;
	case RenderingType::OPENGL2:
		ImGui_ImplOpenGL2_CreateDeviceObjects();
		break;
	case RenderingType::OPENGL3:
		ImGui_ImplOpenGL3_CreateDeviceObjects();
		break;
	}

}

void CUIService::DestroyDeviceUI()
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

void CUIService::CreateImGuiUI()
{
	InitializeDepthStencilStates();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(m_hWindow);

	if (g_pXenon->g_pSystem->IsInternal()) {

		switch (g_pXenon->g_pSystem->GetRenderingType()) {
		case RenderingType::DX11:
			ImGui_ImplDX11_Init(m_pDevice, m_pContext);
			break;
		case RenderingType::OPENGL2:
			ImGui_ImplOpenGL2_Init();
			break;
		case RenderingType::OPENGL3:
			ImGui_ImplOpenGL3_Init();
			break;
		}
	}
	else {
		ImGui_ImplDX11_Init(m_pDevice, m_pContext);
	}


	LoadDefaultFonts();
}

void CUIService::DestroyImGuiUI()
{

	switch (g_pXenon->g_pSystem->GetRenderingType()) {
	case RenderingType::DX11:
		ImGui_ImplDX11_Shutdown();
		break;
	case RenderingType::OPENGL2:
		ImGui_ImplOpenGL2_Shutdown();
		break;
	case RenderingType::OPENGL3:
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

void CUIService::BeginRenderUI()
{

	if (g_pXenon->g_pSystem->IsInternal()) {
		switch (g_pXenon->g_pSystem->GetRenderingType()) {
			case RenderingType::DX11:
				ImGui_ImplDX11_NewFrame();
				break;
			case RenderingType::OPENGL2:
				ImGui_ImplOpenGL2_NewFrame();
				break;
			case RenderingType::OPENGL3:
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

void CUIService::InitializeDepthStencilStates() {
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

void CUIService::EndRenderUI()
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
		case RenderingType::DX11:
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
			break;
		case RenderingType::OPENGL2:
			ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
			break;
		case RenderingType::OPENGL3:
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			break;
		}

	}
	else {
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	if (!g_pXenon->g_pSystem->IsInternal()) m_pSwapChain->Present(1U, 0U);
}
