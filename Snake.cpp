///Snake [Source]
#include "Snake.h"
#include "Resources.h"
#include "Engine.h"

#include <iostream>

///Snake class
Snake::Snake(int x, int y, int w, int h)
{
    texture = Resources::getTexture(SNAKE_VAL);

    waitTime = 0;

    tail = 1;
    eatenFruit = false;

    tile_x[0] = x;
    tile_x[0] = y;

    screen_x[0] = tile_x[0]*32;
    screen_y[0] = tile_y[0]*32;

    width = w;
    height = h;

    srcRect = {0, 0, w, h};
}

Snake::~Snake()
{
    SDL_DestroyTexture(texture);
    texture = NULL;
}

void Snake::update()
{
    for (int i = 0; i < tail; i++)
    {
        screen_x[i] = tile_x[i]*32;
        screen_y[i] = tile_y[i]*32;
    }
}

void Snake::setDir(DIRECTION flag)
{
    cur_dir = flag;
}

void Snake::moving()
{
    if (waitTime > 0)
    {
        waitTime--;
        return;
    }

    int last_x = tile_x[tail-1];
    int last_y = tile_y[tail-1];

    for (int i = tail-1; i > 0; i--)
    {
        tile_x[i] = tile_x[i-1];
        tile_y[i] = tile_y[i-1];
    }

    switch (cur_dir)
    {
        case UP:
            tile_y[0]--;
            break;
        case DOWN:
            tile_y[0]++;
            break;
        case LEFT:
            tile_x[0]--;
            break;
        case RIGHT:
            tile_x[0]++;
            break;
        default:
            break;
    }

    if (tile_y[0] > Engine::height/PIXEL-1)
        tile_y[0] = 0;

    if (tile_y[0] < 0)
        tile_y[0] = Engine::height/PIXEL-1;

    if (tile_x[0] > Engine::width/PIXEL-1)
        tile_x[0] = 0;

    if (tile_x[0] < 0)
        tile_x[0] = Engine::width/PIXEL-1;

    if (eatenFruit)
    {
        tile_x[tail] = last_x;
        tile_y[tail] = last_y;
        tail++;
        eatenFruit = false;
    }

    //Speed
    waitTime = 5;
    update();
}

void Snake::render()
{
    for (int i = 0; i < tail; i++)
    {
        destRect = {screen_x[i], screen_y[i], width, height};
        TextureManager::draw(texture, srcRect, destRect);
    }
}

void Snake::eatFruit()
{
    eatenFruit = true;
}

int Snake::get_tile_x()
{
    return tile_x[0];
}

int Snake::get_tile_y()
{
    return tile_y[0];
}
