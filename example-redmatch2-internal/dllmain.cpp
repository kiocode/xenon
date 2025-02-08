#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/features/waypoints.hpp>
#include <xenon/models/waypoint.hpp>
#include <il2cpp_resolver/il2cpp_resolver.hpp>

#include "RedMatch2Dump/il2cpp.h"


DWORD WINAPI MainThread(LPVOID lpReserved)
{

	Builder builder("RedMatch2 internal");

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
	std::shared_ptr<CWaypoints> pWaypoints = builder.xenon->g_cWaypoints;
	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
	std::shared_ptr<System> pSystem = builder.xenon->g_pSystem;

	pSystem->IsInternal(true);
	pSystem->IsUnityEngine(UnityEngineType::IL2CPP);

	builder.SetInfoLogLevel();
	builder.SetConsoleEnabled();

	pSystem->SetGameDimension(GameDimension::DIM_3D);
	pSystem->SetRenderingType(RenderingType::DX11);
	pSystem->m_fnW2S3D = [pSystem, pGameVariables](Vec3 pos) {
		Unity::Vector3 screenPos;
		Unity::Vector3 unityPos = Unity::Vector3(pos.x, pos.y, pos.z);
		Unity::Camera::GetMain()->WorldToScreen(unityPos, screenPos);

		return new Vec2(screenPos.x, screenPos.y);
	};

	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints, pGameVariables, pSystem]() {
		ImGui::Begin("RedMatch2 internal");

		ImGui::Text("Base: 0x%llx", pSystem->g_pUnityBase);
		ImGui::Text("GameAssembly: 0x%llx", pSystem->g_pUnityGameAssembly);
		ImGui::Text("UnityPlayer: 0x%llx", pSystem->g_pUnityPlayer);

		ImGui::Separator();

		ImGui::Text("LocalPlayer:");
		ImGui::Text("Name: %s", pGameVariables->g_vLocal.m_strName.c_str());
		ImGui::Text("Pos: %f %f %f", pGameVariables->g_vLocal.m_vPos3D.x, pGameVariables->g_vLocal.m_vPos3D.y, pGameVariables->g_vLocal.m_vPos3D.z);

		ImGui::Separator();

		ImGui::Text("Targets: %d", pGameVariables->g_vTargets.size());
		for (auto& target : pGameVariables->g_vTargets) {
			ImGui::Text("Name: %s", target.m_strName.c_str());
			ImGui::Text("Pos: %f %f %f", target.m_vPos3D.x, target.m_vPos3D.y, target.m_vPos3D.z);
		}

		ImGui::End();

		ImGui::Begin("Waypoints");

		for (const Waypoint& waypoint : pWaypoints->GetWaypoints()) {
			ImGui::Text("Waypoint: %s, %f, %f, %f", waypoint.m_strName.c_str(), waypoint.m_vPos3D.x, waypoint.m_vPos3D.y, waypoint.m_vPos3D.z);
		}

		ImGui::End();
	});

	builder.GameManager->OnEvent("Update", [builder, pGameVariables]() {

		pGameVariables->g_vTargets.clear();

		//Unity::Vector3 cameraPos = Unity::Camera::GetMain()->GetTransform()->GetPosition();

		//pGameVariables->g_vLocal.m_vPos3D = Vec3(cameraPos.x, cameraPos.y, cameraPos.z);

		Unity::il2cppArray<Unity::CComponent*>* pTargets = Unity::Object::FindObjectsOfType<Unity::CComponent>("PlayerController");
		if (!pTargets) return;

		for (int i = 0; i < pTargets->m_uMaxLength; i++) {
			PlayerController_o* current = reinterpret_cast<PlayerController_o*>(pTargets->operator[](i));
			if (!current) continue;

			auto currTargetPos = pTargets->operator[](i)->GetTransform()->GetPosition();

			TargetProfile targetProfile;
			targetProfile.m_fWidth = 70.f;
			targetProfile.m_bTemmate = false;
			targetProfile.m_vHeadPos3D = Vec3(currTargetPos.x, currTargetPos.y + 2, currTargetPos.z);
			targetProfile.m_vFeetPos3D = Vec3(currTargetPos.x, currTargetPos.y - 2, currTargetPos.z);
			targetProfile.m_vPos3D = Vec3(currTargetPos.x, currTargetPos.y, currTargetPos.z);

			char buffer[64];
			sprintf_s(buffer, "Player %d", i);
			targetProfile.m_strName = buffer;

			pGameVariables->g_vTargets.push_back(targetProfile);
			
		}
	});

	Cheat cheat = builder.Build();
	cheat.UseUICustom(RenderingHookType::KIERO);
	cheat.UseUIMenu();
	cheat.UseUIRenderOverlays();
	cheat.UseUIRenderMouse();

	cheat.Run();

	if (IL2CPP::Initialize(true)) {
		spdlog::info("Il2Cpp initialize success.");
	}
	else {
		spdlog::error("Il2Cpp initialize failed.");
		Sleep(300);
		exit(0);
	}
	if (!cheat.FetchSDK()) return FALSE;

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

