#include <string>

class QuickActionCheckbox {
public:

	bool* m_bValue;

	QuickActionCheckbox(std::string label, bool* value) : m_strLabel(label), m_bValue(value) {}

	std::string GetLabel() const {
		return m_strLabel;
	}

private:
	std::string m_strLabel;
};