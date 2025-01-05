#include <string>
#include <functional>

#include <xenon/models/quickactions/quickaction.hpp>

class QuickActionButton : public QuickAction {
public:

	QuickActionButton(std::string label, std::function<void()> callback) : m_strLabel(label), m_fnCallback(callback) {}

	void Render() override {
		if (ImGui::Button(m_strLabel.c_str(), ImVec2(100, 30))) {
			m_fnCallback();
		}
	}

private:
	std::string m_strLabel;
	std::function<void()> m_fnCallback;
};