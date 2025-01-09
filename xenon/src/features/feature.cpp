#include <xenon/features/feature.hpp>

#include <fstream>

void Feature::SaveHotkeys(const std::vector<Hotkey>& hotkeys, const std::string& filename) {
    json j;
    for (const auto& hotkey : hotkeys) {
        j.push_back({
            {"key", hotkey.key},
            {"modifiers", hotkey.modifiers}
        });
    }
    std::ofstream file(filename);
    file << j.dump(4); 
}

std::vector<Hotkey> Feature::LoadHotkeys(const std::string& filename) {
    std::ifstream file(filename);
    json j;
    file >> j;

    std::vector<Hotkey> hotkeys;
    for (const auto& item : j) {
        hotkeys.push_back({
            item["key"],
            item["modifiers"].get<std::vector<int>>()
        });
    }
    return hotkeys;
}
