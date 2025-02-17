#include <xenon/components/features/aimbot.hpp>

#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <thread>

#include <xenon/utility/random.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/core/system.hpp>
#include <xenon/utility/utilities.hpp>

void CAimbot::UpdateCurrentTarget(TargetProfile* target) {
    if (!g_pXenonVariables->g_bAimbot) return;

    if (!GetAsyncKeyState(VK_RBUTTON)) {
        hasLockedTarget = false;
        nearestDistance = g_pXenonVariables->g_bNearest ? g_pXenonConfigs->g_pAimConfig->m_nNearest : g_pXenonConfigs->g_pAimConfig->m_fFov;
        ResetTarget();
        return;
    }

    float worldDistance = g_pXenon->g_pSystem->Is3DGame() ? 
        target->m_vPos3D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D) :
        target->m_vPos2D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D);

    Vec2 screenPos;
    switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
        case 0: // Head
            screenPos = g_pXenon->g_pSystem->Is3DGame()
                ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D)
                : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vHeadPos2D);
            break;
        case 1: // Body
            screenPos = g_pXenon->g_pSystem->Is3DGame()
                ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vPos3D)
                : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vPos2D);
            break;
        case 2: // Feet
            screenPos = g_pXenon->g_pSystem->Is3DGame()
                ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D)
                : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vFeetPos2D);
            break;
    }

    if (!screenPos.IsValid()) return;

    bool isInFov = true;

    if (g_pXenonVariables->g_bNearest && worldDistance < nearestDistance) {
        nearestDistance = worldDistance;
        nearestTarget = *target;
    } else if (g_pXenonVariables->g_bFov) {
        Vec2 screenCenter = g_pXenon->g_pSystem->GetScreenCenter();

        if (std::abs(screenPos.x - screenCenter.x) < g_pXenonConfigs->g_pAimConfig->m_fFov && std::abs(screenPos.y - screenCenter.y) < g_pXenonConfigs->g_pAimConfig->m_fFov) {
		    float distanceFromScreenCenter = screenPos.Distance(screenCenter);

            if (distanceFromScreenCenter < nearestDistance) {
			    nearestDistance = distanceFromScreenCenter;
			    nearestTarget = *target;
		    }
        }
        else {
            isInFov = false;
        }
    }

    if (!hasLockedTarget || !Utilities::ListContainsTarget(g_pXenonConfigs->g_pGameVariables->g_vTargets, lockedTarget) || (g_pXenonVariables->g_bFov && target->m_pOriginalAddress == lockedTarget.m_pOriginalAddress && !isInFov)) {
        lockedTarget = nearestTarget;
        hasLockedTarget = true;
    }

    if (target->m_pOriginalAddress != lockedTarget.m_pOriginalAddress || !isInFov) return;

    float scaleFactor = 1;

    if (g_pXenon->g_pSystem->Is3DGame()) {
        scaleFactor = 1.0f / (worldDistance * g_pXenonConfigs->g_pAimConfig->m_fDistanceScale);
    }

    SetTarget(screenPos);
    AimTarget();
}

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
