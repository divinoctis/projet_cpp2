#ifndef SDLWINDOW_H__
#define SDLWINDOW_H__

#include "Window.h"
#include "Sprite.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class SDLWindow : public Window{
public:
    SDLWindow();
    ~SDLWindow();
    void init(int width, int height) override;
    void update() override;
    bool isRunning() override;
    void displayFPS() override;
    void createSurface(int, int, SDL_PixelFormat format) override;
    SDL_Renderer* GetRenderer();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int fps;
};

#endif
