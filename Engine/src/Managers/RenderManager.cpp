#include <Engine/Managers/RenderManager.h>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <Engine/Core/EngineConfig.h>

RenderManager::RenderManager()
    : m_target(sf::Vector2u(gConfig.windowSize))
    , m_backgroundTexture("Content/Textures/Background.png")
    , m_background(gConfig.windowSize)
{
    m_target.setSmooth(true);
    m_background.setTexture(&m_backgroundTexture);
    m_background.setFillColor(gConfig.backgroundColor);
}

void RenderManager::Draw(sf::Drawable const& drawable)
{
    m_target.draw(drawable);
}

void RenderManager::SetView(sf::View const& view)
{
    m_target.setView(view);
}

void RenderManager::ResetView()
{
    SetView(m_target.getDefaultView());
}

void RenderManager::BeginDrawing()
{
    m_target.clear();

    Draw(m_background);
}

sf::Texture const& RenderManager::FinishDrawing()
{
    m_target.display();
    return m_target.getTexture();
}