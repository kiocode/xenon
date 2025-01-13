#include <windows.h>

#include "server.hpp"

#include <xenon/xenon.hpp>
#include <xenon/features/waypoints.hpp>
#include <xenon/models/waypoint.hpp>

struct offsets {
	uintptr_t staticServerAddr = 0x5AABA0 ;
	uintptr_t idLocalPlayer = 0x1450;
	uintptr_t onlinePlayers = 0x1454;
	uintptr_t gametick = 0x147C + 0x0;
	uintptr_t playerPos = 0x147C + 0xE8 + 0x0;

	uintptr_t staticClientAddr = 0x57D630;
	uintptr_t aimPos = 0x10;
};

struct offsets offsets;


static void AddConfigurations(Builder& builder) {

	std::shared_ptr<RadarConfig> pRadarConfig = builder.Services->GetConfiguration<RadarConfig>();
	pRadarConfig->m_nType = 0;
	pRadarConfig->m_fSize = 200.f;
	pRadarConfig->m_fDefaultScale = 1000.0f;
	pRadarConfig->m_fZoom = 1.0f;
	pRadarConfig->m_fLocalSize = 6.0f;
	pRadarConfig->m_fTargetsSize = 6.0f;
	pRadarConfig->m_bTargetsName = true;

	std::shared_ptr<ESPConfig> pESPConfig = builder.Services->GetConfiguration<ESPConfig>();
	pESPConfig->m_bHealthBar = true;

	std::shared_ptr<Waypoints> pWaypoints = builder.Services->GetService<Waypoints>();

	std::shared_ptr<UIConfig> pUIConfig = builder.Services->GetConfiguration<UIConfig>();
	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints]() {
		ImGui::Begin("Positions");

		for (const auto &target : builder.GameGlobalVariables->g_vTargets) {
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

	std::shared_ptr<GameVariables> pGameVariables = builder.Services->GetConfiguration<GameVariables>();
	pUIConfig->m_qActions->AddButton("Set Waypoint", [pGameVariables, pWaypoints]() { 
		pWaypoints->SetWaypoint("test", pGameVariables->g_vLocal.m_vPos2D, ImColor(255,255,255)); 
	});

}

int main()
{

	Builder builder("DDNet external");
	builder.SystemVariables->IsInternal(false);
	builder.SetConsoleEnabled();
	builder.SetDebugLogLevel();

	builder.SystemVariables->SetGameDimension(GameDimensions::DIMENSION_2D);

	builder.MemoryManager->AttachGame("C:\\Program Files (x86)\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	uintptr_t serverAddr = builder.MemoryManager->ReadPointer(offsets.staticServerAddr);
	uintptr_t clientAddr = builder.MemoryManager->ReadPointer(offsets.staticClientAddr);

	if (!serverAddr || !clientAddr) {
		spdlog::error("Failed to find server or client address");
		return 1;
	}

	AddConfigurations(builder);

	Server* server = new Server();

	builder.GameManager->OnEvent("Update", [builder, server, serverAddr]() {

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

		builder.GameGlobalVariables->g_vTargets.clear();
		builder.GameGlobalVariables->g_vLocal.m_vPos2D = server->players[server->localPlayerId].pos;
		for (int i = 0; i < server->players.size(); i++) {
			if (server->players[i].gametick == 0 || server->players[i].id == server->localPlayerId) continue;

			TargetProfile targetProfile;
			targetProfile.m_vPos2D = server->players[i].pos;
			targetProfile.m_strName = "Player " + std::to_string(server->players[i].id);
			targetProfile.m_fHealth = 100;
			builder.GameGlobalVariables->g_vTargets.push_back(targetProfile);
		}
	});

	std::shared_ptr<AimConfig> pAimConfig = builder.Services->GetConfiguration<AimConfig>();
	pAimConfig->m_fnCustomAim = [builder, clientAddr](const Vec2& pos) {

		Vec2 gamePlayerRelativePos = Vec2(pos.x - builder.GameGlobalVariables->g_vLocal.m_vPos2D.x, pos.y - builder.GameGlobalVariables->g_vLocal.m_vPos2D.y);

		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos, gamePlayerRelativePos.x);
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos + 0x4, gamePlayerRelativePos.y);
	};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookTypes::KIERO);
	cheat.UseUIMenu();
	//cheat.UseUIRenderOverlays();
	//cheat.UseUIRadar();
	//cheat.UseUIQuickActions();
	//cheat.UseESPSnapline();
	//cheat.UseESPBox2D();
	//cheat.UseAimbot();

	builder.SystemVariables->m_fnW2S2D = [builder](Vec2 pos) -> Vec2* {
		int playerSize = 64;
		Vec2 gamePlayerRelativePos = Vec2(
			pos.x - builder.GameGlobalVariables->g_vLocal.m_vPos2D.x,
			pos.y - builder.GameGlobalVariables->g_vLocal.m_vPos2D.y
		);

		return new Vec2(
			(gamePlayerRelativePos.x + builder.Services->GetService<System>()->GetScreenCenter().x) - playerSize / 2,
			(gamePlayerRelativePos.y + builder.Services->GetService<System>()->GetScreenCenter().y) - playerSize / 2
		);
	};

	cheat.Run();
}
