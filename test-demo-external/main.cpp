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

static void AddConfigurations(Builder& builder) {

	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
	//pAimConfig->m_bHumanize = true;
	//pAimConfig->m_bStartFromCenter = true;
	//pAimConfig->m_bSmooth = true;
	//pAimConfig->m_fSmooth = 30;
	//pAimConfig->m_fRecoilTiltStrength = 0;
	//pAimConfig->m_fRecoilVerticalStrength = 175; // ash
	//pAimConfig->m_fRecoilVerticalStrength = 185; // castle
	//pAimConfig->m_fRecoilVerticalStrength = 165; // dokkaebi
	//pAimConfig->m_fRecoilVerticalStrength = 165; // thermite
	pAimConfig->m_fRecoilVerticalStrength = 200; // jackal
	//pAimConfig->m_fRecoilVerticalStrength = 120; // onix
	//pAimConfig->m_fRecoilVerticalStrength = 130; // mira
	//pAimConfig->m_bNearest = true;
	//pAimConfig->m_fNearest = 700;
	//pAimConfig->m_fSpinbotRadius = 100; 
	//pAimConfig->m_fSpinbotSpeed = 10; 

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
	pAimConfig->m_mCustomAim = [builder, clientAddr, offsets](const Vec2& pos) {
		Vec2 w2sTarget = { pos.x - builder.GameManager->m_vLocalPos.x, pos.y - builder.GameManager->m_vLocalPos.y };
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos, w2sTarget.x);
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos + 0x4, w2sTarget.y);
		};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseCustomUI();
	//cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

}

static void TestGeneral(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseCustomUI();
	//cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

}

static void TestRecoil(Builder& builder) {

	AddConfigurations(builder);
	AddServices(builder);

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	//cheat.UseCustomUI();
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
	//builder.SetUICustomTheme(theme);
	//builder.SetUICustom(ui);
	//builder.SetUIDefaultFunctions([
	//	{ACTIONTYPE.CHECKBOX, "name", &var}
	//]);

	//TestGeneral(builder);
	TestRecoil(builder);
	//TestDDNetExternal(builder);

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
