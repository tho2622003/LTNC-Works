#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

int main (int argc, char** argv){
    bool running = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG);
    Mix_Init(MIX_INIT_MP3);
    SDL_Window* window = SDL_CreateWindow("testing mixer and image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    SDL_Surface* cover = IMG_Load("../pikachu/keypress_bmp/cover.jpg");
    SDL_Surface* optimized = SDL_ConvertSurface(cover, surface->format, 0);
    SDL_FreeSurface(cover);

    SDL_Rect stretch{0, 0, 600, 600};

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* music = Mix_LoadMUS("../pikachu/keypress_bmp/supernova.mp3");
    Mix_PlayMusic(music, -1);

    SDL_Event quit;
        while(running){
        while(SDL_PollEvent(&quit)){
            switch (quit.type) {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
        SDL_BlitScaled(optimized, NULL, surface, &stretch);
        SDL_UpdateWindowSurface(window);
    }
    SDL_FreeSurface(surface);
    Mix_FreeMusic(music);
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    return 0;
}
