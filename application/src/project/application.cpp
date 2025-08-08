#include <SDL3/SDL.h>
#include <vector>

#include "application.h"
#include "WindowManager.h"
#include "RendererManager.h"
#include "renderobject.h"
#include "TextureManager.h"

ERRORS Application::Init(){
    ERRORS error;
    //Initializes video
    bool init = SDL_Init(SDL_INIT_VIDEO);

    if(!init){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, 
                "Couldn't initialize SDL: %s", SDL_GetError());
        return ERRORS::SDL_INIT_ERROR;
    } 

    error = WindowManager::Init();
    if(error != ERRORS::SUCCSESS){
        return error;
    }

    error = RenderManager::Init();
    if(error != ERRORS::SUCCSESS){
        return error;
    }

    return ERRORS::SUCCSESS;
}

ERRORS Application::Run(){
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

    return ERRORS::SUCCSESS;
}

ERRORS Application::Shutdown(){
    RenderManager::Shutdown();
    WindowManager::Shutdown();

    SDL_Quit();

    return ERRORS::SUCCSESS;
}
