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

        // ステートを登録する
        void RegisterState(TEnum stateType, Execute execute, Update update, Exit exit);
        // ステートを切り替える
        void ChangeState(TEnum toStateType);

        // 登録したステート
        class StateRegister* stateRegister;

        std::unordered_map<TEnum, class StateRegister*> stateMapping;
};

/// <summary>
/// StateMappingを作成する
/// </summary>
/// <typeparam name="TEnum"></typeparam>
/// <param name="stateType"></param>
template <class TEnum>
StateProcessor<TEnum>::StateProcessor(TEnum stateType)
{
    // 渡されたenum classを取り出す
    auto enumValues = magic_enum::enum_values<TEnum>();
    for (auto value : enumValues)
    {
        // enumの値をkeyとしてmapを作成する
        auto mapping = new StateRegister();
        stateMapping.emplace(value, mapping);
    }

    ChangeState(stateType);
};

/// <summary>
/// ステートを登録する
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
/// ステートを切り替える
/// </summary>
/// <typeparam name="TEnum"></typeparam>
/// <param name="toStateType">切り替えたいステート</param>
template<class TEnum>
void StateProcessor<TEnum>::ChangeState(TEnum toStateType)
{
    if (stateRegister != nullptr && stateRegister->Exit)
    {
        // 今のステートから抜ける
        stateRegister->Exit();
    }
    // 切り替えたいステートに
    stateRegister = stateMapping[toStateType];

    if (stateRegister->Execute != nullptr)
    {
        // 切り替えたステートを実行する
        stateRegister->Execute();
    }
}