#ifndef SDLSPRITE_H__
#define SDLSPRITE_H__

#include "Sprite.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Vector2.h"
class SDLSprite : public Sprite
{
private:
    SDL_Renderer* renderer;
    float x, y;
    float xSpeed, ySpeed;
    float radius;
    Uint8 r, g, b, a;


public:
    SDLSprite(SDL_Renderer* renderer, float x, float y, float radius);
    virtual ~SDLSprite();

    float getRadius() const { return radius; }
    float getX() const { return x; }
    float getY() const { return y; }
    float getXSpeed() const { return xSpeed; }
    float getYSpeed() const { return ySpeed; }
    
    void setPosition(float x, float y) override;
    
    void drawCircle(float x, float y, float radius) override;
    virtual void updated(float deltaTime, float, float) override;
    
};


#endif 