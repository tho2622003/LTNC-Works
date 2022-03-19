#include <sdl.h>
#include <iostream>

int main(int argc, char** argv) {
    //the usual stuffs
    bool running = true;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("dancin' pikachu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    SDL_Surfact* bitmap = NULL;

    while(running) {




    }

    SDL_FreeSurface(bitmap);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;


}
