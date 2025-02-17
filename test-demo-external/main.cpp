#include <windows.h>

#include <xenon/xenon.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/services/lua_service.hpp>

static void AddConfigurations(Builder& builder) {

	std::shared_ptr<AimConfig> pAimConfig = builder.xenonConfig->g_pAimConfig;
	//pAimConfig->m_bHumanize = true;
	//pAimConfig->m_bStartFromCenter = true;
	//pAimConfig->m_bSmooth = true;
	//pAimConfig->m_fSmooth = 30;
	//pAimConfig->m_fRecoilTiltStrength = 0;
	//pAimConfig->m_fRecoilVerticalStrength = 175; // ash
	//pAimConfig->m_fRecoilVerticalStrength = 185; // castle
	//pAimConfig->m_fRecoilVerticalStrength = 160; // ela
	//pAimConfig->m_fRecoilVerticalStrength = 190; // ace
	//pAimConfig->m_fRecoilVerticalStrength = 165; // dokkaebi
	//pAimConfig->m_fRecoilVerticalStrength = 175; // nomad
	//pAimConfig->m_fRecoilVerticalStrength = 165; // thermite
	//pAimConfig->m_fRecoilVerticalStrength = 135; // solis
	//pAimConfig->m_fRecoilVerticalStrength = 200; // jackal
	//pAimConfig->m_fRecoilVerticalStrength = 120; // onix
	//pAimConfig->m_fRecoilVerticalStrength = 130; // mira 
	//pAimConfig->m_fRecoilVerticalStrength = 380; // twitch
	//pAimConfig->m_fRecoilVerticalStrength = 100; // tachanka
	//pAimConfig->m_fRecoilVerticalStrength = 150; // mute
	//pAimConfig->m_bNearest = true;
	//pAimConfig->m_fNearest = 700;
	//pAimConfig->m_fSpinbotRadius = 100; 
	//pAimConfig->m_fSpinbotSpeed = 10; 

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	pRadarConfig->m_nType = 0;
	pRadarConfig->m_fSize= 200.f;
	pRadarConfig->m_fDefaultScale = 1000.0f;
	pRadarConfig->m_fZoom = 1.0f;
	pRadarConfig->m_fLocalSize = 6.0f;
	pRadarConfig->m_fTargetsSize = 6.0f;

	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
	std::shared_ptr<CWaypoints> pWaypoint = builder.xenon->g_cWaypoints;
	std::shared_ptr<CNotificationService> pNotificationService = builder.xenon->g_cNotificationService;
	//pUIConfig->m_qActions->AddButton("Set Waypoint", [pWaypoint, pGameVariables]() { pWaypoint->SetWaypoint("waypointTest", pGameVariables->g_vLocal.m_vPos3D, ImColor.new(255, 255, 255)); });
	pUIConfig->m_qActions->AddButton("Damage", [pWaypoint, pGameVariables]() { pGameVariables->g_vTargets[0].m_fHealth -= 5; });
	pUIConfig->m_qActions->AddButton("Set Waypoint", [pWaypoint, pGameVariables]() { pWaypoint->SetWaypoint("waypointTest", pGameVariables->g_vLocal.m_vPos2D, ImColor(255, 255, 255)); });

	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 30);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);

	pUIConfig->m_qActions->AddButton("Test Notification", [pNotificationService]() { pNotificationService->Notify("test", "test message"); });

	pUIConfig->m_vFnWindows.push_back([pGameVariables, pUIConfig, pRadarConfig, pWaypoint, pNotificationService]() {
		ImGui::Begin("Test Window");
	
		//demo funcs
		static bool checkbox1 = false;
		static bool checkbox2 = false;
		static bool checkbox3 = false;
		static int sliderint = 0;
		static float sliderfloat = 0.f;
		static int combo = 0;
		static const char* multi_items[5] = { "One", "Two", "Three", "Four", "Five" };
		static bool multi_items_count[5];
		static int key = 0;
		static char input0[64] = "";
		static char input1[64] = "";

		ImGui::Checkbox("Checkbox", &checkbox3, pUIConfig->m_cMenuBg, pUIConfig->m_cMenuAccent, pUIConfig->m_cMenuOff);
		ImGui::SliderInt("Slider Int", &sliderint, 0, 100);
		ImGui::SliderFloat("Slider Float", &sliderfloat, 0.f, 100.f, "%.1f");
		ImGui::Combo("Combo", &combo, "Selectable 1\0Selectable 2\0Selectable 3", 3);
		ImGui::MultiCombo("Multicombo", multi_items_count, multi_items, 5);
		ImGui::Keybind("Hotkey", &key);

		//if(ImGui::Button("Test Hotkey", ImVec2.new(200, 25)))
		//	isEditing = true;
		//ImGuiHelper::RenderHotkeyEditor(&testhotkey, &isEditing);
				
		//demo funcs

		if (checkbox1)
		{
			ImGui::InputText("Pointer or Offset", input0, 64, ImGuiInputTextFlags_ReadOnly);
			ImGui::InputText("Value", input1, 64, ImGuiInputTextFlags_ReadOnly);
		}
		else
		{
			ImGui::InputText("Pointer or Offset", input0, 64);
			ImGui::InputText("Value", input1, 64);
		}
		ImGui::Checkbox("Read-Only", &checkbox1, pUIConfig->m_cMenuBg, pUIConfig->m_cMenuAccent, pUIConfig->m_cMenuOff);
		ImGui::Checkbox("Loop Command", &checkbox2, pUIConfig->m_cMenuBg, pUIConfig->m_cMenuAccent, pUIConfig->m_cMenuOff);
	
		ImGui::End();
	});
}

