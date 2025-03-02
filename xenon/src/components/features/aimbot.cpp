#include <xenon/components/features/aimbot.hpp>

#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <thread>

#include <xenon/utility/random.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/core/system.hpp>
#include <xenon/utility/utilities.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// test
void CAimbot::Update() {
    if (!g_pXenonVariables->g_bAimbot) return;

    if (!GetAsyncKeyState(g_pXenonConfigs->g_pAimConfig->m_nAimKey)) {
        hasLockedTarget = false;
        nearestDistance = g_pXenonVariables->g_bNearest ? g_pXenonConfigs->g_pAimConfig->m_nNearest : g_pXenonConfigs->g_pAimConfig->m_fFov;
        ResetTarget();
        return;
    }

    TargetProfile nearestTarget;
    nearestDistance = g_pXenonVariables->g_bNearest ? g_pXenonConfigs->g_pAimConfig->m_nNearest : g_pXenonConfigs->g_pAimConfig->m_fFov;

    for (TargetProfile& target : g_pXenonConfigs->g_pGameVariables->g_vTargets) {
        if((g_pXenonConfigs->g_pAimConfig->m_bOnlyVisible && !target.m_bVisible) || target.m_pOriginalAddress == g_pXenonConfigs->g_pGameVariables->g_vLocal.m_pOriginalAddress) continue;

        float distance = g_pXenon->g_pSystem->Is3DGame() ?
            target.m_vPos3D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D) :
            target.m_vPos2D.Distance(g_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D);
        
        if (g_pXenonConfigs->g_pAimConfig->m_nLimitDistance != 0 && distance >= g_pXenonConfigs->g_pAimConfig->m_nLimitDistance) {
            continue;
        }

        Vec2 screenPos;
        if (g_pXenon->g_pSystem->Is3DGame()) {
            switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
                case 0: screenPos = g_pXenon->g_pSystem->m_fnW2S3D(target.m_vHeadPos3D); break;
                case 1: screenPos = g_pXenon->g_pSystem->m_fnW2S3D(target.m_vPos3D); break;
                case 2: screenPos = g_pXenon->g_pSystem->m_fnW2S3D(target.m_vFeetPos3D); break;
            }
        }
        else {
            switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
                case 0: screenPos = g_pXenon->g_pSystem->m_fnW2S2D(target.m_vHeadPos2D); break;
                case 1: screenPos = g_pXenon->g_pSystem->m_fnW2S2D(target.m_vPos2D); break;
                case 2: screenPos = g_pXenon->g_pSystem->m_fnW2S2D(target.m_vFeetPos2D); break;
            }
        }

        if (!screenPos.IsValid()) continue; 

        if(g_pXenonVariables->g_bFov) {
            if (g_pXenon->g_pSystem->Is3DGame()) {
                Vec2 screenCenter = g_pXenon->g_pSystem->GetScreenCenter();

                if (std::abs(screenPos.x - screenCenter.x) < g_pXenonConfigs->g_pAimConfig->m_fFov && std::abs(screenPos.y - screenCenter.y) < g_pXenonConfigs->g_pAimConfig->m_fFov) {
                    distance = screenPos.Distance(screenCenter);
                }            
            }
            else {
                spdlog::warn("2D game not supported yet");
            }
        }

        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestTarget = target;
            hasLockedTarget = true;
        }
    }

    if (nearestDistance >= g_pXenonConfigs->g_pAimConfig->m_nNearest || !hasLockedTarget) return;

    lockedTarget = nearestTarget;

    Vec2 lockedScreenPos;
    if (g_pXenon->g_pSystem->Is3DGame()) {
        switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
            case 0: lockedScreenPos = g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget.m_vHeadPos3D); break;
            case 1: lockedScreenPos = g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget.m_vPos3D); break;
            case 2: lockedScreenPos = g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget.m_vFeetPos3D); break;
        }
    }
    else {
        switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
            case 0: lockedScreenPos = g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget.m_vHeadPos2D); break;
            case 1: lockedScreenPos = g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget.m_vPos2D); break;
            case 2: lockedScreenPos = g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget.m_vFeetPos2D); break;
        }
    }

    if (!lockedScreenPos.IsValid()) return;

    SetTarget(lockedScreenPos);
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

Vec2 CAimbot::GetTarget() const {
	return m_vTarget;
}