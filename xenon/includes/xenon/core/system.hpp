#pragma once

#include <string>
#include <functional>

#include <xenon/utility/vec2.hpp>
#include <xenon/models/game_dimensions.hpp>
#include <xenon/utility/vec3.hpp>

class System {
public:

	float g_fStartPlayTime;
	float g_fDeltaTime;

	std::function<Vec2* (Vec2)> m_fnW2S2D;
	std::function<Vec2* (Vec3)> m_fnW2S3D;

	float GetPlayTime() const;

	Vec2 GetScreenResolution();
	Vec2 GetScreenCenter();

	Vec2 GetMousePos();

	void SetAppTitle(std::string title) {
		m_strAppTitle = title;
	}

	std::string* GetAppTitle() {
		return &m_strAppTitle;
	}

	void IsInternal(bool isInternal) {
		m_bIsInternal = isInternal;
	}

	bool IsInternal() const {
		return m_bIsInternal;
	}

	void SetGameDimension(GameDimensions dim) {
		m_gameDim = dim;
	}

	GameDimensions GetGameDimension() const {
		return m_gameDim;
	}

private:
	std::string m_strAppTitle;
	bool m_bIsInternal;
	GameDimensions m_gameDim = GameDimensions::DIMENSION_2D;

	void GetDesktopResolution(int& horizontal, int& vertical);

};