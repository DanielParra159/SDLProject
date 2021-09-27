#ifndef SDLPROJECT_HERO_H
#define SDLPROJECT_HERO_H


#include <SDL_render.h>
class Texture;
class Animation;
class Controller;

class Hero {
public:
    Hero(SDL_Renderer *renderer, Controller* controller);
    void Init();
    void Release();

    void Update(double elapsedSeconds);

    void Render();

private:
    SDL_Renderer *_renderer;
    Controller *_controller;

    Animation *_heroAnimation;
    SDL_Rect _destHeroRect;
    float _heroXPosition;
};


#endif //SDLPROJECT_HERO_H
