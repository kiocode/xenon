#include <xenon/core/builder.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/wincolor_sink.h>

#include <xenon/core/system.hpp>
#include <xenon/components/features/aimbot.hpp>
#include <xenon/components/features/esp.hpp>
#include <xenon/components/features/waypoints.hpp>
#include <xenon/components/features/radar.hpp>
#include <xenon/components/services/injection_service.hpp>
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

void Builder::RegisterDefaultComponents() {

    xenon = std::make_shared<Xenon>();
    xenonConfig = std::make_shared<XenonConfig>();
    xenonVariables = std::make_shared<XenonVariables>();

    #pragma region Configs
    xenonConfig->g_pAimConfig = std::make_shared<AimConfig>();
    xenonConfig->g_pEspConfig = std::make_shared<EspConfig>();
    xenonConfig->g_pWaypointsConfig = std::make_shared<WaypointsConfig>();
    xenonConfig->g_pUIConfig = std::make_shared<UIConfig>();
    xenonConfig->g_pRadarConfig = std::make_shared<RadarConfig>();
    xenonConfig->g_pGameVariables = std::make_shared<GameVariables>();
    #pragma endregion

    #pragma region Components
    xenon->g_pSystem = std::make_shared<System>();
    xenon->g_pSystem->SetAppTitle(m_strAppTitle);

    xenon->g_cAimbot = std::make_shared<CAimbot>();
    xenon->g_cEsp = std::make_shared<CEsp>();
    xenon->g_cWaypoints = std::make_shared<CWaypoints>();
    xenon->g_cRadar = std::make_shared<CRadar>();

    xenon->g_cAimService = std::make_shared<CAimService>();
    xenon->g_cLuaService = std::make_shared<CLuaService>();
    xenon->g_cMemoryService = std::make_shared<CMemoryService>();
    xenon->g_cInjectionService = std::make_shared<CInjectionService>();
    xenon->g_cNotificationService = std::make_shared<CNotificationService>();
    xenon->g_cUIService = std::make_shared<CUIService>();
    #pragma endregion

    // The order is important for rendering priority and initialization order
    components.push_back(xenon->g_cAimbot);
    components.push_back(xenon->g_cEsp);
    components.push_back(xenon->g_cWaypoints);
    components.push_back(xenon->g_cRadar);
    components.push_back(xenon->g_cAimService);
    components.push_back(xenon->g_cLuaService);
    components.push_back(xenon->g_cMemoryService);
    components.push_back(xenon->g_cInjectionService);
    components.push_back(xenon->g_cNotificationService);
    components.push_back(xenon->g_cUIService);

    for (std::shared_ptr<CComponent> component : components) {
        component->g_pXenon = xenon;
        component->g_pXenonVariables = xenonVariables;
        component->g_pXenonConfigs = xenonConfig;

        component->Init();
    }

    GameManager = std::make_shared<Game>(xenon, xenonConfig, xenonVariables, components);
}

Cheat Builder::Build() const {
    spdlog::debug("Building cheat");
    return Cheat(xenon, xenonVariables, GameManager);
}