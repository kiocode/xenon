#include <xenon/components/features/game.hpp>

#include <xenon/utility/random.hpp>
#include <kiero/kiero.h>
#include <xenon/models/enums/rendering_hook_types.hpp>
#include <xenon/core/system.hpp>
#include <xenon/components/features/radar.hpp>
#include <xenon/components/features/esp.hpp>
#include <xenon/components/features/aimbot.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/services/ui_service.hpp>
#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/aim_service.hpp>

static void EnableHooks()
{
	// EXAMPLE
	//// Health__TakeDamage
	//if (MH_CreateHook(reinterpret_cast<LPVOID*>(
	//	Offsets::Health__TakeDamage_Offset),
	//	&HooksFunctions::Health__TakeDamage_hook,
	//	(LPVOID*)&HooksFunctions::Health__TakeDamage) == MH_OK)
	//{
	//	MH_EnableHook(reinterpret_cast<LPVOID*>(Offsets::Health__TakeDamage_Offset));
	//}
}

void Game::EnableUpdate() {

	if (m_pXenon->g_pSystem->IsInternal()) {

		EnableHooks();

		switch (m_pXenonVariables->g_renderingType) {
		case RenderingHookTypes::KIERO: {
			kiero::bind(8, (void**)&m_pXenon->g_cUIService->oPresent, Game::hkPresentWrapper);
		} break;
		case RenderingHookTypes::DISCORD: {
			uint64_t discordPresentOffset = 0x1060E0;
			uint64_t presentDiscordAddr = (uint64_t)(GetModuleHandleA("DiscordHook64.dll")) + discordPresentOffset;
			Present* discordPresent = (Present*)presentDiscordAddr;
			m_pXenon->g_cUIService->oPresent = *discordPresent;
			_InterlockedExchangePointer((volatile PVOID*)presentDiscordAddr, Game::hkPresentWrapper);
		} break;
		case RenderingHookTypes::STEAM: {
			uint64_t steamPresentOffset = 0x150D70;
			uint64_t presentSteamAddr = (uint64_t)(GetModuleHandleA("GameOverlayRenderer64.dll")) + steamPresentOffset;
			Present* steamPresent = (Present*)presentSteamAddr;
			m_pXenon->g_cUIService->oPresent = *steamPresent;
			_InterlockedExchangePointer((volatile PVOID*)presentSteamAddr, Game::hkPresentWrapper);
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
		auto currentTime = std::chrono::steady_clock::now();
		m_pXenon->g_pSystem->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
		previousTime = currentTime;

		if (GetAsyncKeyState(VK_ESCAPE)) {
			continue;
		}

		if (m_pXenonVariables->g_bRenderUI) {
			m_pXenon->g_cUIService->BeginRenderUI();
		}
		Update();
		if (m_pXenonVariables->g_bRenderUI) {
			m_pXenon->g_cUIService->EndRenderUI();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	if (m_pXenonVariables->g_bRenderUI) {
		m_pXenon->g_cUIService->Destroy();
	}
}

// looply called by the hook
HRESULT __stdcall Game::BindForInternal(IDXGISwapChain* pSwapChain, UINT nSyncInterval, UINT nFlags) {
	if (!m_bInit && m_pXenonVariables->g_bRenderUI)
	{
		if (!m_pXenon->g_cUIService->InitPresent(pSwapChain)) {
			return m_pXenon->g_cUIService->oPresent(pSwapChain, nSyncInterval, nFlags);
		}
		else {
			m_pXenon->g_cUIService->CreateImGuiUI();
			m_bInit = true;
		}
	}

	if (!GetAsyncKeyState(VK_ESCAPE)) {

		if (m_pXenonVariables->g_bRenderUI) {
			m_pXenon->g_cUIService->BeginRenderUI();
		}
		Update();
		if (m_pXenonVariables->g_bRenderUI) {
			m_pXenon->g_cUIService->EndRenderUI();
		}

	}

	return m_pXenon->g_cUIService->oPresent(pSwapChain, nSyncInterval, nFlags);
}

void Game::Update() {

#pragma region System

	TriggerEvent("Update");
	m_pXenon->g_cLuaService->TriggerOnUpdate();
	HandleShortcuts();

#pragma endregion

	for (std::shared_ptr<CComponent> &component : m_pComponents) {
		component->Update();
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
