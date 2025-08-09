#ifndef RENDER_MANAGER
#define RENDER_MANAGER

#include "SDL3/SDL.h"
#include "errors.h"
#include "GameObject.h"

class RenderManager{
    public:
        static ERRORS Init();
        static SDL_Renderer* GetRenderer();
        static void Shutdown(); 

        static void RendererStart();
        static void Render();
        static void RendererEnd();
    private:
        static void RenderGameObject(const GameObject& gameobject);
        static SDL_Renderer* renderer;
        static SDL_FPoint pivot;
        static SDL_FlipMode flip;
};

#endif
