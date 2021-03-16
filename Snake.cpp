///Snake [Source]
#include "Snake.h"
#include "Resources.h"
#include "Engine.h"

const SNAKE_VALUE snake_flag[4][4] = {
    {SNAKE_BODY_UP, SNAKE_UNSET, SNAKE_CORNER_UP_LEFT, SNAKE_CORNER_UP_RIGHT},
    {SNAKE_UNSET, SNAKE_BODY_DOWN, SNAKE_CORNER_DOWN_LEFT, SNAKE_CORNER_DOWN_RIGHT},
    {SNAKE_CORNER_LEFT_UP, SNAKE_CORNER_LEFT_DOWN, SNAKE_BODY_LEFT, SNAKE_UNSET},
    {SNAKE_CORNER_RIGHT_UP, SNAKE_CORNER_RIGHT_DOWN, SNAKE_UNSET, SNAKE_BODY_RIGHT},
};

///Snake class
Snake::Snake(int x, int y, int w, int h)
{
    texture = Resources::getTexture(SNAKE_VAL);

    waitTime = 0;

    tail = 2;
    eatenFruit = false;

    tile_x[0] = x+1;
    tile_x[0] = y;

    tile_x[1] = x;
    tile_y[1] = y;

    update();

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

        if (i == 0)
            dir_at[i] = cur_dir;
        else
        {
            if (tile_y[i-1] == (tile_y[i]-1))
                dir_at[i] = DIRECTION::UP;
            if (tile_y[i-1] == (tile_y[i]+1))
                dir_at[i] = DIRECTION::DOWN;
            if (tile_x[i-1] == (tile_x[i]-1))
                dir_at[i] = DIRECTION::LEFT;
            if (tile_x[i-1] == (tile_x[i]+1))
                dir_at[i] = DIRECTION::RIGHT;
        }
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
        if (i == 0)
        {
            switch (cur_dir)
            {
                case UP:
                    srcRect = Resources::getSprite(SNAKE_HEAD_UP);
                    break;
                case DOWN:
                    srcRect = Resources::getSprite(SNAKE_HEAD_DOWN);
                    break;
                case LEFT:
                    srcRect = Resources::getSprite(SNAKE_HEAD_LEFT);
                    break;
                case RIGHT:
                    srcRect = Resources::getSprite(SNAKE_HEAD_RIGHT);
                    break;
                default:
                    break;
            }
        }
        else
            if (i == tail-1)
            {
                switch (dir_at[i])
                {
                    case UP:
                        srcRect = Resources::getSprite(SNAKE_TAIL_UP);
                        break;
                    case DOWN:
                        srcRect = Resources::getSprite(SNAKE_TAIL_DOWN);
                        break;
                    case LEFT:
                        srcRect = Resources::getSprite(SNAKE_TAIL_LEFT);
                        break;
                    case RIGHT:
                        srcRect = Resources::getSprite(SNAKE_TAIL_RIGHT);
                        break;
                    default:
                        break;
                }
            }
            else
            {
                int f1 = dir_at[i] - 1;
                int f2 = dir_at[i+1] - 1;
                srcRect = Resources::getSprite(snake_flag[f1][f2]);
            }
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
