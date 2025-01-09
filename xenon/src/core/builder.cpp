#include <xenon/core/builder.hpp>
#include <spdlog/spdlog.h>
#include <xenon/configs/aim_config.hpp>
#include <xenon/features/aimbot.hpp>
#include <xenon/services/lua_service.hpp>
#include <xenon/services/notification_service.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>
#include <xenon/features/esp.hpp>
#include <xenon/features/waypoints.hpp>

void Builder::SetConsoleEnabled() const {

    if (SystemVariables->IsInternal()) {
        AllocConsole();
        AttachConsole(GetCurrentProcessId());
    }
    SetConsoleTitle(SystemVariables->GetAppTitle().c_str());

    if (SystemVariables->IsInternal()) {
        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
        system("cls");
    }

    auto console_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
    //console_sink->set_color(spdlog::level::info, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    auto logger = std::make_shared<spdlog::logger>("", console_sink);
    spdlog::set_default_logger(logger);

    //spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");

    spdlog::info(R"(  
     __  __     __     ______     ______     ______     _____     ______    
    /\ \/ /    /\ \   /\  __ \   /\  ___\   /\  __ \   /\  __-.  /\  ___\    
    \ \  _'-.  \ \ \  \ \ \/\ \  \ \ \____  \ \ \/\ \  \ \ \/\ \ \ \  __\   
     \ \_\ \_\  \ \_\  \ \_____\  \ \_____\  \ \_____\  \ \____-  \ \_____\    
      \/_/\/_/   \/_/   \/_____/   \/_____/   \/_____/   \/____/   \/_____/
    )");
}

void Builder::SetDebugLogLevel() {
    spdlog::set_level(spdlog::level::debug);
}

void Builder::SetInfoLogLevel() {
    spdlog::set_level(spdlog::level::info);
}

void Builder::SetWarnLogLevel() {
    spdlog::set_level(spdlog::level::warn);
}

void Builder::SetErrorLogLevel() {
    spdlog::set_level(spdlog::level::err);
}

void Builder::RegisterDefaultServices() {

    #pragma region Configurations

    std::shared_ptr<AimConfig> pAimConfig = Services->AddConfiguration<AimConfig>();
    std::shared_ptr<GameConfig> pGameConfig = Services->AddConfiguration<GameConfig>();
    GameGlobalVariables = Services->AddConfiguration<GameVariables>();
    std::shared_ptr<UIConfig> pUIConfig = Services->AddConfiguration<UIConfig>();
    std::shared_ptr<ESPConfig> pESPConfig = Services->AddConfiguration<ESPConfig>();
    std::shared_ptr<RadarConfig> pRadarConfig = Services->AddConfiguration<RadarConfig>();
    
    #pragma endregion

    #pragma region Utils

    SystemVariables = Services->AddSingleton<System>();
    SystemVariables->SetAppTitle(m_strAppTitle);

    #pragma endregion

    #pragma region Services

    std::shared_ptr<Radar> pRadar = Services->AddSingleton<Radar>(
        [this, pRadarConfig]() {
            return std::make_shared<Radar>(pRadarConfig, GameGlobalVariables);
        }
    );
    std::shared_ptr<NotificationService> pNotificationService = Services->AddSingleton<NotificationService>();

    std::shared_ptr<UIService> pUIService = Services->AddSingleton<UIService>(
        [this, pUIConfig, pAimConfig, pRadar, pNotificationService]() {
            return std::make_shared<UIService>(pUIConfig, SystemVariables, pAimConfig, pRadar, pNotificationService);
        }
    );
    MemoryManager = Services->AddSingleton<MemoryService>();
    std::shared_ptr<LuaService> pLuaService = Services->AddSingleton<LuaService>();
    std::shared_ptr<AimService> pAimService = Services->AddSingleton<AimService>(
        [this, pAimConfig]() {
            return std::make_shared<AimService>(pAimConfig, SystemVariables);
        }
    );


    #pragma endregion

    #pragma region Features

    std::shared_ptr<ESP> pESP = Services->AddSingleton<ESP>(
        [this, pESPConfig]() {
            return std::make_shared<ESP>(pESPConfig, SystemVariables, GameGlobalVariables);
        }
    );
    std::shared_ptr<Aimbot> pAimbot = Services->AddSingleton<Aimbot>(
        [pAimConfig, pAimService]() {
            return std::make_shared<Aimbot>(pAimConfig, pAimService);
        }
    );
    std::shared_ptr<Waypoints> pWaypoints = Services->AddSingleton<Waypoints>(
        [pAimConfig, pAimService]() {
            return std::make_shared<Waypoints>();
        }
    );

    GameManager = Services->AddSingleton<Game>([this, pGameConfig, pAimbot, pAimService, pAimConfig, pUIService, pESP, pLuaService, pRadar, pUIConfig]() {
        return std::make_shared<Game>(pGameConfig, GameGlobalVariables, pUIConfig, pAimConfig, pAimService, pUIService, pLuaService, pAimbot, pESP, pRadar, SystemVariables);
    });

    #pragma endregion

}

Cheat Builder::Build() {
    spdlog::debug("Building cheat");
    return Cheat(
        GameManager, 
        Services->GetConfiguration<GameConfig>(), 
        Services->GetService<UIService>(), 
        Services->GetConfiguration<UIConfig>(), 
        SystemVariables,
        Services->GetConfiguration<NotificationService>()
    );
}