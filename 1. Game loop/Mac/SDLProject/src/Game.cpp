#include <SDL.h>
#include "Game.h"
#include "Exceptions/SDL_Exception.h"

void Game::Init() {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 0, 255, 255);

    _isRunning = true;
}

void Game::InitSDL() {
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if (!isInitialized) {
        throw SDL_Exception(SDL_GetError());
    }
}

void Game::CreateWindowAndRender() {
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer);

    if (_window == NULL || _renderer == NULL) {
        throw SDL_Exception(SDL_GetError());
    }
}


void Game::HandleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        }
    }
}

void Game::Update() {

}

void Game::Render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.

    SDL_RenderPresent(_renderer);
}

void Game::Release() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Game::IsRunning() {
    return _isRunning;
}

