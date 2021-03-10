///Playing [Header]
#ifndef PLAYING_H_
#define PLAYING_H_

//include SDL library
#include <SDL.h>

//Project headers
#include "Console.h"
#include "Resources.h"
#include "TileMap.h"
#include "Snake.h"
#include "Fruit.h"
#include "Direction.h"

///Playing class
class Playing
{
    public:
        Playing();
        void init(SDL_Window* _window, SDL_Renderer* _renderer);
        void loop();
        void render();
        void keyPressed(int key_sym);
        void keyReleased(int key_sym);
        void destroy();

    private:
        Console* console;
        SDL_Window* window;
        SDL_Renderer* renderer;

        int *width, *height;

        TileMap* tileMap;
        Snake* snake;
        Fruit* fruit;

};

#endif // PLAYING_H_
