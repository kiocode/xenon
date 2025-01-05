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
		ImGui::Begin("Healths");

		for (int i = 0; i < builder.GameManager->m_vTargets.size(); i++) {
			ImGui::Text("Position: %f, %f", builder.GameManager->m_vTargets[i].x, builder.GameManager->m_vTargets[i].y);
		}

		ImGui::End();
	});
	
	//pUIConfig->m_qActions->AddButton("Test", []() { std::cout << "test" << std::endl; });
	//pUIConfig->m_qActions->AddCheckbox("Test 2 toggle", &pUIConfig->m_bWatermark);
	//pUIConfig->m_qActions->AddCheckbox("Test 2 toggle", &pUIConfig->m_bWatermark);
	//pUIConfig->m_qActions->AddButton("Test", []() { std::cout << "test" << std::endl; });
	//pUIConfig->m_qActions->AddSlider("Test 3 slider", &pAimConfig->m_fRecoilVerticalStrength, 0, 1000);

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

		builder.GameManager->m_vTargets.clear();
		builder.GameManager->m_vLocalPos = server->players[server->localPlayerId].pos;
		for (int i = 0; i < server->players.size(); i++) {
			if (server->players[i].gametick == 0 || server->players[i].id == server->localPlayerId) continue;

			builder.GameManager->m_vTargets.push_back(server->players[i].pos);
		}
		});

	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
	pAimConfig->m_fnCustomAim = [builder, clientAddr, offsets](const Vec2& pos) {
		Vec2 w2sTarget = { pos.x - builder.GameManager->m_vLocalPos.x, pos.y - builder.GameManager->m_vLocalPos.y };
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos, w2sTarget.x);
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos + 0x4, w2sTarget.y);
		};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingTypes::DIRECTX11);
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

		builder.GameManager->m_vTargets.clear();
		builder.GameManager->m_vLocalPos = Vec2(builder.MemoryManager->Read<int>(serverAddr + offsets.posX), builder.MemoryManager->Read<int>(serverAddr + offsets.posY));

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

			builder.GameManager->m_vTargets.push_back(Vec2(x, y));

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

	builder.GameManager->m_vTargets.push_back({ 100, 100 });
	builder.GameManager->m_vTargets.push_back({ 200, 200 });
	builder.GameManager->m_vTargets.push_back({ 300, 300 });
	builder.GameManager->m_vTargets.push_back({ 400, 400 });
	builder.GameManager->m_vTargets.push_back({ 500, 500 });

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
	//TestRecoil(builder);
	//TestDDNetExternal(builder);
	TestRedEclipseExternal(builder);

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
