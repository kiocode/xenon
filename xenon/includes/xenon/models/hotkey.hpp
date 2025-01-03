#pragma once

#include <vector>
#include <string>

struct Hotkey {
    int key;                   
    std::vector<int> modifiers;

    bool operator==(const Hotkey& other) const {
        return key == other.key && modifiers == other.modifiers;
    }
};
