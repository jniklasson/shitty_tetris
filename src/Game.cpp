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

	//init pieces
	_pieces.emplace_back(new Piece(Tetromino::I_TETROMINO));
	_pieces.emplace_back(new Piece(Tetromino::O_TETROMINO));
	_pieces.emplace_back(new Piece(Tetromino::T_TETROMINO));
	_pieces.emplace_back(new Piece(Tetromino::J_TETROMINO));
	_pieces.emplace_back(new Piece(Tetromino::L_TETROMINO));
	_pieces.emplace_back(new Piece(Tetromino::S_TETROMINO));
	_pieces.emplace_back(new Piece(Tetromino::Z_TETROMINO));
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
	int count = 0;
	for (auto const &p : _pieces) {
		switch (p->get_type()) {
		case Tetromino::I_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0x00, 0xFF, 0xFF,
					       0xFF);
			break;
		case Tetromino::O_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0x00,
					       0xFF);
			break;
		case Tetromino::T_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0xFF,
					       0xFF);
			break;
		case Tetromino::J_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0xFF,
					       0xFF);
			break;
		case Tetromino::L_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0xFF, 0x7F, 0x50,
					       0xFF);
			break;
		case Tetromino::S_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0x00, 0xFF, 0x00,
					       0xFF);
			break;
		case Tetromino::Z_TETROMINO:
			SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00,
					       0xFF);
			break;

		default:
			break;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (p->blocks[(i * 4) + j] != '.') {
					SDL_Rect rect = { (count * 100) + 100 +
								  i * 20,
							  100 + j * 20, 20,
							  20 };
					SDL_RenderFillRect(_renderer, &rect);
				}
			}
		}
		count++;
	}
	/*
	SDL_Rect rect = { 512, 384, 50, 50 };
	SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(_renderer, &rect);
	rect.y += 50;
	SDL_SetRenderDrawColor(_renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(_renderer, &rect);
	rect.y += 50;
	SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(_renderer, &rect);
	*/
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
