#ifndef APPLICATION
#define APPLICATION 

#include "errors.h"
class Application{
    public:
        static ERRORS Init();
        static ERRORS Run();
        static ERRORS Shutdown();
};

#endif
