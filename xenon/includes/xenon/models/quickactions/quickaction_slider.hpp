#include <string>

#include <xenon/models/quickactions/quickaction.hpp>

class QuickActionSlider : public QuickAction {
public:

	QuickActionSlider(std::string label, float* value, float min, float max) : m_strLabel(label), m_fValue(value), m_fMin(min), m_fMax(max) {}

	void Render() override {
		ImGui::SliderFloat(m_strLabel.c_str(),  m_fValue, m_fMin, m_fMax);
	}

private:
	std::string m_strLabel;
	float* m_fValue;
	float m_fMin;
	float m_fMax;
};