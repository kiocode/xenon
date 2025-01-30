#include <windows.h>

#include "server.hpp"

#include <xenon/xenon.hpp>
#include <xenon/models/waypoint.hpp>
#include <xenon/components/features/waypoints.hpp>

struct offsets {
	uintptr_t staticServerAddr = 0x5AABA0;
	uintptr_t idLocalPlayer = 0x1450;
	uintptr_t onlinePlayers = 0x1454;
	uintptr_t gametick = 0x147C + 0x0;
	uintptr_t playerPos = 0x147C + 0xE8 + 0x0;

	uintptr_t staticClientAddr = 0x57D630;
	uintptr_t aimPos = 0x10;
};

struct offsets offsets;


static void AddConfigurations(Builder& builder) {

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfigs->g_pRadarConfig;
	pRadarConfig->m_nType = 0;
	pRadarConfig->m_fSize = 200.f;
	pRadarConfig->m_fDefaultScale = 1000.0f;
	pRadarConfig->m_fZoom = 1.0f;
	pRadarConfig->m_fLocalSize = 6.0f;
	pRadarConfig->m_fTargetsSize = 6.0f;
	pRadarConfig->m_bTargetsName = true;

	std::shared_ptr<EspConfig> pESPConfig = builder.xenonConfigs->g_pEspConfig;
	pESPConfig->m_bHealthBar = true;

	std::shared_ptr<Waypoints> pWaypoints = builder.xenon->g_cWaypoints;

	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfigs->g_pUIConfig;
	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints]() {
		ImGui::Begin("Positions");

		for (const auto &target : builder.xenonConfigs->g_pGameVariables->g_vTargets) {
			ImGui::Text("Position: %f, %f", target.m_vPos2D.x, target.m_vPos2D.y);
		}

		ImGui::End();

		ImGui::Begin("Waypoints");

		for (const Waypoint& waypoint : pWaypoints->GetWaypoints()) {
			ImGui::Text("Waypoint: %s, %f, %f", waypoint.m_strName.c_str(), waypoint.m_vPos2D.x, waypoint.m_vPos2D.y);
		}

		ImGui::End();

	});

	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 5);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);
	pUIConfig->m_qActions->AddSlider("Box2d Type", &pESPConfig->m_nBox2DType, 0, 1);

	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfigs->g_pGameVariables;
	pUIConfig->m_qActions->AddButton("Set Waypoint", [pGameVariables, pWaypoints]() { 
		pWaypoints->SetWaypoint("test", pGameVariables->g_vLocal.m_vPos2D, ImColor(255,255,255)); 
	});

}

int main()
{

	Builder builder("DDNet external");
	builder.xenon->g_pSystem->IsInternal(false);
	builder.SetConsoleEnabled();
	builder.SetInfoLogLevel();

	builder.xenon->g_pSystem->SetGameDimension(GameDimensions::DIMENSION_2D);

	try {
		builder.xenon->g_cMemoryService->AttachGame("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	}
	catch (const std::exception& e) {
		builder.xenon->g_cMemoryService->AttachGame("C:\\Program Files (x86)\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	}
	uintptr_t serverAddr = builder.xenon->g_cMemoryService->ReadPointer(offsets.staticServerAddr);
	uintptr_t clientAddr = builder.xenon->g_cMemoryService->ReadPointer(offsets.staticClientAddr);

	if (!serverAddr || !clientAddr) {
		spdlog::error("Failed to find server or client address");
		return 1;
	}

	AddConfigurations(builder);

	Server* server = new Server();

	std::shared_ptr<GameVariables> gameVariables = builder.xenonConfigs->g_pGameVariables;
	std::shared_ptr<System> system = builder.xenon->g_pSystem;
	std::shared_ptr<MemoryService> memoryService = builder.xenon->g_cMemoryService;

	builder.GameManager->OnEvent("Update", [builder, server, serverAddr, gameVariables, memoryService]() {

		server->players.clear();

		server->localPlayerId = memoryService->Read<int>(serverAddr + offsets.idLocalPlayer);
		server->onlinePlayers = memoryService->Read<int>(serverAddr + offsets.onlinePlayers);
		server->localPlayerConnectedToAServer = server->localPlayerId != -1;

		if (!server->localPlayerConnectedToAServer) return;

		int i = 0;
		do {
			Player player;
			player.id = i;
			player.gametick = memoryService->Read<int>(serverAddr + offsets.gametick + (i * 0xF8));
			player.pos.x = memoryService->Read<float>(serverAddr + offsets.playerPos + (i * 0xF8));
			player.pos.y = memoryService->Read<float>(serverAddr + offsets.playerPos + 0x4 + (i * 0xF8));

			server->players.push_back(player);

			i++;
		} while (i != 63); //memoryService->Read<int>(serverAddr + offsets.gametick + (i * 0xF8)) != -1);

		gameVariables->g_vTargets.clear();
		gameVariables->g_vLocal.m_vPos2D = Vec2(server->players[server->localPlayerId].pos.x - 32, server->players[server->localPlayerId].pos.y - 32);
		for (int i = 0; i < server->players.size(); i++) {
			if (server->players[i].gametick == 0 || server->players[i].id == server->localPlayerId) continue;
			
			float distance = gameVariables->g_vLocal.m_vPos2D.Distance(Vec2(server->players[i].pos.x, server->players[i].pos.y));

			float distanceFactor = distance / 15; // to change

			Vec2 originalPos(server->players[i].pos.x, server->players[i].pos.y);
			Vec2 localPos = gameVariables->g_vLocal.m_vPos2D;
			Vec2 direction = (originalPos - localPos).Normalized();
			Vec2 modifiedPos = originalPos + direction * distanceFactor;

			TargetProfile targetProfile;
			targetProfile.m_fWidth = 64;
			targetProfile.m_vPos2D = modifiedPos;
			targetProfile.m_vHeadPos2D = modifiedPos - Vec2(0, 32);;
			targetProfile.m_vFeetPos2D = modifiedPos + Vec2(0, 32);;
			targetProfile.m_strName = "Player " + std::to_string(server->players[i].id);
			targetProfile.m_fHealth = 100;
			gameVariables->g_vTargets.push_back(targetProfile);
		}
	});

	std::shared_ptr<AimConfig> pAimConfig = builder.xenonConfigs->g_pAimConfig;
	pAimConfig->m_fnCustomAim = [builder, clientAddr, memoryService, gameVariables](const Vec2& pos) {
		Vec2 gamePlayerRelativePos = Vec2(pos.x - gameVariables->g_vLocal.m_vPos2D.x, pos.y - gameVariables->g_vLocal.m_vPos2D.y);

		memoryService->Write<float>(clientAddr + offsets.aimPos, gamePlayerRelativePos.x);
		memoryService->Write<float>(clientAddr + offsets.aimPos + 0x4, gamePlayerRelativePos.y);
	};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom();
	cheat.UseUIMenu();
	cheat.UseUIRenderOverlays();
	cheat.UseUIQuickActions();

	system->m_fnW2S2D = [builder, gameVariables, system](Vec2 pos) -> Vec2* {
		int playerSize = 64;
		Vec2 gamePlayerRelativePos = Vec2(
			pos.x - gameVariables->g_vLocal.m_vPos2D.x,
			pos.y - gameVariables->g_vLocal.m_vPos2D.y
		);

		return new Vec2(
			(gamePlayerRelativePos.x + system->GetScreenCenter().x) - playerSize / 2,
			(gamePlayerRelativePos.y + system->GetScreenCenter().y) - playerSize / 2
		);
	};

	cheat.Run();
}
