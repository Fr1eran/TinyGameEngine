#pragma once
#ifndef SCREENSHOTMANAGER_H
#define SCREENSHOTMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>

class ScreenshotManager
{
private:
    const sf::RenderWindow& m_window;

public:
    ScreenshotManager(const sf::RenderWindow& window);
    void Take() const;
};

#endif