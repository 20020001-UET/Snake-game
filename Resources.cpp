///Resources [Source]
#include "Resources.h"

//Project headers
#include "TextureManager.h"

//Static
SDL_Texture* Resources::tile_map;
SDL_Rect Resources::map_sprite[TILE_MAP_COUNT];
SDL_Texture* Resources::snake;
SDL_Texture* Resources::fruit;

SDL_Renderer* Resources::renderer;

Console Resources::console("Resources");

///Resources class
void Resources::init(SDL_Renderer* _renderer)
{
    renderer = _renderer;

    console.writeLine("Init done!");
}

void Resources::load()
{
    //tile_map
    tile_map = TextureManager::load("Assets/tileMap.png");

    map_sprite[GRASS] = {0, 0, PIXEL, PIXEL};
    map_sprite[DIRT] = {PIXEL, 0, PIXEL, PIXEL};

    //snake
    snake = TextureManager::load("Assets/snake.png");

    //fruit
    fruit = TextureManager::load("Assets/fruit.png");

    console.writeLine("Load textures done!");
}

SDL_Texture* Resources::getTexture(RESOURCES_VALUE value)
{
    SDL_Texture* tmpTexture = NULL;
    switch (value)
    {
        //tile map
        case TILE_MAP:
        case GRASS_VAL:
        case DIRT_VAL:
            tmpTexture = tile_map;
            break;

        //snake
        case SNAKE_VAL:
            tmpTexture = snake;
            break;

        //fruit
        case FRUIT_VAL:
            tmpTexture = fruit;
            break;
    }
    return tmpTexture;
}

SDL_Rect Resources::getSprite(RESOURCES_VALUE value)
{
    SDL_Rect tmpRect = {0, 0, 0, 0};
    switch (value)
    {
        //tile map
        case TILE_MAP:
            break;
        case GRASS_VAL:
            tmpRect = map_sprite[GRASS];
            break;
        case DIRT_VAL:
            tmpRect = map_sprite[DIRT];
            break;

        //snake
        case SNAKE_VAL:
            break;

        //fruit
        case FRUIT_VAL:
            break;
    }
    return tmpRect;
}

void Resources::free()
{
    console.writeLine("Free memory. . .");

    SDL_DestroyTexture(tile_map);
    SDL_DestroyTexture(snake);
    SDL_DestroyTexture(fruit);
    tile_map = NULL;
    snake = NULL;
    fruit = NULL;

    renderer = NULL;
}
