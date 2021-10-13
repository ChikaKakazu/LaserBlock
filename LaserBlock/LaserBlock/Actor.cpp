#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game) : game(game)
{

}

Actor::~Actor()
{

}

void Actor::Update()
{

}

void Actor::UpdateComponents()
{

}

void Actor::UpdateActor()
{

}

/// <summary>
/// コンポーネントを追加する
/// </summary>
/// <param name="component"></param>
void Actor::AddComponent(Component* component)
{
    int myOrder = component->GetUpdateOrder();
    auto iter = components.begin();
    for (iter; iter != components.end(); ++iter)
    {
        // 自分より大きい更新順位だったら
        if (myOrder < (*iter)->GetUpdateOrder())
            break;
    }
    // ループを抜けた際のupdateOrderの一つ前に追加する
    components.insert(iter, component);
}

/// <summary>
/// コンポーネントを削除する
/// </summary>
/// <param name="component"></param>
void Actor::RemoveComponent(Component* component)
{
    // 渡されたコンポーネントを探す
    auto iter = std::find(components.begin(), components.end(), component);
    if (iter != components.end())
    {
        // コンポーネントを削除する
        components.erase(iter);
    }
}