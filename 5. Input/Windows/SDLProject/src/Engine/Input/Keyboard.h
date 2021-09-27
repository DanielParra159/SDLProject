#ifndef SDLPROJECT_KEYBOARD_H
#define SDLPROJECT_KEYBOARD_H


#include "Controller.h"
#include "InputHandler.h"

#include <unordered_map>


class Keyboard : public Controller {
public:
    void AddButtonMap(InputButton &inputButton);
    void AddAxisMap(InputAxis &inputAxis);

    void HandleEvent(const SDL_Event *event) override;
    bool GetButtonDown(int actionId) const override;
    bool GetButtonUp(int actionId) const override;
    bool GetButton(int actionId) const override;
    double GetAxis(const int actionId) const override;

    void ResetEvents() override;


private:
    void HandleButton(const SDL_Event *event);
    void HandleAxis(const SDL_Event *event);

private:
    std::unordered_map<int, InputButton> _buttonsMap;
    std::unordered_map<SDL_Keycode, int> _keyToActionMap;

    std::unordered_map<int, InputAxis> _axisMap;
    std::unordered_map<SDL_Keycode, int> _keyToAxisActionMap;

};


#endif //SDLPROJECT_KEYBOARD_H
