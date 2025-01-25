#include <xenon/components/features/aimbot.hpp>

#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <thread>

#include <xenon/utility/random.hpp>
#include <xenon/components/services/aim_service.hpp>

void Aimbot::Update() {

    if (g_pXenonVariables->g_bAimbot) {

        if (g_pXenonConfigs->g_pAimConfig->m_bNearest) {

            Vec2* nearest = g_pXenon->g_cAimService->GetNearestPos(g_pXenonConfigs->g_pGameVariables->g_vTargets, g_pXenonConfigs->g_pGameVariables->g_vLocal, g_pXenonConfigs->g_pAimConfig->m_fNearest);
            if (nearest == nullptr) ResetTarget();
            else SetTarget(*nearest);

        }

        AimTarget();
    }
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
    POINT cursorPos;
    if (!GetCursorPos(&cursorPos)) {
        spdlog::error("Failed to get cursor position");
        return false;
    }

    spdlog::debug("Cursor pos {}, {}", cursorPos.x, cursorPos.y);

    float deltaX = static_cast<float>(cursorPos.x - m_vTarget.x);
    float deltaY = static_cast<float>(cursorPos.y - m_vTarget.y);

    return std::sqrt(deltaX * deltaX + deltaY * deltaY) <= 2.0f;
}
