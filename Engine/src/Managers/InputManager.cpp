#include "Engine/Utils/InputBinding.h"
#include <Engine/Managers/InputManager.h>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <algorithm>
#include <variant>

void InputManager::Bind(int action, Input::Binding const& binding)
{
    m_bindings.emplace(action, binding);
}

bool InputManager::Pressed(int action) const
{
    auto const [first, last] = m_bindings.equal_range(action);

    return std::any_of(
        first,
        last,
        [this](auto const& entry)
        { return std::visit([this](auto const& binding) { return this->Pressed(binding); }, entry.second); });
}

void InputManager::Clear()
{
    m_bindings.clear();
}

bool InputManager::Pressed(Input::Keyboard const& binding) const
{
    return sf::Keyboard::isKeyPressed(binding.key);
}

bool InputManager::Pressed(Input::Mouse const& binding) const
{
    return sf::Mouse::isButtonPressed(binding.button);
}

bool InputManager::Pressed(Input::Gamepad const& binding) const
{
    auto const button = Input::LogicalToHardware(binding.button, binding.id);
    return button ? sf::Joystick::isButtonPressed(binding.id, *button) : false;
}

bool InputManager::Pressed(Input::Axis const& binding) const
{
    // 归一化到 [-1, 1] 范围内
    float const axis = sf::Joystick::getAxisPosition(binding.id, binding.axis) / 100.f;
    return (binding.threshold >= 0) ? axis > binding.threshold : axis < binding.threshold;
}