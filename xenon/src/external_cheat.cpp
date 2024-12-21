#include <xenon/core/external_cheat.hpp>

void ExternalCheat::Run() {
	spdlog::info("Running external cheats");

	m_pGame->Update();    
}