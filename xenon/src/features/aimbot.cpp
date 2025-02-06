#include <xenon/components/features/aimbot.hpp>

#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <thread>

#include <xenon/utility/random.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/core/system.hpp>


void Aimbot::UpdateCurrentTarget(TargetProfile* target) {
    if (!g_pXenonVariables->g_bAimbot || !g_pXenonVariables->g_bAimNearest) {
        return;
    }

    TargetProfile& local = g_pXenonConfigs->g_pGameVariables->g_vLocal;
    float distance = g_pXenon->g_pSystem->Is3DGame()
        ? target->m_vPos3D.Distance(local.m_vPos3D)
        : target->m_vPos2D.Distance(local.m_vPos2D);

    if (distance < nearestDistance) {
        nearestDistance = distance;
        g_pXenonConfigs->g_pGameVariables->g_vNearestTarget = target;
    }

    if (!g_pXenonConfigs->g_pGameVariables->g_vNearestTarget) {
        ResetTarget();
        return;
    }

    Vec2* nearest = g_pXenon->g_pSystem->Is3DGame()
        ? g_pXenon->g_pSystem->m_fnW2S3D(g_pXenonConfigs->g_pGameVariables->g_vNearestTarget->m_vPos3D)
        : g_pXenon->g_pSystem->m_fnW2S2D(g_pXenonConfigs->g_pGameVariables->g_vNearestTarget->m_vPos2D);

    if (nearest == nullptr) ResetTarget();
    else SetTarget(*nearest);

    AimTarget();
}


bool Aimbot::IsTargetEmpty() const {
    return m_vTarget.x == -99 && m_vTarget.y == -99;
}

void Aimbot::ResetTarget() {
    m_vTarget = { -99, -99 };
}

void Aimbot::SetTarget(Vec2& pos) {
    m_vTarget = pos;
}

void Aimbot::AimTargetWithPrediction(Vec2& vel) {

    // calc predicted target
    auto predictedTarget = /*prediction*/ m_vTarget;

    g_pXenon->g_cAimService->Aim(predictedTarget);

    if (IsTargetReached()) {
        ResetTarget();
    }

}

void Aimbot::AimTarget() {

    if (IsTargetEmpty()) {
        spdlog::debug("Target is empty");
        return;
    }
    
    g_pXenon->g_cAimService->Aim(m_vTarget);

    if (IsTargetReached()) {
        ResetTarget();
    }

}

bool Aimbot::IsTargetReached() const {

    Vec2 cursorPos = g_pXenonConfigs->g_pAimConfig->m_fnGetCustomAim ? g_pXenonConfigs->g_pAimConfig->m_fnGetCustomAim() : g_pXenon->g_pSystem->GetMousePos();

    spdlog::debug("Cursor pos {}, {}", cursorPos.x, cursorPos.y);

    float deltaX = static_cast<float>(cursorPos.x - m_vTarget.x);
    float deltaY = static_cast<float>(cursorPos.y - m_vTarget.y);

    return std::sqrt(deltaX * deltaX + deltaY * deltaY) <= 2.0f;
}
