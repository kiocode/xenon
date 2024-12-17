#include <xenon/features/aimbot.hpp>
#include <windows.h>
#include <spdlog/spdlog.h>

bool Aimbot::IsTargetEmpty() {
    return m_vTarget.x == -99 && m_vTarget.y == -99;
}

void Aimbot::SetTarget(Vec2 pos) {
    m_vTarget = pos;
}

void Aimbot::Aim() {
    if (IsTargetEmpty()) {
        spdlog::info("Target is empty");
        return;
    }

    Vec2 target{ 0, 0 };

    if (m_pConfigs->m_bStartFromCenter) {
        m_pConfigs->m_fSmooth += 3;
        target.x = CalculateSmoothMove(m_vTarget.x, m_pConfigs->m_vScreenCenter.x);
        target.y = CalculateSmoothMove(m_vTarget.y, m_pConfigs->m_vScreenCenter.y);
    }

    mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(target.x), static_cast<DWORD>(target.y), NULL, NULL);
    spdlog::info("Aiming in {}, {}", m_vTarget.x, m_vTarget.y);
}

float Aimbot::CalculateSmoothMove(float targetPos, float centerPos) {
    float move = 0;

    if (targetPos > centerPos) {
        move = -(centerPos - targetPos) / m_pConfigs->m_fSmooth;
        if ((move + centerPos) > centerPos * 2) move = 0;
    }
    else if (targetPos < centerPos) {
        move = (targetPos - centerPos) / m_pConfigs->m_fSmooth;
        if ((move + centerPos) < 0) move = 0;
    }

    return move;
}

void Aimbot::Humanize() {
    // Implementa logica di umanizzazione futura
}