static void AddServices(Builder& builder) {
	//builder.Services->AddSingleton<CAimbot>([]() { return std::make_shared<CAimbot>(); });
}

//static void TestRedEclipseExternal(Builder& builder) {
//
//	#pragma region Offsets
//
//	struct offsets {
//		uintptr_t staticServerAddr = 0x868EB8;
//		uintptr_t staticClientAddr = 0x868EC8;
//		uintptr_t localPlayer = 0x0;
//		uintptr_t posX = 0x0;
//		uintptr_t posY = 0x4;
//		uintptr_t posZ = 0x8;
//		uintptr_t health = 0x48;
//
//		uintptr_t staticViewAddr = 0x859300;
//		uintptr_t pitch = 0x30;
//		uintptr_t yaw = 0x34;
//	};
//
//	offsets offsets;
//
//	#pragma endregion
//
//	builder.MemoryManager->AttachGame("D:\\Steam\\steamapps\\common\\Red Eclipse\\bin\\amd64\\redeclipse.exe");
//	uintptr_t serverAddr = builder.MemoryManager->ReadPointer(offsets.staticServerAddr);
//	uintptr_t clientAddr = builder.MemoryManager->ReadPointer(offsets.staticClientAddr);
//	uintptr_t localPlayerAddr = builder.MemoryManager->Read<uintptr_t>(clientAddr + offsets.localPlayer);
//	uintptr_t viewAddr = builder.MemoryManager->ReadPointer(offsets.staticViewAddr);
//
//	AddConfigurations(builder);
//	AddServices(builder);
//
//	builder.GameManager->OnEvent("Update", [builder, offsets, serverAddr, localPlayerAddr]() {
//
//		builder.xenonConfig->g_pGameVariables->g_vTargets3DWorld.clear();
//		builder.xenonConfig->g_pGameVariables->g_vLocalPos3DWorld = Vec3(builder.MemoryManager->Read<int>(serverAddr + offsets.posX), builder.MemoryManager->Read<int>(serverAddr + offsets.posY), builder.MemoryManager->Read<int>(serverAddr + offsets.posZ));
//
//		int localPlayerHealth = builder.MemoryManager->Read<int>(localPlayerAddr + offsets.health);
//
//		int i = 0;
//		do {
//
//			uintptr_t entityAddr = builder.MemoryManager->Read<uintptr_t>(serverAddr + (i * 0x8));
//			int health = builder.MemoryManager->Read<int>(entityAddr + offsets.health + (i * 0x8));
//
//			if (health <= 0) {
//				i++;
//				continue;
//			}	
//
//			float x = builder.MemoryManager->Read<float>(entityAddr + offsets.posX + (i * 0x8));
//			float y = builder.MemoryManager->Read<float>(entityAddr + offsets.posY + (i * 0x8));
//			float z = builder.MemoryManager->Read<float>(entityAddr + offsets.posZ + (i * 0x8));
//
//			builder.xenonConfig->g_pGameVariables->g_vTargets3DWorld.push_back(Vec3(x, y, z));
//
//			i++;
//		} while (i != 6);
//
//	});
//
//	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
//	pAimConfig->m_fnCustomAim = [builder, viewAddr, offsets](const Vec2& pos) {
//		//Vec2 w2sTarget = ;
//		//
//		//// x rotation
//		//builder.MemoryManager->Write<float>(viewAddr + offsets.pitch, pos.x);
//		//
//		//// y rotation
//		//builder.MemoryManager->Write<float>(viewAddr + offsets.yaw, pos.y);
//	};
//
//	Cheat cheat = builder.Build();
//
//	cheat.UseUpdate();
//	cheat.UseUICustom(RenderingHookType::KIERO);
//	cheat.UseUIRenderOverlays();
//	cheat.UseAimbot();
//	//cheat.UseNoRecoil();
//	//cheat.Use2DSpinbot();
//
//	cheat.Run();
//
//}

