#pragma once
#ifndef ENGINECONFIG_H
#define ENGINECONFIG_H

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

struct EngineConfig
{
    std::string windowTitle;
    sf::Vector2u windowSize;
    sf::Time maximumDeltaTime;
    bool disableSfmlLogs;

    EngineConfig();
};

inline EngineConfig const gConfig;

#endif // ENGINECONFIG_H
