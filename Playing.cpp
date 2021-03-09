///Playing [Source]
#include "Playing.h"

///Playing class
void Playing::init(SDL_Renderer* _renderer)
{
    console = new Console("Playing");

    renderer = _renderer;

    snake = new Snake("Assets/snake.png", renderer, 0, 0, 32, 32);

    console->writeLine("Init done!");
}

void Playing::loop()
{
    snake->moving();
}

void Playing::render()
{
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
