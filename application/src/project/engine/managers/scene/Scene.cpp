#include "GameObject.h"
#include "SceneManager.h"
#include <functional>

GameObject* Scene::CreateGameObject(SDL_Surface* surface, float x, float y){
    GameObject* object = new GameObject{surface, x, y};

    gameObjects.push_back(object);

    return object;
}

void Scene::ForeachGameobject(std::function<void(const GameObject&)> callback){
    for(GameObject* o : gameObjects){
        callback(*o); 
    }
}

void Scene::FreeGameobject(){
    for(auto& o : gameObjects){
        delete o;
        std::cout << "Game Object Freed" << std::endl;
    }
}

Scene::~Scene(){
    FreeGameobject();
}
