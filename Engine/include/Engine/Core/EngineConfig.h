#pragma once
#include <SFML/Graphics/Color.hpp>
#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

struct EngineConfig
{
    std::string windowTitle;
    sf::Vector2f windowSize;
    sf::Time maximumDeltaTime;
    bool disableSfmlLogs;
    float globalVolume;
    sf::Color backgroundColor;
    float cursorRadius;
    float cursorSpeed;
    sf::Color cursorColor;
    float joystickDeadZone;

    EngineConfig();
};

inline EngineConfig const gConfig;

#endif // ENGINECONFIG_H
