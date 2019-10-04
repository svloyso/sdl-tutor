#include <iostream>
#include <cassert>
#include <filesystem>

#include <SDL.h>

#include "utils.h"

using namespace utils;

void test_fatal() {
    sdl_fatal("Just for test");
}

int main(int argc, char** argv){
    SDL sdl(SDL_INIT_VIDEO, argc, argv);

    SDLWindowPtr win = make_SDLWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (!win) {
        sdl_fatal("Can not create window.");
    }

    SDLRendererPtr ren = make_SDLRenderer(win.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!ren) {
        sdl_fatal("Can not create renderer.");
        assert(!!ren);
    }

    std::fs::path img_path = get_resource_path("kitten.bmp");
    SDLSurfacePtr bmp = make_SDLSurface(SDL_LoadBMP(img_path.c_str()));
    if (!bmp) {
        sdl_fatal("Can not open bmp.");
        assert(!!bmp);
    }

    SDLTexturePtr tex = make_SDLTextureFromSurface(ren.get(), bmp.get());
    if (!tex) {
        sdl_fatal("Can not create texture.");
        assert(!!tex);
    }

    for (int i = 0; i < 3; ++i) {
        SDL_RenderClear(ren.get());
        SDL_RenderCopy(ren.get(), tex.get(), nullptr, nullptr);
        SDL_RenderPresent(ren.get());
        SDL_Delay(1000);
    }

    test_fatal();

    return 0;
}

