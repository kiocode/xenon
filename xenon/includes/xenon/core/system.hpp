#pragma once
#include <xenon/utility/vec2.hpp>

class System {
public:

	float g_fStartPlayTime;
	float g_fDeltaTime;

	float GetPlayTime() const;

	Vec2 GetScreenResolution();
	Vec2 GetScreenCenter();

private:

	void GetDesktopResolution(int& horizontal, int& vertical);

};