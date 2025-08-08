#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include <map>
#include <string>

#include "SDL3/SDL.h"
#include "errors.h"

using namespace std;

class TextureManager{
    public:
        static ERRORS GetTexture(string image, SDL_Surface*& texture);
        static void Shutdown();
        
    private:
        static map<string, SDL_Surface*> textureMap; 
};

#endif
