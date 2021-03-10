///Fruit [Source]
#include "Fruit.h"

#include "Resources.h"
#include "TextureManager.h"

#include <random>

///Fruits
Fruit::Fruit(int x, int y, int w, int h)
{
    texture = Resources::getTexture(FRUIT_VAL);

    tile_x = x;
    tile_y = y;
    width = w;
    height = h;

    srcRect = {0, 0, width, height};

    eaten = false;
}

Fruit::~Fruit()
{

}

bool Fruit::isEaten()
{
    return eaten;
}

void Fruit::setEaten()
{
    eaten = true;
}

void Fruit::genarate()
{
    tile_x = rand() % 20;
    tile_y = rand() % 15;

    eaten = false;
}

void Fruit::update()
{
    screen_x = tile_x*PIXEL;
    screen_y = tile_y*PIXEL;
}

void Fruit::render()
{
    destRect = {screen_x, screen_y, width, height};
    TextureManager::draw(texture, srcRect, destRect);
}

int Fruit::get_tile_x()
{
    return tile_x;
}

int Fruit::get_tile_y()
{
    return tile_y;
}
