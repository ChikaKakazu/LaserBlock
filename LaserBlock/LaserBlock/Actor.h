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

        // Actorを更新するために呼ぶ
        void Update();
        // Actorのもつ全てのコンポーネントを更新する
        void UpdateComponents();
        // Actorの更新
        void UpdateActor();

        // コンポーネントの追加 / 削除
        void AddComponent(class Component* component);
        void RemoveComponent(class Component* component);

        ActorState GetActorState() const { return actorState; }
        class Game* GetGame() const { return game; }
    private:
        // Actorの状態
        ActorState actorState;
        // Actorが持つコンポーネント群
        std::vector<class Component*> components;
        class Game* game;
};