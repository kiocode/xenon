#include <string>
#include <functional>

class QuickActionButton {
public:

	QuickActionButton(std::string label, std::function<void()> callback) : m_strLabel(label), m_fnCallback(callback) {}

	std::string GetLabel() const {
		return m_strLabel;
	}

	void Execute() {
		m_fnCallback();
	}

private:
	std::string m_strLabel;
	std::function<void()> m_fnCallback;
};