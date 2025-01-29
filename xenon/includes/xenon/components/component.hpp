#pragma once

#include <vector>
#include <memory>

#include <spdlog/spdlog.h>

#include <xenon/core/xenon_core.hpp>
#include <xenon/core/xenon_variables.hpp>
#include <xenon/core/xenon_configs.hpp>


class CComponent {
public:
	std::shared_ptr<Xenon> g_pXenon;
	std::shared_ptr<XenonVariables> g_pXenonVariables;
	std::shared_ptr<XenonConfigs> g_pXenonConfigs;

	virtual void Init() {}
	virtual void Update() {}
	virtual ~CComponent() = default;
};