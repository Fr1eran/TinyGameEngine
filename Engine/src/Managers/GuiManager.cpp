#include <Engine/Managers/GuiManager.h>
#include <Engine/Utils/InputBinding.h>

GuiManager::GuiManager(sf::RenderWindow& window)
    : m_window(window)
    , m_gui(m_window)
{
    tgui::Theme::setDefault("Content/Themes/Dark.txt");

    m_gui.setTabKeyUsageEnabled(true);
    // m_gui.setFont("Content/Fonts/");
}

void GuiManager::ProcessEvent(const sf::Event& event)
{
    event.visit(
        [this](const auto& type)
        {
            this->HandleEvent(type);
            this->m_gui.handleEvent(type);
        });
}

void GuiManager::Render()
{
    m_gui.draw();
}

void GuiManager::Add(const tgui::Widget::Ptr& widget)
{
    m_gui.add(widget);
}

void GuiManager::Remove(const tgui::Widget::Ptr& widget)
{
    m_gui.remove(widget);
}

void GuiManager::HandleEvent(const sf::Event::Resized& resized)
{
    const sf::Vector2f defaultSize = m_window.getDefaultView().getSize();
    const sf::Vector2f scale = sf::Vector2f(resized.size).componentWiseDiv(defaultSize);
    m_gui.setRelativeView({0, 0, 1 / scale.x, 1 / scale.y});
}

void GuiManager::HandleEvent(const sf::Event::JoystickButtonPressed& joystick)
{
    if (Input::HardwareToLogical(joystick.button, joystick.joystickId) == GamepadButton::South)
    {
        m_gui.handleEvent(sf::Event::MouseButtonPressed({}, sf::Mouse::getPosition(m_window)));
    }
}

void GuiManager::HandleEvent(const sf::Event::JoystickButtonReleased& joystick)
{
    if (Input::HardwareToLogical(joystick.button, joystick.joystickId) == GamepadButton::South)
    {
        m_gui.handleEvent(sf::Event::MouseButtonReleased({}, sf::Mouse::getPosition(m_window)));
    }
}
