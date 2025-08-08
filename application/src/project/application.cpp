#include "SDL3/SDL.h"
#include <vector>

#include "application.h"
#include "GameObject.h"
#include "SDL3/SDL_scancode.h"
#include "WindowManager.h"
#include "RendererManager.h"
#include "renderobject.h"
#include "TextureManager.h"
#include "SceneManager.h"

void RenderGameObject(SDL_Renderer* renderer, const SDL_FPoint pivot, const SDL_FlipMode flip, const GameObject& gameobject){
    RenderObject* renderObject = gameobject.GetRenderObject();

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, renderObject->GetSurface());
    SDL_FRect* rect = renderObject->GetRect();
    double angle = renderObject->GetAngle();

    SDL_RenderTextureRotated(renderer, texture, NULL, rect, angle, &pivot, flip);
    SDL_DestroyTexture(texture);
}

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

    sceneOne->CreateGameObject(surface1, 0, 0);
    sceneOne->CreateGameObject(surface2, 200, 100);

    sceneTwo->CreateGameObject(surface1, 500, 300);
    sceneTwo->CreateGameObject(surface2, 200, 210);

    SceneManager::LoadScene("Test Scene");
}

void Application::Run(ERRORS& errors){
    SDL_Renderer* renderer = RenderManager::GetRenderer(); 

    SDL_FPoint pivot{0, 0};
    SDL_FlipMode flip = SDL_FLIP_NONE;

    SDL_Event event;
    while (true) {
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT) {
            break;
        }
        if (event.key.scancode == SDL_SCANCODE_L){
            SceneManager::LoadScene("Test Scene Two");
        }

        Scene* currentScene = SceneManager::GetCurrentScene();
        if(currentScene == nullptr)
            return;

        auto renderObject = [renderer, pivot, flip](const GameObject& object){
            RenderGameObject(renderer, pivot, flip, object);
        };

        RenderManager::RendererStart();

        currentScene->ForeachGameobject(renderObject);
                    
        RenderManager::RendererEnd();
    } 
}

void Application::Shutdown(ERRORS& errors){
    RenderManager::Shutdown();
    WindowManager::Shutdown();

    SceneManager::DeallocateScenes();

    SDL_Quit();
    errors = ERRORS::SUCCSESS;
}
