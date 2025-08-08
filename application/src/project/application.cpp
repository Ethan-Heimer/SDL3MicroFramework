#include <SDL3/SDL.h>
#include <vector>

#include "application.h"
#include "WindowManager.h"
#include "RendererManager.h"
#include "renderobject.h"
#include "TextureManager.h"

void Application::Init(ERRORS& errors){
    //Initializes video
    bool init = SDL_Init(SDL_INIT_VIDEO);

    if(!init){ 
        errors = ERRORS::SDL_INIT_ERROR;
        return;
    } 

    errors = WindowManager::Init();
    if(errors != ERRORS::SUCCSESS){
        return;
    }

    errors = RenderManager::Init();
    if(errors != ERRORS::SUCCSESS){
        return;
    }
}

void Application::Run(ERRORS& errors){
    std::vector<RenderObject> objects; 

    SDL_Renderer* renderer = RenderManager::GetRenderer(); 

    SDL_Surface* surface1 = NULL;
    SDL_Surface* surface2 = NULL;

    TextureManager::GetTexture("./assets/Dog.jpeg", surface1);
    TextureManager::GetTexture("./assets/Avery.jpg", surface2);

    RenderObject object1{surface1, 0, 0, 100, 100, 0};
    RenderObject object2{surface2, 200, 100, 100, 100, 0};

    objects.push_back(object2);
    objects.push_back(object1);

    SDL_FPoint pivot{0, 0};
    SDL_FlipMode flip = SDL_FLIP_NONE;

    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            break;
        }

        RenderManager::RendererStart();

        for(int i = 0; i < objects.size(); i++){
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, objects[i].GetSurface());
            SDL_FRect* rect = objects[i].GetRect();
            double angle = objects[i].GetAngle();

            SDL_RenderTextureRotated(renderer, texture, NULL, rect, angle, &pivot, flip);

            SDL_DestroyTexture(texture);
        }
        
        RenderManager::RendererEnd();
    } 
}

void Application::Shutdown(ERRORS& errors){
    RenderManager::Shutdown();
    WindowManager::Shutdown();

    SDL_Quit();
    errors = ERRORS::SUCCSESS;
}
