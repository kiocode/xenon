#include <xenon/di_manager.hpp>
#include <xenon/features/game.hpp>
#include "utility/vec2.hpp"

class Builder {
public:
	DIManager Services;
	Game GameManager; // maybe a service

    void SetDebugLogLevel();
    void SetInfoLogLevel();
    void SetErrorLogLevel();

    void Build();

private:
    void GetDesktopResolution(int& horizontal, int& vertical);
};
