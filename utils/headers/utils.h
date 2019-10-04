#include <SDL.h>

#include <filesystem>
#include <memory>
#include <string>

using namespace std::string_literals;

namespace std {
    namespace fs = filesystem;
}  // namespace std

namespace utils {

using SDLWindowPtr      = std::unique_ptr<SDL_Window,   void(*)(SDL_Window*)>;
using SDLRendererPtr    = std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>;
using SDLTexturePtr     = std::unique_ptr<SDL_Texture,  void(*)(SDL_Texture*)>;
using SDLSurfacePtr     = std::unique_ptr<SDL_Surface,  void(*)(SDL_Surface*)>;

class SDL {
public:
    SDL(Uint32 flags, int argc, char** argv);
    ~SDL();

    SDL(const SDL&) = delete;
    SDL(SDL&&) = delete;

    void operator=(const SDL&) = delete;
    void operator=(SDL&&) = delete;
};

std::fs::path get_resource_path(const std::string& file_name);

void log_sdl_error(std::ostream& os, const std::string& msg);
void sdl_fatal(const std::string& msg);

template <class ... Args>
SDLWindowPtr make_SDLWindow(Args&& ... args) {
    return SDLWindowPtr(SDL_CreateWindow(std::forward<Args>(args)...), SDL_DestroyWindow);
}

template <class ... Args>
SDLRendererPtr make_SDLRenderer(Args&& ... args) {
    return SDLRendererPtr(SDL_CreateRenderer(std::forward<Args>(args)...), SDL_DestroyRenderer);
}

template <class ... Args>
SDLTexturePtr make_SDLTexture(Args&& ... args) {
    return SDLTexturePtr(SDL_CreateTexture(std::forward<Args>(args)...), SDL_DestroyTexture);
}

inline
SDLSurfacePtr make_SDLSurface(SDL_Surface* ptr) {
    return SDLSurfacePtr(ptr, SDL_FreeSurface);
}

template <class ... Args>
SDLTexturePtr make_SDLTextureFromSurface(Args&& ... args) {
    return SDLTexturePtr(SDL_CreateTextureFromSurface(std::forward<Args>(args)...), SDL_DestroyTexture);
}

} // namespace utils
