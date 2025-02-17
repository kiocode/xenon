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
        m_vActions.push_back(std::make_unique<QuickActionButton>(label, callback));
    }

    void AddCheckbox(std::string label, bool* value, ImColor bg = ImColor(0, 0, 0, 0), ImColor on = ImColor(0, 255, 0, 255), ImColor off = ImColor(255, 0, 0, 255)) {
        m_vActions.push_back(std::make_unique<QuickActionCheckbox>(label, value, bg, on, off));
    }

    void AddSlider(std::string label, float* value, float min, float max) {
        m_vActions.push_back(std::make_unique<QuickActionSlider>(label, value, min, max));
	}

    void AddSlider(std::string label, int* value, int min, int max) {
        m_vActions.push_back(std::make_unique<QuickActionSlider>(label, value, min, max));
	}

    const std::vector<std::unique_ptr<QuickAction>>& GetComponents() const {
        return m_vActions;
    }

    size_t GetSize() {
        return m_vActions.size();
    }

private:
    std::vector<std::unique_ptr<QuickAction>> m_vActions;
};
