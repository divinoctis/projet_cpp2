#include <iostream>
#include "SDLSprite.h"
SDLSprite::SDLSprite(SDL_Renderer* _renderer, float _x, float _y, float _radius)
    : renderer(_renderer), x(_x), y(_y), radius(_radius), r(255), g(255), b(255), a(255), xSpeed(100.0f), ySpeed(100.0f)
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
    for (float w = 0; w < radius * 2; w++) {
        for (float h = 0; h < radius * 2; h++) {
            float dx = radius - w;
            float dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, static_cast<int>(this->x + dx), static_cast<int>(this->y + dy));
            }
        }
    }
}

void SDLSprite::updated(float deltaTime, float w, float h)
{

    x += xSpeed * deltaTime;
    y += ySpeed * deltaTime;

    if (x - radius <= 0 || x + radius >= w) {
        xSpeed = -xSpeed;
        x += xSpeed * deltaTime;
    }
    if (y - radius <= 0 || y + radius >= h) {
        ySpeed = -ySpeed;
        y += ySpeed * deltaTime;
    }
    setPosition(x, y);
}