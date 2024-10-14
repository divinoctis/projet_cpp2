#include <iostream>
#include "SDLWindow.h"
#include "SDLSprite.h"
int main(int argc, char* argv[]) {
    if (true) {
        SDLWindow* window;
        Sprite* wellyes;
        window = new SDLWindow();
        window->init(500, 500);

        while (!window->isRunning()) {
            window->createSurface(250, 250, );
            window->update();
            window->displayFPS();
            
            SDL_SetRenderDrawColor(window->GetRenderer(), 255, 0, 0, 255);
            SDL_RenderClear(window->GetRenderer());
            SDL_RenderPresent(window->GetRenderer());
        }
        



        delete window;
    }

    return 0;
}