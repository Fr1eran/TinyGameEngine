#pragma once
#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class TimeManager
{
private:
    sf::Clock m_clock;
    sf::Time m_deltaTime;
    sf::Time m_prevTimePoint;

public:
    TimeManager();

    float GetDeltaTime() const;
    float GetElapsedTime() const;

private:
    friend class Engine;
    void Update();
};

#endif // TIMEMANAGER_H
