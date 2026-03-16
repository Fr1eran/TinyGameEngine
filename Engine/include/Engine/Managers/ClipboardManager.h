#pragma once
#ifndef CLIPBOARDMANAGER_H
#define CLIPBOARDMANAGER_H

#include <SFML/System/String.hpp>

class ClipboardManager
{
public:
    void SetString(sf::String const& text);
    sf::String GetString() const;
};

#endif // CLIPBOARDMANAGER_H
