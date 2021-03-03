#include "Board.hpp"
#include <iostream>

Board::Board(int w, int h)
{
	_width = w;
	_height = h;
}
Board::~Board()
{
}
void Board::render(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	for (int y = 0; y < _height; y++) {
		SDL_Rect vert_left = { 0, y * _BLOCK_SIZE, _BLOCK_SIZE,
				       _BLOCK_SIZE };
		SDL_RenderFillRect(renderer, &vert_left);
		SDL_Rect vert_right = { _width * _BLOCK_SIZE, y * _BLOCK_SIZE,
					_BLOCK_SIZE, _BLOCK_SIZE };
		SDL_RenderFillRect(renderer, &vert_right);
	}

	for (int x = 0; x < _width; x++) {
		SDL_Rect vert_left = { x * _BLOCK_SIZE, 0, _BLOCK_SIZE,
				       _BLOCK_SIZE };
		SDL_RenderFillRect(renderer, &vert_left);
		SDL_Rect vert_right = { x * _BLOCK_SIZE,
					(_height - 1) * _BLOCK_SIZE,
					_BLOCK_SIZE, _BLOCK_SIZE };
		SDL_RenderFillRect(renderer, &vert_right);
	}
}