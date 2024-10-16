//#include <iostream>
//#include "SDLWindow.h"
//#include "SDLSprite.h"
//
//int main(int argc, char* argv[]) {
//    SDLWindow window;
//    window.init(500, 500);
//
//    bool running = true;
//    while (running) {
//        SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255); 
//        SDL_RenderClear(window.GetRenderer());
//
//        SDL_SetRenderDrawColor(window.GetRenderer(), 255, 0, 0, 255); 
//        window.drawCircle(250, 250, 50);
//
//        window.displayFPS();
//
//        window.update();
//
//        if (window.isRunning()) {
//            running = false;
//        }
//    }
//
//    return 0;
//}


// updated main vector

#include <iostream>
#include "SDLWindow.h"
#include "SDLSprite.h"

int main(int argc, char* argv[]) {
    SDLWindow window;
    window.init(500, 500);

    bool running = true;

    Uint32 lastTime = SDL_GetTicks();

    while (running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(window.GetRenderer());

        window.updated(deltaTime);

        window.displayFPS();

        window.update();

        if (window.isRunning()) {
            running = true; // mettre false
        }
    }

    return 0;
}
