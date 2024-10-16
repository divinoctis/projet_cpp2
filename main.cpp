#include <iostream>



#include "RaylibWindow.h"
#include "RaylibSprite.h"

int main() {
    RaylibWindow window("well yes", 800, 600);
    RaylibSprite sprite;
    sprite.setPosition(400, 300);  // Position initiale
    sprite.setSpeed(5, 3);
    while (window.isRunning()) {
        window.beginDrawing();
        window.displayFPS();
        sprite.moveCircle(sprite.xSpeed, sprite.ySpeed);
        window.endDrawing();
        window.update();
    }

    return 0;
}

////
////
////// Raylib
////
////#include "SDLWindow.h"
////#include "SDLSprite.h"
////
////int main(int argc, char* argv[]) {
////    SDLWindow window;
////    window.init(500, 500);
////
////    bool running = true;
////    while (running) {
////        SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255);
////        SDL_RenderClear(window.GetRenderer());
////
////        SDL_SetRenderDrawColor(window.GetRenderer(), 255, 0, 0, 255);
////        window.drawCircle(250, 250, 50);
////
////        window.displayFPS();
////
////        window.update();
////
////        if (window.isRunning()) {
////            running = false;
////        }
////    }
////
////    return 0;
////}
//#include <iostream>
//
//// SDL
//
////#include "SDLWindow.h"
////#include "SDLSprite.h"
////
////int main(int argc, char* argv[]) {
////    SDLWindow window;
////    window.init(500, 500);
////
////    bool running = true;
////    while (running) {
////        SDL_SetRenderDrawColor(window.GetRenderer(), 0, 0, 0, 255); 
////        SDL_RenderClear(window.GetRenderer());
////
////        SDL_SetRenderDrawColor(window.GetRenderer(), 255, 0, 0, 255); 
////        window.drawCircle(250, 250, 50);
////
////        window.displayFPS();
////
////        window.update();
////
////        if (window.isRunning()) {
////            running = false;
////        }
////    }
////
////    return 0;
////}
