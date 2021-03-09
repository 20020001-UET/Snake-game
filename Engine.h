///Engine [Header]
#ifndef ENGINE_H_
#define ENGINE_H_

//Project headers
#include "Console.h"
#include "Playing.h"

//include SDL library
#include <SDL.h>

//C++ library
#include <string>

///Engine class
class Engine
{
    public:
        Engine();
        ~Engine();
        static void init(int width, int height, std::string title);
        static bool isRunning();
        static void handleEvents();
        static void render();
        static void close();

    private:
        static SDL_Window* window;
        static SDL_Renderer* renderer;
        static bool running;

        static Console console;

        static Playing playing;

};

#endif // ENGINE_H_
