#pragma once

#include <string>
#include <functional>

#include <spdlog/spdlog.h>

#include <xenon/utility/vec2.hpp>
#include <xenon/utility/vec3.hpp>
#include <xenon/models/enums/game_dimension.hpp>
#include <xenon/models/enums/rendering_type.hpp>
#include <xenon/models/enums/gameengine_type.hpp>
#include <xenon/models/enums/unityengine_type.hpp>
#include <xenon/models/enums/unrealengine_version.hpp>

class System {
public:

	intptr_t g_pUnityBase = 0;
	intptr_t g_pUnityGameAssembly = 0;
	intptr_t g_pUnityPlayer = 0;

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

	void IsUnityEngine(UnityEngineType type) {
		if (!m_bIsInternal) {
			spdlog::warn("External cheat cannot change to Unity Engine.");
		}

		m_gameEngineType = GameEngineType::UNITY_ENGINE;
		m_unityEngineType = type;
	}

	void IsUnrealEngine(UnrealEngineVersion version) {
		if (!m_bIsInternal) {
			spdlog::warn("External cheat cannot change to Unreal Engine.");
		}

		m_gameEngineType = GameEngineType::UNREAL_ENGINE;
		m_unrealEngineVersion = version;
	}

	void SetGameDimension(GameDimension dim) {
		m_gameDimension = dim;
	}

	GameDimension GetGameDimension() const {
		return m_gameDimension;
	}

	bool Is3DGame() const {
		return m_gameDimension == GameDimension::DIM_3D;
	}

	void SetRenderingType(RenderingType type) {

		if (!m_bIsInternal) {
			spdlog::warn("External cheat cannot change rendering type, DX11 will be used.");
		}

		m_renderingType = type;
	}

	RenderingType GetRenderingType() const {
		return m_renderingType;
	}

private:
	std::string m_strAppTitle;
	bool m_bIsInternal;
	GameEngineType m_gameEngineType = GameEngineType::ENGINE_NONE;
	UnityEngineType m_unityEngineType = UnityEngineType::UNITY_NONE;
	UnrealEngineVersion m_unrealEngineVersion = UnrealEngineVersion::UNREAL_NONE;
	GameDimension m_gameDimension = GameDimension::DIM_NONE;
	RenderingType m_renderingType = RenderingType::REND_NONE;

	void GetDesktopResolution(int& horizontal, int& vertical);

};