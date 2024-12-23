#pragma once

#include <memory>

#include <xenon/interfaces/cheat_interface.hpp>
#include <xenon/features/game.hpp>

class ExternalCheat : public Cheat {
public:

	ExternalCheat(std::shared_ptr<Game> game, std::shared_ptr<GameConfig> gameConfig) : Cheat(gameConfig), m_pGame(game) { }

	void Run() override;

private:
	std::shared_ptr<Game> m_pGame;
};