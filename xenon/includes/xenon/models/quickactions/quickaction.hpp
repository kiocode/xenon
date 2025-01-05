#pragma once

class QuickAction {
public:
    virtual ~QuickAction() = default;
    virtual void Render() = 0; 
};