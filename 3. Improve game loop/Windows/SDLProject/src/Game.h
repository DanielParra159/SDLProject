#ifndef SDLPROJECT_GAME_H
#define SDLPROJECT_GAME_H


class Game {
public:
    void Init();

    void HandleEvents();

    void Update();

    void Render();

    void Release();

    bool IsRunning();

private:
    void InitSDL();

    void CreateWindowAndRender();

private:
    bool _isRunning;

    SDL_Window *_window;
    SDL_Renderer *_renderer;

    SDL_Texture *_logoTexture;
    SDL_Rect _sourceLogoRect;
    SDL_Rect _destLogoRect;

    SDL_Texture *_heroTexture;
    SDL_Rect _sourceHeroRect;
    SDL_Rect _destHeroRect;
    int _frameIndex;
};


#endif //SDLPROJECT_GAME_H
