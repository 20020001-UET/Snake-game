///Texture Manager [Header]
#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

//include SDL library
#include <SDL.h>
#include <SDL_image.h>

#include <string>

///TextureManager class
class TextureManager
{
    public:
        static SDL_Texture* load(std::string path, SDL_Renderer* renderer);
};

#endif // TEXTURE_MANAGER_H_
