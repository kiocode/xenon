#include <xenon/components/features/aimbot.hpp>

#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <thread>

#include <xenon/utility/random.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/core/system.hpp>


void CAimbot::UpdateCurrentTarget(TargetProfile* target) {
    if (!g_pXenonVariables->g_bAimbot) return;

    bool isAiming = GetAsyncKeyState(VK_RBUTTON) & 0x8000;
    static TargetProfile* lockedTarget = nullptr;

    if (!isAiming) {
        lockedTarget = nullptr;
        ResetTarget();
    }

    TargetProfile& local = g_pXenonConfigs->g_pGameVariables->g_vLocal;

    if (lockedTarget) {
        Vec2* screenPos = g_pXenon->g_pSystem->Is3DGame()
            ? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget->m_vPos3D)
            : g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget->m_vPos2D);

        if (screenPos) {
            SetTarget(*screenPos);
            if (isAiming) AimTarget();
        }
        else {
            lockedTarget = nullptr;
        }
        return;
    }

    float nearestDistance = FLT_MAX;
    TargetProfile* bestTarget = nullptr;

    Vec2* screenPos = g_pXenon->g_pSystem->Is3DGame()
        ? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vPos3D)
        : g_pXenon->g_pSystem->m_fnW2S2D(target->m_vPos2D);

    if (!screenPos) return;

    float distance = g_pXenon->g_pSystem->Is3DGame()
        ? target->m_vPos3D.Distance(local.m_vPos3D)
        : target->m_vPos2D.Distance(local.m_vPos2D);

    if (g_pXenonVariables->g_bFov) {
        int screenCenterX = g_pXenon->g_pSystem->GetScreenCenter().x;
        int screenCenterY = g_pXenon->g_pSystem->GetScreenCenter().y;
        int aimbotFOV = g_pXenonConfigs->g_pAimConfig->m_fFov;

        if (screenPos->x > (screenCenterX + aimbotFOV) || screenPos->x < (screenCenterX - aimbotFOV) ||
            screenPos->y >(screenCenterY + aimbotFOV) || screenPos->y < (screenCenterY - aimbotFOV)) {
            return;
        }
    }

    if (distance < nearestDistance) {
        nearestDistance = distance;
        bestTarget = target;
    }

    if (bestTarget) {
        lockedTarget = bestTarget;
        SetTarget(*screenPos);
        if (isAiming) AimTarget();
    }
}


bool CAimbot::IsTargetEmpty() const {
    return m_vTarget.x == -99 && m_vTarget.y == -99;
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
