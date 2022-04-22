#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>

const int windowWidth = 860;
const int windowHeight = 640;
const char* name = "Window";

SDL_Window* window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
SDL_Surface* surfaceTile = IMG_Load("./resources/tile.png");
SDL_Surface* surfaceBG = IMG_Load("./resources/background.png");
SDL_Surface* surfaceTileHL = IMG_Load("./resources/tilehighlight.png");

SDL_Texture* textureTile = SDL_CreateTextureFromSurface(renderer, surfaceTile);
SDL_Texture* textureBG = SDL_CreateTextureFromSurface(renderer, surfaceBG);
SDL_Texture* textureTileHL = SDL_CreateTextureFromSurface(renderer, surfaceTileHL);

SDL_Event mouseState;

//struct Tile{
//   double xPos, yPos;
//};

//Tile tileGrid[4][4];

void generateTile(int x, int y) {
    SDL_Rect tileSet {75+x, 75+y, 60, 60};
    SDL_RenderCopy(renderer, textureTile, NULL ,&tileSet);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    bool running = true;
    while(running) {


    SDL_RenderCopy(renderer, textureBG, NULL, NULL);

    for (int i=0; i<480; i=i+60) {
        for (int j=0; j<480; j=j+60) {
            generateTile(i, j);
        }
    }

    SDL_RenderPresent(renderer);


        while(SDL_PollEvent(&mouseState)) {
            switch(mouseState.type){
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }
    SDL_Quit();
    return 0;
}
