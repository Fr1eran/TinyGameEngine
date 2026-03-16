#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>
#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <SFML/Graphics.hpp>

class RenderManager
{
private:
    sf::RenderTexture m_target;

    sf::Texture m_backgroundTexture;
    sf::RectangleShape m_background;

public:
    RenderManager();

    void Draw(sf::Drawable const& drawable);
    void SetView(sf::View const& view);
    void ResetView();

private:
    friend class Engine;

    void BeginDrawing();
    sf::Texture const& FinishDrawing();
};

#endif