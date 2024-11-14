#include "Game.h"
#include <iostream>
#include <cstdlib> 

Game::Game() : window(nullptr), renderer(nullptr), running(true), food(Point(10, 10)), snake(Snake(Point(5, 5))) {}

bool Game::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return renderer != nullptr;
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // רקע שחור
    SDL_RenderClear(renderer);

    // ציור הנחש
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (const auto& segment : snake.body) {
        SDL_Rect rect = { segment.x * 20, segment.y * 20, 20, 20 };
        SDL_RenderFillRect(renderer, &rect);
    }

    // ציור המזון
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect food_rect = { food.x * 20, food.y * 20, 20, 20 };
    SDL_RenderFillRect(renderer, &food_rect);

    SDL_RenderPresent(renderer);
}

void Game::update() {
    snake.move();
    // בדיקת התנגשות עם המזון
    if (snake.front() == food) {
        snake.grow();
        generate_food();
    }
    // בדיקת התנגשות עם הגוף
    for (size_t i = 1; i < snake.body.size(); ++i) {
        if (snake.body[i] == snake.front()) {
            running = false; // סיום המשחק
        }
    }
    // בדיקת התנגשות עם הקירות
    Point head = snake.front();
    if (head.x < 0 || head.y < 0 || head.x >= 40 || head.y >= 30) {
        running = false;
    }
}

void Game::handle_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP:    snake.changeDirection(UP); break;
            case SDLK_DOWN:  snake.changeDirection(DOWN); break;
            case SDLK_LEFT:  snake.changeDirection(LEFT); break;
            case SDLK_RIGHT: snake.changeDirection(RIGHT); break;
            }
        }
    }
}

void Game::generate_food() {
    int x = rand() % 40;
    int y = rand() % 30;
    food = Point(x, y);
}

bool Game::isRunning() const {
    return running;
}

void Game::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
