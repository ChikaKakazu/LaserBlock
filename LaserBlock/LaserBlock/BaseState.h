#pragma once

class BaseState
{
public:
    /// <summary>
    /// ���s����
    /// </summary>
    virtual void Execute() = 0;

    /// <summary>
    /// �X�V����
    /// </summary>
    virtual void Update() = 0;

    /// <summary>
    /// ������
    /// </summary>
    virtual void Exit() = 0;
};