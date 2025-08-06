#include "RendererManager.h"
#include "../window/WindowManager.h"

#include <iostream>

SDL_Renderer* RenderManager::renderer = NULL;

ERRORS RenderManager::Init(){
    SDL_Window* window = WindowManager::GetWindow();

    if(window == NULL){
        return ERRORS::WINDOW_NOT_INIT;
    }
    
    RenderManager::renderer = SDL_CreateRenderer(window, NULL); 
    
    if(renderer == NULL){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        return ERRORS::RENDERER_NOT_INIT;
    }

    return ERRORS::SUCCSESS;
}

SDL_Renderer* RenderManager::GetRenderer(){
    return renderer;
}

void RenderManager::RendererStart(){
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
}

void RenderManager::RendererEnd(){
    SDL_RenderPresent(renderer);
}

void RenderManager::Shutdown(){
    SDL_DestroyRenderer(renderer);
}
