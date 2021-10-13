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

    // Actor�̒ǉ� / �폜
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

    // �A�N�e�B�u��Actor�Q���i�[����
    std::vector<class Actor*> actors;
    // �ҋ@��Ԃ�Actor�Q���i�[����
    std::vector<class Actor*> pendiongActors;
    // Actor���X�V���Ă��邩
    bool isUpdateActor;
};