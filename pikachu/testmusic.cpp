#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>

bool running = true;
int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* window = SDL_CreateWindow("testing musique", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event quit;
    Mix_Music* music;

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048);
    music = Mix_LoadMUS("./keypress_BMP/mexico.mp3");
    Mix_PlayMusic(music, -1);

    while (running) {
        while(SDL_PollEvent(&quit)){
            switch(quit.type) {
            case SDL_QUIT:
                running = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 20, 20, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    Mix_FreeMusic(music);
    music = NULL;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    Mix_Quit();
    return 0;
}
