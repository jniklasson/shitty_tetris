#pragma once
#include <string>
#include <SDL2/SDL_render.h>

class Board {
    public:
	Board() = delete;
	Board(int w, int h);
	~Board();
	char get_block(int x, int y);
	void render(SDL_Renderer *renderer);

    private:
	int _width;
	int _height;
	const int _BLOCK_SIZE = 32;
	std::string _blocks;
};