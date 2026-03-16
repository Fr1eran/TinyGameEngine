#pragma once
#ifndef CURSORMANAGER_H
#define CURSORMANAGER_H
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

class CursorManager
{
private:
    sf::RenderWindow& m_window;
    sf::CircleShape m_shape;
    float m_speed;
    bool m_visible;

public:
    CursorManager(sf::RenderWindow& window);

    void SetSpeed(float speed);
    float GetSpeed() const;

    void SetVisible(bool visible);
    bool IsVisible() const;

    void SetPosition(sf::Vector2f position);
    // 获取在默认视图中的位置
    sf::Vector2f GetPosition() const;
    // 获取相对于摄像机的位置
    sf::Vector2f GetPosition(const sf::View& view) const;

private:
    friend class Engine;
    void Update(float deltaTime);
    void Render() const;
};

#endif