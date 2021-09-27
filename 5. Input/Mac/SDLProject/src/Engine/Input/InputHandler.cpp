#include "InputHandler.h"

void InputHandler::PreHandleEvent() {
    for (const auto &controller : _controllers){
        controller->ResetEvents();
    }
}

void InputHandler::HandleEvent(const SDL_Event *event) {


    for (const auto &controller : _controllers){
        controller->HandleEvent(event);
    }
    //event->key.keysym.sym
}

void InputHandler::AddController(Controller *controller) {
    _controllers.push_back(controller);
}

