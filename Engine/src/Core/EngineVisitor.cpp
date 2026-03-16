#include <Engine/Core/Engine.h>
#include <Engine/Core/EngineVisitor.h>

void EngineVisitor::operator()(sf::Event::Closed const &e)
{
    engine.EventWindowClose();
}

void EngineVisitor::operator()(sf::Event::Resized const &resized)
{
    engine.EventWindowResized(resized.size);
}

void EngineVisitor::operator()(sf::Event::FocusLost const &e)
{
    engine.EventWindowFocusLost();
}

void EngineVisitor::operator()(sf::Event::FocusGained const &e)
{
    engine.EventWindowFocusGained();
}

void EngineVisitor::operator()(sf::Event::JoystickConnected const &joystick)
{
    engine.EventGamepadConnected(joystick.joystickId);
}

void EngineVisitor::operator()(sf::Event::JoystickDisconnected const &joystick)
{
    engine.EventGamepadDisconnected(joystick.joystickId);
}

void EngineVisitor::operator()(sf::Event::KeyPressed const &key)
{
    if (key.scancode == sf::Keyboard::Scan::R) {
        engine.EventSceneRestart();
    } else if (key.scancode == sf::Keyboard::Scan::M) {
        engine.EventSceneMenuReturn();
    } else if (key.scancode == sf::Keyboard::Scan::Escape) {
        engine.EventOverlayPauseToggle();
    } else if (key.control && key.shift && key.scancode == sf::Keyboard::Scan::S) {
        engine.EventWindowScreenshot();
    }
}

void EngineVisitor::operator()(sf::Event::JoystickButtonPressed const &joystick)
{
    // if(auto const button )
}
