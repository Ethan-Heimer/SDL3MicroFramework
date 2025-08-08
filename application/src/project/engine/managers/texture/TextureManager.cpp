#include "TextureManager.h"
#include <iostream>
#include "RendererManager.h"

#include "SDL3_image/SDL_image.h"


map<string, SDL_Surface*> TextureManager::textureMap{}; 


ERRORS TextureManager::GetTexture(string image, SDL_Surface*& texture){
    if(textureMap.find(image) == textureMap.end()){
        cout << "Loading new texture" << endl; 

        SDL_Surface* tex = IMG_Load(image.c_str());
        if (!tex) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
            return TEXTURE_ERROR;
        }

        textureMap[image] = tex;
        
        texture = tex; 
        return SUCCSESS;
    }
    else{
        cout << "Loading Textures from cache" << endl; 

        SDL_Surface* tex = textureMap[image];
        if(tex == NULL){
            return RENDERER_NOT_INIT;
        }

        texture = tex;
        return SUCCSESS;
    }
}

void TextureManager::Shutdown(){
    for(const auto& pair : textureMap){
        SDL_DestroySurface(pair.second);
    }
}
