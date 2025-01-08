#include <windows.h>
#include <xenon/xenon.hpp>
#include <xenon/features/waypoints.hpp>

static void AddConfigurations(Builder& builder) {

	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
	//pAimConfig->m_bHumanize = true;
	//pAimConfig->m_bStartFromCenter = true;
	//pAimConfig->m_bSmooth = true;
	//pAimConfig->m_fSmooth = 30;
	//pAimConfig->m_fRecoilTiltStrength = 0;
	//pAimConfig->m_fRecoilVerticalStrength = 175; // ash
	//pAimConfig->m_fRecoilVerticalStrength = 185; // castle
	pAimConfig->m_fRecoilVerticalStrength = 160; // ela
	//pAimConfig->m_fRecoilVerticalStrength = 190; // ace
	//pAimConfig->m_fRecoilVerticalStrength = 165; // dokkaebi
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

	std::shared_ptr<RadarConfig> pRadarConfig = builder.Services->GetConfiguration<RadarConfig>();
	pRadarConfig->m_nType = 0;
	pRadarConfig->m_fSize= 200.f;
	pRadarConfig->m_fDefaultScale = 1000.0f;
	pRadarConfig->m_fZoom = 1.0f;
	pRadarConfig->m_fLocalSize = 6.0f;
	pRadarConfig->m_fTargetsSize = 6.0f;

	std::shared_ptr<UIConfig> pUIConfig = builder.Services->GetConfiguration<UIConfig>();
	std::shared_ptr<GameVariables> pGameVariables = builder.Services->GetConfiguration<GameVariables>();
	std::shared_ptr<Waypoints> pWaypoint = builder.Services->GetService<Waypoints>();
	pUIConfig->m_qActions->AddButton("Set Waypoint", [pWaypoint, pGameVariables]() { pWaypoint->SetWaypoint("waypointTest", pGameVariables->g_vLocalPos3DWorld, ImColor(255, 255, 255)); });

	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 30);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);
}

static void AddServices(Builder& builder) {
	//builder.Services->AddSingleton<Aimbot>([]() { return std::make_shared<Aimbot>(); });
}

static void TestRedEclipseExternal(Builder& builder) {

	#pragma region Offsets

	struct offsets {
		uintptr_t staticServerAddr = 0x868EB8;
		uintptr_t staticClientAddr = 0x868EC8;
		uintptr_t localPlayer = 0x0;
		uintptr_t posX = 0x0;
		uintptr_t posY = 0x4;
		uintptr_t posZ = 0x8;
		uintptr_t health = 0x48;

		uintptr_t staticViewAddr = 0x859300;
		uintptr_t pitch = 0x30;
		uintptr_t yaw = 0x34;
	};

	offsets offsets;

	#pragma endregion

	builder.MemoryManager->AttachGame("D:\\Steam\\steamapps\\common\\Red Eclipse\\bin\\amd64\\redeclipse.exe");
	uintptr_t serverAddr = builder.MemoryManager->ReadPointer(offsets.staticServerAddr);
	uintptr_t clientAddr = builder.MemoryManager->ReadPointer(offsets.staticClientAddr);
	uintptr_t localPlayerAddr = builder.MemoryManager->Read<uintptr_t>(clientAddr + offsets.localPlayer);
	uintptr_t viewAddr = builder.MemoryManager->ReadPointer(offsets.staticViewAddr);

	AddConfigurations(builder);
	AddServices(builder);

	builder.GameManager->OnEvent("Update", [builder, offsets, serverAddr, localPlayerAddr]() {

		builder.GameGlobalVariables->g_vTargets3DWorld.clear();
		builder.GameGlobalVariables->g_vLocalPos3DWorld = Vec3(builder.MemoryManager->Read<int>(serverAddr + offsets.posX), builder.MemoryManager->Read<int>(serverAddr + offsets.posY), builder.MemoryManager->Read<int>(serverAddr + offsets.posZ));

		int localPlayerHealth = builder.MemoryManager->Read<int>(localPlayerAddr + offsets.health);

		int i = 0;
		do {

			uintptr_t entityAddr = builder.MemoryManager->Read<uintptr_t>(serverAddr + (i * 0x8));
			int health = builder.MemoryManager->Read<int>(entityAddr + offsets.health + (i * 0x8));

			if (health <= 0) {
				i++;
				continue;
			}	

			float x = builder.MemoryManager->Read<float>(entityAddr + offsets.posX + (i * 0x8));
			float y = builder.MemoryManager->Read<float>(entityAddr + offsets.posY + (i * 0x8));
			float z = builder.MemoryManager->Read<float>(entityAddr + offsets.posZ + (i * 0x8));

			builder.GameGlobalVariables->g_vTargets3DWorld.push_back(Vec3(x, y, z));

			i++;
		} while (i != 6);

	});

	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
	pAimConfig->m_fnCustomAim = [builder, viewAddr, offsets](const Vec2& pos) {
		//Vec2 w2sTarget = ;
		//
		//// x rotation
		//builder.MemoryManager->Write<float>(viewAddr + offsets.pitch, pos.x);
		//
		//// y rotation
		//builder.MemoryManager->Write<float>(viewAddr + offsets.yaw, pos.y);
	};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookTypes::KIERO);
	cheat.UseUIRenderOverlays();
	cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

}

