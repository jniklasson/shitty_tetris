#include "Board.hpp"
#include <iostream>
void set_block_color(char c, SDL_Renderer *renderer)
{
	switch (c) {
	case '#':
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		break;
	case 'I':
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);

		break;
	case 'O':
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);

		break;
	case 'T':
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

		break;
	case 'J':
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);

		break;
	case 'L':
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x7F, 0x50, 0xFF);

		break;
	case 'S':
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		break;
	case 'Z':
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

		break;
	default:
		SDL_SetRenderDrawColor(renderer, 0x33, 0x33, 0x33, 0xFF);
		break;
	}
}

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
	int x_pos = piece->get_x_position();
	int y_pos = piece->get_y_position();
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (piece->get_block(x, y) != '.') {
				_blocks[((y_pos + y) * _width) + x_pos + x] =
					piece->get_block(x, y);
			}
		}
	}
	return *this;
}

int Board::check_rows(Piece *piece)
{
	int num_rows = 0;
	int num_blocks = 0;
	int px = piece->get_x_position();
	int py = piece->get_y_position();
	char block = '.';
	for (int y = 0; y < 4; y++) {
		if (py + y == _height - 1) {
			break;
		}
		for (int x = 1; x < _width - 1; x++) {
			block = _blocks[((py + y) * _width) + x];
			if (block == '.' || block == '#') {
				break;
			} else {
				num_blocks++;
			}
		}
		if (num_blocks == _width - 2) {
			num_rows++;
			delete_row((py + y));
		}
		num_blocks = 0;
	}
	return num_rows;
}

int Board::delete_row(int pos_y)
{
	int start_row;
	int row_above;
	for (int y = pos_y; y > 1; y--) {
		start_row = (_width * y);
		row_above = (_width * (y - 1));
		for (int x = 1; x < _width - 1; x++) {
			_blocks[start_row + x] = _blocks[row_above + x];
		}
	}
	return 0;
}

void Board::render(SDL_Renderer *renderer)
{
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			if (this->get_block(x, y) != '.') {
				set_block_color(this->get_block(x, y),
						renderer);
				SDL_Rect rect = { x * _BLOCK_SIZE,
						  y * _BLOCK_SIZE, _BLOCK_SIZE,
						  _BLOCK_SIZE };
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}