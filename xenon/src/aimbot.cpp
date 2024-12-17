#include <xenon/features/aimbot.hpp>
#include <windows.h>
#include <spdlog/spdlog.h>
#include <cmath>
#include <xenon/utility/random.hpp>
#include <thread>

bool Aimbot::IsTargetEmpty() {
    return m_vTarget.x == -99 && m_vTarget.y == -99;
}

void Aimbot::ResetTarget() {
    m_vTarget = { -99, -99 };
}

void Aimbot::SetTarget(Vec2 pos) {
    m_vTarget = pos;
}

void Aimbot::Aim() {
    if (IsTargetEmpty()) {
        spdlog::info("Target is empty");
        return;
    }

    if (m_pConfigs->m_bStartFromCenter) {
        if (m_pConfigs->m_bSmooth) {
            SmoothMoveToTarget();
        }
        else if (m_pConfigs->m_bHumanize) {
            Humanize();
        }
        else {
            MoveDirectlyToTarget();
        }
    }
    else {
        MoveDirectlyToTarget();
    }

    spdlog::debug("Aiming at {}, {}", m_vTarget.x, m_vTarget.y);

    if (IsTargetReached()) {
        ResetTarget();
    }
}

void Aimbot::MoveDirectlyToTarget() {
    SetCursorPos(m_vTarget.x, m_vTarget.y);
}

void Aimbot::SmoothMoveToTarget() {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    float stepX = (m_vTarget.x - cursorPos.x) / m_pConfigs->m_fSmooth;
    float stepY = (m_vTarget.y - cursorPos.y) / m_pConfigs->m_fSmooth;

    for (int i = 1; i <= m_pConfigs->m_fSmooth; ++i) {
        float nextX = cursorPos.x + stepX * i;
        float nextY = cursorPos.y + stepY * i;

        SetCursorPos(static_cast<int>(nextX), static_cast<int>(nextY));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Aimbot::Humanize() {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    std::vector<Vec2> controlPoints = GenerateBezierControlPoints(
        { static_cast<float>(cursorPos.x), static_cast<float>(cursorPos.y) },
        m_vTarget
    );

    for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
        Vec2 point = CalculateBezierPoint(t, controlPoints);
        SetCursorPos(static_cast<int>(point.x), static_cast<int>(point.y));
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

std::vector<Vec2> Aimbot::GenerateBezierControlPoints(const Vec2& start, const Vec2& target) {
    std::vector<Vec2> points;

    float minX = std::min(start.x, target.x);
    float maxX = std::max(start.x, target.x);
    float minY = std::min(start.y, target.y);
    float maxY = std::max(start.y, target.y);

    points.push_back({ start.x, start.y });
    points.push_back({ Random::randomFloat(minX, maxX), Random::randomFloat(minY, maxY) }); 
    points.push_back({ Random::randomFloat(minX, maxX), Random::randomFloat(minY, maxY) });
    points.push_back(target);

    return points;
}

Vec2 Aimbot::CalculateBezierPoint(float t, const std::vector<Vec2>& points) {
    float x = std::pow(1 - t, 3) * points[0].x +
        3 * std::pow(1 - t, 2) * t * points[1].x +
        3 * (1 - t) * std::pow(t, 2) * points[2].x +
        std::pow(t, 3) * points[3].x;

    float y = std::pow(1 - t, 3) * points[0].y +
        3 * std::pow(1 - t, 2) * t * points[1].y +
        3 * (1 - t) * std::pow(t, 2) * points[2].y +
        std::pow(t, 3) * points[3].y;

    return { x, y };
}

bool Aimbot::IsTargetReached() {
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

void Aimbot::TrackMouse() {
    POINT cursorPos;
    if (!GetCursorPos(&cursorPos)) {
        spdlog::error("Failed to get cursor position");
        return;
    }

    spdlog::info("Cursor pos {}, {}", cursorPos.x, cursorPos.y);
}
