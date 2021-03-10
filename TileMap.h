///Tile Map [Header]
#ifndef TILE_MAP_H_
#define TILE_MAP_H_

//Include SDL libraries
#include <SDL.h>

//Project headers
#include "TextureManager.h"

//C++ librarr
#include <string>

///Tile Map class
class TileMap
{
    public:
        TileMap(std::string path, SDL_Renderer* _renderer, int w, int h);
        void load(std::string path);
        bool canRender();
        void render();

    private:
        int width, height;
        int **data;

        bool checkMap;

        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;

};

#endif // TILE_MAP_H_
