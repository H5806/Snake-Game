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

    // ����� �����
    bool initialize();

    // ������ ������ ������ ��� �����
    void render();
    void update();
    void handle_input();
    void generate_food();

    // ����� ��� �����
    bool isRunning() const;
    void cleanup();
};
