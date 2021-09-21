#include <SDL.h>
#include "Game.h"
#include "Exceptions/SDL_Exception.h"
#include "Engine/Texture.h"
#include "Hero.h"

void Game::Init() {
    InitSDL();
    CreateWindowAndRender();
    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);


    _logoTexture = new Texture("resources/logo.png", _renderer);
    _logoTexture->Init();
    _destLogoRect.x = 0;
    _destLogoRect.y = 0;
    _destLogoRect.w = 150;
    _destLogoRect.h = 150;

    _hero = new Hero(_renderer);
    _hero->Init();

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

    if (_window == nullptr || _renderer == nullptr) {
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

void Game::Update(double elapsedSeconds) {
    _hero->Update(elapsedSeconds);
}

void Game::Render() {
    SDL_RenderClear(_renderer);

    // renderizar imagenes, etc.
    _logoTexture->Render(&_destLogoRect);

    _hero->Render();

    SDL_RenderPresent(_renderer);
}

void Game::Release() {
    _hero->Release();
    _logoTexture->Release();

    delete _hero;
    delete _logoTexture;

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Game::IsRunning() {
    return _isRunning;
}

