#ifndef EVENT_MANAGER
#define EVENT_MANAGER

#include "SDL3/SDL.h"
#include <functional>

class EventManager{
    public:
        static void Poll();
        static bool EvaluateEventState(std::function<bool(const SDL_Event&)>);

    private:
        static SDL_Event event;
};

#endif
