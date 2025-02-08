#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/features/waypoints.hpp>
#include <xenon/models/waypoint.hpp>
//#include <il2cpp_resolver/il2cpp_resolver.hpp>

#include "AmongUsDump/il2cpp.h"


DWORD WINAPI MainThread(LPVOID lpReserved)
{

    Builder builder("AmongUs internal");

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	pRadarConfig->m_fDefaultScale = 10;
	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
	std::shared_ptr<CWaypoints> pWaypoints = builder.xenon->g_cWaypoints;
	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
	std::shared_ptr<System> pSystem = builder.xenon->g_pSystem;

    pSystem->IsInternal(true);
    pSystem->IsUnityEngine(UnityEngineType::IL2CPP, true);

	builder.SetInfoLogLevel();
	builder.SetConsoleEnabled();

    pSystem->SetGameDimension(GameDimension::DIM_2D);
    pSystem->SetRenderingType(RenderingType::DX11);
	//pSystem->m_fnW2S2D = [pSystem, pGameVariables](Vec2 pos) {
	//	Unity::CCamera* cam = Unity::Camera::GetMain();

	//	float screenWidth = pSystem->GetScreenResolution().x;
	//	float screenHeight = pSystem->GetScreenResolution().y;

	//	float x = (pos.x - pGameVariables->g_vLocal.m_vPos2D.x) * (screenWidth / cam->GetOrthographicSize()) * 0.3;
	//	float y = (pos.y - pGameVariables->g_vLocal.m_vPos2D.y) * (screenHeight / cam->GetOrthographicSize()) * 0.4;

	//	return new Vec2(screenWidth / 2 + x, screenHeight / 2 - y);
	//};

	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints, pGameVariables, pSystem]() {
		ImGui::Begin("AmongUs internal");

		ImGui::Text("Base: 0x%llx", pSystem->g_pUnityBase);
		ImGui::Text("GameAssembly: 0x%llx", pSystem->g_pUnityGameAssembly);
		ImGui::Text("UnityPlayer: 0x%llx", pSystem->g_pUnityPlayer);

		ImGui::Separator();

		ImGui::Text("LocalPlayer:");
		ImGui::Text("Name: %s", pGameVariables->g_vLocal.m_strName.c_str());
		ImGui::Text("Pos: %f %f", pGameVariables->g_vLocal.m_vPos2D.x, pGameVariables->g_vLocal.m_vPos2D.y);

		ImGui::Separator();

		ImGui::Text("Targets: %d", pGameVariables->g_vTargets.size());
		for (auto& target : pGameVariables->g_vTargets) {
			ImGui::Text("Name: %s", target.m_strName.c_str());
			ImGui::Text("Pos: %f %f", target.m_vPos2D.x, target.m_vPos2D.y);
		}

		ImGui::End();

		ImGui::Begin("Waypoints");

		for (const Waypoint& waypoint : pWaypoints->GetWaypoints()) {
			ImGui::Text("Waypoint: %s, %f, %f", waypoint.m_strName.c_str(), waypoint.m_vPos2D.x, waypoint.m_vPos2D.y);
		}

		ImGui::End();
	});

	//builder.GameManager->OnEvent("Update", [builder, pGameVariables]() {
	//	
	//	pGameVariables->g_vTargets.clear();

	//	Unity::il2cppArray<Unity::CComponent*>* pTargets = Unity::Object::FindObjectsOfType<Unity::CComponent>("PlayerControl");
	//	if (!pTargets) return;

	//	for (int i = 0; i < pTargets->m_uMaxLength; i++) {
	//		PlayerControl_o* current = reinterpret_cast<PlayerControl_o*>(pTargets->operator[](i));
	//		if (!current) continue;

	//		auto currTargetPos = pTargets->operator[](i)->GetTransform()->GetPosition();

	//		TargetProfile targetProfile;
	//		targetProfile.m_fWidth = 70.f;
	//		targetProfile.m_bTemmate = false;
	//		targetProfile.m_vHeadPos2D = Vec2(currTargetPos.x, currTargetPos.y + .35f);
	//		targetProfile.m_vFeetPos2D = Vec2(currTargetPos.x, currTargetPos.y - .35f);
	//		targetProfile.m_vPos2D = Vec2(currTargetPos.x, currTargetPos.y);

	//		char buffer[64];
	//		sprintf_s(buffer, "Player %d", i);
	//		targetProfile.m_strName = buffer;

	//		if (current->fields.cosmetics->fields.localPlayer) {
	//			pGameVariables->g_vLocal = targetProfile;
	//			//auto &flashlight = current->fields.lightSource;
	//			//if (flashlight != nullptr) {
	//			//	flashlight->fields.useFlashlight = true;
	//			//	flashlight->fields.flashlightSize = 1000.f;
	//			//}
	//		} else {
	//			pGameVariables->g_vTargets.push_back(targetProfile);
	//		}
	//	}
	//});

    Cheat cheat = builder.Build();
    cheat.UseUICustom(RenderingHookType::KIERO);
    cheat.UseUIMenu();

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

