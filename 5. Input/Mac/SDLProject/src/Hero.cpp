#include "Engine/Graphics/Animation.h"
#include "Engine/Input/Controller.h"
#include "Hero.h"

const int LEFT = 1;
const int RIGHT = 2;

Hero::Hero(SDL_Renderer *renderer, Controller *controller) : _renderer(renderer), _controller(controller) {
}

void Hero::Init() {
    _heroAnimation = new Animation("resources/hero_walk.png", _renderer, 10, 1, 707, 587);
    _heroAnimation->Init();

    _destHeroRect.x = 0;
    _destHeroRect.y = 155;
    _destHeroRect.w = 195;
    _destHeroRect.h = 235;

    _heroXPosition = 0;
}

void Hero::Update(double elapsedSeconds) {
    if (_controller->GetButtonDown(RIGHT)) {
        _heroXPosition += 30 * elapsedSeconds;
    } else if (_controller->GetButtonDown(LEFT)) {
        _heroXPosition -= 30 * elapsedSeconds;
    }
    _destHeroRect.x = _heroXPosition;

    _heroAnimation->Update(elapsedSeconds);
}

void Hero::Render() {
    _heroAnimation->Render(&_destHeroRect);
}

void Hero::Release() {
    _heroAnimation->Release();
    delete _heroAnimation;
}


