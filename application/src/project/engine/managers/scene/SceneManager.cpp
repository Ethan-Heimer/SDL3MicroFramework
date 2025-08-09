#include "SceneManager.h"
#include <iostream>

Scene* SceneManager::currentScene;
map<string, Scene*> SceneManager::scenes{};

Scene* SceneManager::CreateScene(string name){
    Scene* scene = new Scene;
    scenes[name] = scene;

    return scene;
}

void SceneManager::LoadScene(string name){
    if(scenes.find(name) != scenes.end()){
        currentScene = scenes[name];
    }
}

Scene* SceneManager::GetCurrentScene(){
    return currentScene;
}

void SceneManager::DeallocateScenes(){
    for(auto& pair : scenes){
        auto scene = pair.second;
        delete scene;

        std::cout << "Deallocated Scene: " << pair.first << std::endl;
    }
}

void SceneManager::InvokeSceneUpdate(){
   currentScene->InvokeGameobjectsUpdate(); 
}
