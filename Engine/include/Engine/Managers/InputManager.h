#pragma once
#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <unordered_map>
#include <Engine/Utils/InputBinding.h>

// 处理按键持续按下
class InputManager
{
private:
    // 动作映射至输入绑定
    std::unordered_map<int, Input::Binding> m_bindings;

public:
    void Bind(int action, Input::Binding const& binding);
    bool Pressed(int action) const;
    void Clear();

private:
    bool Pressed(Input::Keyboard const&) const;
    bool Pressed(Input::Mouse const&) const;
    bool Pressed(Input::Gamepad const&) const;
    bool Pressed(Input::Axis const&) const;
};

#endif