#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

#include <SDL3/SDL_tray.h>
#include <vector>

#include "application.h"
#include "managers/window/WindowManager.h"
#include "managers/render/RendererManager.h"
#include "managers/texture/TextureManager.h"
#include "utils/errors/errors.h"
#include "objects/renderobjects/renderobject.h"

int main(int argc, char* argv[]){
    ERRORS errors;

    errors = Application::Init();
    if(errors != ERRORS::SUCCSESS){
        LogError(errors);            
        return errors;
    }

    errors = Application::Run();
    if(errors != ERRORS::SUCCSESS){
        LogError(errors);            
        return errors;
    } 

    errors = Application::Shutdown();
    if(errors != ERRORS::SUCCSESS){
        LogError(errors);            
        return errors;
    }

    return 0;
}
