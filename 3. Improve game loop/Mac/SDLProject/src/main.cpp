#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include <exception>

int main(int argc, char *args[]) {
    auto game = Game();
    try {
        game.Init();

        while (game.IsRunning()) {
            double start = SDL_GetTicks();
            game.HandleEvents();

            game.Update();

            game.Render();
            const int MS_PER_FRAME = 16;
            double end = SDL_GetTicks();
            auto delay = start + MS_PER_FRAME - end;


            if (delay > 0) {
                SDL_Delay(delay);
            }
        }

        game.Release();
    } catch (std::exception &exception) {
        fprintf(stderr, exception.what());
        SDL_Quit();
        return -1;
    }

    return 0;
}





