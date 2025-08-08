#include "errors.h"

#include "SDL3/SDL.h"
#include <iostream>

void LogError(ERRORS error){
    if(error == ERRORS::SUCCSESS)
        return;
    
    std::cout << "System Error:" << std::endl;
    switch(error){
        case ERRORS::SUCCSESS:
            std::cout << "Succsess" << std::endl;
            break;

        case ERRORS::RENDERER_NOT_INIT:
            std::cout << "Renderer Not Initailized" << std::endl;
            break;

        case ERRORS::WINDOW_NOT_INIT:
            std::cout << "Window Not Initailized" << std::endl;
            break;

        case ERRORS::TEXTURE_ERROR:
            std::cout << "TEXTURE ERROR: Image likely not found" << std::endl;
            break;

        case ERRORS::SDL_INIT_ERROR:
            std::cout << "SDL INIT ERROR: SDL failed to initialize" << std::endl;
            break;

        default:
            std::cout << "Error Not Found" << std::endl;
            break;
    }

    std::cout << "SDL says: " << SDL_GetError() << std::endl;
}
