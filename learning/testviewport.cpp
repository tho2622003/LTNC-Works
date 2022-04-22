#include <sdl.h>
#include <sdl_image.h>

bool running = true;
const int width = 600;
const int height = 600;

int main(int argc, char* argv[]){
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_JPG);
        SDL_Window* window = SDL_CreateWindow("hErE's Da ViEwPoRt huduh", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_Surface* surface = IMG_Load("./keypress_bmp/cover.jpg");
        SDL_Texture* current = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

        SDL_Event quit;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        while(running){
            while(SDL_PollEvent(&quit)){
                switch(quit.type){
                    case SDL_QUIT:
                running = false;
                break;
                }
            }
        //full screen texture
        SDL_RenderCopy(renderer, current, NULL, NULL);
        //make a test viewport
        SDL_Rect topleftviewport {30, 30, width/2, height/2};
        SDL_RenderSetViewport(renderer, &topleftviewport);
        SDL_RenderCopy(renderer, current, NULL, NULL);
        //make a test viewport
        SDL_Rect downrightviewport {400, 400, width/2, height/2};
        SDL_RenderSetViewport(renderer, &downrightviewport);
        SDL_RenderCopy(renderer, current, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(current);
    SDL_FreeSurface(surface);
    SDL_Quit();
    IMG_Quit();
    return 0;
}
