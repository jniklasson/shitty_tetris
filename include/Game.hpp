#pragma once
#include <SDL2/SDL.h>
#include <Block.hpp>

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
	void update(Block &b);
	void gameLoop();
	void render(Block &b);

	SDL_Window *_window;
	SDL_Renderer *_renderer;
	int _screen_width;
	int _screen_height;
	GameState _gameState;
};