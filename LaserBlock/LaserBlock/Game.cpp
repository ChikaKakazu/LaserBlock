#include "Game.h"
#include "DxLib.h"
#include "StateRegister.h"


Game::Game() : isRunning(true)
{

}

Game::~Game()
{

}

bool Game::Initialize()
{
    ChangeWindowMode(true);
    SetWindowSizeChangeEnableFlag(false, false);
    SetMainWindowText(TITLE);
    SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
    SetWindowSizeExtendRate(1.0);
    SetBackgroundColor(35, 35, 35);
    SetDrawScreen(DX_SCREEN_BACK);

    if (DxLib_Init() == -1) return -1;

    InitializeStateToRegister();

    return true;
}

void Game::RunLoop()
{
    while (isRunning)
    {
        ProcessInput();
        UpdateGame();
    }
}

void Game::ProcessInput()
{
    // ループの終了
    if (ProcessMessage() == -1) isRunning = false;
    if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) isRunning = false;
}

void Game::UpdateGame()
{
    ClearDrawScreen();

    // ステートを切り替える
    /*if (GetMouseInput() & MOUSE_INPUT_LEFT)
        stateProcessor->ChangeState(StateType::GameMain);
    else if (GetMouseInput() & MOUSE_INPUT_RIGHT)
        stateProcessor->ChangeState(StateType::End);
    else if (GetMouseInput() & MOUSE_INPUT_MIDDLE)
        stateProcessor->ChangeState(StateType::Title);

    stateProcessor->stateRegister->Update();*/

    ScreenFlip();

    WaitTimer(20);
}

void Game::Shutdown()
{
    DxLib_End();
}

/// <summary>
/// 各ステートを登録する
/// </summary>
void Game::InitializeStateToRegister()
{
    //stateProcessor = new StateProcessor<StateType>(StateType::Title);

    //titleState = new TitleState();
    //gameMainState = new GameMainState();
    //endState = new EndState();

    //// TitleState
    //std::function<void()> TitleStateExecute = std::bind(&TitleState::Execute, titleState);
    //std::function<void()> TitleStateUpdate = std::bind(&TitleState::Update, titleState);
    //std::function<void()> TitleStateExit = std::bind(&TitleState::Exit, titleState);
    //// GameMainState
    //std::function<void()> GameMainStateExecute = std::bind(&GameMainState::Execute, gameMainState);
    //std::function<void()> GameMainStateUpdate = std::bind(&GameMainState::Update, gameMainState);
    //std::function<void()> GameMainStateExit = std::bind(&GameMainState::Exit, gameMainState);
    //// EndState
    //std::function<void()> EndStateExecute = std::bind(&EndState::Execute, endState);
    //std::function<void()> EndStateUpdate = std::bind(&EndState::Update, endState);
    //std::function<void()> EndStateExit = std::bind(&EndState::Exit, endState);

    //// ステートを登録する
    //stateProcessor->RegisterState(StateType::Title, TitleStateExecute, TitleStateUpdate, TitleStateExit);
    //stateProcessor->RegisterState(StateType::GameMain, GameMainStateExecute, GameMainStateUpdate, GameMainStateExit);
    //stateProcessor->RegisterState(StateType::End, EndStateExecute, EndStateUpdate, EndStateExit);
}