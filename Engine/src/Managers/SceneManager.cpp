#include <Engine/Managers/SceneManager.h>
#include <Engine/Utils/Logger.h>
#include <utility>

std::optional<std::string> SceneManager::FetchNextScene()
{
    // 检查是否已指定下一个场景的名称
    if (m_nextScene)
    {
        // 检查下一个场景的名称是否与当前场景相同
        if (m_currentScene == *m_nextScene)
        {
            // 一致则说明重启
            LOG_INFO("Restarting Scene: {}", m_currentScene);
        }
        else
        {
            LOG_INFO("Changing Scene to: {}", *m_nextScene);
        }

        m_currentScene = *m_nextScene;
        return std::exchange(m_nextScene, std::nullopt);
    }

    return std::nullopt;
}

void SceneManager::ChangeScene(std::string_view name)
{
    if (!m_nextScene)
    {
        m_nextScene = name;
    }
}

void SceneManager::RestartCurrentScene()
{
    ChangeScene(m_currentScene);
}