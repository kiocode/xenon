#include <xenon/features/aimbot.hpp>
#include <spdlog/spdlog.h>
#include <windows.h>

void Aimbot::SetTarget(Vec2 pos) {
	m_vTarget = pos;
}

void Aimbot::Aim()
{

	SetCursorPos(m_vTarget.x, m_vTarget.y);
	spdlog::info("Aiming in {}, {}", m_vTarget.x, m_vTarget.y);

}

void Aimbot::Humanize()
{
}
