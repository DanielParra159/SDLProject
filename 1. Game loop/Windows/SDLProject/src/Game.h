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
};


#endif //SDLPROJECT_GAME_H
