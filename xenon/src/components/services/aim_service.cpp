#include <xenon/components/services/aim_service.hpp>

#include <spdlog/spdlog.h>
#include <xenon/utility/random.hpp>
#include <xenon/core/system.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void CAimService::Update() {

	if (GetAsyncKeyState(VK_ESCAPE)) return;

    if (g_pXenonVariables->g_bNoRecoil) {
        if (GetAsyncKeyState(VK_RBUTTON) && GetAsyncKeyState(VK_LBUTTON)) {
            KeepRecoil();
        }
    }

    if (g_pXenonVariables->g_bSpinbot2D) {
        Spin2D();
    }

    if (g_pXenonVariables->g_bSpinbot3D) {
        Spin3D();
    }

}

void CAimService::KeepRecoil() {
    float playTime = g_pXenon->g_pSystem->GetPlayTime();

    float adjustedVerticalOffset = g_pXenonConfigs->g_pAimConfig->m_fRecoilVerticalStrength * 10 * g_pXenon->g_pSystem->g_fDeltaTime;

    float adjustedHorizontalOffset = g_pXenonConfigs->g_pAimConfig->m_fRecoilTiltStrength * std::sin(playTime) * g_pXenon->g_pSystem->g_fDeltaTime;

    MoveMouseTo({ adjustedHorizontalOffset, adjustedVerticalOffset });
}

void CAimService::Aim(Vec2& target) {
    if (g_pXenonVariables->g_bSmooth) {
        SmoothMoveToTarget(target);
    }
    else if (g_pXenonVariables->g_bHumanize) {
        Humanize(target);
    }
    else {
        SetAimPos(target);
    }

    spdlog::debug("Aiming at {}, {}", target.x, target.y);
}

void CAimService::Spin2D() {
    static float angle = 0.0f;

    angle += g_pXenonConfigs->g_pAimConfig->m_fSpinbotSpeed;
    if (angle >= 360.0f) angle = 0.0f;

    float x = static_cast<float>(std::cos(angle * M_PI / 180.0f)) * g_pXenonConfigs->g_pAimConfig->m_fSpinbotRadius + g_pXenon->g_pSystem->GetScreenCenter().x;
    float y = static_cast<float>(std::sin(angle * M_PI / 180.0f)) * g_pXenonConfigs->g_pAimConfig->m_fSpinbotRadius + g_pXenon->g_pSystem->GetScreenCenter().y;

    SetAimPos({ x, y });
}

void CAimService::Spin3D() {
    static float angle = 0.0f;
    int centerX = GetSystemMetrics(SM_CXSCREEN) / 2;
    int centerY = GetSystemMetrics(SM_CYSCREEN) / 2;

    angle += g_pXenonConfigs->g_pAimConfig->m_fSpinbotSpeed;
    if (angle >= 360.0f) angle = 0.0f;

    float x = static_cast<float>(std::cos(angle * M_PI / 180.0f) * g_pXenonConfigs->g_pAimConfig->m_fSpinbotRadius + centerX);
    float y = static_cast<float>(std::sin(angle * M_PI / 180.0f) * g_pXenonConfigs->g_pAimConfig->m_fSpinbotRadius + centerY);
    float z = static_cast<float>(std::cos(angle * M_PI / 180.0f) * g_pXenonConfigs->g_pAimConfig->m_fSpinbotDepth);

    SetAimPos({ x, y });
}
//
//Vec2* CAimService::GetNearestPos(std::vector<TargetProfile> targets, TargetProfile local) {
//    float maxdist = 99999;
//
//	return GetNearestPos(targets, local, maxdist);
//}
//
//Vec2* CAimService::GetNearestPos(std::vector<TargetProfile> targets, TargetProfile local, float maxdist) {
//	Vec2 nearest = nullptr;
//	float minDistance = maxdist;
//
//    if (g_pXenon->g_pSystem->Is3DGame()) {
//
//        if (!g_pXenon->g_pSystem->m_fnW2S3D) {
//            spdlog::error("World to screen 3D function not set");
//            return nullptr;
//        }
//
//        for (TargetProfile target : targets) {
//            float distance = target.m_vPos3D.Distance(local.m_vPos3D);
//            if (distance < minDistance) {
//                minDistance = distance;
//                nearest = g_pXenon->g_pSystem->m_fnW2S3D(target.m_vPos3D);
//            }
//        }
//
//    } else {
//
//        if (!g_pXenon->g_pSystem->m_fnW2S2D) {
//            spdlog::error("World to screen 2D function not set");
//			return nullptr;
//        }
//
//        for (TargetProfile target : targets) {
//            float distance = target.m_vPos2D.Distance(local.m_vPos2D);
//            if (distance < minDistance) {
//                minDistance = distance;
//                nearest = g_pXenon->g_pSystem->m_fnW2S2D(target.m_vPos2D);
//            }
//        }
//
//    }
//
//
//	return nearest;
//}

#pragma region CAimService::Private

void CAimService::SmoothMoveToTarget(Vec2& target) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    float stepX = (target.x - cursorPos.x) / g_pXenonConfigs->g_pAimConfig->m_fSmooth;
    float stepY = (target.y - cursorPos.y) / g_pXenonConfigs->g_pAimConfig->m_fSmooth;

    float nextX = cursorPos.x + stepX;
    float nextY = cursorPos.y + stepY;

    SetAimPos({ nextX, nextY });
}

