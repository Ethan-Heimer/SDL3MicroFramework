#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "renderobject.h"
#include <cwchar>
#include <utility>

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
        }

        RenderObject* GetRenderObject() const {
            return renderObject;
        }
            
    private:
        RenderObject* renderObject;
};

#endif
