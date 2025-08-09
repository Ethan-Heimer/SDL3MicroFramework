#ifndef COMPONENTS
#define COMPONENTS

#include <concepts>

class Component{
    public:
        virtual void Start(){};
        virtual void Update(){};
        
        virtual ~Component(){};
};

template <typename T>
concept ComponentBase = std::is_base_of<Component, T>::value;


#endif
