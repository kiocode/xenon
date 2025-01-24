#pragma once

#include <memory>

//#include <xenon/core/system.hpp>

//#include <xenon/components/features/aimbot.hpp>
//#include <xenon/components/features/esp.hpp>
//#include <xenon/components/features/radar.hpp>
//#include <xenon/components/features/waypoints.hpp>
//
//#include <xenon/components/services/aim_service.hpp>	
//#include <xenon/components/services/lua_service.hpp>
//#include <xenon/components/services/notification_service.hpp>
//#include <xenon/components/services/ui_service.hpp>
//#include <xenon/components/services/memory_service.hpp>

class Aimbot;
class Esp;
class Radar;
class Waypoints;

class AimService;
class LuaService;
class MemoryService;
class NotificationService;
class UIService;

class System;

class Xenon {
public:

	std::shared_ptr<System> g_pSystem;

	std::shared_ptr<Aimbot> g_cAimbot;
	std::shared_ptr<Esp> g_cEsp;
	std::shared_ptr<Radar> g_cRadar;
	std::shared_ptr<Waypoints> g_cWaypoints;

	std::shared_ptr<AimService> g_cAimService;
	std::shared_ptr<LuaService> g_cLuaService;
	std::shared_ptr<MemoryService> g_cMemoryService;
	std::shared_ptr<NotificationService> g_cNotificationService;
	std::shared_ptr<UIService> g_cUIService;

};