#include <xenon/features/game.hpp>
#include <xenon/utility/random.hpp>
#include <kiero/kiero.h>

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

	if (m_pSystem->IsInternal()) {

		EnableHooks();

		switch (m_pConfigs->m_bRenderingType) {
			case RenderingHookTypes::KIERO: {
				kiero::bind(8, (void**)&m_pUIService->oPresent, Game::hkPresentWrapper);
			} break;
			case RenderingHookTypes::DISCORD: {
				uint64_t discordPresentOffset = 0x1060E0;
				uint64_t presentDiscordAddr = (uint64_t)(GetModuleHandleA("DiscordHook64.dll")) + discordPresentOffset;
				Present* discordPresent = (Present*)presentDiscordAddr;
				m_pUIService->oPresent = *discordPresent;
				_InterlockedExchangePointer((volatile PVOID*)presentDiscordAddr, Game::hkPresentWrapper);
			} break;
			case RenderingHookTypes::STEAM: {
				uint64_t steamPresentOffset = 0x150D70;
				uint64_t presentSteamAddr = (uint64_t)(GetModuleHandleA("GameOverlayRenderer64.dll")) + steamPresentOffset;
				Present* steamPresent = (Present*)presentSteamAddr;
				m_pUIService->oPresent = *steamPresent;
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
	m_pSystem->g_fStartPlayTime = static_cast<float>(previousTime.time_since_epoch().count());

	if (m_pConfigs->m_bUseUICustom) {
		m_pUIService->InitExternal();
	}

	//update loop
	while (m_pConfigs->m_bUseUpdate) {
		auto currentTime = std::chrono::steady_clock::now();
		m_pSystem->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
		previousTime = currentTime;

		if (GetAsyncKeyState(VK_ESCAPE)) {
			continue;
		}

		if (m_pConfigs->m_bUseUICustom) {
			m_pUIService->BeginRenderUI();
		}
		Update();
		if (m_pConfigs->m_bUseUICustom) {
			m_pUIService->EndRenderUI();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	if (m_pConfigs->m_bUseUICustom) {
		m_pUIService->Destroy();
	}
}

// looply called by the hook
HRESULT __stdcall Game::BindForInternal(IDXGISwapChain* pSwapChain, UINT nSyncInterval, UINT nFlags) {
	if (!m_bInit && m_pConfigs->m_bUseUICustom)
	{
		if (!m_pUIService->InitPresent(pSwapChain)) {
			return m_pUIService->oPresent(pSwapChain, nSyncInterval, nFlags);
		}
		else {
			m_pUIService->CreateImGuiUI();
			m_bInit = true;
		}
	}
	
	if (!GetAsyncKeyState(VK_ESCAPE)) {

		if (m_pConfigs->m_bUseUICustom) {
			m_pUIService->BeginRenderUI();
		}
		Update();
		if (m_pConfigs->m_bUseUICustom) {
			m_pUIService->EndRenderUI();
		}

	}

	return m_pUIService->oPresent(pSwapChain, nSyncInterval, nFlags);
}

void Game::Update() {

	#pragma region System

	TriggerEvent("Update");
	m_pLuaService->TriggerOnUpdate();
	HandleShortcuts();

	#pragma endregion

	if (m_pConfigs->m_bUseUICustom) {
		m_pUIService->Update();
	}

	#pragma region ESP
	
	if (m_pConfigs->m_bUseESPSnapline) {
		m_pESP->RenderSnapline();
	}
	
	if (m_pConfigs->m_bUseESPBox2D) {
		m_pESP->Render2DBox();
	}

	if (m_pConfigs->m_bUseESPBox3D) {
		m_pESP->Render3DBox();
	}

	if (m_pConfigs->m_bUseESPSkeleton) {
		m_pESP->RenderSkeleton();
	}

	#pragma endregion

	if (m_pConfigs->m_bUseAimbot) {

		if (m_pAimConfigs->m_bNearest) {

			Vec2* nearest = m_pAimService->GetNearestPos(m_pVariables->g_vTargets, m_pVariables->g_vLocal, m_pAimConfigs->m_fNearest);
			if (nearest == nullptr) m_pAimbot->ResetTarget();
			else m_pAimbot->SetTarget(*nearest);

		}

		m_pAimbot->AimTarget();
	}

	if (m_pConfigs->m_bUseRecoil) {
		if (GetAsyncKeyState(VK_RBUTTON) && GetAsyncKeyState(VK_LBUTTON)) {
			m_pAimService->KeepRecoil();
		}
	}

	if (m_pConfigs->m_bUse2DSpinbot) {
		m_pAimService->Spin2D();
	}

	if (m_pConfigs->m_bUse3DSpinbot) {
		m_pAimService->Spin3D();
	}

}

void Game::HandleShortcuts() {

	if (GetAsyncKeyState(m_pConfigs->m_nToggleUIKey) & 1) {
		m_pUIService->m_bShowMenu = !m_pUIService->m_bShowMenu;

		if (!m_pSystem->IsInternal()) {
			if (m_pUIService->m_bShowMenu) m_pUIService->SetMenuOpen();
			else m_pUIService->SetMenuClose();
		}
	}

}

#pragma endregion
