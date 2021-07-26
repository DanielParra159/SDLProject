#include <SDL.h>
#include <stdio.h>
#include <exception>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
bool isRunning;


class SDL_Exception : public std::exception {
public:
    SDL_Exception(const char *message) : message(message) {}

    virtual const char *what() const throw() {
        return message;
    }

    const char *message;
};

void initGame() {
    isRunning = true;
}

void initSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }
}

void createWindowAndRenderer() {
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &window, &renderer);

    if (window == NULL || renderer == NULL) {
        throw SDL_Exception(SDL_GetError());
    }
}

void releaseGame() {

}

void handleEvents() {
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

void update() {
    // game logic
}

void render() {
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

int main(int argc, char *args[]) {
    try {
        initSDL();
        createWindowAndRenderer();
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    } catch (SDL_Exception &ex) {
        printf(ex.what());
        SDL_Quit();
        return -1;
    }

    initGame();

    while (isRunning) {
        handleEvents();

        update();

        render();
    }

    releaseGame();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}