#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <windows.h>

#include <xenon/core/di_manager.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/core/builder.hpp>
#include <xenon/utility/random.hpp>
#include <xenon/services/aim_service.hpp>

#include "server.hpp"
#include <xenon/configs/ui_config.hpp>
#include <xenon/services/lua_service.hpp>

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

	std::shared_ptr<ESPConfig> pESPConfig = builder.Services->GetConfiguration<ESPConfig>();
	std::shared_ptr<UIConfig> pUIConfig = builder.Services->GetConfiguration<UIConfig>();
	//pUIConfig->m_fnCustomMenu = []() {
	//	ImGui::Begin("Custom menu");
	//	ImGui::Text("Hello, world!");
	//	ImGui::End();
	//};
	//pUIConfig->m_fnCustomRadar = []() {
	//	ImGui::Begin("Custom menu");
	//	ImGui::Text("Hello, world!");
	//	ImGui::End();
	//};
	//pUIConfig->m_fnCustomNotification = []() {
	//	ImGui::Begin("Custom menu");
	//	ImGui::Text("Hello, world!");
	//	ImGui::End();
	//};
	//pUIConfig->m_bWatermark = true;
	//pUIConfig->m_vFnWindows.push_back([]() {
	//	ImGui::Begin("Custom draw list");
	//	ImGui::Text("Hello, world!");
	//	ImGui::End();
	//});
	pUIConfig->m_vFnOverlays.push_back([builder]() {
		ImGui::Begin("Positions");

		for (int i = 0; i < builder.GameGlobalVariables->g_vTargets2DWorld.size(); i++) {
			ImGui::Text("Position: %f, %f", builder.GameGlobalVariables->g_vTargets2DWorld[i].x, builder.GameGlobalVariables->g_vTargets2DWorld[i].y);
		}

		ImGui::End();
	});
	
	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 5);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);
	pUIConfig->m_qActions->AddSlider("Box2d Type", &pESPConfig->m_nBox2DType, 0, 1);

}

static void AddServices(Builder& builder) {
	//builder.Services->AddSingleton<Aimbot>([]() { return std::make_shared<Aimbot>(); });
}

static void TestDDNetExternal(Builder& builder) {
	/*std::shared_ptr<Aimbot> c_pAimbot = builder.Services->GetService<Aimbot>();
	std::shared_ptr<AimService> c_pAimService = builder.Services->GetService<AimService>();

	auto previousTime = std::chrono::steady_clock::now();
	builder.GameManager->g_fStartPlayTime = previousTime.time_since_epoch().count();
	while (true)
	{
		auto currentTime = std::chrono::steady_clock::now();
		builder.GameManager->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count() * 100;
		previousTime = currentTime;


		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}*/

	#pragma region Offsets

	struct offsets {
		uintptr_t staticServerAddr = 0x5ABBA0;
		uintptr_t idLocalPlayer = 0x1450;
		uintptr_t onlinePlayers = 0x1454;
		uintptr_t gametick = 0x147C + 0x0;
		uintptr_t playerPos = 0x147C + 0xE8 + 0x0;

		uintptr_t staticClientAddr = 0x455C40;
		uintptr_t aimPos = 0x10;
	};

	offsets offsets;

	#pragma endregion

	builder.MemoryManager->AttachGame("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	uintptr_t serverAddr = builder.MemoryManager->ReadPointer(offsets.staticServerAddr);
	uintptr_t clientAddr = builder.MemoryManager->ReadPointer(offsets.staticClientAddr);

	AddConfigurations(builder);
	AddServices(builder);

	Server* server = new Server();

	builder.GameManager->OnEvent("Update", [builder, server, offsets, serverAddr]() {

		server->players.clear();

		server->localPlayerId = builder.MemoryManager->Read<int>(serverAddr + offsets.idLocalPlayer);
		server->onlinePlayers = builder.MemoryManager->Read<int>(serverAddr + offsets.onlinePlayers);
		server->localPlayerConnectedToAServer = server->localPlayerId != -1;

		if (!server->localPlayerConnectedToAServer) return;

		int i = 0;
		do {
			Player player;
			player.id = i;
			player.gametick = builder.MemoryManager->Read<int>(serverAddr + offsets.gametick + (i * 0xF8));
			player.pos.x = builder.MemoryManager->Read<float>(serverAddr + offsets.playerPos + (i * 0xF8));
			player.pos.y = builder.MemoryManager->Read<float>(serverAddr + offsets.playerPos + 0x4 + (i * 0xF8));

			server->players.push_back(player);

			i++;
		} while (i != 63); //builder.MemoryManager->Read<int>(serverAddr + offsets.gametick + (i * 0xF8)) != -1);

		builder.GameGlobalVariables->g_vTargetsCustom.clear(); // aimbot custom
		builder.GameGlobalVariables->g_vTargets2DWorld.clear();
		builder.GameGlobalVariables->g_vTargetsScreen.clear();
		builder.GameGlobalVariables->g_vLocalPos2DWorld = server->players[server->localPlayerId].pos;
		for (int i = 0; i < server->players.size(); i++) {
			if (server->players[i].gametick == 0 || server->players[i].id == server->localPlayerId) continue;

			Vec2 w2sTarget = { server->players[i].pos.x - builder.GameGlobalVariables->g_vLocalPos2DWorld.x, server->players[i].pos.y - builder.GameGlobalVariables->g_vLocalPos2DWorld.y };
			builder.GameGlobalVariables->g_vTargetsCustom.push_back(w2sTarget);
			builder.GameGlobalVariables->g_vTargets2DWorld.push_back(server->players[i].pos);

			// edit pos
			Vec2 pos = Vec2((w2sTarget.x + builder.Services->GetService<System>()->GetScreenCenter().x) - 32, (w2sTarget.y + builder.Services->GetService<System>()->GetScreenCenter().y) - 32);
			builder.GameGlobalVariables->g_vTargetsScreen.push_back(pos);
		}
	});

	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
	pAimConfig->m_fnCustomAim = [builder, clientAddr, offsets](const Vec2& pos) {
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos, pos.x);
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos + 0x4, pos.y);
	};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingTypes::DIRECTX11);
	cheat.UseUIRenderOverlays();
	cheat.UseUIRadar();
	cheat.UseUIQuickActions();
	cheat.UseESPSnapline();
	cheat.UseESPBox2D();
	//cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

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
	cheat.UseUICustom(RenderingTypes::DIRECTX11);
	cheat.UseUIRenderOverlays();
	cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

}

static void TestGeneral(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 100, 100 });
	builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 200, 200 });
	builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 300, 300 });
	builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 400, 400 });
	builder.GameGlobalVariables->g_vTargetsScreen.push_back({ 500, 500 });

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingTypes::DIRECTX11);
	//cheat.UseUIRadar();
	//cheat.UseUIMenu();
	//cheat.UseUIRenderWindows();
	//cheat.UseUIRenderOverlays();
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
	cheat.UseUICustom(RenderingTypes::DIRECTX11);
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

	//TestGeneral(builder);
	//TestLua(builder);
	//TestRecoil(builder);
	TestDDNetExternal(builder);
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
