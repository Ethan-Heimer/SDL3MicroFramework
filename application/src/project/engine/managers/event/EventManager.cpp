#include "EventManager.h"

SDL_Event EventManager::event; 

void EventManager::Poll(){
    SDL_PollEvent(&event);
}

bool EventManager::EvaluateEventState(std::function<bool (const SDL_Event &)> callback){
    return callback(event); 
}
