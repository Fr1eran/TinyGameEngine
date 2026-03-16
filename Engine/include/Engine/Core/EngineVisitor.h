#pragma once
#ifndef ENGINEVISITOR_H
#define ENGINEVISITOR_H

#include <SFML/Window/Event.hpp>

// 可以处理单次按键按下引发的事件
struct EngineVisitor
{
    // forward declaration
    // avoid cycle reference
    class Engine& engine;

    void operator()(sf::Event::Closed const&);
    void operator()(sf::Event::Resized const&);
    void operator()(sf::Event::FocusLost const&);
    void operator()(sf::Event::FocusGained const&);
    void operator()(sf::Event::JoystickConnected const&);
    void operator()(sf::Event::JoystickDisconnected const&);
    void operator()(sf::Event::KeyPressed const&);
    void operator()(sf::Event::JoystickButtonPressed const&);
    void operator()(sf::Event const&) {}
};

#endif // ENGINEVISITOR_H
