#ifndef SPRITE_H__
#define SPRITE_H__

#include "Vector2.h"

class Sprite
{
public:
    Sprite() : position(0, 0), velocity(100, 100) {} // init pos et velocité
        virtual ~Sprite();
        virtual void setPosition(float x, float y) = 0;
        virtual void drawCircle(float x, float y, float radius) = 0;
        virtual void updated(float deltaTime, float, float) = 0;

protected:
    Vector2 position;
    Vector2 velocity;
    };

#endif // !SPRITE_H__
