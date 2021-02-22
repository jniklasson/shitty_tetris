#include "Game.hpp"
#include <iostream>

void fatalError(std::string errorString)
{
    std::cout << errorString << std::endl;
    std::cout << "Press any key to quit..." << std::endl;
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
}

Game::Game()
{
    _window = nullptr;
    _screenSurface = nullptr;
    _screen_width = 1024;
    _screen_height = 768;
    _gameState = GameState::RUNNING;
}
Game::~Game()
{
}

void Game::run()
{
    init();
    gameLoop();
}
void Game::init()
{
    //Init SDL
    SDL_Init(SDL_INIT_VIDEO);

    _window = SDL_CreateWindow("Shitty Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screen_width, _screen_height, SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        fatalError("SDL Window could not be created");
    }
    _screenSurface = SDL_GetWindowSurface(_window);
    SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0x13, 0x37, 0x45));
    SDL_UpdateWindowSurface(_window);
}
void Game::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            _gameState = GameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            std::cout << event.motion.x << " " << event.motion.y << std::endl;
            break;
        }
    }
}
void Game::gameLoop()
{
    while (_gameState != GameState::EXIT)
    {
        processInput();
    }
}

void Game::render()
{
}