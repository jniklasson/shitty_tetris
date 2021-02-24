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
	_renderer = nullptr;
	_screen_width = 1024;
	_screen_height = 768;
	_game_state = GameState::RUNNING;
}
Game::~Game()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}

void Game::run()
{
	init();
	gameLoop();
}
void Game::init()
{
	// Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Shitty Tetris", SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED, _screen_width,
				   _screen_height, SDL_WINDOW_SHOWN);
	if (_window == nullptr) {
		fatalError("SDL Window could not be created");
	}
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	//Init pieces
	for (Tetromino t; t != Tetromino::NUMBER_OF_TETROMINOS; ++t) {
		_pieces[static_cast<int>(t)] = new Piece(t);
	}
}
void Game::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			_game_state = GameState::EXIT;
			break;
		}
	}
}

void Game::render()
{
	//Clear screen
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::gameLoop()
{
	while (_game_state != GameState::EXIT) {
		update();
		render();
		SDL_Delay(16);
	}
}
