#pragma once
#include <SDL2/SDL.h>
#include <Piece.hpp>
#include <Board.hpp>
#include <vector>

enum class GameState {
	RUNNING,
	EXIT,
};

class Game {
    public:
	Game();
	~Game();

	void run();

    private:
	void init();
	void update();
	void gameLoop();
	void render();

	SDL_Window *_window;
	SDL_Renderer *_renderer;
	int _screen_width;
	int _screen_height;
	GameState _game_state;
	Board _board;
	Piece *_active_piece;
};