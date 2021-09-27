#include "Keyboard.h"


void Keyboard::AddButtonMap(InputButton &inputButton) {
    _buttonsMap[inputButton.ActionId] = inputButton;
    _keyToActionMap[inputButton.Code] = inputButton.ActionId;
}

void Keyboard::AddAxisMap(InputAxis &inputAxis) {
    _axisMap[inputAxis.ActionId] = inputAxis;
    _keyToAxisActionMap[inputAxis.PositiveCode] = inputAxis.ActionId;
    _keyToAxisActionMap[inputAxis.NegativeCode] = inputAxis.ActionId;
}

void Keyboard::ResetEvents() {
    for (auto &item : _buttonsMap) {
        item.second.State = ButtonStates::None;
    }

    for (auto &item : _axisMap) {
        item.second.Value = 0;
    }
}

void Keyboard::HandleEvent(const SDL_Event *event) {
    if (event->type != SDL_KEYDOWN && event->type != SDL_KEYUP) {
        return;
    }

    HandleButton(event);
    HandleAxis(event);

}

void Keyboard::HandleButton(const SDL_Event *event) {
    auto code = event->key.keysym.sym;
    auto action = _keyToActionMap.find(code);
    if (action == _keyToActionMap.cend()) {
        return;
    }

    if (event->key.state == SDL_PRESSED) {
        _buttonsMap[action->second].State = Pressed;
        return;
    }
    _buttonsMap[action->second].State = Released;
}

void Keyboard::HandleAxis(const SDL_Event *event) {

}

bool Keyboard::GetButtonDown(int actionId) const {
    auto inputButton = _buttonsMap.find(actionId);
    if (inputButton == _buttonsMap.cend()) {
        return false;
    }

    return inputButton->second.State == ButtonStates::Pressed;
}

bool Keyboard::GetButtonUp(int actionId) const {
    auto inputButton = _buttonsMap.find(actionId);
    if (inputButton == _buttonsMap.cend()) {
        return false;
    }

    return inputButton->second.State == ButtonStates::Released;
}

bool Keyboard::GetButton(int actionId) const {
    auto inputButton = _buttonsMap.find(actionId);
    if (inputButton == _buttonsMap.cend()) {
        return false;
    }

    return inputButton->second.State == ButtonStates::Released;
}

double Keyboard::GetAxis(const int actionId) const {
    auto inputAxis = _axisMap.find(actionId);
    if (inputAxis == _axisMap.cend()) {
        return 0;
    }

    return inputAxis->second.Value;
}






