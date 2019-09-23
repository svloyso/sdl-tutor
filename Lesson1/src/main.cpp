#include <iostream>
#include <SDL.h>

#include "utils.h"

using namespace utils;

int main(int, char**){
    SDL sdl(SDL_INIT_VIDEO);

    SDLWindowPtr win = make_SDLWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win.get() == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDLRendererPtr ren = make_SDLRenderer(win.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren.get() == nullptr){
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    return 0;
}

