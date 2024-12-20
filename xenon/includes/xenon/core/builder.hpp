#include <chrono>

#include <xenon/core/di_manager.hpp>
#include <xenon/features/game.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/services/aim_service.hpp>
#include <spdlog/spdlog.h>

class Builder {
public:
	DIManager Services;
    std::shared_ptr<Game> GameManager;

    Builder() {
        RegisterDefaultServices();
    }

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetErrorLogLevel();

    void DisableUpdate();
    void BuildAndRun() const;

    Vec2 GetScreenResolution() {
        int width, height;
        GetDesktopResolution(width, height);

        Vec2 resolution{ static_cast<double>(width), static_cast<double>(height) };

        spdlog::debug("Screen resolution: {}x{}", resolution.x, resolution.y);
    }

    Vec2 GetScreenCenter() {
        int width, height;
        GetDesktopResolution(width, height);

        Vec2 center{ static_cast<double>(width / 2), static_cast<double>(height / 2) };

        spdlog::debug("Screen center: {}, {}", center.x, center.y);
    }

private:
    bool m_bUseUpdate = true;
    
    void RegisterDefaultServices();
    void GetDesktopResolution(int& horizontal, int& vertical);
};
