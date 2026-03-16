#pragma once
#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/TGUI.hpp>

class GuiManager
{
private:
    sf::RenderWindow& m_window;
    tgui::Gui m_gui;

public:
    GuiManager(sf::RenderWindow& window);

    void Add(const tgui::Widget::Ptr& widget);
    void Remove(const tgui::Widget::Ptr& widget);

private:
    friend class Engine;
    void ProcessEvent(const sf::Event&);
    void Render();

private:
    void HandleEvent(const sf::Event::Resized&);
    void HandleEvent(const sf::Event::JoystickButtonPressed&);
    void HandleEvent(const sf::Event::JoystickButtonReleased&);
    void HandleEvent(const auto&);
};

#endif