#include <sdl.h>

bool running = true;
int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("vibe with pika", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Surface* bitmap = NULL;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)){
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }
    SDL_FreeSurface(bitmap);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

return 0;
