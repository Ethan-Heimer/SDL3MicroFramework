#include "renderobject.h"

#include <iostream>

RenderObject::~RenderObject(){
    SDL_DestroySurface(surface);
    delete rect;

    std::cout << "Freed Render Object" << std::endl;
}

SDL_Surface* RenderObject::GetSurface(){
    return surface; 
}


SDL_FRect* RenderObject::GetRect(){
    return rect;
}

double RenderObject::GetAngle(){
    return angle;
}
