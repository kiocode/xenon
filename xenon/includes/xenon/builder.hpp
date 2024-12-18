#include <xenon/di_manager.hpp>
#include <xenon/features/game.hpp>
#include <xenon/utility/vec2.hpp>
#include <xenon/services/aim_service.hpp>

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
    void BuildAndRun();

private:
    bool m_bUseUpdate = true;
    
    void RegisterDefaultServices();
    void GetDesktopResolution(int& horizontal, int& vertical);
};