static void TestGeneral(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	//builder.GameGlobalVariables->g_vLocalPos3DWorld = Vec3( 1500, 100, 600 );

	//builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 100, 100 });
	//builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 200, 200 });
	//builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 300, 300 });
	//builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 400, 400 });
	//builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 500, 500 });

	builder.GameGlobalVariables->g_vLocalPos2DWorld = Vec2(300, 600 );
	 
	builder.GameGlobalVariables->g_vTargets2DWorld.push_back({ 100, 100 });
	builder.GameGlobalVariables->g_vTargets2DWorld.push_back({ 200, 200 });
	builder.GameGlobalVariables->g_vTargets2DWorld.push_back({ 300, 300 });
	builder.GameGlobalVariables->g_vTargets2DWorld.push_back({ 400, 400 });
	builder.GameGlobalVariables->g_vTargets2DWorld.push_back({ 500, 500 });

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookTypes::KIERO);
	cheat.UseUIRadar();
	//cheat.UseUIMenu();
	//cheat.UseUIRenderWindows();
	cheat.UseUIRenderOverlays();
	cheat.UseUIQuickActions();
	//cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();
	cheat.UseESPSnapline();
	cheat.UseESPBox2D();

	cheat.Run();

}

static void TestLua(Builder& builder) {

	//AddConfigurations(builder);
	//AddServices(builder);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookTypes::KIERO);
	cheat.UseUIQuickActions();
	/*cheat.UseESPSnapline();
	cheat.UseESPBox2D();*/


	std::shared_ptr<LuaService> pLuaService = builder.Services->GetService<LuaService>();

	//pLuaService->ExecuteScriptFile("scripts\\test.lua");
	pLuaService->ExecuteScript(R"(
        function OnUpdate()
			--local staticServerAddr = 0x5ABBA0
			--local idLocalPlayer = 0x1450
			--
			--local mem = MemoryService()
			--local baseAddress = mem:getModuleAddress("DDNet.exe")
			--print(string.format("Base Address: 0x%X", baseAddress))
			--
			--local staticServer = mem:readPointer(baseAddress + staticServerAddr)
			--print(string.format("Static Server Address: 0x%X", staticServer))
			--
			--local localPlayerId = mem:readInt(staticServer + idLocalPlayer)
			--print(string.format("Local Player ID: %i", localPlayer))

			local address = memoryService:getModuleAddress("DDNet.exe")
			local value = memoryService:readPointer(address + 0x1234)
			print(value)

        end

    )");

	cheat.Run();

}

static void TestRecoil(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	//cheat.UseUICustom(RenderingType::DIRECTX11);
	//cheat.UseAimbot();
	cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

}

static void RunTests() {

	Builder builder("Demo external");
	builder.SystemVariables->IsInternal(false);
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
