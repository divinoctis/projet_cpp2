#include <iostream>
#include "SDLWindow.h"
#include "SDLSprite.h"
SDLWindow::SDLWindow() : window(), renderer(), fps(0) {}

SDLWindow::~SDLWindow()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SDLWindow::createSurface(int width, int height, Uint32 format) {
	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
	if (surface == nullptr) {
		std::cerr << "Surface could not be created! SDL_Error: " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(surface);
}

void SDLWindow::init(int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void SDLWindow::update() {
	SDL_RenderPresent(renderer);
}

bool SDLWindow::isRunning() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			return true;
		}
	}
	return false;
}

void SDLWindow::displayFPS() {
	fps++;
// à faire
}
void SDLWindow::drawCircle(float x, float y, float radius) {
	SDLSprite sprite(renderer, x, y, radius);

	sprite.drawCircle(x,y,radius);
}

SDL_Renderer* SDLWindow::GetRenderer() {
	return renderer;
}

void SDLWindow::setPosition(float x, float y)
{
	
}