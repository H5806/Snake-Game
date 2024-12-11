#define SDL_MAIN_HANDLED
#include "Game.h"

int main() {
    Game game;
    if (!game.initialize()) {
        return -1;
    }
    game.generate_food(); 

    while (game.isRunning()) {
        game.handle_input();
        game.update();
        game.render();
        SDL_Delay(50); 
    }

    game.cleanup();
    return 0;
}