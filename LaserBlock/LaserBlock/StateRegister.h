#pragma once
#include <functional>
#include "BaseState.h"

class StateRegister
{
public:
    /// <summary>
    /// 実行する
    /// </summary>
    std::function<void()> Execute;

    /// <summary>
    /// 更新する
    /// </summary>
    std::function<void()> Update;

    /// <summary>
    /// 抜ける
    /// </summary>
    std::function<void()> Exit;
};