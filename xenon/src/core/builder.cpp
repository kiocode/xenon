#include <xenon/core/builder.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>

#include <xenon/core/system.hpp>
#include <xenon/components/features/aimbot.hpp>
#include <xenon/components/features/esp.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/features/radar.hpp>
#include <xenon/components/services/aim_service.hpp>
#include <xenon/components/services/lua_service.hpp>
#include <xenon/components/services/ui_service.hpp>

void Builder::SetConsoleEnabled() const {

    if (xenon->g_pSystem->IsInternal()) {
        AllocConsole();
        AttachConsole(GetCurrentProcessId());
    }
    SetConsoleTitle(xenon->g_pSystem->GetAppTitle()->c_str());

    //if (SystemVariables->IsInternal()) {
        //FILE* f;
        //freopen_s(&f, "CONOUT$", "w", stdout);
    system("cls");
    //}

    auto console_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();

    auto logger = std::make_shared<spdlog::logger>("", console_sink);
    spdlog::set_default_logger(logger);

    //spdlog::set_pattern("[%H:%M:%S] [%^%l%$] %v");

    spdlog::info(R"(        
                                   
  8b,     ,d8  ,adPPYba,  8b,dPPYba,    ,adPPYba,   8b,dPPYba,   
   `Y8, ,8P'  a8P_____88  88P'   `"8a  a8"     "8a  88P'   `"8a  
     )888(    8PP"""""""  88       88  8b       d8  88       88  
   ,d8" "8b,  "8b,   ,aa  88       88  "8a,   ,a8"  88       88  
  8P'     `Y8  `"Ybbd8"'  88       88   `"YbbdP"'   88       88
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

    xenon = std::make_shared<Xenon>();
    xenonConfigs = std::make_shared<XenonConfigs>();
    xenonVariables = std::make_shared<XenonVariables>();

    xenonConfigs->g_pAimConfig = std::make_shared<AimConfig>();
    xenonConfigs->g_pEspConfig = std::make_shared<EspConfig>();
    xenonConfigs->g_pWaypointsConfig = std::make_shared<WaypointsConfig>();
    xenonConfigs->g_pUIConfig = std::make_shared<UIConfig>();
    xenonConfigs->g_pRadarConfig = std::make_shared<RadarConfig>();
    xenonConfigs->g_pGameVariables = std::make_shared<GameVariables>();

    xenon->g_pSystem = std::make_shared<System>();

    xenon->g_cAimbot = std::make_shared<Aimbot>();
    xenon->g_cEsp = std::make_shared<Esp>();
    xenon->g_cWaypoints = std::make_shared<Waypoints>();
    xenon->g_cRadar = std::make_shared<Radar>();

    xenon->g_cAimService = std::make_shared<AimService>();
    xenon->g_cLuaService = std::make_shared<LuaService>();
    xenon->g_cMemoryService = std::make_shared<MemoryService>();
    xenon->g_cNotificationService = std::make_shared<NotificationService>();
    xenon->g_cUIService = std::make_shared<UIService>();

    components.push_back(xenon->g_cAimbot);
    components.push_back(xenon->g_cEsp);
    components.push_back(xenon->g_cWaypoints);
    components.push_back(xenon->g_cRadar);
    components.push_back(xenon->g_cAimService);
    components.push_back(xenon->g_cLuaService);
    components.push_back(xenon->g_cMemoryService);
    components.push_back(xenon->g_cNotificationService);
    components.push_back(xenon->g_cUIService);

    for (std::shared_ptr<CComponent> component : components) {
        component->g_pXenon = xenon;
        component->g_pXenonVariables = xenonVariables;
        component->g_pXenonConfigs = xenonConfigs;

        component->Init();
    }

    GameManager = std::make_shared<Game>(xenon, xenonConfigs, xenonVariables, components);
}

Cheat Builder::Build() const {
    spdlog::debug("Building cheat");
    return Cheat(xenon, xenonVariables, GameManager);
}