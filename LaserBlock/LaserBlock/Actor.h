#pragma once
#include <vector>

enum class ActorState : int
{
    EActive,
    EPaused,
    EDead,
};

class Actor
{
    public:
        /*enum ActorState
        {

        };*/
        Actor(class Game* game);
        virtual ~Actor();

        // Actor���X�V���邽�߂ɌĂ�
        void Update();
        // Actor�̂��S�ẴR���|�[�l���g���X�V����
        void UpdateComponents();
        // Actor�̍X�V
        void UpdateActor();

        // �R���|�[�l���g�̒ǉ� / �폜
        void AddComponent(class Component* component);
        void RemoveComponent(class Component* component);

        ActorState GetActorState() const { return actorState; }
        class Game* GetGame() const { return game; }
    private:
        // Actor�̏��
        ActorState actorState;
        // Actor�����R���|�[�l���g�Q
        std::vector<class Component*> components;
        class Game* game;
};