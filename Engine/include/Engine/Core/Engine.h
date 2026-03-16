#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <Engine/Core/EngineContext.h>
#include <Engine/Core/EngineVisitor.h>
#include <SFML/Graphics.hpp>

class Engine
{
private:
    sf::RenderWindow m_window;
    EngineContext m_context;

public:
    Engine();

    bool IsRunning() const;

    void ProcessEvents();
    void Update();
    void Render();

private:
    friend EngineVisitor;

    struct OverlaySelection;

    void EventWindowClose();
    void EventWindowResized(sf::Vector2u size);
    void EventWindowFocusLost();
    void EventWindowFocusGained();
    void EventWindowScreenshot() const;
    void EventGamepadConnected(int id);
    void EventGamepadDisconnected(int id);
    void EventSceneChange(std::string const &name);
    void EventSceneRestart();
    void EventSceneMenuReturn();
    void EventOverlayPauseToggle();
    void EventOverlaySelect(OverlaySelection selection);
};

#endif // ENGINE_H