void CAimService::Humanize(Vec2& target) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    std::vector<Vec2> controlPoints = GenerateBezierControlPoints({ static_cast<float>(cursorPos.x), static_cast<float>(cursorPos.y) }, target);

    for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
        Vec2 point = CalculateBezierPoint(t, controlPoints);
        SetAimPos(point);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

std::vector<Vec2> CAimService::GenerateBezierControlPoints(const Vec2& start, const Vec2& target) {
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

Vec2 CAimService::CalculateBezierPoint(float t, const std::vector<Vec2>& points) {
    float x = static_cast<float>(std::pow(1 - t, 3) * points[0].x +
        3 * std::pow(1 - t, 2) * t * points[1].x +
        3 * (1 - t) * std::pow(t, 2) * points[2].x +
        std::pow(t, 3) * points[3].x);

    float y = static_cast<float>(std::pow(1 - t, 3) * points[0].y +
        3 * std::pow(1 - t, 2) * t * points[1].y +
        3 * (1 - t) * std::pow(t, 2) * points[2].y +
        std::pow(t, 3) * points[3].y);

    return { x, y };
}

void CAimService::TrackMouse() {
    Vec2 cursorPos = g_pXenon->g_pSystem->GetMousePos();

    spdlog::info("Cursor pos {}, {}", cursorPos.x, cursorPos.y);
}

void CAimService::MoveMouseTo(Vec2 pos) {
    int x = static_cast<int>(pos.x);
    int y = static_cast<int>(pos.y);

    switch (g_pXenonConfigs->g_pAimConfig->m_nMouseInputMode) {
        case 0: { 
            INPUT input = {};
            input.type = INPUT_MOUSE;
            input.mi.dx = x;
            input.mi.dy = y;
            input.mi.dwFlags = MOUSEEVENTF_MOVE;
            SendInput(1, &input, sizeof(INPUT));
            break;
        }
        case 1: { 
            SetCursorPos(x, y);
            break;
        }
        case 2: { 
            HWND hwnd = GetForegroundWindow();
            if (hwnd) {
                LPARAM lParam = MAKELPARAM(x, y);
                PostMessage(hwnd, WM_MOUSEMOVE, 0, lParam);
            }
            break;
        }
        case 3: {
            int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);
            MouseMove(static_cast<float>(x), static_cast<float>(y),
                static_cast<float>(screenWidth), static_cast<float>(screenHeight),
                g_pXenonConfigs->g_pAimConfig->m_fSmooth);
            break;
        }
    }
}

void CAimService::SetMouseTo(Vec2 pos) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int x = static_cast<int>((pos.x / screenWidth) * 65535.0f);
    int y = static_cast<int>((pos.y / screenHeight) * 65535.0f);

    switch (g_pXenonConfigs->g_pAimConfig->m_nMouseInputMode) {
        case 0: { 
            INPUT input = {};
            input.type = INPUT_MOUSE;
            input.mi.dx = x;
            input.mi.dy = y;
            input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
            SendInput(1, &input, sizeof(INPUT));
            break;
        }
        case 1: { 
            SetCursorPos(static_cast<int>(pos.x), static_cast<int>(pos.y));
            break;
        }
        case 2: {
            HWND hwnd = GetForegroundWindow();
            if (hwnd) {
                LPARAM lParam = MAKELPARAM(static_cast<int>(pos.x), static_cast<int>(pos.y));
                PostMessage(hwnd, WM_MOUSEMOVE, 0, lParam);
            }
            break;
        }
        case 3: { 
            MouseMove(static_cast<float>(pos.x), static_cast<float>(pos.y),
                static_cast<float>(screenWidth), static_cast<float>(screenHeight),
                g_pXenonConfigs->g_pAimConfig->m_fSmooth);
            break;
        }
    }
}

void CAimService::MouseMove(float tarx, float tary, float X, float Y, int smooth) {
    float ScreenCenterX = (X / 2);
    float ScreenCenterY = (Y / 2);
    float TargetX = 0;
    float TargetY = 0;

    smooth = smooth + 3;

    if (tarx != 0) {
        if (tarx > ScreenCenterX) {
            TargetX = -(ScreenCenterX - tarx);
            TargetX /= smooth;
            if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
        }
        else {
            TargetX = tarx - ScreenCenterX;
            TargetX /= smooth;
            if (TargetX + ScreenCenterX < 0) TargetX = 0;
        }
    }

    if (tary != 0) {
        if (tary > ScreenCenterY) {
            TargetY = -(ScreenCenterY - tary);
            TargetY /= smooth;
            if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
        }
        else {
            TargetY = tary - ScreenCenterY;
            TargetY /= smooth;
            if (TargetY + ScreenCenterY < 0) TargetY = 0;
        }
    }

    mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), 0, 0);
}

void CAimService::SetAimPos(Vec2 pos) {

    if (g_pXenonConfigs->g_pAimConfig->m_fnCustomAim) {
        g_pXenonConfigs->g_pAimConfig->m_fnCustomAim(pos);
    }
    else {
        SetMouseTo(pos);
    }

}

#pragma endregion
