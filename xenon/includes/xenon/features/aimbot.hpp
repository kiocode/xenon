#pragma once

#include <memory>
#include <vector>
#include <spdlog/spdlog.h>

#include <xenon/utility/vec2.hpp>
#include <xenon/configs/aimbot_config.hpp>
#include <xenon/features/game.hpp>

class Aimbot {
public:
    Aimbot(
        std::shared_ptr<AimbotConfig> configs,
        std::shared_ptr<Game> game,
        std::shared_ptr<AimService> aimService
    ) : m_pConfigs(configs), m_pGame(game), m_pAimService(aimService) { }

    bool IsTargetEmpty() const;
    void SetTarget(Vec2 pos);
    bool IsTargetReached() const;
    void TrackMouse();
    void AimTarget();
    void AimTargetWithPrediction(Vec2* vel);

private:
    std::shared_ptr<AimbotConfig> m_pConfigs;
    std::shared_ptr<Game> m_pGame;
    std::shared_ptr<AimService> m_pAimService;
    Vec2 m_vTarget;

    void MoveDirectlyToTarget(Vec2* target);
    void Humanize(Vec2* target);
    void ResetTarget();
    void SmoothMoveToTarget(Vec2* target);
    std::vector<Vec2> GenerateBezierControlPoints(const Vec2& start, const Vec2& target);
    Vec2 CalculateBezierPoint(float t, const std::vector<Vec2>& points);
};
