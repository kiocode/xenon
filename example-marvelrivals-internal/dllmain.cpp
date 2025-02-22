#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/features/aimbot.hpp>
#include <xenon/models/waypoint.hpp>
#include <xenon/xenon.hpp>
#include <spdlog/spdlog.h>

#include "MarvelRivalsDump/SDK.hpp"

inline static SDK::UEngine* m_pEngine;
inline static SDK::UWorld* m_pWorld;
inline static SDK::APlayerController* m_pMyController;
inline static SDK::APawn* m_pMyPawn;
inline static SDK::ACharacter* m_pMyCharacter;

float width = 3000;
float distanceScale = 0.08f;
float head = 90;
float feet = -90;

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

	Builder builder("Marvel Rivals internal");

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
	std::shared_ptr<CWaypoints> pWaypoints = builder.xenon->g_cWaypoints;
	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
	std::shared_ptr<System> pSystem = builder.xenon->g_pSystem;
	pSystem->IsInternal(true);
	pSystem->IsUnrealEngine(UnrealEngineVersion::UE4);

	builder.SetInfoLogLevel();
	builder.SetConsoleEnabled();

	pSystem->SetGameDimension(GameDimension::DIM_3D);
	pSystem->SetRenderingType(RenderingType::DX12);
	pSystem->m_fnW2S3D = [](Vec3 pos) {
		SDK::FVector2D screenPos;
		SDK::FVector unrealPos(pos.x, pos.z, pos.y);
		if (m_pMyController->ProjectWorldLocationToScreen(unrealPos, &screenPos, false)) {
			return Vec2(screenPos.X, screenPos.Y);
		}
		else {
			return Vec2(-99, -99);
		}
	};

	builder.xenonConfig->g_pAimConfig->m_fDistanceScale = distanceScale;
	builder.xenonConfig->g_pEspConfig->m_fHealthBarWidth = 35;

	pUIConfig->m_qActions->AddSlider("Scale", &width, 0.01, 2);
	pUIConfig->m_qActions->AddSlider("Player Width", &width, 100, 9999);
	pUIConfig->m_qActions->AddSlider("Player Head", &head, 5, 200);
	pUIConfig->m_qActions->AddSlider("Player Feet", &feet, 5, 200);
	pUIConfig->m_qActions->AddSlider("Radar Zoom", &pRadarConfig->m_fZoom, 0.3, 5);
	pUIConfig->m_qActions->AddButton("Reset Radar Zoom", [pRadarConfig]() { pRadarConfig->m_fZoom = 1; });
	pUIConfig->m_qActions->AddSlider("Radar Type", &pRadarConfig->m_nType, 0, 1);

	pUIConfig->m_qActions->AddButton("Set Waypoint", [pGameVariables, pWaypoints]() {
		pWaypoints->SetWaypoint("test", pGameVariables->g_vLocal.m_vPos3D, ImColor(255, 255, 255));
	});


	builder.GameManager->OnEvent("Update", [builder, pGameVariables]() {
		if(!FetchSDK()) return;
		
		pGameVariables->g_vTargets.clear();

		SDK::FVector myPos = m_pMyCharacter->K2_GetActorLocation();
		pGameVariables->g_vLocal.m_vPos3D = Vec3(myPos.X, myPos.Z, myPos.Y);

		for (int i = 0; i < SDK::UObject::GObjects->Num(); i++) {
			SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);

			if (!obj || obj == nullptr || obj->IsDefaultObject()) continue;
			if (!obj->IsA(SDK::APlayerController::StaticClass())) continue;

			SDK::APlayerController* npc = static_cast<SDK::APlayerController*>(obj);
			if (npc->Character->Controller && npc->Character->Controller->IsLocalPlayerController()) continue;

			if (!npc || npc == nullptr || npc->GetLifeSpan() <= 0) continue;

			SDK::FVector unrealTargetPos = npc->K2_GetActorLocation();

			if (unrealTargetPos.X == 0 || unrealTargetPos.Y == 0 || unrealTargetPos.Z == 0) continue;

			TargetProfile targetProfile;
			targetProfile.m_fWidth = width;
			targetProfile.m_vHeadPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Z + head, unrealTargetPos.Y);
			targetProfile.m_vFeetPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Z + feet, unrealTargetPos.Y);
			targetProfile.m_vPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Z, unrealTargetPos.Y);
			targetProfile.m_strName = npc->GetName();
			targetProfile.m_fHealth = npc->GetLifeSpan();
			pGameVariables->g_vTargets.push_back(targetProfile);
		}
	});

    Cheat cheat = builder.Build();
    cheat.UseUICustom(RenderingHookType::KIERO);
    cheat.UseUIMenu();
    cheat.UseUIRenderMouse();
	cheat.UseUIRenderEnabledCheats();
	cheat.UseUIQuickActions();

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

