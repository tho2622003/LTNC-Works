#include <sdl.h>
#include <sdl_image.h>

bool running = true;

const int width = 600;
const int height = 600;

int main (int argc, char* argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("texture loading", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surface = IMG_Load("../pikachu/keypress_bmp/artwork.png");
    SDL_Texture* cover = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    SDL_Event event;

    while(running) {
        while(SDL_PollEvent(&event)){
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, cover, NULL, NULL);
    SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(cover);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
