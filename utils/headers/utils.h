#include <SDL.h>

#include <memory>

namespace utils {

using SDLWindowPtr = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>;
using SDLRendererPtr = std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)>;
using SDLTexturePtr = std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)>;

class SDL {
public:
    SDL(Uint32 flags);
    ~SDL();

    SDL(const SDL&) = delete;
    SDL(SDL&&) = delete;

    void operator=(const SDL&) = delete;
    void operator=(SDL&&) = delete;
};

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

} // namespace utils
