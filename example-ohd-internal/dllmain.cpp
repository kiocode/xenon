#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <spdlog/spdlog.h>

#include "OHDDump/SDK.hpp"

inline static SDK::UEngine* m_pEngine;
inline static SDK::UWorld* m_pWorld;
inline static SDK::APlayerController* m_pMyController;
inline static SDK::APawn* m_pMyPawn;
inline static SDK::ACharacter* m_pMyCharacter;

static bool FetchSDK() {
	m_pEngine = SDK::UEngine::GetEngine();
	m_pWorld = SDK::UWorld::GetWorld();

	if (!m_pEngine || m_pEngine == nullptr || !m_pWorld || m_pWorld == nullptr) {
		//spdlog::error("Failed to get engine or world");
		return false;
	}

	if (!m_pWorld->OwningGameInstance) {
		//spdlog::error("Failed to get game instance");
		return false;
	}

	if (!m_pWorld->OwningGameInstance->LocalPlayers.Num()) {
		//spdlog::error("Failed to get local players");
		return false;
	}

	m_pMyController = m_pWorld->OwningGameInstance->LocalPlayers[0]->PlayerController;
	if (!m_pMyController || m_pMyController == nullptr) {
		//spdlog::error("Failed to get controller");
		return false;
	}

	m_pMyPawn = m_pMyController->AcknowledgedPawn;
	if (!m_pMyPawn || m_pMyPawn == nullptr) {
		//spdlog::error("Failed to get pawn");
		return false;
	}

	m_pMyCharacter = m_pMyController->Character;
	if (!m_pMyCharacter || m_pMyCharacter == nullptr) {
		//spdlog::error("Failed to get character");
		return false;
	}

	return true;

}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	Builder builder("OHD internal");
	builder.SystemVariables->IsInternal(true);
	builder.SystemVariables->IsUnrealEngine(UnrealEngineVersions::UE4);
	builder.SystemVariables->SetGameDimension(GameDimensions::DIMENSION_3D);
	builder.SystemVariables->SetRenderingType(RenderingTypes::DX11);
	builder.SystemVariables->m_fnW2S3D = [](Vec3 pos) {
		SDK::FVector2D screenPos;
		SDK::FVector unrealPos(pos.x, pos.z, pos.y);
		if (m_pMyController->ProjectWorldLocationToScreen(unrealPos, &screenPos, false)) {
			return new Vec2(screenPos.X, screenPos.Y);
		}
		else {
			return new Vec2(-99, -99);
		}
	};

	builder.SetInfoLogLevel();
	builder.SetConsoleEnabled();

	std::shared_ptr<RadarConfig> pRadarConfig = builder.Services->GetConfiguration<RadarConfig>();
	std::shared_ptr<UIConfig> pUIConfig = builder.Services->GetConfiguration<UIConfig>();
	std::shared_ptr<Waypoints> pWaypoints = builder.Services->GetService<Waypoints>();

	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints]() {
		ImGui::Begin("OHD internal");

		ImGui::Text("Engine: %p", m_pEngine);
		ImGui::Text("World: %p", m_pWorld);
		ImGui::Text("Controller: %p", m_pMyController);
		ImGui::Text("Pawn: %p", m_pMyPawn);
		ImGui::Text("Character: %p", m_pMyCharacter);

		ImGui::Separator();

		ImGui::Text("Targets: %d", builder.GameGlobalVariables->g_vTargets.size());
		for (auto& target : builder.GameGlobalVariables->g_vTargets) {
			ImGui::Text("Name: %s", target.m_strName.c_str());
			ImGui::SameLine();
			ImGui::Text(" - Health: %f", target.m_fHealth);
			ImGui::Text("Pos: %f %f %f", target.m_vPos3D.x, target.m_vPos3D.y, target.m_vPos3D.z);
		}

		ImGui::End();

		ImGui::Begin("Waypoints");

		for (const Waypoint& waypoint : pWaypoints->GetWaypoints()) {
			ImGui::Text("Waypoint: %s, %f, %f, %f", waypoint.m_strName.c_str(), waypoint.m_vPos3D.x, waypoint.m_vPos3D.y, waypoint.m_vPos3D.z);
		}

		ImGui::End();
		});

	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 5);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);

	std::shared_ptr<GameVariables> pGameVariables = builder.Services->GetConfiguration<GameVariables>();
	pUIConfig->m_qActions->AddButton("Set Waypoint", [pGameVariables, pWaypoints]() {
		pWaypoints->SetWaypoint("test", pGameVariables->g_vLocal.m_vPos3D, ImColor(255, 255, 255));
	});


	builder.GameManager->OnEvent("Update", [builder]() {
		if (!FetchSDK()) return;

		builder.GameGlobalVariables->g_vTargets.clear();

		SDK::FVector myPos = m_pMyCharacter->K2_GetActorLocation();
		builder.GameGlobalVariables->g_vLocal.m_vPos3D = Vec3(myPos.X, myPos.Z, myPos.Y);

		for (int i = 0; i < SDK::UObject::GObjects->Num(); i++) {
			SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);

			if (!obj || obj == nullptr || obj->IsDefaultObject()) continue;
			if (!obj->IsA(SDK::AHDPlayerCharacter::StaticClass())) continue;

			SDK::AHDPlayerCharacter* npc = static_cast<SDK::AHDPlayerCharacter*>(obj);
			if (npc->Controller && npc->Controller->IsLocalPlayerController()) continue;

			if (!npc || npc == nullptr || npc->Health <= 0) continue;

			SDK::FVector unrealTargetPos = npc->K2_GetActorLocation();

			if (unrealTargetPos.X == 0 || unrealTargetPos.Y == 0 || unrealTargetPos.Z == 0) continue;

			TargetProfile targetProfile;
			targetProfile.m_vPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Z, unrealTargetPos.Y);

			if (targetProfile.m_vPos3D.Distance(builder.GameGlobalVariables->g_vLocal.m_vPos3D) > 10000) {
				return;
			}

			targetProfile.m_vHeadPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Z - 100, unrealTargetPos.Y);
			targetProfile.m_vFeetPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Z + 100, unrealTargetPos.Y);
			targetProfile.m_fWidth = 50;
			targetProfile.m_strName = npc->GetName();
			targetProfile.m_fHealth = npc->Health;
			targetProfile.m_strTag = "NPC";
			builder.GameGlobalVariables->g_vTargets.push_back(targetProfile);
		}
	});

	Cheat cheat = builder.Build();
	cheat.UseUICustom(RenderingHookTypes::KIERO);
	cheat.UseUIMenu();
	cheat.UseUIRadar();
	cheat.UseUIRenderMouse();
	cheat.UseESPSnapline();
	cheat.UseESPBox2D();
	cheat.UseESPHealthBar();
	cheat.UseUIRenderOverlays();
	cheat.UseUIQuickActions();
	//cheat.UseAimbot();

	cheat.Run();

	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dReasonForCall, LPVOID lpReserved)
{
	switch (dReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

