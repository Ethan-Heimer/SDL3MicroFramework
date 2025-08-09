#include "InputComponent.h"

#include "InputMananger.h"
#include "SDL3/SDL_scancode.h"
#include <iostream>
#include "GameObject.h"

void InputComponent::Update() {
    if(InputManager::IsKeyDown(SDL_SCANCODE_D)){
       this->gameObject->Move(speed, 0);  
    }

    if(InputManager::IsKeyDown(SDL_SCANCODE_A)){
       this->gameObject->Move(-speed, 0);  
    }
    
    if(InputManager::IsKeyDown(SDL_SCANCODE_W)){
       this->gameObject->Move(0, -speed);  
    }

    if(InputManager::IsKeyDown(SDL_SCANCODE_S)){
       this->gameObject->Move(0, speed);  
    }
}

void InputComponent::SetSpeed(float speed){
    this->speed = speed;
}
