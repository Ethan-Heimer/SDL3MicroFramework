#ifndef INPUT_COMPONENT
#define INPUT_COMPONENT

#include "Components.h"
class InputComponent : public Component{
    public:
        void Update() override;
        void SetSpeed(float speed);
    private:
        float speed;
};

#endif
