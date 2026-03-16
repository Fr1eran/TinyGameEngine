#include <Engine/Managers/CursorManager.h>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Mouse.hpp>
#include <algorithm>
#include <Engine/Core/EngineConfig.h>

CursorManager::CursorManager(sf::RenderWindow& window)
    : m_window(window)
    , m_shape(gConfig.cursorRadius)
    , m_speed(gConfig.cursorSpeed)
    , m_visible(true)
{
    m_shape.setFillColor(gConfig.cursorColor);
    m_shape.setOrigin(m_shape.getGeometricCenter());
    m_shape.setPosition(gConfig.windowSize / 2.f);
}

void CursorManager::Update(float deltaTime)
{
    // 归一化得到摇杆移动方向
    const sf::Vector2f joystickDirection{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X),
                                         sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)};
    // 判断摇杆是否在死区范围内
    if (joystickDirection.length() > gConfig.joystickDeadZone)
    {
        // 如果不在则计算此时的移动量
        m_shape.move(joystickDirection * m_speed * deltaTime);
        m_shape.setPosition({std::clamp(m_shape.getPosition().x, 0.f, gConfig.windowSize.x - 1),
                             std::clamp(m_shape.getPosition().y, 0.f, gConfig.windowSize.y - 1)});

        // 移动系统光标位置
        SetPosition(m_shape.getPosition());
    }
    else
    {
        // 摇杆没有推出死区
        // 或使用鼠标操作系统光标
        // 则形状位置与光标位置保持同步
        m_shape.setPosition(GetPosition());
    }
}

void CursorManager::Render() const
{
    if (m_visible)
    {
        m_window.draw(m_shape);
    }
}

void CursorManager::SetSpeed(float speed)
{
    m_speed = speed;
}

float CursorManager::GetSpeed() const
{
    return m_speed;
}

void CursorManager::SetVisible(bool visible)
{
    m_visible = visible;
}

bool CursorManager::IsVisible() const
{
    return m_visible;
}

void CursorManager::SetPosition(sf::Vector2f position)
{
    sf::Mouse::setPosition(m_window.mapCoordsToPixel(position, m_window.getDefaultView()), m_window);
}

sf::Vector2f CursorManager::GetPosition() const
{
    return GetPosition(m_window.getDefaultView());
}

sf::Vector2f CursorManager::GetPosition(const sf::View& view) const
{
    return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window), view);
}