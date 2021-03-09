#include "Board.hpp"
#include <iostream>

Board::Board(int w, int h)
{
	_width = w + 2;
	_height = h + 2;
	int num_blocks = 0;
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			if ((y == 0) || (y == _height - 1) || (x == 0) ||
			    (x == _width - 1)) {
				_blocks.push_back('#');
				num_blocks++;
			} else {
				_blocks.push_back('.');
			}
		}
	}
}
Board::~Board()
{
}

char Board::get_block(int x, int y)
{
	return _blocks[(y * _width) + x];
}

void Board::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			if (this->get_block(x, y) == '#') {
				SDL_Rect rect = { x * _BLOCK_SIZE,
						  y * _BLOCK_SIZE, _BLOCK_SIZE,
						  _BLOCK_SIZE };
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}