#include <xenon/services/aim_service.hpp>
#include <spdlog/spdlog.h>
#include <xenon/utility/random.hpp>

void AimService::KeepRecoil() {
    float playTime = m_pGame->GetPlayTime();

    int adjustedVerticalOffset = static_cast<int>(
        (m_pConfigs->m_fRecoilVerticalStrength * 0.4) * m_pGame->g_fDeltaTime
    );

    int adjustedHorizontalOffset = static_cast<int>(
        (m_pConfigs->m_fRecoilTiltStrength * 0.4) * std::sin(playTime) * m_pGame->g_fDeltaTime
    );

    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dx = adjustedHorizontalOffset;
    input.mi.dy = adjustedVerticalOffset;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;

    SendInput(1, &input, sizeof(INPUT));
}

void AimService::Aim(Vec2& target) {

    if (m_pConfigs->m_bSmooth) {
        SmoothMoveToTarget(target);
    }
    else if (m_pConfigs->m_bHumanize) {
        Humanize(target);
    }
    else {
        SetCursorPos(target.x, target.y);
    }

    spdlog::debug("Aiming at {}, {}", target.x, target.y);

}

#pragma region AimService::Private

void AimService::SmoothMoveToTarget(Vec2& target) {

    POINT cursorPos;
    GetCursorPos(&cursorPos);

    float stepX = (target.x - cursorPos.x) / m_pConfigs->m_fSmooth;
    float stepY = (target.y - cursorPos.y) / m_pConfigs->m_fSmooth;

    for (int i = 1; i <= m_pConfigs->m_fSmooth; ++i) {
        float nextX = cursorPos.x + stepX * i;
        float nextY = cursorPos.y + stepY * i;

        SetCursorPos(static_cast<int>(nextX), static_cast<int>(nextY));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void AimService::Humanize(Vec2& target) {

    POINT cursorPos;
    GetCursorPos(&cursorPos);

    std::vector<Vec2> controlPoints = GenerateBezierControlPoints({ static_cast<float>(cursorPos.x), static_cast<float>(cursorPos.y) }, target);

    for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
        Vec2 point = CalculateBezierPoint(t, controlPoints);
        SetCursorPos(static_cast<int>(point.x), static_cast<int>(point.y));
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

std::vector<Vec2> AimService::GenerateBezierControlPoints(const Vec2& start, const Vec2& target) {
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

Vec2 AimService::CalculateBezierPoint(float t, const std::vector<Vec2>& points) {
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
void AimService::TrackMouse() {
    POINT cursorPos;
    if (!GetCursorPos(&cursorPos)) {
        spdlog::error("Failed to get cursor position");
        return;
    }

    spdlog::info("Cursor pos {}, {}", cursorPos.x, cursorPos.y);
}

#pragma endregion
