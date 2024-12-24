#include <xenon/features/game.hpp>
#include <xenon/utility/random.hpp>

void Game::Update() {

	auto previousTime = std::chrono::steady_clock::now();
	m_pSystem->g_fStartPlayTime = previousTime.time_since_epoch().count();

	while (m_pConfigs->m_bUseUpdate) {
		auto currentTime = std::chrono::steady_clock::now();
		m_pSystem->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
		previousTime = currentTime;

		TriggerEvent("OnUpdate");

		if (GetAsyncKeyState(VK_ESCAPE)) {
			continue;
		}

		if (m_pConfigs->m_bUseAimbot) {
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

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

}

#pragma region Game:Private


#pragma endregion
