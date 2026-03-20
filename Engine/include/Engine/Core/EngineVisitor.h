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

    void operator()(const sf::Event::Closed&);
    void operator()(const sf::Event::Resized&);
    void operator()(const sf::Event::FocusLost&);
    void operator()(const sf::Event::FocusGained&);
    void operator()(const sf::Event::JoystickConnected&);
    void operator()(const sf::Event::JoystickDisconnected&);
    void operator()(const sf::Event::KeyPressed&);
    void operator()(const sf::Event::JoystickButtonPressed&);
    void operator()(const sf::Event&) {}
};

#endif // ENGINEVISITOR_H
