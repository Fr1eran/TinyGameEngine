#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <optional>
#include <string>
#include <string_view>

class SceneManager
{
private:
    std::string m_currentScene;
    std::optional<std::string> m_nextScene;

public:
    void ChangeScene(std::string_view name);
    void RestartCurrentScene();

private:
    friend class Engine;
    // 每一帧开始时调用此方法切换场景
    std::optional<std::string> FetchNextScene();
};

#endif