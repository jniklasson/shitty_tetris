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

Board &Board::add_piece(Piece *piece)
{
	int x_pos = piece->get_x_position() / _BLOCK_SIZE;
	int y_pos = piece->get_y_position() / _BLOCK_SIZE;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (piece->get_block(x, y) == '#') {
				_blocks[((y_pos + y) * _width) + x_pos + x] =
					'#';
			}
		}
	}
	return *this;
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