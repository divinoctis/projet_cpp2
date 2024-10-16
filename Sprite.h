//#ifndef SPRITE_H__
//#define SPRITE_H__
//
//
//class Sprite
//{
//public:
//	virtual ~Sprite();
//	virtual void setPosition(float x, float y) = 0;
//	virtual void drawCircle(float x, float y, float radius) = 0;
//};
//
//
//#endif // !SPRITE_H__

// post vector 2

#ifndef SPRITE_H__
#define SPRITE_H__

#include "Vector2.h"

class Sprite
{
public:
    virtual ~Sprite();
    virtual void setPosition(float x, float y) = 0;
    virtual void drawCircle(float x, float y, float radius) = 0;
    virtual void updated(float deltaTime) = 0;

protected:
    Vector2 position;
    Vector2 velocity;
};

#endif // !SPRITE_H__
