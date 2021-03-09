///Texture Manager [Source]
#include "TextureManager.h"

///TextureManager class
SDL_Texture* TextureManager::load(std::string path, SDL_Renderer* renderer)
{
    SDL_Surface* tmpSurface = IMG_Load(path.c_str());
    SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tmpTexture;
}
