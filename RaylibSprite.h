#pragma once
#ifndef RAYLIBSPRITE_H__
#define RAYLIBSPRITE_H__

#include "Sprite.h"
#include "raylib.h"

class RaylibSprite : public Sprite {
public:
    RaylibSprite();

    void setPosition(float x, float y) override;
    void drawCircle(float x, float y, float radius) override;
    void moveCircle(float, float) override;
    void setSpeed(float xSpeed, float ySpeed);
    ~RaylibSprite() override;
    float x, y;         // Position du cercle
    float xSpeed, ySpeed; // Vitesse du cercle
    float radius;       // Rayon du cercle
};

#endif
