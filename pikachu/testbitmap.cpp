#include <sdl.h>
#include <iostream>

int main (int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    bool running = true;
    //make a window
    SDL_Window* window = SDL_CreateWindow("pikachu pika pika pika", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    //make a renderer, the same old stuff
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //make a surface to be transferred onto
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    //make a bitmap surface to load image
    SDL_Surface* bitmap = NULL;
    while(running) {
        //load the damn bitmap then boil... blit the hell out of it
        bitmap = SDL_LoadBMP("../pikachu/smug.bmp");
        SDL_BlitSurface(bitmap, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);

        //event for quiting and tracking mouse coordinates
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                std::cout << "stahp clickin'" << '\n';
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
    //typical exit procedures
    SDL_FreeSurface(bitmap);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
