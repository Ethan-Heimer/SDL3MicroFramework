#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "SDL3/SDL.h"

class InputManager{
    public:
        static bool IsKeyDown(SDL_Scancode key);
};

#endif
