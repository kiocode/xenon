#include <vector>
#include <memory>
#include <string>
#include <functional>

#include <xenon/models/quickactions/quickaction_button.hpp>
#include <xenon/models/quickactions/quickaction_checkbox.hpp>
#include <xenon/models/quickactions/quickaction_slider.hpp>

class QuickActions {
public:
    void AddButton(std::string label, std::function<void()> callback) {
        m_vButtons.push_back(std::make_unique<QuickActionButton>(label, callback));
    }

    void AddCheckbox(std::string label, bool* value) {
        m_vCheckboxes.push_back(std::make_unique<QuickActionCheckbox>(label, value));
    }

    void AddSlider(std::string label, float* value, float min, float max) {
		m_vSliders.push_back(std::make_unique<QuickActionSlider>(label, value, min, max));
	}

    const std::vector<std::unique_ptr<QuickActionButton>>& GetButtons() const {
        return m_vButtons;
    }

    const std::vector<std::unique_ptr<QuickActionCheckbox>>& GetCheckboxes() const {
        return m_vCheckboxes;
    }

    const std::vector<std::unique_ptr<QuickActionSlider>>& GetSliders() const {
        return m_vSliders;
    }

    int GetSize() {
        return m_vButtons.size() + m_vCheckboxes.size();
    }

private:
    std::vector<std::unique_ptr<QuickActionButton>> m_vButtons;
    std::vector<std::unique_ptr<QuickActionCheckbox>> m_vCheckboxes;
    std::vector<std::unique_ptr<QuickActionSlider>> m_vSliders;
};
