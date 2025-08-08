#ifndef RENDER_OBJECT
#define RENDER_OBJECT

#include "SDL3/SDL.h"
#include <iostream>

class RenderObject{
    public: 
        RenderObject(SDL_Surface* surface, float x, float y, float w, float h, double angle) 
            : surface(surface), angle(angle){
            rect = new SDL_FRect{x, y, w, h}; 
        }

        RenderObject(const RenderObject& original){
            rect = new SDL_FRect{}; 
            rect->x = original.rect->x;
            rect->y = original.rect->y;
            rect->w = original.rect->w;
            rect->h = original.rect->h;

            surface = SDL_DuplicateSurface(original.surface);

            std::cout << "Copy constructor called" << std::endl;
        }

        RenderObject(RenderObject&& original){
            rect = original.rect; 
            surface = original.surface;

            original.rect = NULL;
            original.surface = NULL;
            
            std::cout << "Move constructor called" << std::endl;
        }

        ~RenderObject();

        SDL_Surface* GetSurface(); 
        SDL_FRect* GetRect();

        double GetAngle();
               
    private:
        SDL_Surface* surface = NULL;
        SDL_FRect* rect = NULL;

        double angle = 0; 
};


#endif
