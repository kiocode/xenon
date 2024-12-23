#include <xenon/core/external_cheat.hpp>

void ExternalCheat::Run() {
	spdlog::info("External cheat initialized");

	m_pGame->Update();    
}