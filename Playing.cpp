///Playing [Source]
#include "Playing.h"

#include <ctime>
#include <random>

///Playing class
Playing::Playing()
{
    console = NULL;

    width = new int;
    height = new int;

    renderer = NULL;
    window = NULL;

    snake = NULL;
}

void Playing::init(SDL_Window* _window, SDL_Renderer* _renderer)
{
    console = new Console("Playing");

    window = _window;
    renderer = _renderer;
    SDL_GetWindowSize(window, width, height);

    tileMap = new TileMap("map.dat", renderer, (*height)/PIXEL, (*width)/PIXEL);

    if (tileMap->canRender())
        console->writeLine("Map init done!");

    snake = new Snake(0, 0, 32, 32);

    fruit = new Fruit(10, 8, 32, 32);

    srand(time(NULL));

    console->writeLine("Init done!");
}

void Playing::loop()
{
    if (fruit->isEaten())
    {
        fruit->genarate();
    }

    if ((snake->get_tile_x() == fruit->get_tile_x()) && (snake->get_tile_y() == fruit->get_tile_y()) && !fruit->isEaten())
    {
        snake->eatFruit();
        fruit->setEaten();
    }

    fruit->update();

    snake->moving();
}

void Playing::render()
{
    tileMap->render();

    if (!fruit->isEaten())
        fruit->render();

    snake->render();
}

void Playing::keyPressed(int key_sym)
{
    console->writeLine("Key pressed.");

    switch (key_sym)
    {
        case SDLK_UP:
            snake->setDir(DIRECTION::UP);
            break;
        case SDLK_DOWN:
            snake->setDir(DIRECTION::DOWN);
            break;
        case SDLK_LEFT:
            snake->setDir(DIRECTION::LEFT);
            break;
        case SDLK_RIGHT:
            snake->setDir(DIRECTION::RIGHT);
            break;
    }
}

void Playing::keyReleased(int key_sym)
{
    console->writeLine("Key released.");
}

void Playing::destroy()
{
    window = NULL;
    renderer = NULL;

    delete snake;
    snake = NULL;

    delete width;
    width = NULL;
    delete height;
    height = NULL;

    console->writeLine("Destroyed Playing State!");

    delete console;
    console = NULL;
}
