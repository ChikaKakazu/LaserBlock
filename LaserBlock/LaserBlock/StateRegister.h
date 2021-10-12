#pragma once
#include <functional>
#include "BaseState.h"

class StateRegister
{
public:
    /// <summary>
    /// ���s����
    /// </summary>
    std::function<void()> Execute;

    /// <summary>
    /// �X�V����
    /// </summary>
    std::function<void()> Update;

    /// <summary>
    /// ������
    /// </summary>
    std::function<void()> Exit;
};