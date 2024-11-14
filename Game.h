#pragma once
#include <SDL.h>
#include "Snake.h"
#include "Point.h"

class Game {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Point food;
    Snake snake;

    Game();

    // אתחול המשחק
    bool initialize();

    // פעולות גרפיקה ועדכון מצב המשחק
    void render();
    void update();
    void handle_input();
    void generate_food();

    // ניהול מצב המשחק
    bool isRunning() const;
    void cleanup();
};
