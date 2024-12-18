#include <xenon/di_manager.hpp>
#include <xenon/features/game.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/services/aim_service.hpp>

class Builder {
public:
	DIManager Services;
    std::shared_ptr<Game> GameManager;

    Builder() {
        GameManager = Services.AddSingleton<Game>([this]() { return std::make_shared<Game>(); });
        Services.AddSingleton<AimService>([this]() { return std::make_shared<AimService>(); });
    }

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetErrorLogLevel();

    void DisableUpdate();
    void BuildAndRun();

private:
    bool m_bUseUpdate = true;
    
    void GetDesktopResolution(int& horizontal, int& vertical);
};
