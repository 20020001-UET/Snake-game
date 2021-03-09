///Playing [Header]
#ifndef PLAYING_H_
#define PLAYING_H_

//include SDL library
#include <SDL.h>

//Project headers
#include "Console.h"
#include "Snake.h"
#include "Direction.h"

///Playing class
class Playing
{
    public:
        void init(SDL_Renderer* _renderer);
        void loop();
        void render();
        void keyPressed(int key_sym);
        void keyReleased(int key_sym);

    private:
        Console* console;
        SDL_Renderer* renderer;

        Snake* snake;

};

#endif // PLAYING_H_
