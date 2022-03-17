#include <SDL.h>

int  main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("testpikachu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    SDL_Event quit;

    while(running) {
        SDL_SetRenderDrawColor(renderer, 120, 0, 0, 255);
        SDL_RenderClear(renderer);
        //begin of insert dumb stuffs here

        //draw a line
        SDL_SetRenderDrawColor(renderer, 200, 100, 0, 255);
        SDL_RenderDrawLine(renderer, 0, 0, 50, 50);

        //define and draw a rectangle
        SDL_Rect location{100, 100, 100, 100};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &location);

        //fill the previous rectangle
        SDL_SetRenderDrawColor(renderer, 25, 255, 50, 255);
        SDL_RenderFillRect(renderer, &location);

        //end of insert dumb stuffs here
        SDL_RenderPresent(renderer);

        while(SDL_PollEvent(&quit)){
            switch(quit.type){
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
            }
        }
    }

    SDL_Quit();

    return 0;
}
