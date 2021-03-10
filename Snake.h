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
        Snake(int x, int y, int w, int h);
        ~Snake();

        void update();
        void setDir(DIRECTION flag);
        void moving();
        void render();
        void eatFruit();

        int get_tile_x();
        int get_tile_y();

    private:
        DIRECTION cur_dir;

        bool eatenFruit;
        int waitTime;
        int width, height;
        int tail;
        int tile_x[100], tile_y[100];
        int screen_x[100], screen_y[100];

        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
};

#endif // SNAKE_H_
