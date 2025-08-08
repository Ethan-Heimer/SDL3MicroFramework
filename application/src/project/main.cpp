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
