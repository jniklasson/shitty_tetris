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
	_gameState = GameState::RUNNING;
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
}
void Game::update(Block &b)
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << e.motion.x << " " << e.motion.y
				  << std::endl;
			break;
		}
	}
	const uint8_t *currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_UP]) {
		b.set_y_velocity(-10);
		b.set_x_velocity(0);
	} else if (currentKeyStates[SDL_SCANCODE_DOWN]) {
		b.set_y_velocity(10);
		b.set_x_velocity(0);
	} else if (currentKeyStates[SDL_SCANCODE_LEFT]) {
		b.set_x_velocity(-10);
		b.set_y_velocity(0);
	} else if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
		b.set_x_velocity(10);
		b.set_y_velocity(0);
	} else {
		b.set_y_velocity(0);
		b.set_x_velocity(0);
	}
	if ((b.get_x_position() + b.get_x_velocity() + b.get_width() <
	     _screen_width) &&
	    (b.get_x_position() + b.get_x_velocity() - b.get_height() > -1)) {
		b.set_x_position(b.get_x_position() + b.get_x_velocity());
	}
	if ((b.get_y_position() + b.get_y_velocity() + b.get_height() <
	     _screen_height) &&
	    (b.get_y_position() + b.get_y_velocity() - b.get_height() > -1)) {
		b.set_y_position(b.get_y_position() + b.get_y_velocity());
	}
}

void Game::render(Block &b)
{
	//Clear screen
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer);
	SDL_Rect rect{ b.get_x_position(), b.get_y_position(), b.get_width(),
		       b.get_height() };
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(_renderer, &rect);
	SDL_RenderPresent(_renderer);
}

void Game::gameLoop()
{
	Block b(10, 10);
	while (_gameState != GameState::EXIT) {
		update(b);
		render(b);
		SDL_Delay(16);
	}
}
