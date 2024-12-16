#pragma once

#include <memory>
#include <spdlog/spdlog.h>

#include <xenon/interfaces/aimbot_interface.hpp>
#include <xenon/configs/aimbot_config.hpp>

class Aimbot : public IAimbot {
public:

	Aimbot(std::shared_ptr<AimbotConfig> configs) : m_pConfigs(configs) 
	{
		spdlog::info("Aimbot config: m_bStartFromCenter = {}, m_vScreenCenter = {}/{}", m_pConfigs->m_bStartFromCenter, m_pConfigs->m_vScreenCenter.x, m_pConfigs->m_vScreenCenter.y);
	}

	bool IsTargetEmpty() override;
	void SetTarget(Vec2 pos) override;
	void Humanize() override;
	void Aim() override;

private:
	std::shared_ptr<AimbotConfig> m_pConfigs;
	Vec2 m_vTarget;
};