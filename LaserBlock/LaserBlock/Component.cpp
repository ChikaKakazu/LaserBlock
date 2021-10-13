#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner, int updateOrder) : owner(owner), updateOrder(updateOrder)
{
    // このコンポーネントを追加する
    owner->AddComponent(this);
}

Component::~Component()
{
    // このコンポーネントを削除する
    owner->RemoveComponent(this);
}

void Component::Update()
{

}