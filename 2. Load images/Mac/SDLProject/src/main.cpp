#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include <exception>

int main(int argc, char *args[]) {
    auto game = Game();
    try {
        game.Init();

        while (game.IsRunning()) {
            game.HandleEvents();

            game.Update();

            game.Render();
        }

        game.Release();
    } catch (std::exception &exception) {
        fprintf(stderr, exception.what());
        SDL_Quit();
        return -1;
    }

    return 0;
}





