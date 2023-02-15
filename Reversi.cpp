#include "Reversi.h"
#include <cstdio>
#include "SimpleShape.h"


// パラメータ
const int window_x = 768;
const int window_y = 768;

Reversi::Reversi()
:mWindow(nullptr),
mRenderer(nullptr),
mTicksCount(0)
{}

bool Reversi::Initialize(){
    printf("Start Initialize, Status: ");
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if(sdlResult!=0){
        // /SDLでメッセージをコンソールに出す
        SDL_Log("SDLを初期化で来ません:%s",SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow(
		"Game Programming in C++ (Chapter 1)", // Window title
		100,	// Top left x-coordinate of window
		100,	// Top left y-coordinate of window
		window_x,	// Width of window
		window_y,	// Height of window
		0		// Flags (0 for no flags set)
	);

    if(!mWindow){
        printf("Failed to create window: %s", SDL_GetError());
		return false;
    }
    mRenderer = SDL_CreateRenderer(
        mWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    return true;
}

void Reversi::Shutdown(){
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Reversi::RunLoop(){
    SDL_Event event;
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Reversi::ProcessInput(){
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            // ユーザがウィンドウを閉じようとしたとき
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
    // ESCキーの状態を取得
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_ESCAPE]){
        mIsRunning = false;
    }

    // 操作例
    // if(state[SDL_SCANCODE_W]){
    //     mPaddleDir-=1;
    // }
}

void Reversi::UpdateGame(){
    while (!SDL_TICKS_PASSED(SDL_GetTicks(),mTicksCount+16));

    float deltaTime = (SDL_GetTicks()-mTicksCount)/1000.0f;
    mTicksCount = SDL_GetTicks();
    // デルタタイムの最大値
    if(deltaTime>0.05f){
        deltaTime=0.05f;
    }

    /**ゲームの処理を記述*/
}

void Reversi::GenerateOutput(){
    SDL_SetRenderDrawColor(
        mRenderer,
        0,
        0,
        0,
        255
    );
    SDL_RenderClear(mRenderer);
    SDL_SetRenderDrawColor(
        mRenderer,
        255,255,255,255
    );

    DrawEllipse(60,100,100,mRenderer);
    SDL_RenderPresent(mRenderer);
}