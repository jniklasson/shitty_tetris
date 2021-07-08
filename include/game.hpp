#pragma once
#include <SDL2/SDL.h>
#include <piece.hpp>
#include <board.hpp>
#include <vector>

enum class GameState {
	RUNNING,
	EXIT,
};

class Game {
    public:
	Game();
	Game(int w, int h);
	~Game();

	void run();
	unsigned int get_score();

    private:
	void init();
	void update();
	void gameLoop();
	void render();
	bool check_input(SDL_Event e);
	SDL_Window *_window;
	SDL_Renderer *_renderer;
	int _screen_width;
	int _screen_height;
	GameState _game_state;
	int _ticks;
	int _game_speed;
	Board *_board;
	Piece *_active_piece;
	unsigned int _score;
	const int _BOARD_WIDTH = 12;
	const int _BOARD_HEIGHT = 24;
};