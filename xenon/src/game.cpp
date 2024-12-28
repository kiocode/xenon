#include <xenon/features/game.hpp>
#include <xenon/utility/random.hpp>
#include <kiero/kiero.h>

void Game::EnableUpdate() {

	if (m_pSystem->IsInternal()) {
		kiero::bind(8, (void**)&m_pUIService->oPresent, UIService::hkPresentWrapper);
	}
	else {

		auto previousTime = std::chrono::steady_clock::now();
		m_pSystem->g_fStartPlayTime = previousTime.time_since_epoch().count();

		if (m_pConfigs->m_bUseCustomUI) {
			m_pUIService->Init();
		}

		while (m_pConfigs->m_bUseUpdate) {
			auto currentTime = std::chrono::steady_clock::now();
			m_pSystem->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
			previousTime = currentTime;

			if (GetAsyncKeyState(VK_ESCAPE)) {
				continue;
			}

			TriggerEvent("Update");

			HandleShortcuts();

			if (m_pConfigs->m_bUseCustomUI && UIService::m_bShowMenu) {
				m_pUIService->Update();
			}

			Update();

			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}

		if (m_pConfigs->m_bUseCustomUI) {
			m_pUIService->Destroy();
		}
	}

}

#pragma region Game:Private

void Game::Update() {


	if (m_pConfigs->m_bUseAimbot) {

		if (m_pAimConfigs->m_bNearest) {

			Vec2* nearest = m_pAimService->GetNearestPos(m_vTargets, m_vLocalPos, m_pAimConfigs->m_fNearest);

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
		m_pUIService->m_bShowMenu = !UIService::m_bShowMenu;
		if (UIService::m_bShowMenu) m_pUIService->SetMenuOpen();
		else m_pUIService->SetMenuClose();
	}


}

#pragma endregion
