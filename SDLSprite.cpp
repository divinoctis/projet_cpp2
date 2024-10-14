#include <iostream>
#include "SDLSprite.h"
SDLSprite::SDLSprite(SDL_Renderer* _renderer, float _x, float _y, float _radius) : renderer(_renderer), x(_x), y(_y), radius(_radius)
{

}
SDLSprite::~SDLSprite() {}

void SDLSprite::setPosition(float x, float y) 
{

	this->x = x;
	this->y = y;
}
void SDLSprite::drawCircle(float x, float y, float radius) 
{

    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}
