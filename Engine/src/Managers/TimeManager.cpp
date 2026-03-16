#include <Engine/Managers/TimeManager.h>
#include <Engine/Core/EngineConfig.h>

TimeManager::TimeManager() {}

void TimeManager::Update()
{
    sf::Time currentTimePoint = m_clock.getElapsedTime();
    m_deltaTime = currentTimePoint - m_prevTimePoint;
    if (m_deltaTime > gConfig.maximumDeltaTime) {
        m_deltaTime = gConfig.maximumDeltaTime;
    }

    m_prevTimePoint = currentTimePoint;
}

float TimeManager::GetDeltaTime() const
{
    return m_deltaTime.asSeconds();
}

float TimeManager::GetElapsedTime() const
{
    return m_clock.getElapsedTime().asSeconds();
}
