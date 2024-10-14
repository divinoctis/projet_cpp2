#pragma once
#ifndef RAYLIBWINDOW_H__
#define RAYLIBWINDOW_H__

#include "Window.h"
#include "raylib.h"

class RaylibWindow : public Window {
public:
    void init(int width, int height, const char* title) override {
        InitWindow(width, height, title);
        SetTargetFPS(60);
    }

    void close() override {
        CloseWindow();
    }

    bool shouldClose() override {
        return WindowShouldClose();
    }

    void beginDrawing() override {
        BeginDrawing();
        ClearBackground(RAYWHITE);
    }

    void endDrawing() override {
        EndDrawing();
    }

    ~RaylibWindow() override {
        // Any specific cleanup for Raylib
    }
};

#endif
