#pragma once

class BaseState
{
public:
    /// <summary>
    /// 実行する
    /// </summary>
    virtual void Execute() = 0;

    /// <summary>
    /// 更新する
    /// </summary>
    virtual void Update() = 0;

    /// <summary>
    /// 抜ける
    /// </summary>
    virtual void Exit() = 0;
};