#include <Engine/Managers/ClipboardManager.h>
#include <SFML/Window/Clipboard.hpp>

void ClipboardManager::SetString(sf::String const& text)
{
    sf::Clipboard::setString(text);
}

sf::String ClipboardManager::GetString() const
{
    return sf::Clipboard::getString();
}
