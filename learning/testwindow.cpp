#include <SDL.h>

int  main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    //create a window
    SDL_Window* window = SDL_CreateWindow("testpikachu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    //create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //boolean to check if program is running correctly
    bool running = true;

    //make an event to handle quitting program
    SDL_Event quit;

    while(running) {
        SDL_SetRenderDrawColor(renderer, 64, 204, 208, 255);
        SDL_RenderClear(renderer);
        //begin of insert dumb stuffs here

        //draw a line
        SDL_SetRenderDrawColor(renderer, 200, 100, 0, 255);
        SDL_RenderDrawLine(renderer, 0, 0, 50, 50);

        //define a rectangle
        SDL_Rect location{100, 100, 100, 100};

        /*draw a stroke-only (no fill) rectangle
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &location);*/

        //draw a color filled rectangle
        SDL_SetRenderDrawColor(renderer, 25, 255, 50, 255);
        SDL_RenderFillRect(renderer, &location);

        //end of insert dumb stuffs here
        SDL_RenderPresent(renderer);

        //a while loop for the quit event
        while(SDL_PollEvent(&quit)){
            switch(quit.type){
            //click x to quit window (SDL_QUIT != SDL_Quit())
            case SDL_QUIT:
                running = false;
                break;
            //press escape to quit window using SDL_KeyDown
            case SDL_KEYDOWN:
                if (quit.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    running = false;
                }
            default:
                break;
            }
        }
    }

    //quit everything (required)
    /*SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