static void TestGeneral(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	#pragma region Edit Configs
	std::shared_ptr<EspConfig> pEspConfig = builder.xenonConfig->g_pEspConfig;
	pEspConfig->m_cBox2DDistance = ImColor(255, 255, 255, 255);

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	pRadarConfig->m_fDefaultScale = 2000;
	#pragma endregion

	#pragma region Mock 
	TargetProfile local = TargetProfile();
	local.m_vPos2D = builder.xenon->g_pSystem->GetScreenCenter();
	local.m_vHeadPos2D = Vec2(local.m_vPos2D.x, local.m_vPos2D.y + 100);
	local.m_vFeetPos2D = Vec2(local.m_vPos2D.x, local.m_vPos2D.y - 100);
	local.m_fHealth = 100;
	local.m_fMaxHealth = 100;
	local.m_fWidth = 80;
	builder.xenonConfig->g_pGameVariables->g_vLocal = local;

	TargetProfile target1 = TargetProfile();
	target1.m_vPos2D = Vec2(300, 500);
	target1.m_vHeadPos2D = Vec2(target1.m_vPos2D.x, target1.m_vPos2D.y - 100);
	target1.m_vFeetPos2D = Vec2(target1.m_vPos2D.x, target1.m_vPos2D.y + 100);
	target1.m_fHealth = 100;
	target1.m_fMaxHealth = 100;
	target1.m_fWidth = 80;
	builder.xenonConfig->g_pGameVariables->g_vTargets.push_back(target1);

	TargetProfile target2 = TargetProfile();
	target2.m_vPos2D = Vec2(1000, 400);
	target2.m_vHeadPos2D = Vec2(target2.m_vPos2D.x, target2.m_vPos2D.y - 100);
	target2.m_vFeetPos2D = Vec2(target2.m_vPos2D.x, target2.m_vPos2D.y + 100);
	target2.m_fHealth = 80;
	target2.m_fMaxHealth = 100;
	target2.m_fWidth = 80;
	builder.xenonConfig->g_pGameVariables->g_vTargets.push_back(target2);

	TargetProfile target3 = TargetProfile();
	target3.m_vPos2D = Vec2(1500, 800);
	target3.m_vHeadPos2D = Vec2(target3.m_vPos2D.x, target3.m_vPos2D.y - 100);
	target3.m_vFeetPos2D = Vec2(target3.m_vPos2D.x, target3.m_vPos2D.y + 100);
	target3.m_fHealth = 70;
	target3.m_fMaxHealth = 100;
	target3.m_fWidth = 80;
	builder.xenonConfig->g_pGameVariables->g_vTargets.push_back(target3);

	TargetProfile target4 = TargetProfile();
	target4.m_vPos2D = Vec2(400, 400);
	target4.m_vHeadPos2D = Vec2(target4.m_vPos2D.x, target4.m_vPos2D.y - 100);
	target4.m_vFeetPos2D = Vec2(target4.m_vPos2D.x, target4.m_vPos2D.y + 100);
	target4.m_fHealth = 50;
	target4.m_fMaxHealth = 100;
	target4.m_fWidth = 80;
	builder.xenonConfig->g_pGameVariables->g_vTargets.push_back(target4);
	#pragma endregion

	builder.xenonConfig->g_pUIConfig->m_qActions->AddSlider("Distance Scale", &builder.xenonConfig->g_pAimConfig->m_fDistanceScale, 0.0f, 100.0f);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookType::KIERO);
	cheat.UseUIMenu();
	cheat.UseUIRenderEnabledCheats();
	//cheat.UseUIRenderWindows();
	//cheat.UseUIRenderOverlays();
	//cheat.UseUIQuickActions();
	
	//cheat.UseUIRadar();
	//cheat.UseAimbot();
	//cheat.UseNoRecoil();
	//cheat.Use2DSpinbot();
	//cheat.UseESPSnapline();
	//cheat.UseESPBox2D();
	//cheat.UseESPHealthBar();

	cheat.Run();

}

