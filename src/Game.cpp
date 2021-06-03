#include "Game.hpp"
#include <iostream>

void fatal_error(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Press any key to quit..." << std::endl;
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}

bool valid_pos(Piece *piece, Board *board, int dx, int dy)
{
	int x_pos = piece->get_x_position();
	int y_pos = piece->get_y_position();

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (piece->get_block(x, y) != '.') {
				if (board->get_block(x_pos + x + dx,
						     y_pos + y + dy) != '.') {
					return false;
				}
			}
		}
	}

	return true;
}

bool Game::check_input(SDL_Event e)
{
	switch (e.type) {
	case SDL_QUIT:
		_game_state = GameState::EXIT;
		break;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym) {
		case SDLK_LEFT:
			if (valid_pos(_active_piece, _board, -1, 0)) {
				_active_piece->move(-1, 0);
			}
			break;
		case SDLK_RIGHT:
			if (valid_pos(_active_piece, _board, 1, 0)) {
				_active_piece->move(1, 0);
			}
			break;
		case SDLK_DOWN:
			return true;
			break;
		case SDLK_x:
			_active_piece->rotate(1);
			if (!valid_pos(_active_piece, _board, 0, 0)) {
				_active_piece->rotate(-1);
			}
			break;
		}
	}
	return false;
}
Game::Game()
{
	_window = nullptr;
	_renderer = nullptr;
	_screen_width = 768;
	_screen_height = 1024;
	_game_state = GameState::RUNNING;
	_ticks = 0;
	_game_speed = 20;
}

Game::Game(int w, int h)
{
	_window = nullptr;
	_renderer = nullptr;
	_screen_width = w;
	_screen_height = h;
	_game_state = GameState::RUNNING;
	_ticks = 0;
	_game_speed = 20;
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

unsigned int Game::get_score()
{
	return _score;
}

void Game::init()
{
	// Init SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Shitty Tetris", SDL_WINDOWPOS_CENTERED,
				   SDL_WINDOWPOS_CENTERED, _screen_width,
				   _screen_height,
				   SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (_window == nullptr) {
		fatal_error("SDL Window could not be created");
	}
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	_board = new Board(10, 24);
	_active_piece = new Piece(static_cast<Tetromino>(
		rand() % static_cast<int>(Tetromino::NUMBER_OF_TETROMINOS)));
	_score = 0;
}
void Game::update()
{
	bool move_down = false;
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		move_down = check_input(e);
	}
	if (_ticks == _game_speed) {
		move_down = true;
		_ticks = 0;
	} else {
		_ticks++;
	}
	if (move_down) {
		if (valid_pos(_active_piece, _board, 0, 1)) {
			_active_piece->move(0, 1);
		} else {
			_board->add_piece(_active_piece);
			_score +=
				25 + (_board->check_rows(_active_piece) * 100);
			std::cout << "Current score: " << _score << std::endl;
			delete _active_piece;
			_active_piece = new Piece(static_cast<Tetromino>(
				rand() %
				static_cast<int>(
					Tetromino::NUMBER_OF_TETROMINOS)));
		}
	}
	move_down = false;
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
		SDL_Delay(50);
	}
}
