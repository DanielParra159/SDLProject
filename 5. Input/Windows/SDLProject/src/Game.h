#ifndef SDLPROJECT_GAME_H
#define SDLPROJECT_GAME_H

class Texture;
class Hero;
class InputHandler;

class Game {
public:
    void Init();

    void HandleEvents();

    void Update(double elapsedSeconds);

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

    Texture *_logoTexture;
    SDL_Rect _destLogoRect;

    Hero *_hero;

    InputHandler* _inputHandler;
};


#endif //SDLPROJECT_GAME_H
