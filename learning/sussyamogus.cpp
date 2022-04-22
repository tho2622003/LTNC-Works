#include <sdl.h>
#include <sdl_mixer.h>

bool running = true;
const int width = 640;
const int height = 480;

int main(int argc, char* argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    Mix_Init(MIX_INIT_MP3);
    SDL_Window* window = SDL_CreateWindow("sussy baka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = NULL;
    Mix_Music* music;

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048);
    music = Mix_LoadMUS("./keypress_BMP/trap.mp3");
    Mix_PlayMusic(music, -1);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL_Event event;

    while(running){
        while(SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    //clear screen
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    //render red rectangle
    SDL_Rect red {160, 50, 320, 300};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &red);
    //another red rectangle
    SDL_Rect bacc {80, 120, 80, 180};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &bacc);
    //and another
    SDL_Rect feet1 {160, 350, 100, 60};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &feet1);
    //and another
    SDL_Rect feet2 {380, 350, 100, 60};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &feet2);
    //and another
    SDL_Rect visor {260, 100, 220, 80};
    SDL_SetRenderDrawColor(renderer, 0, 168, 236, 255);
    SDL_RenderFillRect(renderer, &visor);
    //and another
    SDL_Rect shade1 {280, 120, 16, 34};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &shade1);
    //and the final piece
    SDL_Rect shade2 {280, 120, 34, 16};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &shade2);
    //present everything
    SDL_RenderPresent(renderer);
    }
    Mix_FreeMusic(music);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_Quit();
    return 0;
}
