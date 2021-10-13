#pragma once
#include "StateProcessor.h"
#include "SceneState.h"

class Game
{
public:
    Game();
    ~Game();

    bool Initialize();
    void RunLoop();
    void UpdateGame();
    void Shutdown();
    void ProcessInput();

    void InitializeSceneStateToRegister();
    class StateProcessor<SceneState>* sceneState;

    // Actorの追加 / 削除
    void AddActor(class Actor* actor);
    void RemoveActor(class Actor* actor);
private:
    const int const WIN_WIDTH = 960;
    const int const WIN_HEIGHT = 540;
    const char* const TITLE = "CppStatePattern";
    bool isRunning;

    class TitleScene* titleScene;
    /*class GameMainState* gameMainState;
    class EndState* endState;*/

    // アクティブなActor群を格納する
    std::vector<class Actor*> actors;
    // 待機状態のActor群を格納する
    std::vector<class Actor*> pendiongActors;
    // Actorを更新しているか
    bool isUpdateActor;
};