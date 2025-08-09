#include "RendererManager.h"
#include "WindowManager.h"
#include "SceneManager.h"

#include <iostream>

SDL_Renderer* RenderManager::renderer = NULL;
SDL_FPoint RenderManager::pivot{0, 0};
SDL_FlipMode RenderManager::flip = SDL_FLIP_NONE; 

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

void RenderManager::Render(){
    Scene* currentScene = SceneManager::GetCurrentScene();
    if(currentScene == nullptr)
        return; 

    RenderManager::RendererStart();                    
    currentScene->ForeachGameobject(RenderGameObject);
    RenderManager::RendererEnd();
}

void RenderManager::RenderGameObject(const GameObject& gameobject){
    RenderObject* renderObject = gameobject.GetRenderObject();

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, renderObject->GetSurface());
    SDL_FRect* rect = renderObject->GetRect();
    double angle = renderObject->GetAngle();

    SDL_RenderTextureRotated(renderer, texture, NULL, rect, angle, &pivot, flip);
    SDL_DestroyTexture(texture);
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

SDL_Renderer* RenderManager::GetRenderer(){
    return renderer;
}

