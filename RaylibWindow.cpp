#include "RaylibWindow.h"
RaylibWindow::RaylibWindow(const char* title, int width, int height) 
{
	init(width, height, title);
}
void RaylibWindow::init(int width, int height, const char* title) 
{
    InitWindow(width, height, title);
    SetTargetFPS(60);
    w = width;
    h = height;
}
void RaylibWindow::update() 
{
    if (shouldClose()) {
        close();
    }
}
bool RaylibWindow::isRunning() 
{
    return !shouldClose();
}
void RaylibWindow::displayFPS() 
{
    DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, DARKGRAY);
}
void RaylibWindow::close()
{
    CloseWindow();
}
bool RaylibWindow::shouldClose() 
{
    return WindowShouldClose();
}
void RaylibWindow::beginDrawing() 
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}
void RaylibWindow::endDrawing() 
{
    EndDrawing();
}
RaylibWindow::~RaylibWindow() {
    close();
}