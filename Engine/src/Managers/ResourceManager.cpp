#include <Engine/Managers/ResourceManager.h>
#include <Engine/Utils/Logger.h>

sf::Texture* ResourceManager::FetchTexture(std::string const& filename)
{
    if (!m_textures.contains(filename))
    {
        if (!m_textures[filename].loadFromFile("Content/Textures/" + filename))
        {
            LOG_ERROR("Failed to load texture: {}",filename);
            return nullptr;
        }
    }
    return &m_textures.at(filename);
}

sf::Font* ResourceManager::FetchFont(std::string const& filename)
{
    if (!m_fonts.contains(filename))
    {
        if (!m_fonts[filename].openFromFile("Content/Fonts/" + filename))
        {
            LOG_ERROR("Failed to load font: {}", filename);
            return nullptr;
        }
    }
    return &m_fonts.at(filename);
}

std::optional<sf::Music> ResourceManager::FetchMusic(std::string const& filename) const
{
    sf::Music music;
    if (!music.openFromFile("Content/Musics/" + filename))
    {
        LOG_ERROR("Failed to load music: {}", filename);
        return std::nullopt;
    }
    return music;
}
