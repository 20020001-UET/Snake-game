///Snake [Header]
#ifndef SNAKE_H_
#define SNAKE_H_

//include SDL library
#include <SDL.h>
#include <SDL_image.h>

//Project headers
#include "TextureManager.h"
#include "Direction.h"

//C++ library
#include <string>

///Snake class
class Snake
{
    public:
        Snake(std::string path, SDL_Renderer* _renderer, int x, int y, int w, int h);
        ~Snake();

        void setDir(DIRECTION flag);
        void moving();
        void render();

    private:
        DIRECTION cur_dir;

        int width, height;
        int xpos, ypos;

        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;
};

#endif // SNAKE_H_
