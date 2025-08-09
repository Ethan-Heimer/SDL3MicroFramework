#ifndef COMPONENTS
#define COMPONENTS

#include <concepts>

class GameObject;
class Component{
    public:
        friend class GameObject;

        virtual void Start(){};
        virtual void Update(){};
        
        virtual ~Component(){};
        GameObject* gameObject;
};

template <typename T>
concept ComponentBase = std::is_base_of<Component, T>::value;


#endif
