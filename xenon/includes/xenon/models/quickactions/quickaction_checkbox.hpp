#include <string>

#include <xenon/models/quickactions/quickaction.hpp>

class QuickActionCheckbox : public QuickAction {
public:


	QuickActionCheckbox(std::string label, bool* value) : m_strLabel(label), m_bValue(value) {}

	void Render() override {
		ImGui::Checkbox(m_strLabel.c_str(), m_bValue);
	}

private:
	std::string m_strLabel;
	bool* m_bValue;
};