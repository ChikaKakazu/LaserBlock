#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game) : game(game)
{
    // Actor��ǉ�����
    game->AddActor(this);
}

Actor::~Actor()
{
    // Actor���폜����
    game->RemoveActor(this);
    // �R���|�[�l���g��S�č폜����
    while (!components.empty())
    {
        // ��납��폜���Ă���
        delete components.back();
    }
}

void Actor::Update()
{
    if (actorState == ActorState::EActive)
    {
        UpdateComponents();
        UpdateActor();
    }
}

void Actor::UpdateComponents()
{
    // Actor�ɂ��Ă���S�ẴR���|�[�l���g���X�V����
    for (auto comp : components)
    {
        comp->Update();
    }
}

void Actor::UpdateActor()
{
    
}

/// <summary>
/// �R���|�[�l���g��ǉ�����
/// </summary>
/// <param name="component"></param>
void Actor::AddComponent(Component* component)
{
    int myOrder = component->GetUpdateOrder();
    auto iter = components.begin();
    for (iter; iter != components.end(); ++iter)
    {
        // �������傫���X�V���ʂ�������
        if (myOrder < (*iter)->GetUpdateOrder())
            break;
    }
    // ���[�v�𔲂����ۂ�updateOrder�̈�O�ɒǉ�����
    components.insert(iter, component);
}

/// <summary>
/// �R���|�[�l���g���폜����
/// </summary>
/// <param name="component"></param>
void Actor::RemoveComponent(Component* component)
{
    // �n���ꂽ�R���|�[�l���g��T��
    auto iter = std::find(components.begin(), components.end(), component);
    if (iter != components.end())
    {
        // �R���|�[�l���g���폜����
        components.erase(iter);
    }
}