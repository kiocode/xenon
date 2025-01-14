#include <string>

#include <xenon/models/quickactions/quickaction.hpp>

class QuickActionSlider : public QuickAction {
public:

	QuickActionSlider(std::string label, float* value, float min, float max) : m_strLabel(label), m_fValue(value), m_fMin(min), m_fMax(max), m_bIsFloat(true) {}
	QuickActionSlider(std::string label, int* value, int min, int max) : m_strLabel(label), m_nValue(value), m_nMin(min), m_nMax(max), m_bIsFloat(false) {}

	void Render() override {
		if (m_bIsFloat) {
			ImGui::SliderFloat(m_strLabel.c_str(), m_fValue, m_fMin, m_fMax);
		} else {
			ImGui::SliderInt(m_strLabel.c_str(), m_nValue, m_nMin, m_nMax);
		}
	}

private:
	bool m_bIsFloat = false;
	std::string m_strLabel;

	float* m_fValue = nullptr;
	float m_fMin = 0;
	float m_fMax = 10;	
	
	int* m_nValue = nullptr;
	int m_nMin = 0;
	int m_nMax = 10;
};