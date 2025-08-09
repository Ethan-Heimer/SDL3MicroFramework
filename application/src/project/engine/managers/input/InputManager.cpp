#include "EventManager.h"
#include "InputMananger.h"
#include "SDL3/SDL_scancode.h"
#include "SDL3/SDL.h"

bool InputManager::IsKeyDown(SDL_Scancode key){
    return SDL_GetKeyboardState(NULL)[key];
}
