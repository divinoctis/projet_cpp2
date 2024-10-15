#pragma once
#ifndef RAYLIBSPRITE_H__
#define RAYLIBSPRITE_H__

#include "Sprite.h"
#include "raylib.h"

class RaylibSprite : public Sprite {
public:
    RaylibSprite() {
        
    }

    void setPosition(float x, float y) override {
        
    }

    void drawCircle(float x, float y, float radius) override {
        
        DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, RED);
    }

    ~RaylibSprite() override {
        
    }
};

#endif
