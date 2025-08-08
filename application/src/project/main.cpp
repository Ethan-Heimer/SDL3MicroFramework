#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

#include <SDL3/SDL_tray.h>
#include <vector>

#include "application.h"
#include "WindowManager.h"
#include "RendererManager.h"
#include "TextureManager.h"
#include "errors.h"
#include "renderobject.h"

void Play(ERRORS& errors);

int main(int argc, char* argv[]){
    ERRORS errors;
    std::cout << "Trying to play" << std::endl;

    Application::Init(errors);
    LogError(errors);            

    Play(errors);
    LogError(errors);            

    Application::Shutdown(errors);
    LogError(errors);            

    return 0;
}

void Play(ERRORS& errors){
    if(errors == ERRORS::SUCCSESS){
        Application::Run(errors);
    }
}
