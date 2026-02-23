#pragma once
#ifndef ENGINECONTEXT_H
#define ENGINECONTEXT_H

#include "RandomManager.h"
#include "SaveManager.h"
#include "TimeManager.h"

struct EngineContext
{
    RandomManager random;
    TimeManager time;
    SaveManager save;
};

#endif // ENGINECONTEXT_H
