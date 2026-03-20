#include <Engine/Core/Engine.h>
#include <Engine/Core/EngineConfig.h>
#include <Engine/Utils/Logger.h>
#include <SFML/Graphics/Sprite.hpp>

Engine::Engine()
    : m_window(sf::VideoMode(sf::Vector2u(gConfig.windowSize)), gConfig.windowTitle)
    , m_context(m_window)
{
    m_window.setIcon(
        sf::Image("C:/Users/ARCH/Documents/gitprojects/TinyGameEngine/Engine/Content/Textures/GamePad.png"));
    m_window.setMinimumSize(m_window.getSize() / 2u);
    m_window.setKeyRepeatEnabled(false);
    m_window.setMouseCursorVisible(false);
    if (gConfig.disableSfmlLogs)
    {
        sf::err().rdbuf(nullptr);
    }

    m_context.audio.SetGlobalVolume(gConfig.globalVolume);

    m_context.save.Set("Scores", 10);

    LOG_INFO("Window created");
}

bool Engine::IsRunning() const
{
    return m_window.isOpen();
}

void Engine::ProcessEvents()
{
    // 处理sfml事件前，先处理场景切换请求
    if (const auto nextScene = m_context.scenes.FetchNextScene())
    {
        EventSceneChange(*nextScene);
    }

    auto visitor = EngineVisitor{*this};
    while (auto const event = m_window.pollEvent())
    {
        event->visit(visitor);
        m_context.gui.ProcessEvent(*event);
    }
}

void Engine::Update()
{
    m_context.time.Update();
    m_context.cursor.Update(m_context.time.GetDeltaTime());
}

void Engine::Render()
{
    m_window.clear();

    // Update
    m_context.renderer.BeginDrawing();
    m_window.draw(sf::Sprite(m_context.renderer.FinishDrawing()));

    m_context.gui.Render();
    m_context.cursor.Render();

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

void Engine::EventGamepadConnected(int id)
{
    LOG_INFO("Gamepad {} connected", id);
}

void Engine::EventGamepadDisconnected(int id)
{
    LOG_INFO("Gamepad {} disconnected", id);
}

void Engine::EventWindowScreenshot() const
{
    m_context.screenshot.Take();
}

void Engine::EventSceneChange(const std::string& name)
{
    // scene changing logic
}

void Engine::EventSceneRestart()
{
    m_context.scenes.RestartCurrentScene();
}

void Engine::EventSceneMenuReturn()
{
    m_context.scenes.ChangeScene("Menu");
}