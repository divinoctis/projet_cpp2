//#ifndef SDLSPRITE_H__
//#define SDLSPRITE_H__
//
//#include "Sprite.h"
//#define SDL_MAIN_HANDLED
//#include <SDL2/SDL.h>
//
//class SDLSprite : public Sprite
//{
//private:
//    SDL_Renderer* renderer;
//    float x, y;
//    float radius;
//    Uint8 r, g, b, a;
//
//public:
//    SDLSprite(SDL_Renderer* renderer, float x, float y, float radius);
//    virtual ~SDLSprite();
//    void setPosition(float x, float y) override;
//    void drawCircle(float x, float y, float radius) override;
//
//};
//
//
//#endif 

// post vector 2

#ifndef SDLSPRITE_H__
#define SDLSPRITE_H__

#include "Sprite.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class SDLSprite : public Sprite
{
private:
    SDL_Renderer* renderer;
    float x, y;
    float radius;
    Uint8 r, g, b, a;

public:
    SDLSprite(SDL_Renderer* renderer, float x, float y, float radius);
    virtual ~SDLSprite();
    void setPosition(float x, float y) override;
    void drawCircle(float x, float y, float radius) override;
    virtual void updated(float deltaTime) override; // ++
};


#endif 