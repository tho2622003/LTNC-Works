#include <sdl.h>
#include <iostream>

int main (int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    bool running = true;
    SDL_Window* window = SDL_CreateWindow("testing cursor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Surface* bitmap = NULL;
    while(running) {

        bitmap = SDL_LoadBMP("../pikachu/smug.bmp");
        SDL_BlitSurface(bitmap, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);

        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEMOTION:
                std::cout << event.motion.x << " " << event.motion.y << '\n';
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    running = false;
                }
            default:
                break;
            }
        }
    }
    SDL_FreeSurface(bitmap);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
