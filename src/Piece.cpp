#include "Piece.hpp"
#include <SDL2/SDL.h>

Piece::Piece()
{
	_pos_x = 0;
	_pos_y = 0;
}

Piece::Piece(Tetromino type)
{
	_pos_x = 368;
	_pos_y = -2 * _block_width;
	_type = type;
	_rotation = Rotation::ROT_0;
	switch (type) {
	case Tetromino::I_TETROMINO:
		_blocks.append("..#.");
		_blocks.append("..#.");
		_blocks.append("..#.");
		_blocks.append("..#.");
		break;
	case Tetromino::O_TETROMINO:
		_blocks.append("....");
		_blocks.append(".##.");
		_blocks.append(".##.");
		_blocks.append("....");
		break;
	case Tetromino::T_TETROMINO:
		_blocks.append("....");
		_blocks.append("..#.");
		_blocks.append(".##.");
		_blocks.append("..#.");
		break;
	case Tetromino::J_TETROMINO:
		_blocks.append("....");
		_blocks.append("..#.");
		_blocks.append("..#.");
		_blocks.append(".##.");
		break;
	case Tetromino::L_TETROMINO:
		_blocks.append("....");
		_blocks.append(".#..");
		_blocks.append(".#..");
		_blocks.append(".##.");
		break;
	case Tetromino::S_TETROMINO:
		_blocks.append("....");
		_blocks.append("..##");
		_blocks.append(".##.");
		_blocks.append("....");
		break;
	case Tetromino::Z_TETROMINO:
		_blocks.append("....");
		_blocks.append(".##.");
		_blocks.append("..##");
		_blocks.append("....");
		break;
	default:
		break;
	}
}

Piece::~Piece()
{
}

Piece &Piece::set_x_position(int pos_x)
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	if (pos_x >= DM.w) {
		_pos_x = DM.w;
	} else if (pos_x <= 0) {
		_pos_x = 0;
	} else {
		_pos_x = pos_x;
	}

	return *this;
}
Piece &Piece::set_y_position(int pos_y)
{
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	if (pos_y >= DM.h) {
		_pos_y = DM.h;
	} else if (pos_y <= 0) {
		_pos_y = 0;
	} else {
		_pos_y = pos_y;
	}
	return *this;
}
Piece &Piece::set_rotation(Rotation rot)
{
	_rotation = rot;
	return *this;
}
int Piece::get_block_width()
{
	return _block_width;
}
int Piece::get_block_height()
{
	return _block_height;
}
int Piece::get_x_position()
{
	return _pos_x;
}
int Piece::get_y_position()
{
	return _pos_y;
}

Rotation Piece::get_rotation()
{
	return _rotation;
}

char Piece::get_block(int x, int y)
{
	switch (_rotation) {
	case Rotation::ROT_0:
		return _blocks[(x * 4) + y];
		break;
	case Rotation::ROT_90:
		return _blocks[12 + x - (y * 4)];
		break;
	case Rotation::ROT_180:
		return _blocks[15 - (x * 4) - y];
		break;
	case Rotation::ROT_270:
		return _blocks[3 - x + (y * 4)];
		break;
	}
	return _blocks[(x * 4) + y];
}

Tetromino Piece::get_type()
{
	return _type;
}

Rotation Piece::rotate()
{
	switch (_rotation) {
	case Rotation::ROT_0:
		_rotation = Rotation::ROT_90;
		break;
	case Rotation::ROT_90:
		_rotation = Rotation::ROT_180;
		break;
	case Rotation::ROT_180:
		_rotation = Rotation::ROT_270;
		break;
	case Rotation::ROT_270:
		_rotation = Rotation::ROT_0;
		break;
	}
	return _rotation;
}

void Piece::render(SDL_Renderer *renderer)

{
	switch (_type) {
	case Tetromino::I_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
		break;
	case Tetromino::O_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
		break;
	case Tetromino::T_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
		break;
	case Tetromino::J_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
		break;
	case Tetromino::L_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x7F, 0x50, 0xFF);
		break;
	case Tetromino::S_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		break;
	case Tetromino::Z_TETROMINO:
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
		break;

	default:
		break;
	}
	int x, y;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (this->get_block(i, j) != '.') {
				x = _pos_x + i * _block_width;
				y = _pos_y + j * _block_height;
				SDL_Rect rect = { x, y, _block_width,
						  _block_height };
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}