#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/features/waypoints.hpp>
#include <xenon/models/waypoint.hpp>

#include "AmongUsDump/il2cpp.h"
#include <il2cpp_resolver/il2cpp_resolver.hpp>

intptr_t m_pBase = 0;
intptr_t m_pGameAssembly = 0;
intptr_t m_pUnityPlayer = 0;

float scale = 1.f;

static bool FetchSDK() {

	m_pBase = (intptr_t)GetModuleHandle(NULL);
	if (m_pBase == 0) {
		//spdlog::error("Failed to get base address");
		return false;
	}

	m_pGameAssembly = (intptr_t)GetModuleHandle("GameAssembly.dll");
	if (m_pGameAssembly == 0) {
		//spdlog::error("Failed to get GameAssembly address");
		return false;
	}

	m_pUnityPlayer = (intptr_t)GetModuleHandle("UnityPlayer.dll");
	if (m_pUnityPlayer == 0) {
		//spdlog::error("Failed to get UnityPlayer address");
		return false;
	}

	return true;

}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

    Builder builder("AmongUs internal");
    builder.xenon->g_pSystem->IsInternal(true);
    builder.xenon->g_pSystem->IsUnityEngine(UnityEngineType::IL2CPP);

	if (IL2CPP::Initialize(true)) {
		std::cout << "Il2Cpp initialized\n" << std::endl;
	}
	else {
		std::cout << "Il2Cpp initialize failed, quitting..." << std::endl;
		Sleep(300);
		exit(0);
	}
	if (!FetchSDK()) return FALSE;


	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
	std::shared_ptr<Waypoints> pWaypoints = builder.xenon->g_cWaypoints;
	std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
	std::shared_ptr<System> pSystem = builder.xenon->g_pSystem;

    pSystem->SetGameDimension(GameDimension::DIM_3D);
    pSystem->SetRenderingType(RenderingType::DX11);
	pSystem->m_fnW2S3D = [pSystem, pGameVariables](Vec3 pos) {
		Unity::CCamera* cam = Unity::Camera::GetMain();

		float screenWidth = pSystem->GetScreenResolution().x;
		float screenHeight = pSystem->GetScreenResolution().y;

		float x = (pos.x - pGameVariables->g_vLocal.m_vPos3D.x) * (screenWidth / cam->GetOrthographicSize()) * 0.3;
		float y = (pos.y - pGameVariables->g_vLocal.m_vPos3D.y) * (screenHeight / cam->GetOrthographicSize()) * 0.5;

		return new Vec2(screenWidth / 2 + x, screenHeight / 2 - y);
	};

	builder.SetInfoLogLevel();
    builder.SetConsoleEnabled();

	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints, pGameVariables]() {
		ImGui::Begin("AmongUs internal");

		ImGui::Text("Base: 0x%llx", m_pBase);
		ImGui::Text("GameAssembly: 0x%llx", m_pGameAssembly);
		ImGui::Text("UnityPlayer: 0x%llx", m_pUnityPlayer);

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

	pUIConfig->m_qActions->AddSlider("Scale", &scale, 0.1f, 10.f);

	builder.GameManager->OnEvent("Update", [builder, pGameVariables]() {
		
		pGameVariables->g_vTargets.clear();

		Unity::il2cppArray<Unity::CComponent*>* pTargets = Unity::Object::FindObjectsOfType<Unity::CComponent>("PlayerControl");
		if (!pTargets) return;

		for (int i = 0; i < pTargets->m_uMaxLength; i++) {
			PlayerControl_o* current = reinterpret_cast<PlayerControl_o*>(pTargets->operator[](i));
			if (!current) continue;

			auto currTargetPos = pTargets->operator[](i)->GetTransform()->GetPosition();

			TargetProfile targetProfile;
			targetProfile.m_fWidth = 70.f;
			targetProfile.m_bTemmate = false;
			targetProfile.m_vHeadPos3D = Vec3(currTargetPos.x, currTargetPos.y + .35f, currTargetPos.z);
			targetProfile.m_vFeetPos3D = Vec3(currTargetPos.x, currTargetPos.y - .35f, currTargetPos.z);
			targetProfile.m_vPos3D = Vec3(currTargetPos.x, currTargetPos.y, currTargetPos.z);

			char buffer[64];
			sprintf_s(buffer, "Player %d", i);
			targetProfile.m_strName = buffer;

			if (current->fields.cosmetics->fields.localPlayer) {
				pGameVariables->g_vLocal = targetProfile;
				auto &flashlight = current->fields.lightSource;
				if (flashlight != nullptr) {
					flashlight->fields.useFlashlight = true;
					flashlight->fields.flashlightSize = 1000.f;
				}

			} else {
				pGameVariables->g_vTargets.push_back(targetProfile);
			}
		}
	});

    Cheat cheat = builder.Build();
    cheat.UseUICustom(RenderingHookType::KIERO);
    cheat.UseUIMenu();
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

