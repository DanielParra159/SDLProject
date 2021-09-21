#ifndef SDLPROJECT_ANIMATION_H
#define SDLPROJECT_ANIMATION_H

#include <SDL_render.h>
#include <string>

class Texture;

class Animation {
public:
    Animation(std::string path, SDL_Renderer *renderer, int frames, float duration, int frameHeight, int frameWidth);

    void Init();
    void Release();

    void Update(double elapsedSeconds);

    void Render(const SDL_Rect *destRect) const;

private:
    Texture *_texture;
    int _frames;
    float _duration;
    double _currentTime;
    SDL_Rect _sourceRect;
    int _frameHeight;
    int _frameWidth;
};


#endif //SDLPROJECT_ANIMATION_H
