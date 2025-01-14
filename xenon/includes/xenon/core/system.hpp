#pragma once

#include <string>
#include <functional>

#include <spdlog/spdlog.h>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/enums/game_dimensions.hpp>
#include <xenon/models/enums/rendering_types.hpp>
#include <xenon/models/enums/gameengine_types.hpp>
#include <xenon/models/enums/unityengine_types.hpp>
#include <xenon/models/enums/unrealengine_versions.hpp>

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

	void IsUnityEngine(UnityEngineTypes type) {
		if (!m_bIsInternal) {
			spdlog::warn("External cheat cannot change to Unity Engine.");
		}

		m_gameEngineType = GameEngineTypes::UNITY_ENGINE;
		m_unityEngineType = type;
	}

	void IsUnrealEngine(UnrealEngineVersions version) {
		if (!m_bIsInternal) {
			spdlog::warn("External cheat cannot change to Unreal Engine.");
		}

		m_gameEngineType = GameEngineTypes::UNREAL_ENGINE;
		m_unrealEngineVersion = version;
	}

	void SetGameDimension(GameDimensions dim) {
		m_gameDimension = dim;
	}

	GameDimensions GetGameDimension() const {
		return m_gameDimension;
	}

	bool Is3DGame() const {
		return m_gameDimension == GameDimensions::DIMENSION_3D;
	}

	void SetRenderingType(RenderingTypes type) {

		if (!m_bIsInternal) {
			spdlog::warn("External cheat cannot change rendering type, DX11 will be used.");
		}

		m_renderingType = type;
	}

	RenderingTypes GetRenderingType() const {
		return m_renderingType;
	}

private:
	std::string m_strAppTitle;
	bool m_bIsInternal;
	GameEngineTypes m_gameEngineType = GameEngineTypes::ENGINE_NONE;
	UnityEngineTypes m_unityEngineType = UnityEngineTypes::UNITY_NONE;
	UnrealEngineVersions m_unrealEngineVersion = UnrealEngineVersions::UNREAL_NONE;
	GameDimensions m_gameDimension = GameDimensions::DIM_NONE;
	RenderingTypes m_renderingType = RenderingTypes::REND_NONE;

	void GetDesktopResolution(int& horizontal, int& vertical);
	
};