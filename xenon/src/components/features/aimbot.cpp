#include <xenon/components/features/aimbot.hpp>

#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <thread>

#include <xenon/utility/random.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/core/system.hpp>

static bool ListContainsTarget(std::vector<TargetProfile>& list, TargetProfile target) {
    for (auto& t : list) {
        if (t.m_pOriginalAddress == target.m_pOriginalAddress) {
			return true;
		}
	}
	return false;
}

void CAimbot::UpdateCurrentTarget(TargetProfile* target) {
    if (!g_pXenonVariables->g_bAimbot) return;

    if (!GetAsyncKeyState(VK_RBUTTON)) {
        hasLockedTarget = false;
        ResetTarget();
        return;
    }

    if (!hasLockedTarget || !ListContainsTarget(g_pXenonConfigs->g_pGameVariables->g_vTargets, lockedTarget)) {
        lockedTarget = *target;
        hasLockedTarget = true;
    }

    if (target->m_pOriginalAddress != lockedTarget.m_pOriginalAddress) return;

    float scaleFactor = 1;

    if (g_pXenon->g_pSystem->Is3DGame()) {
        float distance = target->m_vPos3D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D);
        scaleFactor = 1.0f / (distance * g_pXenonConfigs->g_pAimConfig->m_fDistanceScale);
    }

    Vec2 screenPos = g_pXenon->g_pSystem->Is3DGame()
        ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D)
        : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vHeadPos2D);

    if (!screenPos.IsValid()) return;

    SetTarget(screenPos);
    AimTarget();
}

//void CAimbot::UpdateCurrentTarget(TargetProfile* target) {
//    if (!g_pXenonVariables->g_bAimbot) return;
//
//    bool isAiming = GetAsyncKeyState(VK_RBUTTON) & 0x8000;
//
//    if (!isAiming) {
//        hasLockedTarget = false;
//        ResetTarget();
//        return;
//    }
//
//    TargetProfile& local = g_pXenonConfigs->g_pGameVariables->g_vLocal;
//
//    if (!hasLockedTarget || !ListContainsTarget(g_pXenonConfigs->g_pGameVariables->g_vTargets, lockedTarget)) {
//        hasLockedTarget = false;
//        lockedTarget = *nearestTarget; 
//    }
//
//    nearestDistance = g_pXenonConfigs->g_pAimConfig->m_fNearest;
//    nearestTarget = nullptr;
//
//    for (auto& potentialTarget : g_pXenonConfigs->g_pGameVariables->g_vTargets) {
//        Vec2 screenPos = g_pXenon->g_pSystem->Is3DGame()
//            ? g_pXenon->g_pSystem->m_fnW2S3D(potentialTarget.m_vHeadPos3D)
//            : g_pXenon->g_pSystem->m_fnW2S2D(potentialTarget.m_vHeadPos2D);
//
//        if (!screenPos.IsValid()) continue;
//
//        float distanceToCompare;
//        if (g_pXenonVariables->g_bFov) {
//            Vec2 screenCenter = g_pXenon->g_pSystem->GetScreenCenter();
//            distanceToCompare = screenPos.Distance(screenCenter);
//        }
//        else {
//            distanceToCompare = g_pXenon->g_pSystem->Is3DGame()
//                ? local.m_vPos3D.Distance(potentialTarget.m_vPos3D)
//                : local.m_vPos2D.Distance(potentialTarget.m_vPos2D);
//        }
//
//        if (distanceToCompare < nearestDistance) {
//            nearestDistance = distanceToCompare;
//            nearestTarget = &potentialTarget;
//        }
//    }
//
//    if (!hasLockedTarget && nearestTarget) {
//        lockedTarget = *nearestTarget;
//        hasLockedTarget = true;
//    }
//
//    if (!hasLockedTarget) return;
//
//    Vec2 screenPos;
//    switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
//    case 0: // Head
//        screenPos = g_pXenon->g_pSystem->Is3DGame()
//            ? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget.m_vHeadPos3D)
//            : g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget.m_vHeadPos2D);
//        break;
//    case 1: // Body
//        screenPos = g_pXenon->g_pSystem->Is3DGame()
//            ? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget.m_vPos3D)
//            : g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget.m_vPos2D);
//        break;
//    case 2: // Feet
//        screenPos = g_pXenon->g_pSystem->Is3DGame()
//            ? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget.m_vFeetPos3D)
//            : g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget.m_vFeetPos2D);
//        break;
//    }
//
//    if (!screenPos.IsValid()) {
//        hasLockedTarget = false;
//        return;
//    }
//
//    SetTarget(screenPos);
//    AimTarget();
//}

bool CAimbot::IsTargetEmpty() const {
    return !m_vTarget.IsValid();
}

void CAimbot::ResetTarget() {
    m_vTarget = { -99, -99 };
}

void CAimbot::SetTarget(Vec2& pos) {
    m_vTarget = pos;
}

void CAimbot::AimTargetWithPrediction(Vec2& vel) {

    // calc predicted target
    auto predictedTarget = /*prediction*/ m_vTarget;

    g_pXenon->g_cAimService->Aim(predictedTarget);

    if (IsTargetReached()) {
        ResetTarget();
    }

}

void CAimbot::AimTarget() {

    if (IsTargetEmpty()) {
        spdlog::debug("Target is empty");
        return;
    }
    
    g_pXenon->g_cAimService->Aim(m_vTarget);

    if (IsTargetReached()) {
        ResetTarget();
    }

}

bool CAimbot::IsTargetReached() const {

    Vec2 cursorPos = g_pXenonConfigs->g_pAimConfig->m_fnGetCustomAim ? g_pXenonConfigs->g_pAimConfig->m_fnGetCustomAim() : g_pXenon->g_pSystem->GetMousePos();

    spdlog::debug("Cursor pos {}, {}", cursorPos.x, cursorPos.y);

    float deltaX = static_cast<float>(cursorPos.x - m_vTarget.x);
    float deltaY = static_cast<float>(cursorPos.y - m_vTarget.y);

    return std::sqrt(deltaX * deltaX + deltaY * deltaY) <= 2.0f;
}
