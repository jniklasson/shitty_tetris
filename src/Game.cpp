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

Game::Game(int w, int h)
{
	_window = nullptr;
	_renderer = nullptr;
	_screen_width = w;
	_screen_height = h;
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
	_board = new Board(10, 24);
	_active_piece = new Piece(static_cast<Tetromino>(
		rand() % static_cast<int>(Tetromino::NUMBER_OF_TETROMINOS)));
}
void Game::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			_game_state = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym) {
			case SDLK_LEFT:
				_active_piece->set_x_position(
					_active_piece->get_x_position() -
					_active_piece->get_block_width());
				break;
			case SDLK_RIGHT:
				_active_piece->set_x_position(
					_active_piece->get_x_position() +
					_active_piece->get_block_width());
				break;
			case SDLK_x:
				_active_piece->rotate();
				break;
			}
		}
	}
	if (_active_piece->get_y_position() > 768) {
		delete _active_piece;
		_active_piece = new Piece(static_cast<Tetromino>(
			rand() %
			static_cast<int>(Tetromino::NUMBER_OF_TETROMINOS)));
	}
	_active_piece->set_y_position(_active_piece->get_y_position() +
				      _active_piece->get_block_height());
}

void Game::render()
{
	//Clear screen
	SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(_renderer);
	_active_piece->render(_renderer);
	_board->render(_renderer);
	SDL_RenderPresent(_renderer);
}

void Game::gameLoop()
{
	while (_game_state != GameState::EXIT) {
		update();
		render();
		SDL_Delay(200);
	}
}
