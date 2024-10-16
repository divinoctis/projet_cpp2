#include <iostream>
#include "SDLWindow.h"
#include "SDLSprite.h"

SDLWindow::SDLWindow() : window(nullptr), renderer(nullptr), fps(0){}

SDLWindow::~SDLWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLWindow::createSurface(int width, int height, SDL_PixelFormat format) {
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format.format);
    if (surface == nullptr) {
        std::cerr << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else {
        SDL_FreeSurface(surface);
    }
}

void SDLWindow::init(int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    this->w = width;
    this->h = height;

    window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

void SDLWindow::update() {
    SDL_RenderPresent(renderer);
}

bool SDLWindow::isRunning() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

void SDLWindow::displayFPS() {
    static Uint32 lastTime = SDL_GetTicks();
    Uint32 currentTime = SDL_GetTicks();
    fps++;

    if (currentTime - lastTime >= 1000) { 
        std::cout << "FPS: " << fps << std::endl;
        fps = 0;
        lastTime = currentTime;
    }
}



SDL_Renderer* SDLWindow::GetRenderer() {
    return renderer;
}


