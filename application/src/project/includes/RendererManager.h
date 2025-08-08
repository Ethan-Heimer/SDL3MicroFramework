#ifndef RENDER_MANAGER
#define RENDER_MANAGER

#include "SDL3/SDL.h"
#include "errors.h"

class RenderManager{
    public:
        static ERRORS Init();
        static SDL_Renderer* GetRenderer();
        static void Shutdown(); 

        static void RendererStart();
        //Render Object
        static void RendererEnd();
    private:
        static SDL_Renderer* renderer;
};

#endif
