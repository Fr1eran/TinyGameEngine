#include "Engine.h"
#include "EngineConfig.h"
#include "Logger.h"

Engine::Engine()
    : m_window(sf::VideoMode(gConfig.windowSize), gConfig.windowTitle)
{
    m_window.setIcon(sf::Image(
        "C:/Users/ARCH/Documents/gitprojects/TinyGameEngine/Engine/Content/Textures/GamePad.png"));
    m_window.setMinimumSize(m_window.getSize() / 2u);

    if (gConfig.disableSfmlLogs) {
        sf::err().rdbuf(nullptr);
    }

    m_context.save.Set("Scores", 10);

    LOG_INFO("Window created");
}

bool Engine::IsRunning() const
{
    return m_window.isOpen();
}

void Engine::ProcessEvents()
{
    auto visitor = EngineVisitor{*this};
    while (auto const event = m_window.pollEvent()) {
        event->visit(visitor);
    }
}

void Engine::Update()
{
    m_context.time.Update();
}

void Engine::Render()
{
    m_window.clear();

    // Update

    m_window.display();
}

void Engine::EventWindowClose()
{
    m_window.close();
    LOG_INFO("Window closed after {:.2f} seconds", m_context.time.GetElapsedTime());
}

void Engine::EventWindowResized(sf::Vector2u size)
{
    LOG_INFO("Window resized to: {}x{}", size.x, size.y);
}

void Engine::EventWindowFocusLost()
{
    LOG_INFO("Window focus lost");
}

void Engine::EventWindowFocusGained()
{
    LOG_INFO("Window focus gained");
}
