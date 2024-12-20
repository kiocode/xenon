#include <xenon/core/builder.hpp>

#include <spdlog/spdlog.h>
#include <xenon/configs/aim_config.hpp>
#include <xenon/features/aimbot.hpp>

void Builder::SetDebugLogLevel() {
    spdlog::set_level(spdlog::level::debug);
}

void Builder::SetInfoLogLevel() {
    spdlog::set_level(spdlog::level::info);
}

void Builder::SetErrorLogLevel() {
    spdlog::set_level(spdlog::level::err);
}

void Builder::DisableUpdate() {
    m_bUseUpdate = false;
}

void Builder::RegisterDefaultServices() {
    std::shared_ptr<AimConfig> pAimConfig = Services.AddConfiguration<AimConfig>();

    GameManager = Services.AddSingleton<Game>([]() {
        return std::make_shared<Game>();
    });

    std::shared_ptr<AimService> pAimService = Services.AddSingleton<AimService>([this, pAimConfig]() {
        return std::make_shared<AimService>(pAimConfig, GameManager);
    });

    std::shared_ptr<Aimbot> pAimbot = Services.AddSingleton<Aimbot>(
        [this, pAimConfig, pAimService]() {
            return std::make_shared<Aimbot>(pAimConfig, GameManager, pAimService);
        }
    );
}

void Builder::BuildAndRun() const {
    auto previousTime = std::chrono::steady_clock::now();
    GameManager->g_fStartPlayTime = previousTime.time_since_epoch().count();

    while (m_bUseUpdate) {
        auto currentTime = std::chrono::steady_clock::now();
        GameManager->g_fDeltaTime = std::chrono::duration<float>(currentTime - previousTime).count();
        previousTime = currentTime;

        GameManager->Update();

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

}

void Builder::GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;

    const HWND hDesktop = GetDesktopWindow();

    GetWindowRect(hDesktop, &desktop);

    horizontal = desktop.right;
    vertical = desktop.bottom;
}
