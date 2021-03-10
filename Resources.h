///Resources [Header]
#ifndef RESOURCES_H_
#define RESOURCES_H_

//Include SDL library
#include <SDL.h>

//Project headers
#include "Console.h"

enum RESOURCES_VALUE
{
    //tile map
    TILE_MAP = 0,
    GRASS_VAL,
    DIRT_VAL,

    //snake
    SNAKE_VAL,

    //fruit
    FRUIT_VAL
};

enum TILE_MAP_VALUE
{
    GRASS = 0,
    DIRT,
    TILE_MAP_COUNT
};

enum SNAKE_VALUE
{
    SNAKE,
    SNAKE_COUNT
};

enum FRUIT_VALUE
{
    FRUIT,
    FRUIT_COUNT
};

const int PIXEL = 32;

///Resources class
class Resources
{
    public:
        static void init(SDL_Renderer* _renderer);
        static void load();
        static SDL_Texture* getTexture(RESOURCES_VALUE value);
        static SDL_Rect getSprite(RESOURCES_VALUE value);

    private:
        //static void loadFile(std::string path);

        static SDL_Texture* tile_map;
        static SDL_Rect map_sprite[TILE_MAP_COUNT];
        static SDL_Texture* snake;
        static SDL_Texture* fruit;

        static SDL_Renderer* renderer;

        static Console console;
};

#endif // RESOURCES_H_
