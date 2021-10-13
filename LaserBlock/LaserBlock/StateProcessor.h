#pragma once
#include <unordered_map>
#include <magic_enum.hpp>
#include "StateRegister.h"

using Execute = std::function<void()>;
using Update = std::function<void()>;
using Exit = std::function<void()>;

template <class TEnum>
class StateProcessor
{
    public:
        StateProcessor(TEnum stateType);

        // �X�e�[�g��o�^����
        void RegisterState(TEnum stateType, Execute execute, Update update, Exit exit);
        // �X�e�[�g��؂�ւ���
        void ChangeState(TEnum toStateType);

        // �o�^�����X�e�[�g
        class StateRegister* stateRegister;

        std::unordered_map<TEnum, class StateRegister*> stateMapping;
};

/// <summary>
/// StateMapping���쐬����
/// </summary>
/// <typeparam name="TEnum"></typeparam>
/// <param name="stateType"></param>
template <class TEnum>
StateProcessor<TEnum>::StateProcessor(TEnum stateType)
{
    // �n���ꂽenum class�����o��
    auto enumValues = magic_enum::enum_values<TEnum>();
    for (auto value : enumValues)
    {
        // enum�̒l��key�Ƃ���map���쐬����
        auto mapping = new StateRegister();
        stateMapping.emplace(value, mapping);
    }

    ChangeState(stateType);
};

/// <summary>
/// �X�e�[�g��o�^����
/// </summary>
/// <typeparam name="TEnum"></typeparam>
/// <param name="type"></param>
/// <param name="execute"></param>
/// <param name="update"></param>
/// <param name="exit"></param>
template <class TEnum>
void StateProcessor<TEnum>::RegisterState(TEnum stateType, Execute execute, Update update, Exit exit)
{
    auto stateRegister = stateMapping[stateType];

    stateRegister->Execute = execute;
    stateRegister->Update = update;
    stateRegister->Exit = exit;
}

/// <summary>
/// �X�e�[�g��؂�ւ���
/// </summary>
/// <typeparam name="TEnum"></typeparam>
/// <param name="toStateType">�؂�ւ������X�e�[�g</param>
template<class TEnum>
void StateProcessor<TEnum>::ChangeState(TEnum toStateType)
{
    if (stateRegister != nullptr && stateRegister->Exit)
    {
        // ���̃X�e�[�g���甲����
        stateRegister->Exit();
    }
    // �؂�ւ������X�e�[�g��
    stateRegister = stateMapping[toStateType];

    if (stateRegister->Execute != nullptr)
    {
        // �؂�ւ����X�e�[�g�����s����
        stateRegister->Execute();
    }
}