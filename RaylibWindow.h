#pragma once
#ifndef RAYLIBWINDOW_H__
#define RAYLIBWINDOW_H__

#include "Window.h"
#include "raylib.h"

class RaylibWindow : public Window {
public:
    RaylibWindow(const char* title, int width, int height) {
        init(width, height, title);
    }

    void init(int width, int height, const char* title) override {
        InitWindow(width, height, title);
        SetTargetFPS(60);
        w = width;
        h = height;
    }

    void createSurface(int width, int height, SDL_PixelFormat format) override {
        // Implémenter si nécessaire
    }

    void update() override {
        if (shouldClose()) {
            close();
        }
        // Autres mises à jour si nécessaire
    }

    bool isRunning() override {
        return !shouldClose();
    }

    void displayFPS() override {
        DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, DARKGRAY);
    }

    void close() {
        CloseWindow();
    }

    bool shouldClose() {
        return WindowShouldClose();
    }

    void beginDrawing() {
        BeginDrawing();
        ClearBackground(RAYWHITE);
    }

    void endDrawing() {
        EndDrawing();
    }

    ~RaylibWindow() override {
        close();
    }
};

#endif
