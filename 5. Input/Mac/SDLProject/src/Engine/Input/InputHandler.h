#ifndef SDLPROJECT_INPUTHANDLER_H
#define SDLPROJECT_INPUTHANDLER_H


#include <SDL_events.h>
#include <vector>
#include "Controller.h"

enum ButtonStates {
    None,
    Pressed,
    Released
};

struct InputButton {
    int ActionId;
    int Code;
    ButtonStates State;

    InputButton() {}

    InputButton(int actionId, int code) : ActionId(actionId), Code(code), State(ButtonStates::None) {
    }
};

struct InputAxis {
    int ActionId;
    int NegativeCode;
    int PositiveCode;
    int Value;

    InputAxis() {}

    InputAxis(int actionId, int negativeCode, int positiveCode) : ActionId(actionId), NegativeCode(negativeCode),
                                                                  PositiveCode(positiveCode), Value(0) {
    }
};

class InputHandler {
public:
    void PreHandleEvent();

    void HandleEvent(const SDL_Event *event);

    void Update(double elapsedSeconds);

    void AddController(Controller *controller);

private:
    std::vector<Controller *> _controllers;
};


#endif //SDLPROJECT_INPUTHANDLER_H
