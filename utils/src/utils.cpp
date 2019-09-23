#include <SDL.h>
#include <cstdlib>
#include <iostream>

#include "utils.h"

namespace utils {

SDL::SDL(Uint32 flags) {
    if (SDL_Init(flags) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }
}

SDL::~SDL() {
    SDL_Quit();
}

} // namespace utils
