#pragma once

class BaseState
{
public:
    /// <summary>
    /// é¿çsÇ∑ÇÈ
    /// </summary>
    virtual void Execute() = 0;

    /// <summary>
    /// çXêVÇ∑ÇÈ
    /// </summary>
    virtual void Update() = 0;

    /// <summary>
    /// î≤ÇØÇÈ
    /// </summary>
    virtual void Exit() = 0;
};