#include <xenon/components/features/game.hpp>

#include <xenon/utility/random.hpp>
#include <kiero/kiero.h>
#include <xenon/models/enums/rendering_hook_type.hpp>
#include <xenon/core/system.hpp>
#include <xenon/components/features/radar.hpp>
#include <xenon/components/features/esp.hpp>
#include <xenon/components/features/aimbot.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/services/ui_service.hpp>
#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/components/services/memory_service.hpp>
#include <xenon/components/services/notification_service.hpp>

void Game::EnableUpdate() {

	if (m_pXenon->g_pSystem->IsInternal()) {

		switch (m_pXenonVariables->g_renderingType) {
			case RenderingHookType::KIERO: {
				kiero::bind(8, (void**)&m_pXenon->g_cUIService->oPresent, Game::BindForInternal);
			} break;
			case RenderingHookType::DISCORD: {
				uint64_t discordPresentOffset = 0x1060E0;
				uint64_t presentDiscordAddr = (uint64_t)(GetModuleHandleA("DiscordHook64.dll")) + discordPresentOffset;
				Present* discordPresent = (Present*)presentDiscordAddr;
				m_pXenon->g_cUIService->oPresent = *discordPresent;
				_InterlockedExchangePointer((volatile PVOID*)presentDiscordAddr, Game::BindForInternal);
			} break;
			case RenderingHookType::STEAM: {
				uint64_t steamPresentOffset = 0x150D70;
				uint64_t presentSteamAddr = (uint64_t)(GetModuleHandleA("GameOverlayRenderer64.dll")) + steamPresentOffset;
				Present* steamPresent = (Present*)presentSteamAddr;
				m_pXenon->g_cUIService->oPresent = *steamPresent;
				_InterlockedExchangePointer((volatile PVOID*)presentSteamAddr, Game::BindForInternal);
			} break;
		}

	}
	else {

		// enable hooks
		BindForExternal();
	}

}

#pragma region Game:Private

// called one time and it makes a loop of call manually
void Game::BindForExternal() {

	auto previousTime = std::chrono::steady_clock::now();
	m_pXenon->g_pSystem->g_fStartPlayTime = static_cast<float>(previousTime.time_since_epoch().count());

	if (m_pXenonVariables->g_bRenderUI) {
		m_pXenon->g_cUIService->InitExternal();
	}

	//update loop
	while (m_pXenonVariables->g_bUpdate) {
		if(!m_pXenon->g_cMemoryService->IsGameRunning()) {
			spdlog::error("Game is not running, exiting...");
			exit(0);
		}

		auto currentTime = std::chrono::steady_clock::now();
		m_pXenon->g_pSystem->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
		previousTime = currentTime;

		Update();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));

	}

	if (m_pXenonVariables->g_bRenderUI) {
		m_pXenon->g_cUIService->Destroy();
	}
}

// looply called by the hook
HRESULT __stdcall Game::BindForInternal(IDXGISwapChain* pSwapChain, UINT nSyncInterval, UINT nFlags) {
	if (!m_bInit && m_bRenderUI)
	{
		if (!m_pUIService->InitPresent(pSwapChain)) {
			return m_pUIService->oPresent(pSwapChain, nSyncInterval, nFlags);
		}
		else {
			m_pUIService->CreateImGuiUI();
			m_bInit = true;
		}
	}

	UpdateWrapper();

	return m_pUIService->oPresent(pSwapChain, nSyncInterval, nFlags);
}

bool init = false;
void Game::Update() {

	if (m_bRenderUI) {
		m_pUIService->BeginRenderUI();
	}

	TriggerEvent("Update");
	HandleShortcuts();

	for (std::shared_ptr<CComponent> &component : m_pComponents) {
		component->Update();
	}

	if (!init) {
		char aBuff[99];
		sprintf_s(aBuff, "%s initialized", m_pXenon->g_pSystem->GetAppTitle()->c_str());
		m_pXenon->g_cNotificationService->Notify(m_pXenon->g_pSystem->GetAppTitle()->c_str(), aBuff);
		init = true;
	}

	for (TargetProfile& target : m_pXenonConfigs->g_pGameVariables->g_vTargets) {
		TriggerEvent("UpdateCurrentTarget", &target);

		float distance = 0;
		if (m_pXenon->g_pSystem->Is3DGame()) {

			if (!m_pXenon->g_pSystem->m_fnW2S3D) {
				throw std::runtime_error("No world to screen 3D function set");
				return;
			}
			else if (!m_pXenon->g_pSystem->m_fnW2S3D(target.m_vPos3D).IsValid()) {
				continue;
			}

			distance = target.m_vPos3D.Distance(m_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos3D);

		}
		else {

			if (!m_pXenon->g_pSystem->m_fnW2S2D) {
				throw std::runtime_error("No world to screen 2D function set");
				return;
			}
			else if (!m_pXenon->g_pSystem->m_fnW2S2D(target.m_vPos2D).IsValid()) {
				continue;
			}

			distance = target.m_vPos2D.Distance(m_pXenonConfigs->g_pGameVariables->g_vLocal.m_vPos2D);

		}

		for (std::shared_ptr<CComponent>& component : m_pComponents) {
			component->UpdateCurrentTarget(&target);
		}
	}

	if (m_bRenderUI) {
		m_pUIService->EndRenderUI();
	}

}

void Game::HandleShortcuts() {

	if (GetAsyncKeyState(m_pXenonVariables->g_nToggleUIKey) & 1) {
		m_pXenonVariables->g_bShowMenu = !m_pXenonVariables->g_bShowMenu;

		if (!m_pXenon->g_pSystem->IsInternal()) {
			if (m_pXenonVariables->g_bShowMenu) m_pXenon->g_cUIService->SetMenuOpen();
			else m_pXenon->g_cUIService->SetMenuClose();
		}
	}

}

#pragma endregion
