#include "InputComponent.h"
#include "InputMananger.h"
#include "SDL3/SDL.h"
#include <vector>

#include "application.h"
#include "GameObject.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_scancode.h"
#include "WindowManager.h"
#include "RendererManager.h"
#include "renderobject.h"
#include "TextureManager.h"
#include "SceneManager.h"
#include "EventManager.h"

void Application::Init(ERRORS& errors){
    //Initializes video
    bool init = SDL_Init(SDL_INIT_VIDEO);

    if(!init){ 
        errors = ERRORS::SDL_INIT_ERROR;
        return;
    } 

    errors = WindowManager::Init();
    if(errors != ERRORS::SUCCSESS){
        return;
    }

    errors = RenderManager::Init();
    if(errors != ERRORS::SUCCSESS){
        return;
    }

    Scene* sceneOne = SceneManager::CreateScene("Test Scene");
    Scene* sceneTwo = SceneManager::CreateScene("Test Scene Two");
    
    SDL_Surface* surface1 = NULL;
    SDL_Surface* surface2 = NULL;

    TextureManager::GetTexture("./assets/Dog.jpeg", surface1);
    TextureManager::GetTexture("./assets/Avery.jpg", surface2);

    GameObject* gameObject = sceneOne->CreateGameObject(surface1, 0, 0);
    GameObject* gameObject2 = sceneOne->CreateGameObject(surface2, 200, 100);

    sceneTwo->CreateGameObject(surface1, 500, 300);
    sceneTwo->CreateGameObject(surface2, 200, 210);

    auto* component = gameObject->AddComponent<InputComponent>();
    component->SetSpeed(.5f);

    SceneManager::LoadScene("Test Scene");
}

void Application::Run(ERRORS& errors){
    SDL_Renderer* renderer = RenderManager::GetRenderer(); 

    while (true) {
        EventManager::Poll();

        if(EventManager::EvaluateEventState([](const SDL_Event& event){
            return event.type == SDL_EVENT_QUIT;
        })){
           break; 
        }
 
        if (InputManager::IsKeyDown(SDL_SCANCODE_L)){
            SceneManager::LoadScene("Test Scene Two");
        }

        SceneManager::InvokeSceneUpdate(); 
        RenderManager::Render();
    } 
}

void Application::Shutdown(ERRORS& errors){
    RenderManager::Shutdown();
    WindowManager::Shutdown();

    SceneManager::DeallocateScenes();

    SDL_Quit();
    errors = ERRORS::SUCCSESS;
}
