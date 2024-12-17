#pragma once

#include <memory>
#include <vector>
#include <spdlog/spdlog.h>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aimbot_config.hpp>

class Aimbot {
public:
    Aimbot(std::shared_ptr<AimbotConfig> configs) : m_pConfigs(configs) { }

    bool IsTargetEmpty();
    void SetTarget(Vec2 pos);
    bool IsTargetReached();
    void Aim();
    void TrackMouse();
    void MoveDirectlyToTarget();

private:
    std::shared_ptr<AimbotConfig> m_pConfigs;
    Vec2 m_vTarget;

    void Humanize();
    void ResetTarget();
    void SmoothMoveToTarget();
    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);
    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};
