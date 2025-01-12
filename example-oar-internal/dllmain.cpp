#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <spdlog/spdlog.hpp>

#include "OARDump/SDK.hpp"

inline static SDK::UEngine* m_pEngine;
inline static SDK::UWorld* m_pWorld;
inline static SDK::APlayerController* m_pMyController;
inline static SDK::APawn* m_pMyPawn;
inline static SDK::ACharacter* m_pMyCharacter;

static bool FetchSDK() {
    m_pEngine = SDK::UEngine::GetEngine();
    m_pWorld = SDK::UWorld::GetWorld();

    if (!m_pEngine || m_pEngine == nullptr || !m_pWorld || m_pWorld == nullptr) {
        spdlog::error("Failed to get engine or world");
        return false;
    }

    if (!m_pWorld->OwningGameInstance) {
		spdlog::error("Failed to get game instance");
		return false;
	}

    if (!m_pWorld->OwningGameInstance->LocalPlayers.Num()) {
		spdlog::error("Failed to get local players");
		return false;
	}

    m_pMyController = m_pWorld->OwningGameInstance->LocalPlayers[0]->PlayerController;
    if (!m_pMyController || m_pMyController == nullptr) {
		spdlog::error("Failed to get controller");
		return false;
	}

	m_pMyPawn = m_pMyController->AcknowledgedPawn;
    if (!m_pMyPawn || m_pMyPawn == nullptr) {
		spdlog::error("Failed to get pawn");
		return false;
	}

	m_pMyCharacter = m_pMyController->Character;
    if (!m_pMyCharacter || m_pMyCharacter == nullptr) {
		spdlog::error("Failed to get character");
		return false;
	}

	return true;

}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

    Builder builder("OAR internal");
    builder.SystemVariables->IsInternal(true);
    builder.SystemVariables->IsUnrealEngine(UnrealEngineVersions::UE4);
    builder.SystemVariables->SetGameDimension(GameDimensions::DIMENSION_3D);
    builder.SystemVariables->SetRenderingType(RenderingTypes::DX11);
	builder.SystemVariables->m_fnW2S3D = [](Vec3 pos) {
		SDK::FVector2D screenPos;
		if (m_pMyController->ProjectWorldLocationToScreen(SDK::FVector(pos.x, pos.y, pos.z), &screenPos, false)) {
			return new Vec2(screenPos.X, screenPos.Y);
		}
		else {
			return new Vec2(-99, -99);
		}
	};

	builder.SetDebugLogLevel();
    builder.SetConsoleEnabled();

	builder.Services->GetConfiguration<UIConfig>()->m_vFnOverlays.push_back([builder]() {
		ImGui::Begin("OAR internal");

		ImGui::Text("Engine: %p", m_pEngine);
		ImGui::Text("World: %p", m_pWorld);
		ImGui::Text("Controller: %p", m_pMyController);
		ImGui::Text("Pawn: %p", m_pMyPawn);
		ImGui::Text("Character: %p", m_pMyCharacter);

		ImGui::Separator();

		ImGui::Text("Targets: %d", builder.GameGlobalVariables->g_vTargets.size());
		for (auto& target : builder.GameGlobalVariables->g_vTargets) {
			ImGui::Text("Name: %s", target.m_strName.c_str());
			ImGui::Text("Health: %f", target.m_fHealth);
			ImGui::Text("Pos: %f %f %f", target.m_vPos3D.x, target.m_vPos3D.y, target.m_vPos3D.z);
		}

		ImGui::End();
	});

	builder.GameManager->OnEvent("Update", [builder]() {
		if(!FetchSDK()) return;
		
		builder.GameGlobalVariables->g_vTargets.clear();

		SDK::FVector myPos = m_pMyCharacter->K2_GetActorLocation();
		builder.GameGlobalVariables->g_vLocal.m_vPos3D = Vec3(myPos.X, myPos.Y, myPos.Z);

		for (int i = 0; i < SDK::UObject::GObjects->Num(); i++) {
			SDK::UObject* obj = SDK::UObject::GObjects->GetByIndex(i);

			if (!obj || obj == nullptr || obj->IsDefaultObject()) continue;
			if (!obj->IsA(SDK::ANPCBase_C::StaticClass())) continue;

			SDK::ANPCBase_C* npc = static_cast<SDK::ANPCBase_C*>(obj);
			if (npc->Controller && npc->Controller->IsLocalPlayerController()) continue;

			if (!npc || npc == nullptr || npc->Health <= 0 || npc->Dead_) continue;

			SDK::FVector unrealTargetPos = npc->K2_GetActorLocation();

			TargetProfile targetProfile;
			targetProfile.m_vPos3D = Vec3(unrealTargetPos.X, unrealTargetPos.Y, unrealTargetPos.Z);
			targetProfile.m_strName = npc->GetName();
			targetProfile.m_fHealth = npc->Health;
			builder.GameGlobalVariables->g_vTargets.push_back(targetProfile);
		}
	});

    Cheat cheat = builder.Build();
    cheat.UseUICustom(RenderingHookTypes::KIERO);
    cheat.UseUIMenu();
    cheat.UseUIRenderMouse();
	cheat.UseESPSnapline();
	cheat.UseUIRenderOverlays();

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

