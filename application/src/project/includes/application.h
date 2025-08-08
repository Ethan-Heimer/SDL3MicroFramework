#ifndef APPLICATION
#define APPLICATION 

#include "errors.h"
class Application{
    public:
        static void Init(ERRORS& errors);
        static void Run(ERRORS& errors);
        static void Shutdown(ERRORS& errors);
};

#endif
