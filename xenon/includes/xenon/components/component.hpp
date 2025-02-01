#pragma once

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>

#include <xenon/core/xenon_core.hpp>
#include <xenon/core/xenon_variables.hpp>
#include <xenon/core/xenon_config.hpp>


class CComponent {
public:
	std::shared_ptr<Xenon> g_pXenon;
	std::shared_ptr<XenonVariables> g_pXenonVariables;
	std::shared_ptr<XenonConfig> g_pXenonConfigs;

	virtual void Init() {}
	virtual void Update() {}
	virtual void UpdateCurrentTarget(TargetProfile* target) {}
	virtual ~CComponent() = default;
};