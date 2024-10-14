#pragma once
#ifndef RAYLIBSPRITE_H__
#define RAYLIBSPRITE_H__

#include "Sprite.h"
#include "raylib.h"

class RaylibSprite : public Sprite {
public:
    void drawCircle(float x, float y, float radius, int color) override {
        DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, color);
    }

    ~RaylibSprite() override {
    }
};

#endif
