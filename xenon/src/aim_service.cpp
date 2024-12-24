#include <xenon/services/aim_service.hpp>
#include <spdlog/spdlog.h>
#include <xenon/utility/random.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void AimService::KeepRecoil() {
    float playTime = m_pSystem->GetPlayTime();

    double adjustedVerticalOffset = m_pConfigs->m_fRecoilVerticalStrength * 10 * m_pSystem->g_fDeltaTime;

    double adjustedHorizontalOffset = m_pConfigs->m_fRecoilTiltStrength * std::sin(playTime) * m_pSystem->g_fDeltaTime;

    MoveMouseTo({ adjustedHorizontalOffset, adjustedVerticalOffset });
}

void AimService::Aim(Vec2& target) {
    if (m_pConfigs->m_bSmooth) {
        SmoothMoveToTarget(target);
    }
    else if (m_pConfigs->m_bHumanize) {
        Humanize(target);
    }
    else {
        MoveMouseTo(target);
    }

    spdlog::debug("Aiming at {}, {}", target.x, target.y);
}

void AimService::Spin2D() {
    static float angle = 0.0f;

    angle += m_pConfigs->m_fSpinbotSpeed;
    if (angle >= 360.0f) angle = 0.0f;

    float x = std::cos(angle * M_PI / 180.0f) * m_pConfigs->m_fSpinbotRadius + m_pSystem->GetScreenCenter().x;
    float y = std::sin(angle * M_PI / 180.0f) * m_pConfigs->m_fSpinbotRadius + m_pSystem->GetScreenCenter().y;

    SetMouseTo({ x, y });
}

void AimService::Spin3D() {
    static float angle = 0.0f;
    int centerX = GetSystemMetrics(SM_CXSCREEN) / 2;
    int centerY = GetSystemMetrics(SM_CYSCREEN) / 2;

    angle += m_pConfigs->m_fSpinbotSpeed;  
    if (angle >= 360.0f) angle = 0.0f;

    float x = std::cos(angle * M_PI / 180.0f) * m_pConfigs->m_fSpinbotRadius + centerX;
    float y = std::sin(angle * M_PI / 180.0f) * m_pConfigs->m_fSpinbotRadius + centerY;
    float z = std::cos(angle * M_PI / 180.0f) * m_pConfigs->m_fSpinbotDepth;

    SetMouseTo({ x, y });
    spdlog::info("3D spin at depth: {}", z);
}

#pragma region AimService::Private

void AimService::SmoothMoveToTarget(Vec2& target) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    double stepX = (target.x - cursorPos.x) / m_pConfigs->m_fSmooth;
    double stepY = (target.y - cursorPos.y) / m_pConfigs->m_fSmooth;

    for (int i = 1; i <= m_pConfigs->m_fSmooth; ++i) {
        double nextX = cursorPos.x + stepX * i;
        double nextY = cursorPos.y + stepY * i;

        SetMouseTo({ nextX, nextY });
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void AimService::Humanize(Vec2& target) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    std::vector<Vec2> controlPoints = GenerateBezierControlPoints({ static_cast<float>(cursorPos.x), static_cast<float>(cursorPos.y) }, target);

    for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
        Vec2 point = CalculateBezierPoint(t, controlPoints);
        SetMouseTo(point);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

std::vector<Vec2> AimService::GenerateBezierControlPoints(const Vec2& start, const Vec2& target) {
    std::vector<Vec2> points;

    double minX = std::min(start.x, target.x);
    double maxX = std::max(start.x, target.x);
    double minY = std::min(start.y, target.y);
    double maxY = std::max(start.y, target.y);

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

void AimService::MoveMouseTo(Vec2 pos) {

    int x = static_cast<int>(pos.x);
    int y = static_cast<int>(pos.y);

    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;

    SendInput(1, &input, sizeof(INPUT));
}

void AimService::SetMouseTo(Vec2 pos) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int x = static_cast<int>((pos.x / screenWidth) * 65535.0f);
    int y = static_cast<int>((pos.y / screenHeight) * 65535.0f);

    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

    SendInput(1, &input, sizeof(INPUT));
}

#pragma endregion
