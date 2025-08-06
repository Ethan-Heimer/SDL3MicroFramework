#include "WindowManager.h"

SDL_Window* WindowManager::window = NULL;

ERRORS WindowManager::Init(){
    WindowManager::window = SDL_CreateWindow("Hello SDL", 
            1920, 1080, SDL_WINDOW_OPENGL); 

    if(window == NULL){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return ERRORS::WINDOW_NOT_INIT;
    }   

    return ERRORS::SUCCSESS;
}

SDL_Window* WindowManager::GetWindow(){
    return window;
}

void WindowManager::Shutdown(){
    SDL_DestroyWindow(window);
}
