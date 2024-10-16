#pragma once
#ifndef RAYLIBWINDOW_H__
#define RAYLIBWINDOW_H__

#include "Window.h"
#include "raylib.h"

class RaylibWindow : public Window {
public:
    RaylibWindow(const char*, int, int);

    void init(int, int, const char*) override;

    void update() override;

    bool isRunning() override;

    void displayFPS() override;

    void close();

    bool shouldClose();

    void beginDrawing();

    void endDrawing();

    ~RaylibWindow() override;
};

#endif
