#include <Windows.h>

#include "basic_ue.hpp"
#include <xenon/xenon.hpp>

// test variables
float width = 4000;
float head = 62;
float feet = -102;
float scale = 0.01;

DWORD WINAPI MainThread(LPVOID lpReserved) {
    // going to use xenon there

    Builder builder("OHD Example");
    builder.SetConsoleEnabled();
    builder.SetInfoLogLevel();

    std::shared_ptr<GameVariables> pGameVariables = builder.xenonConfig->g_pGameVariables;
    std::shared_ptr<EspConfig> pEspConfig= builder.xenonConfig->g_pEspConfig;
    std::shared_ptr<UIConfig> pUIConfig = builder.xenonConfig->g_pUIConfig;
    std::shared_ptr<AimConfig> pAimConfig = builder.xenonConfig->g_pAimConfig;
    std::shared_ptr<RadarConfig> pRadarConfig = builder.xenonConfig->g_pRadarConfig;
    std::shared_ptr<System> pSystem = builder.xenon->g_pSystem;

    pSystem->IsInternal(true);
    pSystem->IsUnrealEngine(UnrealEngineVersion::UE4);
    pSystem->SetGameDimension(GameDimension::DIM_3D);
    pSystem->SetRenderingType(RenderingType::DX11);
    pSystem->m_fnW2S3D = [](Vec3 pos) {
        SDK::FVector2D screenPos; // <-- result
        SDK::FVector unrealPos(pos.x, pos.z, pos.y);
        if (UE::m_pMyController->ProjectWorldLocationToScreen(unrealPos, &screenPos, false)) {
            return Vec2(screenPos.X, screenPos.Y);
        }
        else {
            return Vec2(-99, -99);
        }
	};

    // set configurations
    pAimConfig->m_fDistanceScale = 0.06f;
    pAimConfig->m_nLimitDistance = 50000;
    pEspConfig->m_nLimitDistance = 50000;
    pEspConfig->m_fHealthBarWidth = 40;

    pEspConfig->m_fnGetBoneScreenPosFromIndex3D = [](int index) {
        SDK::FVector bonePos = UE::m_pMyCharacter->Mesh->GetSocketLocation(UE::m_pMyCharacter->Mesh->GetBoneName(index));

        return Vec3(bonePos.X, bonePos.Z, bonePos.Y);
    };

    pEspConfig->m_tBonePairs = {
        // Spine
        {1, 2},  // pelvis -> spine_01
        {2, 3},  // spine_01 -> spine_02
        {3, 4},  // spine_02 -> spine_03
        {4, 47}, // spine_03 -> neck_01
        {47, 48}, // neck_01 -> head

        // Left arm
        {4, 5},   // spine_03 -> clavicle_l
        {5, 6},   // clavicle_l -> UpperArm_L
        {6, 7},   // UpperArm_L -> lowerarm_l
        {7, 8},   // lowerarm_l -> Hand_L
        {8, 9},   // Hand_L -> index_01_l
        {9, 10},  // index_01_l -> index_02_l
        {10, 11}, // index_02_l -> index_03_l
        {8, 12},  // Hand_L -> middle_01_l
        {12, 13}, // middle_01_l -> middle_02_l
        {13, 14}, // middle_02_l -> middle_03_l
        {8, 15},  // Hand_L -> pinky_01_l
        {15, 16}, // pinky_01_l -> pinky_02_l
        {16, 17}, // pinky_02_l -> pinky_03_l
        {8, 18},  // Hand_L -> ring_01_l
        {18, 19}, // ring_01_l -> ring_02_l
        {19, 20}, // ring_02_l -> ring_03_l
        {8, 21},  // Hand_L -> thumb_01_l
        {21, 22}, // thumb_01_l -> thumb_02_l
        {22, 23}, // thumb_02_l -> thumb_03_l

        // Right arm
        {4, 26},  // spine_03 -> clavicle_r
        {26, 27}, // clavicle_r -> UpperArm_R
        {27, 28}, // UpperArm_R -> lowerarm_r
        {28, 29}, // lowerarm_r -> Hand_R
        {29, 30}, // Hand_R -> index_01_r
        {30, 31}, // index_01_r -> index_02_r
        {31, 32}, // index_02_r -> index_03_r
        {29, 33}, // Hand_R -> middle_01_r
        {33, 34}, // middle_01_r -> middle_02_r
        {34, 35}, // middle_02_r -> middle_03_r
        {29, 36}, // Hand_R -> pinky_01_r
        {36, 37}, // pinky_01_r -> pinky_02_r
        {37, 38}, // pinky_02_r -> pinky_03_r
        {29, 39}, // Hand_R -> ring_01_r
        {39, 40}, // ring_01_r -> ring_02_r
        {40, 41}, // ring_02_r -> ring_03_r
        {29, 42}, // Hand_R -> thumb_01_r
        {42, 43}, // thumb_01_r -> thumb_02_r
        {43, 44}, // thumb_02_r -> thumb_03_r

        // Left leg
        {1, 49},  // pelvis -> Thigh_L
        {49, 50}, // Thigh_L -> calf_l
        {50, 52}, // calf_l -> Foot_L
        {52, 53}, // Foot_L -> ball_l

        // Right leg
        {1, 55},  // pelvis -> Thigh_R
        {55, 56}, // Thigh_R -> calf_r
        {56, 58}, // calf_r -> Foot_R
        {58, 59}  // Foot_R -> ball_r
    };

    // SET DEBUG VALUES
	pUIConfig->m_qActions->AddSlider("Width", &width, 10, 80000);
    pUIConfig->m_qActions->AddSlider("Head", &head, 0, 900);
    pUIConfig->m_qActions->AddSlider("Feet", &feet, -900, 0);
    pUIConfig->m_qActions->AddSlider("Distance scale", &pAimConfig->m_fDistanceScale, 0.001, 2);
    pUIConfig->m_qActions->AddSlider("Radar scale", &pRadarConfig->m_fDefaultScale, 0, 100000);
    pUIConfig->m_qActions->AddSlider("Limit Esp Distance", &pEspConfig->m_nLimitDistance, 0, 100000);
    pUIConfig->m_qActions->AddSlider("Limit Aim Distance", &pAimConfig->m_nLimitDistance, 0, 100000);

    // maybe add overlay to check available targets
    pUIConfig->m_vFnOverlays.push_back([pGameVariables]() {
        ImGui::Begin("Test UI");

        ImGui::Text("Engine: 0x%llx", UE::m_pEngine);
        ImGui::Text("World: 0x%llx", UE::m_pWorld);
        ImGui::Text("MyCharacter: 0x%llx", UE::m_pMyCharacter);

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

    builder.GameManager->OnEvent("Update", [builder, pGameVariables]() {
        if(!UE::FetchSDK()) return;

        pGameVariables->g_vTargets.clear();

        SDK::FVector myPos = UE::m_pMyController->K2_GetActorLocation();
        pGameVariables->g_vLocal.m_vPos3D = Vec3(myPos.X, myPos.Z, myPos.Y); // ue use y and z in reverse

        for (int i = 0; i < SDK::UObject::GObjects->Num(); i++) {
			SDK::UObject* pObject = SDK::UObject::GObjects->GetByIndex(i);

			if(!pObject || pObject == nullptr || pObject->IsDefaultObject()) continue;
            if(!pObject->IsA(SDK::ACharacter::StaticClass())) continue; // there we can set a specific class that will go to search later

            // using ACharacter for the moment
            SDK::ACharacter* target = static_cast<SDK::ACharacter*>(pObject);
            if(!target || target == nullptr || !target->Controller || target->Controller->IsLocalPlayerController()) continue;
            // maybe later check life

            SDK::FVector targetPos = target->K2_GetActorLocation();

            if(targetPos.X == 0 && targetPos.Y == 0 && targetPos.Z == 0) continue;

            TargetProfile targetProfile;
            // a trick to set a unique id is use the memory address
            //targetProfile.m_pOriginalAddress = reinterpret_cast<int>(target);
            targetProfile.m_fWidth = width;
            targetProfile.m_vHeadPos3D = Vec3(targetPos.X, targetPos.Z + head, targetPos.Y);
            targetProfile.m_vPos3D = Vec3(targetPos.X, targetPos.Z, targetPos.Y);
            targetProfile.m_vFeetPos3D = Vec3(targetPos.X, targetPos.Z + feet, targetPos.Y);
            targetProfile.m_strName = target->GetName();
            targetProfile.m_fHealth = target->GetLifeSpan(); // not working always
            targetProfile.m_bVisible = UE::m_pMyController->LineOfSightTo(target, UE::m_pMyController->PlayerCameraManager->CameraCachePrivate.POV.Location, false);

            pGameVariables->g_vTargets.push_back(targetProfile);

		}

    });

    Cheat cheat = builder.Build();
    cheat.UseUICustom(RenderingHookType::KIERO);
    cheat.UseUIMenu();
    cheat.UseUIRenderMouse();
    cheat.UseUIRenderEnabledCheats(); // <-- minecraft style at right top
    cheat.UseUIRenderOverlays(); 
    cheat.UseUIQuickActions(); // testing values of the game like scales

    cheat.Run();

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
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

