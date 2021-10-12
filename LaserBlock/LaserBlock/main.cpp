#include "DxLib.h"
#include <magic_enum.hpp>
const char* TITLE = "Untitled";
const int WIN_WIDTH = 960;
const int WIN_HEIGHT = 540;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    ChangeWindowMode(true);
    SetWindowSizeChangeEnableFlag(false, false);
    SetMainWindowText(TITLE);
    SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
    SetWindowSizeExtendRate(1.0);
    SetBackgroundColor(35, 35, 35);
    SetDrawScreen(DX_SCREEN_BACK);

    if (DxLib_Init() == -1) { return -1; }

    while (true)
    {
        ClearDrawScreen();
        
        ScreenFlip();
        WaitTimer(20);
        if (ProcessMessage() == -1) { break; }
        if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) { break; }
    }

    DxLib_End();
    return 0;
}