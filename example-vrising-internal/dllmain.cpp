#include <stdio.h>
#include <windows.h>
#include <iostream>

#include <xenon/xenon.hpp>
#include <spdlog/spdlog.h>

#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/features/aimbot.hpp>
#include <xenon/models/waypoint.hpp>
#include <il2cpp_resolver/il2cpp_resolver.hpp>

#include "VRisingDump/il2cpp.h"

float head = 0.8f;
float feet = -0.8f;
float width = 300.0f;

bool WorldToScreen(Vec2 screenSize, Vec3 world, Vec2& screen)
{
	Unity::CCamera* cameraMain = Unity::Camera::GetMain();
	if (!cameraMain) {
		return false;
	}

	Unity::Vector3 buffer = cameraMain->CallMethodSafe<Unity::Vector3>("WorldToScreenPoint", Unity::Vector3(world.x, world.y, world.z), Unity::m_eCameraEye::m_eCameraEye_Center);

	if (buffer.x > screenSize.x || buffer.y > screenSize.y || buffer.x < 0 || buffer.y < 0 || buffer.z < 0)
	{
		return false;
	}

	if (buffer.z > 0.0f)
	{
		screen = Vec2(buffer.x, screenSize.y - buffer.y);
	}

	if (screen.x > 0 || screen.y > 0)
	{
		return true;
	}

	return false;
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	Builder builder("V Rising internal");

	std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
	pRadarConfig->m_fDefaultScale = 40;
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
		Vec2 screenPos;
		WorldToScreen(pSystem->GetScreenResolution(), pos, screenPos);

		return screenPos;
	};

	pUIConfig->m_vFnOverlays.push_back([builder, pWaypoints, pGameVariables, pSystem]() {
		ImGui::Begin("V Rising internal");

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

	});

	builder.xenonConfig->g_pAimConfig->m_fDistanceScale = 0.6f;
	builder.xenonConfig->g_pEspConfig->m_fHealthBarWidth = 35;

	pUIConfig->m_qActions->AddSlider("Head", &head, -10.0f, 10.0f);
	pUIConfig->m_qActions->AddSlider("Feet", &feet, -10.0f, 10.0f);
	pUIConfig->m_qActions->AddSlider("Width", &width, 0.0f, 300.0f);
	pUIConfig->m_qActions->AddSlider("Distance Scale", &builder.xenonConfig->g_pAimConfig->m_fDistanceScale, 0.0f, 100.0f);

	builder.GameManager->OnEvent("Update", [builder, pGameVariables]() {

		void* m_pThisThread = IL2CPP::Thread::Attach(IL2CPP::Domain::Get());
		if (!m_pThisThread) return;

		pGameVariables->g_vTargets.clear();

		Unity::il2cppArray<Unity::CComponent*>* pTargets = nullptr;
		try {
			pTargets = Unity::Object::FindObjectsOfType<Unity::CComponent>("Entity");
		}
		catch (std::exception e) {
			spdlog::error("Error: {}", e.what());
			return;
		}
		if (!pTargets) return;

		spdlog::info("Found {} targets", pTargets->m_uMaxLength);

		//for (int i = 0; i < pTargets->m_uMaxLength; i++) {
		//	PlayerController_o* current = reinterpret_cast<PlayerController_o*>(pTargets->operator[](i));
		//	if (!current) continue;

		//	Unity::CTransform* currTargetTransform = pTargets->operator[](i)->GetTransform();
		//	if (!currTargetTransform) continue;

		//	Unity::Vector3 currTargetPos = currTargetTransform->GetPosition();
		//	if(currTargetPos.x == 0 && currTargetPos.y == 0 && currTargetPos.z == 0) continue;

		//	TargetProfile targetProfile;
		//	targetProfile.m_pOriginalAddress = reinterpret_cast<intptr_t>(current);
		//	targetProfile.m_fWidth = width;
		//	targetProfile.m_bTemmate = false;
		//	targetProfile.m_fHealth = 100.f;
		//	targetProfile.m_fMaxHealth = 100.f;		
		//	targetProfile.m_vHeadPos3D = Vec3(currTargetPos.x, currTargetPos.y + head, currTargetPos.z);
		//	targetProfile.m_vFeetPos3D = Vec3(currTargetPos.x, currTargetPos.y + feet, currTargetPos.z);
		//	targetProfile.m_vPos3D = Vec3(currTargetPos.x, currTargetPos.y, currTargetPos.z);

		//	char buffer[64];
		//	sprintf_s(buffer, "Player %d", i);
		//	targetProfile.m_strName = buffer;

		//	if(current == current->klass->static_fields->LocalInstance)
		//		pGameVariables->g_vLocal = targetProfile;
		//	else
		//		pGameVariables->g_vTargets.push_back(targetProfile);
		//	
		//}

		IL2CPP::Thread::Detach(m_pThisThread);

	});

	Cheat cheat = builder.Build();
	cheat.UseUICustom(RenderingHookType::KIERO);
	cheat.UseUIMenu();
	cheat.UseUIRenderOverlays();
	cheat.UseUIRenderEnabledCheats();
	//cheat.UseUIQuickActions();
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

