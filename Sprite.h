#pragma once
#ifndef SPRITE_H__
#define SPRITE_H__


class Sprite
{
public:
	virtual ~Sprite();
	virtual void setPosition(float x, float y) = 0;
	virtual void drawCircle(float x, float y, float radius) = 0;
	virtual void moveCircle(float xSpeed, float ySpeed) = 0;
};


#endif // !SPRITE_H__