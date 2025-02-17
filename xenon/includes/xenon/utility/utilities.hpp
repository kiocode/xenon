#include <vector>
#include <xenon/models/profiles/target_profile.hpp>

namespace Utilities {
	bool ListContainsTarget(std::vector<TargetProfile>& list, TargetProfile target) {
		for (auto& t : list) {
			if (t.m_pOriginalAddress == target.m_pOriginalAddress) {
				return true;
			}
		}
		return false;
	}
}