#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <SFML/Window/Event.hpp>
#include <Engine/Core/EngineContext.h>

class Scene
{
protected:
    EngineContext& ctx;

public:
    Scene(EngineContext& context)
        : ctx(context)
    {
    }
    virtual ~Scene() = default;

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() const = 0; // 不改变场景状态，仅显示内容

    virtual void OnEvent(const sf::Event&) {}
    virtual void OnPause(bool /* paused */) {}
    virtual void OnCleanup() {}
};

#endif