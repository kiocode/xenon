#include <string>

class QuickActionSlider {
public:

	float* m_fValue;

	QuickActionSlider(std::string label, float* value, float min, float max) : m_strLabel(label), m_fValue(value), m_fMin(min), m_fMax(max) {}

	std::string GetLabel() const {
		return m_strLabel;
	}

	float GetMin() const {
		return m_fMin;
	}

	float GetMax() const {
		return m_fMax;
	}

private:
	std::string m_strLabel;
	float m_fMin;
	float m_fMax;
};