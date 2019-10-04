#include <SDL.h>
#include <cstdlib>
#include <cassert>
#include <iostream>

#include <boost/stacktrace.hpp>

#include "utils.h"

namespace utils {

static std::fs::path RESOURCE_PATH;

SDL::SDL(Uint32 flags, int argc, char** argv) {
    (void)argc;
    if (SDL_Init(flags) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }
    RESOURCE_PATH = std::fs::absolute(argv[0]).remove_filename() / "resources";
    assert(std::fs::exists(RESOURCE_PATH));
}

SDL::~SDL() {
    SDL_Quit();
}

std::fs::path get_resource_path(const std::string& file_name) {
    return RESOURCE_PATH / file_name;
}

void log_sdl_error(std::ostream& os, const std::string& msg) {
    os << msg << " SDLError: " << SDL_GetError() << std::endl;
}

void sdl_fatal(const std::string& msg) {
    std::cerr << "Fatal error: " << msg << std::endl;
    std::cerr << boost::stacktrace::stacktrace();
    std::exit(1);
}

}  // namespace utils
