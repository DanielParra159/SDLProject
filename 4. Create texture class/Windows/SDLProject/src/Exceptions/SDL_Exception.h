#ifndef SDLPROJECT_SDL_EXCEPTION_H
#define SDLPROJECT_SDL_EXCEPTION_H

#include <exception>

class SDL_Exception : public std::exception {
public:
    SDL_Exception(const char *message) : message(message) {}

    virtual const char *what() const throw() {
        return message;
    }

    const char *message;
};


#endif //SDLPROJECT_SDL_EXCEPTION_H
