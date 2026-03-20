#pragma once
#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include <Engine/Managers/RandomManager.h>
#include <Engine/Managers/SaveManager.h>
#include <Engine/Managers/TimeManager.h>
#include <Engine/Managers/ClipboardManager.h>
#include <Engine/Managers/ResourceManager.h>
#include <Engine/Managers/AudioManager.h>
#include <Engine/Managers/InputManager.h>
#include <Engine/Managers/RenderManager.h>
#include <Engine/Managers/ScreenshotManager.h>
#include <Engine/Managers/CursorManager.h>
#include <Engine/Managers/GuiManager.h>
#include <Engine/Managers/SceneManager.h>

struct EngineContext
{
    RandomManager random;
    TimeManager time;
    SaveManager save;
    ClipboardManager clipboard;
    ResourceManager res;
    AudioManager audio;
    InputManager input;
    RenderManager renderer;
    ScreenshotManager screenshot;
    CursorManager cursor;
    GuiManager gui;
    SceneManager scenes;

    EngineContext(sf::RenderWindow& window)
        : screenshot(window)
        , cursor(window)
        , gui(window)
    {
    }
};

#endif // ENGINECONTEXT_H
