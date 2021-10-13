#include "Game.h"
#include "DxLib.h"
#include "StateRegister.h"
#include "TitleScene.h"


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

    InitializeSceneStateToRegister();

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
    // ���[�v�̏I��
    if (ProcessMessage() == -1) isRunning = false;
    if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) isRunning = false;
}

void Game::UpdateGame()
{
    ClearDrawScreen();

    // �X�e�[�g��؂�ւ���(�m�F�p)
    if (GetMouseInput() & MOUSE_INPUT_LEFT)
        sceneState->ChangeState(SceneState::ETitle);


    // ���݂̃V�[����Update���Ă� 
    sceneState->stateRegister->Update();

    ScreenFlip();

    WaitTimer(20);
}

void Game::Shutdown()
{
    DxLib_End();
}

/// <summary>
/// �e�X�e�[�g��o�^����
/// </summary>
void Game::InitializeSceneStateToRegister()
{
    sceneState = new StateProcessor<SceneState>(SceneState::ETitle);
    
    titleScene = new TitleScene();
    //gameMainState = new GameMainState();
    //endState = new EndState();

    // TitleScene
    std::function<void()> titleSceneExecute = std::bind(&TitleScene::Execute, titleScene);
    std::function<void()> titleSceneUpdate = std::bind(&TitleScene::Update, titleScene);
    std::function<void()> titleSceneExit = std::bind(&TitleScene::Exit, titleScene);
    //// GameMainState
    //std::function<void()> GameMainStateExecute = std::bind(&GameMainState::Execute, gameMainState);
    //std::function<void()> GameMainStateUpdate = std::bind(&GameMainState::Update, gameMainState);
    //std::function<void()> GameMainStateExit = std::bind(&GameMainState::Exit, gameMainState);
    //// EndState
    //std::function<void()> EndStateExecute = std::bind(&EndState::Execute, endState);
    //std::function<void()> EndStateUpdate = std::bind(&EndState::Update, endState);
    //std::function<void()> EndStateExit = std::bind(&EndState::Exit, endState);

    // �X�e�[�g��o�^����
    sceneState->RegisterState(SceneState::ETitle, titleSceneExecute, titleSceneUpdate, titleSceneExit);
    //stateProcessor->RegisterState(StateType::GameMain, GameMainStateExecute, GameMainStateUpdate, GameMainStateExit);
    //stateProcessor->RegisterState(StateType::End, EndStateExecute, EndStateUpdate, EndStateExit);
}

/// <summary>
/// Actor��ǉ�����
/// </summary>
/// <param name="actor"></param>
void Game::AddActor(Actor* actor)
{
    // Actor�̍X�V���Ȃ�ҋ@��Ԃɒǉ�
    if (isUpdateActor)
    {
        pendiongActors.emplace_back(actor);
    }
    else
    {
        actors.emplace_back(actor);
    }
}

/// <summary>
/// Actor���폜����
/// </summary>
/// <param name="actor"></param>
void Game::RemoveActor(Actor* actor)
{
    // Actor���ҋ@��ԂȂ�
    auto iter = std::find(pendiongActors.begin(), pendiongActors.end(), actor);
    if (iter != pendiongActors.end())
    {
        // �Ō�Ɏ����Ă��č폜����
        std::iter_swap(iter, pendiongActors.end() - 1);
        pendiongActors.pop_back();
    }

    // Actor���X�V���Ȃ�
    iter = std::find(actors.begin(), actors.end(), actor);
    if (iter != actors.end())
    {
        // �Ō�Ɏ����Ă��č폜����
        std::iter_swap(iter, actors.end() -1);
        actors.pop_back();
    }
}