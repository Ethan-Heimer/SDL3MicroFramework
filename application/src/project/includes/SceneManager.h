#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include <functional>
#include <string>
#include <map>
#include <vector>
#include <iostream>

#include "GameObject.h"

using namespace std;

class Scene{
    public:
        friend class SceneManager;  

        GameObject* CreateGameObject(SDL_Surface* surface, float x, float y);
        void ForeachGameobject(std::function<void(const GameObject& gameobject)> callback);

        ~Scene();
    private: 
        void InvokeGameobjectsUpdate();
        void FreeGameobject();
        vector<GameObject*> gameObjects;
};

class SceneManager{
    public:
        static Scene* CreateScene(string name);
        static void LoadScene(string name);

        static Scene* GetCurrentScene();

        static void DeallocateScenes();

        static void InvokeSceneUpdate();

    private:
        static Scene* currentScene;
        static map<string, Scene*> scenes;
};

#endif
