#pragma once
#include <SDL2/SDL.h>

enum class GameState
{
    RUNNING,
    EXIT,
};

class Game
{
public:
    Game();
    ~Game();

    void run();

private:
    void init();
    void processInput();
    void gameLoop();
    void render();

    SDL_Window *_window;
    SDL_Surface *_screenSurface;
    int _screen_width;
    int _screen_height;
    GameState _gameState;
};