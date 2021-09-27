#include <SDL.h>
#include "Game.h"
#include "Exceptions/SDL_Exception.h"
#include "Engine/Graphics/Texture.h"
#include "Hero.h"
#include "Engine/Input/InputHandler.h"
#include "Engine/Input/Keyboard.h"

const int JUMP = 0;
const int LEFT = 1;
const int RIGHT = 2;
Keyboard *keyboard;

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



    _inputHandler = new InputHandler();
    keyboard = new Keyboard();
    //auto button1 = InputButton{JUMP, SDLK_d};
    auto button1 = InputButton{RIGHT, SDLK_d};
    auto button2 = InputButton{LEFT, SDLK_a};
    keyboard->AddButtonMap(button1);
    keyboard->AddButtonMap(button2);
    _inputHandler->AddController(keyboard);

    _hero = new Hero(_renderer, keyboard);
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
    _inputHandler->PreHandleEvent();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        } else {
            _inputHandler->HandleEvent(&event);
        }
    }
}

void Game::Update(double elapsedSeconds) {
    if (keyboard->GetButtonDown(JUMP)) {
        printf("Down ");
    }
    if (keyboard->GetButtonUp(JUMP)) {
        printf("Up ");
    }
    if (keyboard->GetButton(JUMP)) {
        printf("Button ");
    }

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
    delete keyboard;
    delete _inputHandler;

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Game::IsRunning() {
    return _isRunning;
}

