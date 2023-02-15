/**/

#include <SDL.h>

class Reversi
{
    public:
        Reversi();
        bool Initialize();
        void RunLoop();
        void Shutdown();

    private:
        void ProcessInput();
        void UpdateGame();
        void GenerateOutput();

        // SDLが作るウィンドウ
        SDL_Window* mWindow;
        // ゲームの続行
        bool mIsRunning;
        SDL_Renderer* mRenderer;

        Uint32 mTicksCount;

};