static void TestLua(Builder& builder) {

	//AddConfigurations(builder);
	//AddServices(builder);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookType::KIERO);
	cheat.UseUIMenu();
	cheat.UseUIQuickActions();
	/*cheat.UseESPSnapline();
	cheat.UseESPBox2D();*/

	std::shared_ptr<CLuaService> pLuaService = builder.xenon->g_cLuaService;

	try {
		sol::protected_function_result result = pLuaService->ExecuteScript(R"(
			function onUpdate()
				-- Create a new window and draw content
				beginWindow("My Window")
				setCursorPos(50, 50)
				drawText("Hello, World!")
				sameLine()
				createButton("Click Me")
				endWindow()

				-- Get the draw list
				local drawList = getDrawList()

				-- Check if drawList is valid
				if not drawList then
					print("Error: Draw list is null!")
				else
					-- Draw a line
					local startPos = ImVec2.new(100, 100)
					local endPos = ImVec2.new(200, 100)
					local lineColor = ImColor.new(255, 0, 0, 255)
					drawList:drawLine(startPos, endPos, lineColor:toU32(), 2)
					print("Line drawn successfully!")

					-- Draw a rectangle
					local rectMin = ImVec2.new(50, 50)
					local rectMax = ImVec2.new(150, 150)
					local rectColor = ImColor.new(0, 255, 0, 255)
					drawList:drawRect(rectMin, rectMax, rectColor:toU32(), 0.0, 0, 2)
					print("Rectangle drawn successfully!")

					-- Draw a filled rectangle
					local filledRectColor = ImColor.new(0, 0, 255, 255)
					drawList:drawRectFilled(rectMin, rectMax, filledRectColor:toU32(), 0.0, 0)
					print("Filled rectangle drawn successfully!")

					-- Draw a circle
					local circleCenter = ImVec2.new(400, 100)
					local circleColor = ImColor.new(255, 255, 0, 255)
					drawList:drawCircle(circleCenter, 50, circleColor:toU32(), 12, 2)
					print("Circle drawn successfully!")

					-- Draw a filled circle
					local filledCircleColor = ImColor.new(255, 0, 255, 255)
					drawList:drawCircleFilled(circleCenter, 50, filledCircleColor:toU32(), 12)
					print("Filled circle drawn successfully!")

					-- Draw a triangle
					local p1 = ImVec2.new(600, 100)
					local p2 = ImVec2.new(650, 150)
					local p3 = ImVec2.new(700, 100)
					local triangleColor = ImColor.new(255, 0, 0, 255)
					drawList:drawTriangle(p1, p2, p3, triangleColor:toU32(), 2)
					print("Triangle drawn successfully!")

					-- Draw a filled triangle
					local filledTriangleColor = ImColor.new(0, 255, 0, 255)
					drawList:drawTriangleFilled(p1, p2, p3, filledTriangleColor:toU32())
					print("Filled triangle drawn successfully!")

				end
			end

		)");

		if (!result.valid()) {
			sol::error err = result;
			spdlog::error("Lua error: {}", err.what()); 
		}
		else {
			spdlog::info("Lua script executed successfully");
		}
	}
	catch (const std::exception& e) {
		spdlog::error("C++ Exception: {}", e.what());
	}


	cheat.Run();

}

static void TestRecoil(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	//cheat.UseUICustom(RenderingType::DIRECTX11);
	//cheat.UseAimbot();
	cheat.UseNoRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

}

static void RunTests() {

	Builder builder("Demo external");
	builder.xenon->g_pSystem->IsInternal(false);
	builder.xenon->g_pSystem->SetGameDimension(GameDimension::DIM_2D);
	builder.xenon->g_pSystem->m_fnW2S2D = [](Vec2 pos) { return Vec2(pos.x, pos.y); };
	builder.SetConsoleEnabled();
	builder.SetDebugLogLevel();

	TestGeneral(builder);
	//TestLua(builder);
	//TestRecoil(builder);
	//TestRedEclipseExternal(builder);

}

int main()
{

	try {
		RunTests();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
