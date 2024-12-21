#include <xenon/features/game.hpp>
#include <xenon/utility/random.hpp>


void Game::Update() {

	auto previousTime = std::chrono::steady_clock::now();
	m_pSystem->g_fStartPlayTime = previousTime.time_since_epoch().count();

	while (m_pConfigs->m_bUseUpdate) {
		auto currentTime = std::chrono::steady_clock::now();
		m_pSystem->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
		previousTime = currentTime;

		if (GetAsyncKeyState(VK_ESCAPE)) {
			return;
		}

		if (m_pConfigs->m_bUseAimbot) {
			if (m_pAimbot->IsTargetEmpty()) {
				Vec2 randomPos{ round(Random::randomFloat(0, GetScreenResolution().x - 1)), round(Random::randomFloat(0, GetScreenResolution().y - 1)) };
				m_pAimbot->SetTarget(randomPos);
			}
			m_pAimbot->AimTarget();
		}

		if (m_pConfigs->m_bUseRecoil) {
			if (GetAsyncKeyState(VK_RBUTTON) && GetAsyncKeyState(VK_LBUTTON)) {
				m_pAimService->KeepRecoil();
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

}

Vec2 Game::GetScreenResolution() {
	int width, height;
	GetDesktopResolution(width, height);

	Vec2 resolution{ static_cast<double>(width), static_cast<double>(height) };

	spdlog::debug("Screen resolution: {}x{}", resolution.x, resolution.y);

	return resolution;
}

Vec2 Game::GetScreenCenter() {
	int width, height;
	GetDesktopResolution(width, height);

	Vec2 center{ static_cast<double>(width / 2), static_cast<double>(height / 2) };

	spdlog::debug("Screen center: {}, {}", center.x, center.y);

	return center;
}

#pragma region Game:Private

void Game::GetDesktopResolution(int& horizontal, int& vertical)
{
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow();

	GetWindowRect(hDesktop, &desktop);

	horizontal = desktop.right;
	vertical = desktop.bottom;
}

#pragma endregion
