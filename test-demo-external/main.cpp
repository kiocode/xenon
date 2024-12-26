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

	std::shared_ptr<AimConfig> pAimConfig = builder.Services.GetConfiguration<AimConfig>();
	//pAimbotConfig->m_bHumanize = true;
	//pAimbotConfig->m_bStartFromCenter = true;
	//pAimbotConfig->m_bSmooth = true;
	//pAimbotConfig->m_fSmooth = 30;
	//pAimbotConfig->m_fRecoilTiltStrength = 0;
	//pAimbotConfig->m_fRecoilVerticalStrength = 175; // ash
	//pAimbotConfig->m_fRecoilVerticalStrength = 185; // castle
	//pAimbotConfig->m_fRecoilVerticalStrength = 165; // dokkaebi
	//pAimbotConfig->m_fRecoilVerticalStrength = 165; // thermite
	pAimConfig->m_bNearest = true;
	pAimConfig->m_fNearest = 700;
	pAimConfig->m_fRecoilVerticalStrength = 130; // mira
	pAimConfig->m_fSpinbotRadius = 100; 
	pAimConfig->m_fSpinbotSpeed = 10; 

}

static void AddServices(Builder& builder) {
	//builder.Services.AddSingleton<Aimbot>([]() { return std::make_shared<Aimbot>(); });
}

static void Test(Builder& builder) {
	/*std::shared_ptr<Aimbot> c_pAimbot = builder.Services.GetService<Aimbot>();
	std::shared_ptr<AimService> c_pAimService = builder.Services.GetService<AimService>();

	auto previousTime = std::chrono::steady_clock::now();
	builder.GameManager->g_fStartPlayTime = previousTime.time_since_epoch().count();
	while (true)
	{
		auto currentTime = std::chrono::steady_clock::now();
		builder.GameManager->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count() * 100;
		previousTime = currentTime;

		 c_pAimbot->SetTarget

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}*/
}

int main()
{
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

	Builder builder;
	builder.SetDebugLogLevel();
	//builder.SetUICustomTheme(theme);
	//builder.SetUICustom(ui);

	builder.MemoryManager->AttachGame("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	uintptr_t baseAddr = builder.MemoryManager->GetModuleAddress();
	uintptr_t serverAddr = builder.MemoryManager->Read<uintptr_t>(baseAddr + offsets.staticServerAddr);
	uintptr_t clientAddr = builder.MemoryManager->Read<uintptr_t>(baseAddr + offsets.staticClientAddr);

	AddConfigurations(builder);
	AddServices(builder);

	Server* server = new Server();

	builder.GameManager->OnEvent("Update", [builder, server, offsets, serverAddr]() {

		server->players.clear();

		server->localPlayerId = builder.MemoryManager->Read<int>(serverAddr + offsets.idLocalPlayer);
		server->onlinePlayers = builder.MemoryManager->Read<int>(serverAddr + offsets.onlinePlayers);
		server->localPlayerConnectedToAServer = server->localPlayerId != -1;

		if(!server->localPlayerConnectedToAServer) return;

		int i = 0;
		do {
			Player player;
			player.id = i;
			player.gametick = builder.MemoryManager->Read<int>(serverAddr + offsets.gametick + (i * 0xF8));
			player.pos.x = builder.MemoryManager->Read<float>(serverAddr + offsets.playerPos + (i * 0xF8));
			player.pos.y = builder.MemoryManager->Read<float>(serverAddr + offsets.playerPos + 0x4 + (i * 0xF8));

			server->players.push_back(player);

			if (player.id == server->localPlayerId) {
				server->localPlayer = &player;
			}

			i++;
		} while (i != 63); //builder.MemoryManager->Read<int>(serverAddr + offsets.gametick + (i * 0xF8)) != -1);

		builder.GameManager->m_vTargets.clear();
		builder.GameManager->m_vLocalPos = server->localPlayer->pos;
		for (int i = 0; i < server->players.size(); i++) {
			if(server->players[i].gametick == 0 || server->players[i].id == server->localPlayerId) continue;

			Vec2 w2sTarget = { server->players[i].pos.x - server->localPlayer->pos.x, server->players[i].pos.y - server->localPlayer->pos.y };
			builder.GameManager->m_vTargets.push_back(w2sTarget);
		}
	});

	std::shared_ptr<AimConfig> pAimConfig = builder.Services.GetConfiguration<AimConfig>();
	pAimConfig->m_mCustomAim = [builder, clientAddr, offsets](const Vec2& pos) {
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos, pos.x);
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos + 0x4, pos.y);
	};

	ExternalCheat cheat = builder.BuildExternal();

	cheat.UseUpdate();
	//cheat.UseCustomUI(); <-- voto: pisnelo
	cheat.UseAimbot();
	//cheat.UseRecoil();
	//cheat.Use2DSpinbot();

	cheat.Run();

	//Test(builder);

	return 0;
}
