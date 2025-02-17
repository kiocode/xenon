#include <string>

#include <xenon/models/quickactions/quickaction.hpp>

class QuickActionCheckbox : public QuickAction {
public:

	QuickActionCheckbox(std::string label, bool* value, ImColor bg, ImColor on, ImColor off) : m_strLabel(label), m_bValue(value), m_cBg(bg), m_cOn(on), m_cOff(off) {}

	void Render() override {
		ImGui::Checkbox(m_strLabel.c_str(), m_bValue, m_cBg, m_cOn, m_cOff);
	}

private:
	std::string m_strLabel;
	bool* m_bValue;

	ImColor m_cBg;
	ImColor m_cOn;
	ImColor m_cOff;
};