#include <xenon/core/gui.hpp>

#include <imgui/imgui_internal.h>

void GUI::InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

void GUI::LoadFonts()
{
	ImGui::GetIO().Fonts->AddFontDefault();
	ImFontConfig font_cfg;
	font_cfg.GlyphExtraSpacing.x = 1.2;
}

void GUI::RenderUI()
{

	{
		//notifications
		if (notiftype == 0)
		{
			ImGui::Begin("Notif0", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove);
			{
				if (notifpressed && 1)
				{
					shouldmove = true;

					static float timer = 0.f;
					timer += 4.f * ImGui::GetIO().DeltaTime;

					if (timer > 10.f)
						shouldresize = false;

					if (timer > 20.f)
						shouldmove = false;

					if (timer > 30.f)
						logoshouldmove = false;

					if (timer > 40.f)
						finalresizeshouldmove = false;

					if (timer > 50.f)
					{
						notifpressed = 0;
						closemove = false;
					}

					ImGuiContext& g = *GImGui;
					anim = ImLerp(anim, shouldmove ? 0.f : 300.f, g.IO.DeltaTime * 6.f);
					resizeanim = ImLerp(resizeanim, shouldresize ? 0.f : 320.f, g.IO.DeltaTime * 5.f);
					logomove = ImLerp(logomove, logoshouldmove ? 0.f : 320.f, g.IO.DeltaTime * 5.f);
					finalresize = ImLerp(finalresize, finalresizeshouldmove ? 0.f : 320.f, g.IO.DeltaTime * 5.f);
					closeanim = ImLerp(closeanim, closemove ? 0.f : 500.f, g.IO.DeltaTime * 1.f);

					//sizing + pos
					ImGui::SetWindowSize(ImVec2(80 + resizeanim + resizeanim - finalresize - finalresize, 60));
					ImGui::SetWindowPos(ImVec2(900 - resizeanim + finalresize, 900 + closeanim));

					//helpers def
					drawlist = ImGui::GetWindowDrawList();
					pos = ImGui::GetWindowPos() + ImVec2(5, 5);

					//main draws
					drawlist->AddRectFilled(pos, ImVec2(pos.x + 70 + resizeanim + resizeanim - finalresize - finalresize, pos.y + 50), ImColor(0, 79, 65, 255), 20.f); //bg
					drawlist->AddRect(pos, ImVec2(pos.x + 70 + resizeanim + resizeanim - finalresize - finalresize, pos.y + 50), ImColor(0, 229, 189, 255), 20.f, 0, 1.5f); //rect

					//logo
					ImGui::PushFont(logo);
					ImGui::SetCursorPos(ImVec2(15 + logomove - finalresize, 7));
					ImGui::TextColored(ImColor(255, 255, 255, 255), "A");
					ImGui::SetCursorPos(ImVec2(15 + logomove - finalresize, 7));
					ImGui::TextColored(ImColor(0, 229, 189), "B");
					ImGui::SetCursorPos(ImVec2(15 + logomove - finalresize, 7));
					ImGui::TextColored(ImColor(0, 229, 189), "C");
					ImGui::PopFont();

					//render notifts
					ImGui::PushFont(notiffont);
					ImGui::SetCursorPos(ImVec2(78, 13 - anim));
					ImGui::TextColored(ImColor(255, 255, 255, 255), notiftitle);
					ImGui::PopFont();

					ImGui::SetCursorPos(ImVec2(78, 32 - anim));
					ImGui::TextColored(ImColor(255, 255, 255, 255), notifdesc);

					ImGui::PushFont(notiffont);
					ImGui::SetCursorPos(ImVec2(78, 321 - anim - logomove));
					ImGui::TextColored(ImColor(255, 255, 255, 255), notifsecondtitle);
					ImGui::PopFont();

					ImGui::PushFont(notiffont);
					ImGui::SetCursorPos(ImVec2(80, 341 - logomove - finalresize));
					ImGui::TextColored(ImColor(255, 255, 255, 255), "Welcome to RageByte");

					ImGui::SetCursorPos(ImVec2(475, 341 - logomove - finalresize));
					ImGui::TextColored(ImColor(255, 255, 255, 255), "Dominate the game!");
					ImGui::PopFont();
				}
			}
			ImGui::End();
		}
		if (notiftype == 1)
		{
			ImGui::Begin("Notif1", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove);
			{
				if (notifpressed && 1)
				{
					shouldmove = false;

					static float timer = 0.f;
					timer += 2.f * ImGui::GetIO().DeltaTime;

					if (timer > 10.f)
						shouldmove = true;

					if (timer > 20.0f)
					{
						timer = 0.f;
						notifpressed = 0;
					}
				}

				ImGuiContext& g = *GImGui;
				anim = ImLerp(anim, shouldmove ? 0.f : 800.f, g.IO.DeltaTime * 6.f);
				if (anim <= 799.f)
					shouldresize = true;
				else
					shouldresize = false;

				resizeanim = ImLerp(resizeanim, shouldresize ? 0.f : 310.f, g.IO.DeltaTime * 5.f);

				//sizing + pos
				ImGui::SetWindowSize(ImVec2(80 + resizeanim, 60));
				ImGui::SetWindowPos(ImVec2(20, -780 + anim));

				//helpers def
				drawlist = ImGui::GetWindowDrawList();
				pos = ImGui::GetWindowPos() + ImVec2(5, 5);

				//main draws
				drawlist->AddRectFilled(pos, ImVec2(pos.x + 70 + resizeanim, pos.y + 50), ImColor(0, 79, 65, 255), 20.f); //bg
				drawlist->AddRect(pos, ImVec2(pos.x + 70 + resizeanim, pos.y + 50), ImColor(0, 229, 189, 255), 20.f, 0, 1.5f); //rect

				//logo
				ImGui::PushFont(logo);
				ImGui::SetCursorPos(ImVec2(15, 7));
				ImGui::TextColored(ImColor(255, 255, 255, 255), "A");
				ImGui::SetCursorPos(ImVec2(15, 7));
				ImGui::TextColored(ImColor(0, 229, 189), "B");
				ImGui::SetCursorPos(ImVec2(15, 7));
				ImGui::TextColored(ImColor(0, 229, 189), "C");
				ImGui::PopFont();

				//render notifts
				ImGui::PushFont(notiffont);
				ImGui::SetCursorPos(ImVec2(78, 13));
				ImGui::TextColored(ImColor(255, 255, 255, 255), notiftitle);
				ImGui::PopFont();

				ImGui::SetCursorPos(ImVec2(78, 32));
				ImGui::TextColored(ImColor(255, 255, 255, 255), notifdesc);
			}
			ImGui::End();
		}

		ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBackground);

		//sizing
		ImGui::SetWindowSize(ImVec2(490, 440));

		//helpers def
		drawlist = ImGui::GetWindowDrawList();
		pos = ImGui::GetWindowPos() + ImVec2(5, 5);

		//main rect
		drawlist->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 430), ImColor(29, 40, 54, 150), 6.f, ImDrawFlags_RoundCornersAll);

		//title
		drawlist->AddRectFilled(pos, ImVec2(pos.x + 480, pos.y + 25), ImColor(29, 40, 54, 255), 6.f, ImDrawFlags_RoundCornersTop);
		drawlist->AddText(CenterText(pos, ImVec2(pos.x + 480, pos.y + 25), "RageByte - MWIII"), ImColor(165, 186, 197, 255), "RageByte - MWIII");

		//tabs
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::SetCursorPos(ImVec2(5, 35));
		ImGui::BeginGroup();
		{
			if (devconsole)
			{
				if (ImGui::Tabs("Players", ImVec2(80, 20), tabs == 0)) tabs = 0;
				if (ImGui::Tabs("Radar", ImVec2(80, 20), tabs == 1)) tabs = 1;
				if (ImGui::Tabs("Loot", ImVec2(80, 20), tabs == 2)) tabs = 2;
				if (ImGui::Tabs("Aim", ImVec2(80, 20), tabs == 3)) tabs = 3;
				if (ImGui::Tabs("Misc", ImVec2(80, 20), tabs == 4)) tabs = 4;
				if (ImGui::Tabs("Dev", ImVec2(80, 20), tabs == 5)) tabs = 5;
			}
			else
			{
				if (ImGui::Tabs("Players", ImVec2(96, 20), tabs == 0)) tabs = 0;
				if (ImGui::Tabs("Radar", ImVec2(96, 20), tabs == 1)) tabs = 1;
				if (ImGui::Tabs("Loot", ImVec2(96, 20), tabs == 2)) tabs = 2;
				if (ImGui::Tabs("Aim", ImVec2(96, 20), tabs == 3)) tabs = 3;
				if (ImGui::Tabs("Misc", ImVec2(96, 20), tabs == 4)) tabs = 4;
			}
		}
		ImGui::EndGroup();

		//subtabs ( if it's the case )
		if (tabs == 0)
		{
			ImGui::SetCursorPos(ImVec2(5, 55));
			ImGui::BeginGroup();
			{
				if (ImGui::Tabs("Colors", ImVec2(240, 20), subtabs == 0)) subtabs = 0;
				if (ImGui::Tabs("Settings", ImVec2(240, 20), subtabs == 1)) subtabs = 1;
			}
			ImGui::EndGroup();
		}

		ImGui::PopStyleVar(); // this pops the itemspacing push

		//functions
		if (tabs == 0)
		{
			ImGui::SetCursorPos(ImVec2(10, 80));
			ImGui::BeginChild("MainChild", ImVec2(470, 345));
			{
				//demo funcs
				static bool checkbox[8];
				static int sliderint[4];

				//render funcs
				ImGui::SetCursorPos(ImVec2(10, 10));
				ImGui::BeginGroup();
				{
					ImGui::Checkbox("Only Visible", &checkbox[0]);
					ImGui::Checkbox("Friends", &checkbox[1]);
					ImGui::Checkbox("Name", &checkbox[2]);
					ImGui::Checkbox("Line", &checkbox[3]);
					ImGui::Checkbox("Health", &checkbox[4]);
					ImGui::Checkbox("Box 2D", &checkbox[5]);
					ImGui::Checkbox("Distance", &checkbox[6]);
					ImGui::Checkbox("Skeleton", &checkbox[7]);
					ImGui::SliderInt("Size line skeleton", &sliderint[0], 0, 10);
					ImGui::SliderInt("Skeleton draw distance", &sliderint[1], 0, 100);
					ImGui::Checkbox("Developer Console", &devconsole);
				}
				ImGui::EndGroup();
			}
			ImGui::EndChild();
		}

		if (tabs == 1)
		{
			ImGui::SetCursorPos(ImVec2(10, 60));
			ImGui::BeginChild("MainChild", ImVec2(470, 365));
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
					ImGui::Combo("Combo", &combo, "Selectable 1\0\Selectable 2\0\Selectable 3", 3);
					ImGui::MultiCombo("Multicombo", multi_items_count, multi_items, 5);
					ImGui::Keybind("Keybind", &key);
				}
				ImGui::EndGroup();
			}
			ImGui::EndChild();
		}

		//achievements
		if (tabs == 2)
		{
			ImGui::SetCursorPos(ImVec2(10, 60));
			ImGui::BeginChild("MainChild", ImVec2(470, 365));
			{
				//render funcs
				ImGui::SetCursorPos(ImVec2(10, 10));
				ImGui::BeginGroup();
				{
					ImGui::InputText("Notification Title", notiftitle, 64);
					ImGui::InputText("Notification Description", notifdesc, 64);
					ImGui::InputText("Notification Second Title", notifsecondtitle, 64);
					if (ImGui::Button("Showcase notification", ImVec2(200, 25)))
						notifpressed++;
					ImGui::Combo("Notificiation Type", &notiftype, "Xbox\0\PS4", 2);
				}
				ImGui::EndGroup();
			}
			ImGui::EndChild();
		}

		if (tabs == 5)
		{
			ImGui::SetCursorPos(ImVec2(10, 60));
			ImGui::BeginChild("MainChild", ImVec2(470, 365));
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
					ImGui::Combo("Type", &combo, "Byte\0\r2 Byte\0\r4 Byte\0\rFloat\0\Double\0\String", 6);
				}
				ImGui::EndGroup();
			}
			ImGui::EndChild();
		}

		ImGui::End();

		ImGui::Begin("Radar", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
		{
			//size + pos
			ImGui::SetWindowSize(ImVec2(260, 260));

			//helpers def
			drawlist = ImGui::GetWindowDrawList();
			pos = ImGui::GetWindowPos();

			//render main rect
			drawlist->AddRectFilled(ImVec2(pos.x + 5, pos.y + 5), ImVec2(pos.x + 255, pos.y + 255), ImColor(25, 25, 25, 150), 8.f);

			//render radar elements
			drawlist->AddLine(ImVec2(pos.x + 130, pos.y + 5), ImVec2(pos.x + 130, pos.y + 255), ImColor(83, 83, 83, 255)); //center
			drawlist->AddLine(ImVec2(pos.x + 8, pos.y + 8), ImVec2(pos.x + 130, pos.y + 130), ImColor(83, 83, 83, 255)); //left
			drawlist->AddLine(ImVec2(pos.x + 253, pos.y + 8), ImVec2(pos.x + 130, pos.y + 130), ImColor(83, 83, 83, 255)); //right

			//border
			drawlist->AddRect(ImVec2(pos.x + 5, pos.y + 5), ImVec2(pos.x + 255, pos.y + 255), ImColor(83, 83, 83, 255), 8.f);

			//main player i assume
			drawlist->AddCircleFilled(ImVec2(pos.x + 130, pos.y + 127), 6.f, ImColor(170, 170, 170, 255));
		}
		ImGui::End();
	}

}

LRESULT __stdcall GUI::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (showMenu && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	if (showMenu)
		return true;

	return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall GUI::hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)GUI::WndProcWrapper);
			InitImGui();
			init = true;
		} else return oPresent(pSwapChain, SyncInterval, Flags);
	}

	if (GetAsyncKeyState(VK_INSERT) & 1)
	{
		showMenu = !showMenu;
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (showMenu) RenderUI();

	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}