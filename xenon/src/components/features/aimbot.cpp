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

    if (!isAiming) {
        lockedTarget = nullptr;
        nearestDistance = g_pXenonConfigs->g_pAimConfig->m_fNearest;
        bestTarget = nullptr;
        ResetTarget();
        return;
    }

    TargetProfile& local = g_pXenonConfigs->g_pGameVariables->g_vLocal;

    if (lockedTarget) {
        Vec2 screenPos;
        
        switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
            case 0: // head
				screenPos = g_pXenon->g_pSystem->Is3DGame()
					? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget->m_vHeadPos3D)
					: g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget->m_vHeadPos2D);
				break;
            case 1: // body
                screenPos = g_pXenon->g_pSystem->Is3DGame()
                    ? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget->m_vPos3D)
                    : g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget->m_vPos2D);
            case 2: // feet
				screenPos = g_pXenon->g_pSystem->Is3DGame()
					? g_pXenon->g_pSystem->m_fnW2S3D(lockedTarget->m_vFeetPos3D)
					: g_pXenon->g_pSystem->m_fnW2S2D(lockedTarget->m_vFeetPos2D);
        }

        if (screenPos.IsValid()) {
            SetTarget(screenPos);
            if (isAiming) AimTarget();
        }
        else {
            lockedTarget = nullptr;
            nearestDistance = FLT_MAX;
            bestTarget = nullptr;
        }
        return;
    }

    Vec2 screenPos;
    switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
		case 0: // head
			screenPos = g_pXenon->g_pSystem->Is3DGame()
				? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vHeadPos3D)
				: g_pXenon->g_pSystem->m_fnW2S2D(target->m_vHeadPos2D);
			break;
		case 1: // body
			screenPos = g_pXenon->g_pSystem->Is3DGame()
				? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vPos3D)
				: g_pXenon->g_pSystem->m_fnW2S2D(target->m_vPos2D);
		case 2: // feet
			screenPos = g_pXenon->g_pSystem->Is3DGame()
				? g_pXenon->g_pSystem->m_fnW2S3D(target->m_vFeetPos3D)
				: g_pXenon->g_pSystem->m_fnW2S2D(target->m_vFeetPos2D);
	}

    if (!screenPos.IsValid()) return;

    if (g_pXenonVariables->g_bFov) {
        Vec2 screenCenter = g_pXenon->g_pSystem->GetScreenCenter();
        int aimbotFOV = g_pXenonConfigs->g_pAimConfig->m_fFov;

        if (screenPos.x > (screenCenter.x + aimbotFOV) || screenPos.x < (screenCenter.x - aimbotFOV) ||
            screenPos.y >(screenCenter.y + aimbotFOV) || screenPos.y < (screenCenter.y - aimbotFOV)) {
            return;
        }
    }

    float distance = 999;
    switch (g_pXenonConfigs->g_pAimConfig->m_nAimTo) {
        case 0: // head
            distance = g_pXenon->g_pSystem->Is3DGame()
				? local.m_vHeadPos3D.Distance(target->m_vHeadPos3D)
				: local.m_vHeadPos2D.Distance(target->m_vHeadPos2D);
            break;
        case 1: // body
            distance = g_pXenon->g_pSystem->Is3DGame()
				? local.m_vPos3D.Distance(target->m_vPos3D)
				: local.m_vPos2D.Distance(target->m_vPos2D);
        case 2: // feet
            distance = g_pXenon->g_pSystem->Is3DGame()
                ? local.m_vFeetPos3D.Distance(target->m_vFeetPos3D)
                : local.m_vFeetPos2D.Distance(target->m_vFeetPos2D);
    }

    if (!g_pXenonVariables->g_bFov) {
        if (distance < nearestDistance) {
            nearestDistance = distance;
            bestTarget = target;
        }
    }
    else {
        Vec2 screenCenter = g_pXenon->g_pSystem->GetScreenCenter();
        float distanceToCenter = screenPos.Distance(screenCenter);

        if (distanceToCenter < nearestDistance) {
            nearestDistance = distanceToCenter;
            bestTarget = target;
        }
    }

    if (bestTarget) {
        lockedTarget = bestTarget;
        SetTarget(screenPos);
        if (isAiming) AimTarget();
    }
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
