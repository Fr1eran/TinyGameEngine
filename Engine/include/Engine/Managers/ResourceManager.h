#pragma once
#ifndef TINYGAMEENGINE_RESOURCEMANAGER_H
#define TINYGAMEENGINE_RESOURCEMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>
#include <unordered_map>
#include <optional>

class ResourceManager
{
private:
    std::unordered_map<std::string,sf::Texture> m_textures;
    std::unordered_map<std::string,sf::SoundBuffer> m_soundBuffers;
    std::unordered_map<std::string,sf::Font> m_fonts;

public:
    sf::Texture* FetchTexture(std::string const& filename);
    sf::SoundBuffer* FetchSound(std::string const& filename);
    sf::Font* FetchFont(std::string const& filename);
    std::optional<sf::Music> FetchMusic(std::string const& filename) const;
};

#endif // TINYGAMEENGINE_RESOURCEMANAGER_H
