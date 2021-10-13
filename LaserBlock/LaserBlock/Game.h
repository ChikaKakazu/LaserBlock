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

    // Actor‚Ì’Ç‰Á / íœ
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

    // ƒAƒNƒeƒBƒu‚ÈActorŒQ‚ğŠi”[‚·‚é
    std::vector<class Actor*> actors;
    // ‘Ò‹@ó‘Ô‚ÌActorŒQ‚ğŠi”[‚·‚é
    std::vector<class Actor*> pendiongActors;
    // Actor‚ğXV‚µ‚Ä‚¢‚é‚©
    bool isUpdateActor;
};