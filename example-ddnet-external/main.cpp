#include <windows.h>

#include "server.hpp"

#include <xenon/xenon.hpp>
#include <xenon/models/waypoint.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/features/aimbot.hpp>

struct offsets {
	uintptr_t staticServerAddr;
	uintptr_t idLocalPlayer;
	uintptr_t onlinePlayers;
	uintptr_t gametick;
	uintptr_t playerPos;

	uintptr_t staticClientAddr;
	uintptr_t aimPos;
};

struct offsets offsets;

bool ddper = true;

static void AddConfigurations(Builder& builder) {

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	pRadarConfig->m_nType = 0;
	pRadarConfig->m_fSize = 200.f;
	pRadarConfig->m_fDefaultScale = 1000.0f;
	pRadarConfig->m_fZoom = 1.0f;
	pRadarConfig->m_fLocalSize = 6.0f;
	pRadarConfig->m_fTargetsSize = 6.0f;
	pRadarConfig->m_bTargetsName = true;

	std::shared_ptr<AimConfig> pAimConfig = builder.xenonConfig->g_pAimConfig;
	std::shared_ptr<EspConfig> pESPConfig = builder.xenonConfig->g_pEspConfig;
	pESPConfig->m_bHealthBar = true;

	std::shared_ptr<CWaypoints> pWaypoints = builder.xenon->g_cWaypoints;

	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints]() {
		ImGui::Begin("Positions");

		for (const auto &target : builder.xenonConfig->g_pGameVariables->g_vTargets) {
			ImGui::Text("Position: %f, %f", target.m_vPos2D.x, target.m_vPos2D.y);
		}

		ImGui::Separator();

		ImGui::Text("Aimbot target: %f, %f", builder.xenon->g_cAimbot->GetTarget().x, builder.xenon->g_cAimbot->GetTarget().y);

		ImGui::End();

	});

	builder.xenon->g_pSystem->m_fDistanceScale = 0.040;
	pUIConfig->m_qActions->AddSlider("Distance Scale", &builder.xenon->g_pSystem->m_fDistanceScale, 0.001, 2);
	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 5);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);
	pUIConfig->m_qActions->AddSlider("Box2d Type", &pESPConfig->m_nBox2DType, 0, 1);

	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
	pUIConfig->m_qActions->AddButton("Set Waypoint", [pGameVariables, pWaypoints]() { 
		pWaypoints->SetWaypoint("test", pGameVariables->g_vLocal.m_vPos2D, ImColor(255,255,255)); 
	});

}

