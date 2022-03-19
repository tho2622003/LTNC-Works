#include <sdl.h>
#include <iostream>
#include <stdio.h>
#include <string>

bool running = true;
//make an enum list (gan gia tri tu 1 - 6 cho cac bien tu tren xuong duoi --> data type int)
//enum PHAI nam ngoai int main
enum KeyPressSurfaces {

    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    //de deallocate surface
    KEY_PRESS_SURFACE_TOTAL

};

int main(int argc, char** argv) {

    //standard stuffs
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("vibin' with smug pika", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //ham loadSurface trong SDL_Surface: load tung anh mot
    SDL_Surface* loadSurface(std::string path);
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    //tao array chua KEY_PRESS_SURFACE_TOTAL = 6 anh duoc load (de deallocate)
    SDL_Surface* keypress [KEY_PRESS_SURFACE_TOTAL];
    //anh hien tai dang duoc load, de BlitSurface len surface
    //SDL_BlitSurface(current --> surface)
    SDL_Surface* current = NULL;
    SDL_Event event;

    while (running) {

        //load each image into the keypress array
        keypress[KEY_PRESS_SURFACE_DEFAULT] = SDL_LoadBMP("../pikachu/keypress_bmp/default.bmp");
        keypress[KEY_PRESS_SURFACE_UP] = SDL_LoadBMP("../pikachu/keypress_bmp/up.bmp");
        keypress[KEY_PRESS_SURFACE_DOWN] = SDL_LoadBMP("../pikachu/keypress_bmp/down.bmp");
        keypress[KEY_PRESS_SURFACE_LEFT] = SDL_LoadBMP("../pikachu/keypress_bmp/left.bmp");
        keypress[KEY_PRESS_SURFACE_RIGHT] = SDL_LoadBMP("../pikachu/keypress_bmp/right.bmp");

        while (SDL_PollEvent(&event)){
            switch (event.type) {
            //user click x
            case SDL_QUIT:
                running = false;
                break;
            //user press ESC
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    current = keypress[KEY_PRESS_SURFACE_UP];
                    break;
                case SDLK_DOWN:
                    current = keypress[KEY_PRESS_SURFACE_DOWN];
                    break;
                case SDLK_LEFT:
                    current = keypress[KEY_PRESS_SURFACE_LEFT];
                    break;
                case SDLK_RIGHT:
                    current = keypress[KEY_PRESS_SURFACE_RIGHT];
                    break;
                }
            }
        SDL_BlitSurface(current, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);
        }
    }

    //deallocating surfaces
    for(int i=0; i<KEY_PRESS_SURFACE_TOTAL; ++i) {
        SDL_FreeSurface(keypress[i]);
        keypress[i] = NULL;
    }

    //destroy everythangggg
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
