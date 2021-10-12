#pragma once
#include <functional>
#include "BaseState.h"

class StateRegister
{
public:
    /// <summary>
    /// é¿çsÇ∑ÇÈ
    /// </summary>
    std::function<void()> Execute;

    /// <summary>
    /// çXêVÇ∑ÇÈ
    /// </summary>
    std::function<void()> Update;

    /// <summary>
    /// î≤ÇØÇÈ
    /// </summary>
    std::function<void()> Exit;
};