int main()
{
	if (!ddper) {
		offsets.staticServerAddr = 0x5B8E80;
		offsets.idLocalPlayer = 0x2090;
		offsets.onlinePlayers = 0x2098;
		offsets.gametick = 0x20D4 + 0x0;
		offsets.playerPos = 0x20D4 + 0xE8;

		offsets.staticClientAddr = 0x460A80;
		offsets.aimPos = 0x10;
	}
	else {
		offsets.staticServerAddr = 0x424100;
		offsets.idLocalPlayer = 0x22E0;
		offsets.onlinePlayers = 0x22E4;
		offsets.gametick = 0x2318 + 0x4;
		offsets.playerPos = 0x2318 + 0xEC;

		offsets.staticClientAddr = 0x3F35C0;
		offsets.aimPos = 0x10;
	}

	Builder builder(!ddper ? "DDNet external" : "DDPer external");
	builder.xenon->g_pSystem->IsInternal(false);
	builder.SetConsoleEnabled();
	builder.SetInfoLogLevel();

	builder.xenon->g_pSystem->SetGameDimension(GameDimension::DIM_2D);

	try {
		builder.xenon->g_cMemoryService->AttachGame(!ddper ? "D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe" : "C:\\Users\\kio\\Desktop\\DDPER-v8.2.1-win64\\DDPER.exe");
	}
	catch (const std::exception& e) {
		builder.xenon->g_cMemoryService->AttachGame(!ddper ? "C:\\Program Files (x86)\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe" : "C:\\Users\\kio\\Desktop\\DDPER-v8.2.1-win64\\DDPER.exe");
	}
	uintptr_t serverAddr = builder.xenon->g_cMemoryService->ReadPointer(offsets.staticServerAddr);
	uintptr_t clientAddr = builder.xenon->g_cMemoryService->ReadPointer(offsets.staticClientAddr);

	if (!serverAddr || !clientAddr) {
		spdlog::error("Failed to find server or client address");
		return 1;
	}

	AddConfigurations(builder);

	Server* server = new Server();

	std::shared_ptr<GameVariables> gameVariables = builder.xenonConfig->g_pGameVariables;
	std::shared_ptr<System> system = builder.xenon->g_pSystem;
	std::shared_ptr<CMemoryService> memoryService = builder.xenon->g_cMemoryService;

	builder.GameManager->OnEvent("Update", [builder, server, serverAddr, gameVariables, memoryService]() {

		server->players.clear();

		server->localPlayerId = memoryService->Read<int>(serverAddr + offsets.idLocalPlayer);
		server->onlinePlayers = memoryService->Read<int>(serverAddr + offsets.onlinePlayers);
		server->localPlayerConnectedToAServer = server->localPlayerId != -1;

		if (!server->localPlayerConnectedToAServer) return;

		int i = 0;
		int offsetPlayers = 0xF8;
		do {
			Player player;
			player.id = i;
			player.gametick = memoryService->Read<int>(serverAddr + offsets.gametick + (i * offsetPlayers));
			player.pos.x = memoryService->Read<float>(serverAddr + offsets.playerPos + (i * offsetPlayers));
			player.pos.y = memoryService->Read<float>(serverAddr + offsets.playerPos + 0x4 + (i * offsetPlayers));

			server->players.push_back(player);

			i++;
		} while (i != 63); //memoryService->Read<int>(serverAddr + offsets.gametick + (i * 0xF8)) != -1);

		gameVariables->g_vTargets.clear();
		gameVariables->g_vLocal.m_vPos2D = Vec2(server->players[server->localPlayerId].pos.x - 32, server->players[server->localPlayerId].pos.y - 32);
		for (int i = 0; i < server->players.size(); i++) {
			if (server->players[i].gametick == 0 || server->players[i].id == server->localPlayerId || (server->players[i].pos.x == 0 && server->players[i].pos.y == 0)) continue;
			
			//float distance = gameVariables->g_vLocal.m_vPos2D.Distance(Vec2(server->players[i].pos.x, server->players[i].pos.y));

			//float distanceFactor = distance / 15; // to change

			Vec2 originalPos(server->players[i].pos.x, server->players[i].pos.y);
			Vec2 localPos = gameVariables->g_vLocal.m_vPos2D;
			//Vec2 direction = (originalPos - localPos).Normalized();
			Vec2 modifiedPos = originalPos;// + direction * distanceFactor;

			TargetProfile targetProfile;
			targetProfile.m_fWidth = 64;
			targetProfile.m_vPos2D = modifiedPos;
			targetProfile.m_vHeadPos2D = modifiedPos - Vec2(0, 32);
			targetProfile.m_vFeetPos2D = modifiedPos + Vec2(0, 32);
			targetProfile.m_strName = "Player " + std::to_string(server->players[i].id);
			targetProfile.m_fHealth = 100;
			gameVariables->g_vTargets.push_back(targetProfile);
		}
	});

	std::shared_ptr<AimConfig> pAimConfig = builder.xenonConfig->g_pAimConfig;
	pAimConfig->m_nAimTo = 1;
	pAimConfig->m_fnCustomAim = [builder, clientAddr, memoryService, gameVariables](const Vec2& pos) {
		Vec2 screenToWorldPos = builder.xenon->g_pSystem->m_fnS2W2D(pos);
		
		Vec2 gamePlayerRelativePos = Vec2(screenToWorldPos.x - gameVariables->g_vLocal.m_vPos2D.x, screenToWorldPos.y - gameVariables->g_vLocal.m_vPos2D.y);

		memoryService->Write<float>(clientAddr + offsets.aimPos, gamePlayerRelativePos.x);
		memoryService->Write<float>(clientAddr + offsets.aimPos + 0x4, gamePlayerRelativePos.y);
	};

	pAimConfig->m_fnCustomGetAim = [builder, clientAddr, memoryService]() {
		return Vec2(memoryService->Read<float>(clientAddr + offsets.aimPos), memoryService->Read<float>(clientAddr + offsets.aimPos + 0x4));
	};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom();
	cheat.UseUIMenu();
	cheat.UseUIRenderOverlays();
	cheat.UseUIQuickActions();
	cheat.UseUIRenderEnabledCheats();
	cheat.UseESPBox2D();
	cheat.UseESPSnapline();
	cheat.UseUIRadar();
	cheat.UseAimbot();

	system->m_fnW2S2D = [builder, gameVariables, system](Vec2 pos) {
		int playerSize = 64;
		Vec2 gamePlayerRelativePos = Vec2(
			pos.x - gameVariables->g_vLocal.m_vPos2D.x,
			pos.y - gameVariables->g_vLocal.m_vPos2D.y
		);

		return Vec2(
			(gamePlayerRelativePos.x + system->GetScreenCenter().x) - playerSize / 2,
			(gamePlayerRelativePos.y + system->GetScreenCenter().y) - playerSize / 2
		);
	};

	system->m_fnS2W2D = [builder, gameVariables, system](Vec2 pos) {
		int playerSize = 64;
		Vec2 gamePlayerRelativePos = Vec2(
			pos.x - system->GetScreenCenter().x,
			pos.y - system->GetScreenCenter().y
		);

		return Vec2(
			gamePlayerRelativePos.x + gameVariables->g_vLocal.m_vPos2D.x,
			gamePlayerRelativePos.y + gameVariables->g_vLocal.m_vPos2D.y
		);
	};

	cheat.Run();
}
