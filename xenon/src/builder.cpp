#include <xenon/builder.hpp>

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

    std::shared_ptr<AimService> pAimService = Services.AddSingleton<AimService>([pAimConfig]() {
        return std::make_shared<AimService>(pAimConfig);
    });

    std::shared_ptr<Aimbot> pAimbot = Services.AddSingleton<Aimbot>(
        [this, pAimConfig, pAimService]() {
            return std::make_shared<Aimbot>(pAimConfig, GameManager, pAimService);
        }
    );
}

void Builder::BuildAndRun() {

    #pragma region SetScreenResolution & Get the center

    int width, height;
    GetDesktopResolution(width, height);

    GameManager->g_vScreenResolution = Vec2(static_cast<double>(width), static_cast<double>(height));
    GameManager->g_vScreenCenter = Vec2(GameManager->g_vScreenResolution.x / 2, GameManager->g_vScreenResolution.y / 2);

    spdlog::info("Screen resolution: {}x{}", GameManager->g_vScreenResolution.x, GameManager->g_vScreenResolution.y);

    #pragma endregion


    while (m_bUseUpdate) {
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
