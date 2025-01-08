#include <windows.h>

#include "server.hpp"

#include <xenon/xenon.hpp>

struct offsets {
	uintptr_t staticServerAddr = 0x5ABBA0;
	uintptr_t idLocalPlayer = 0x1450;
	uintptr_t onlinePlayers = 0x1454;
	uintptr_t gametick = 0x147C + 0x0;
	uintptr_t playerPos = 0x147C + 0xE8 + 0x0;

	uintptr_t staticClientAddr = 0x455C40;
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

	std::shared_ptr<ESPConfig> pESPConfig = builder.Services->GetConfiguration<ESPConfig>();

	std::shared_ptr<UIConfig> pUIConfig = builder.Services->GetConfiguration<UIConfig>();
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

int main()
{

	Builder builder("DDNet external");
	builder.SystemVariables->IsInternal(false);
	builder.SetConsoleEnabled();
	builder.SetDebugLogLevel();


	builder.MemoryManager->AttachGame("D:\\Steam\\steamapps\\common\\DDraceNetwork\\ddnet\\DDNet.exe");
	uintptr_t serverAddr = builder.MemoryManager->ReadPointer(offsets.staticServerAddr);
	uintptr_t clientAddr = builder.MemoryManager->ReadPointer(offsets.staticClientAddr);

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
	pAimConfig->m_fnCustomAim = [builder, clientAddr](const Vec2& pos) {
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos, pos.x);
		builder.MemoryManager->Write<float>(clientAddr + offsets.aimPos + 0x4, pos.y);
	};

	Cheat cheat = builder.Build();

	cheat.UseUpdate();
	cheat.UseUICustom(RenderingHookTypes::KIERO);
	cheat.UseUIRenderOverlays();
	cheat.UseUIRadar();
	cheat.UseUIQuickActions();
	cheat.UseESPSnapline();
	cheat.UseESPBox2D();
	//cheat.UseAimbot();

	cheat.Run();
}
