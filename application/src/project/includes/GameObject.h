#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "Components.h"
#include "renderobject.h"
#include <type_traits>
#include <typeinfo>
#include <vector>

class GameObject{
    public:
        GameObject(SDL_Surface* surface, float x, float y){
            renderObject = new RenderObject(surface, x, y, 100, 100, 0);
        }
        
        GameObject(const GameObject& copy){
            SDL_FRect* copyRect = copy.renderObject->GetRect();
            
            renderObject = new RenderObject(*(copy.renderObject)); 
        }

        GameObject(GameObject&& move){
            renderObject = move.renderObject;
            move.renderObject = nullptr;
        }
        
        ~GameObject(){
            delete renderObject;
            FreeComponents();
        }

        RenderObject* GetRenderObject() const {
            return renderObject;
        }

        void InvokeComponentsUpdate(){
            for(auto& o : components){
                o->Update();
            }
        }

        template<ComponentBase T>
        T* AddComponent(){
            T* component = new T();   
            components.push_back(component);

            component->gameObject = this;
            component->Start();

            return component;
        }

        void Move(float x, float y){
            auto* rect = this->renderObject->GetRect();
            rect->x += x;
            rect->y += y;
        }
     
    private:
        RenderObject* renderObject;
        std::vector<Component*> components;

        void FreeComponents(){
            for(auto o : components){
                delete o;
            }
            std::cout << "Free Component" << std::endl;
        }
};

#endif
