#include "errors.h"
#include <iostream>

void LogError(ERRORS error){
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

        default:
            std::cout << "Error Not Found" << std::endl;
            break;
    }
}
