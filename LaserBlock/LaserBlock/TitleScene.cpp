#include "TitleScene.h"
#include "DxLib.h"// debug用 あとで消す

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

void TitleScene::Execute()
{
  
}

void TitleScene::Update()
{
    DrawFormatString(200, 75, GetColor(255, 255, 255), "%s", "TitleScene::Update");
}

void TitleScene::Exit()
{

}