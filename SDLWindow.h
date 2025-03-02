#ifndef SDLWINDOW_H
#define SDLWINDOW_H

#include "Window.h"
#include "Sprite.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class SDLWindow : public Window, public Sprite {
public:
    SDLWindow();
    ~SDLWindow();
    void init(int width, int height) override;
    void update() override;
    bool isRunning() override;
    void displayFPS() override;
    void drawCircle(float, float, float) override;
    void setPosition(float, float) override;
    void createSurface(int, int, SDL_PixelFormat) override;
    SDL_Renderer* GetRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int fps;
};

#endif
