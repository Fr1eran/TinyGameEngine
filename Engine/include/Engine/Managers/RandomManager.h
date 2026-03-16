#pragma once
#ifndef RANDOMMANAGER_H
#define RANDOMMANAGER_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>

#include <random>

class RandomManager
{
private:
    // direct member initilize
    std::mt19937 m_gen{std::random_device{}()};

public:
    int Int(int min, int max);
    float Float(float min, float max);
    bool Bool(float probability = 0.5f);

    sf::Vector2f Position(sf::Vector2f min, sf::Vector2f max);
    sf::Angle Angle(sf::Angle min, sf::Angle max);
    sf::Color Color(sf::Color min, sf::Color max);
};

#endif // RANDOMMANAGER_H
