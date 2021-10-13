#include "Component.h"
#include "Actor.h"

Component::Component(Actor* owner, int updateOrder) : owner(owner), updateOrder(updateOrder)
{
    // ���̃R���|�[�l���g��ǉ�����
    owner->AddComponent(this);
}

Component::~Component()
{
    // ���̃R���|�[�l���g���폜����
    owner->RemoveComponent(this);
}

void Component::Update()
{

}