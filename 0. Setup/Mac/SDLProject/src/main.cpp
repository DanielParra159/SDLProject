#include <SDL.h>
#include <stdio.h>

bool init() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

SDL_Window *getWindow() {
    SDL_Window *window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          512, 512, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

    }
    return window;
}

SDL_Surface *getSurface(SDL_Window *window) {
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);

    if (screenSurface == NULL) {
        printf("Surface could not be created! SDL_Error: %s\n", SDL_GetError());
    }

    return screenSurface;
}

void release(SDL_Window *window, SDL_Surface *screenSurface) {
    SDL_FreeSurface(screenSurface);
    screenSurface = NULL;

    SDL_DestroyWindow(window);

    SDL_Quit();
}

void mainLoop() {
    bool mustQuit = false;
    SDL_Event e;
    while (!mustQuit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                mustQuit = true;
            }
        }
    }
}

int main(int argc, char *args[]) {
    if (!init()) {
        SDL_Quit();
        return -1;
    }

    SDL_Window *window = getWindow();
    if (window == NULL) {
        SDL_Quit();
        return -1;
    }

    SDL_Surface *screenSurface = getSurface(window);
    if (screenSurface == NULL) {
        SDL_Quit();
        return -1;
    }

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    SDL_UpdateWindowSurface(window);

    mainLoop();

    release(window, screenSurface);

    return 0;
}





