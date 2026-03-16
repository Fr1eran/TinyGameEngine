#include <Engine/Managers/ScreenshotManager.h>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <chrono>
#include <format>
#include <string>

#include <Engine/Utils/Logger.h>

ScreenshotManager::ScreenshotManager(const sf::RenderWindow& window)
    : m_window(window)
{
}

void ScreenshotManager::Take() const
{
    std::string filename = std::format("Screenshot_{:%Y%m%d_%H%M%S}.png",
                                       std::chrono::floor<std::chrono::milliseconds>(std::chrono::system_clock::now()));

    filename.replace(filename.find('.'), 1, "-");

    sf::Texture screenshot(m_window.getSize());
    screenshot.update(m_window);

    if (screenshot.copyToImage().saveToFile("Content/Screenshots/" + filename))
    {
        LOG_INFO("Screenshot saved as {}", filename);
    }
    else
    {
        LOG_WARNING("Failed to save screenshot to {}", filename);
    }
}