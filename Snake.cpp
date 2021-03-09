///Snake [Source]
#include "Snake.h"

#include <iostream>

///Snake class
Snake::Snake(std::string path, SDL_Renderer* _renderer, int x, int y, int w, int h)
{
    renderer = _renderer;
    texture = TextureManager::load(path, renderer);

    xpos = x;
    ypos = y;

    width = w;
    height = h;

    srcRect = {x, y, w, h};
    destRect = {x, y, w, h};
}

Snake::~Snake()
{

}

void Snake::setDir(DIRECTION flag)
{
    cur_dir = flag;
}

void Snake::moving()
{
    int block = 32;
    int speed = block / 10;

    switch (cur_dir)
    {
        case UP:
            destRect.y -= speed;
            break;
        case DOWN:
            destRect.y += speed;
            break;
        case LEFT:
            destRect.x -= speed;
            break;
        case RIGHT:
            destRect.x += speed;
            break;
        default:
            break;
    }
}

void Snake::render()
{
    SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
