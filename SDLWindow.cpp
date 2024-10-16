//#include <iostream>
//#include "SDLWindow.h"
//#include "SDLSprite.h"
//SDLWindow::SDLWindow() : window(), renderer(), fps(0) {}
//
//SDLWindow::~SDLWindow()
//{
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//}
//
//void SDLWindow::createSurface(int width, int height, SDL_PixelFormat format) {
//	SDL_Color color;
//	Uint32 r = 255;
//	Uint32 g = 0;
//	Uint32 b = 0;
//	Uint32 a = 255;
//	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, r);
//	if (surface == nullptr) {
//		std::cerr << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//	}
//	SDL_FreeSurface(surface);
//}
//
//
//void SDLWindow::init(int width, int height)
//{
//	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//		return;
//	}
//
//	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
//	if (window == nullptr) {
//		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//		return;
//	}
//	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//	if (!renderer) {
//		std::cout << "bruh" << std::endl;
//	}
//}
//
//void SDLWindow::update() {
//	SDL_RenderPresent(renderer);
//}
//
//bool SDLWindow::isRunning() {
//	SDL_Event event;
//	while (SDL_PollEvent(&event) != 0) {
//		if (event.type == SDL_QUIT) {
//			return true;
//		}
//	}
//	return false;
//}
//
//void SDLWindow::displayFPS() {
//	fps++;
//// à faire
//}
//void SDLWindow::drawCircle(float x, float y, float radius) {
//	SDLSprite sprite(renderer, x, y, radius);
//
//	sprite.drawCircle(x,y,radius);
//}
//
//SDL_Renderer* SDLWindow::GetRenderer() {
//	return renderer;
//}
//
//void SDLWindow::setPosition(float x, float y)
//{
//	
//}
//
//void SDLWindow::updated(float deltaTime)
//{
//
//}



// updated (flop probable)

#include <iostream>
#include "SDLWindow.h"
#include "SDLSprite.h"

SDLWindow::SDLWindow() : window(nullptr), renderer(nullptr), fps(0), position(0, 0), velocity(100, 100) {}

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

void SDLWindow::drawCircle(float x, float y, float radius) {
    SDLSprite sprite(renderer, x, y, radius);
    sprite.drawCircle(x, y, radius); 
}

SDL_Renderer* SDLWindow::GetRenderer() {
    return renderer;
}

void SDLWindow::setPosition(float x, float y) {

    position.x = x;
    position.y = y;
}

void SDLWindow::updated(float deltaTime) {

    position.x += velocity.x * deltaTime;  
    position.y += velocity.y * deltaTime;

    if (position.x <= 0 || position.x >= w) {
        velocity.x = -velocity.x; 
    }
    if (position.y <= 0 || position.y >= h) {
        velocity.y = -velocity.y;
    }

    drawCircle(position.x, position.y, 10); 
}
