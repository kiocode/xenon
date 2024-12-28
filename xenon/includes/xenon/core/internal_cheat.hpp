#pragma once

#include <memory>

#include <xenon/interfaces/cheat_interface.hpp>
#include <xenon/features/game.hpp>

enum class UnityEngineType {
	IL2CPP,
	Mono
};

enum class UnrealEngineVersion {
	UE3,
	UE4,
	UE5
};

class InternalCheat : public Cheat {
public:

	InternalCheat(std::shared_ptr<Game> game, std::shared_ptr<GameConfig> gameConfig, std::shared_ptr<UIService> UIService) : Cheat(gameConfig), m_pGame(game), m_pUIService(UIService) { }

	void IsUnityEngine(UnityEngineType type);
	void IsUnrealEngine(UnrealEngineVersion version);

	void Run() override;

private:
	std::shared_ptr<Game> m_pGame;
	std::shared_ptr<UIService> m_pUIService;

	void InitialSetup();
};