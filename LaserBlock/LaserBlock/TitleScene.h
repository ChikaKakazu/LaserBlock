#pragma once
#include "BaseState.h"

class TitleScene : BaseState
{
    public:
        TitleScene();
        ~TitleScene();

        void Execute() override;
        void Update() override;
        void Exit() override;
};