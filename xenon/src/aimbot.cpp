#include <xenon/features/aimbot.hpp>
#include <windows.h>

bool Aimbot::IsTargetEmpty() 
{
	return m_vTarget.x == -99 && m_vTarget.y == -99;
}

void Aimbot::SetTarget(Vec2 pos) 
{
	m_vTarget = pos;
}

void Aimbot::Aim()
{
	if (IsTargetEmpty())
	{
		spdlog::info("Target is empty");
		return;
	}

	Vec2 target{ 0,0 };
	
	if (m_pConfigs->m_bStartFromCenter) 
	{

		m_pConfigs->m_fSmooth += 3;

		if (m_vTarget.x != 0)
		{
			if (m_vTarget.x > m_pConfigs->m_vScreenCenter.x)
			{
				target.x = -(m_pConfigs->m_vScreenCenter.x - m_vTarget.x);
				target.x /= m_pConfigs->m_fSmooth;
				if (target.x + m_pConfigs->m_vScreenCenter.x > m_pConfigs->m_vScreenCenter.x * 2) target.x = 0;
			}

			if (m_vTarget.x < m_pConfigs->m_vScreenCenter.x)
			{
				target.x = m_vTarget.x - m_pConfigs->m_vScreenCenter.x;
				target.x /= m_pConfigs->m_fSmooth;
				if (target.x + m_pConfigs->m_vScreenCenter.x < 0) target.x = 0;
			}
		}

		if (m_vTarget.y != 0)
		{
			if (m_vTarget.y > m_pConfigs->m_vScreenCenter.y)
			{
				target.y = -(m_pConfigs->m_vScreenCenter.y - m_vTarget.y);
				target.y /= m_pConfigs->m_fSmooth;
				if (target.y + m_pConfigs->m_vScreenCenter.y > m_pConfigs->m_vScreenCenter.y * 2) target.y = 0;
			}

			if (m_vTarget.y < m_pConfigs->m_vScreenCenter.y)
			{
				target.y = m_vTarget.y - m_pConfigs->m_vScreenCenter.y;
				target.y /= m_pConfigs->m_fSmooth;
				if (target.y + m_pConfigs->m_vScreenCenter.y < 0) target.y = 0;
			}
		}
	}

	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(target.x), static_cast<DWORD>(target.y), NULL, NULL);
	spdlog::info("Aiming in {}, {}", m_vTarget.x, m_vTarget.y);

}

void Aimbot::Humanize()
{
}

//bool Aimbot::IsTargetReached() 
//{
//
//	// check if the cursor is at the target position
//	return false;
//}