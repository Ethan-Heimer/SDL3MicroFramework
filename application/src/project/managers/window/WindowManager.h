#ifndef WINDOW_MANAGER
#define WINDOW_MANAGER

#include "SDL3/SDL.h"
#include "../../utils/errors/errors.h"

class WindowManager{
    private:
        static SDL_Window* window;
    public:
        static ERRORS Init();
        static SDL_Window* GetWindow();
        static void Shutdown();
};

#endif
