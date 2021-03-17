#include "Piece.hpp"
#include <SDL2/SDL.h>

Piece::Piece()
{
	_pos_x = 0;
	_pos_y = 0;
}

Piece::Piece(Tetromino type)
{
	_pos_x = _BLOCK_SIZE * 4;
	_pos_y = 0;
	_type = type;
	_rotation = Rotation::ROT_0;
	switch (type) {
	case Tetromino::I_TETROMINO:
		_blocks.append(".I..");
		_blocks.append(".I..");
		_blocks.append(".I..");
		_blocks.append(".I..");
		break;
	case Tetromino::O_TETROMINO:
		_blocks.append("....");
		_blocks.append(".OO.");
		_blocks.append(".OO.");
		_blocks.append("....");
		break;
	case Tetromino::T_TETROMINO:
		_blocks.append(".T..");
		_blocks.append(".TT.");
		_blocks.append(".T..");
		_blocks.append("....");
		break;
	case Tetromino::J_TETROMINO:
		_blocks.append("..J.");
		_blocks.append("..J.");
		_blocks.append(".JJ.");
		_blocks.append("....");
		break;
	case Tetromino::L_TETROMINO:
		_blocks.append(".L..");
		_blocks.append(".L..");
		_blocks.append(".LL.");
		_blocks.append("....");
		break;
	case Tetromino::S_TETROMINO:
		_blocks.append("....");
		_blocks.append(".SS.");
		_blocks.append("SS..");
		_blocks.append("....");
		break;
	case Tetromino::Z_TETROMINO:
		_blocks.append("....");
		_blocks.append("ZZ..");
		_blocks.append(".ZZ.");
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
	_pos_x = pos_x;
	return *this;
}
Piece &Piece::set_y_position(int pos_y)
{
	_pos_y = pos_y;
	return *this;
}
Piece &Piece::set_rotation(Rotation rot)
{
	_rotation = rot;
	return *this;
}
Piece &Piece::move(int dx, int dy)
{
	_pos_x += dx * _BLOCK_SIZE;
	_pos_y += dy * _BLOCK_SIZE;
	return *this;
}
int Piece::get_block_width()
{
	return _BLOCK_SIZE;
}
int Piece::get_block_height()
{
	return _BLOCK_SIZE;
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

Rotation Piece::rotate(int dir)
{
	switch (_rotation) {
	case Rotation::ROT_0:
		_rotation = dir >= 0 ? Rotation::ROT_90 : Rotation::ROT_270;
		break;
	case Rotation::ROT_90:
		_rotation = dir >= 0 ? Rotation::ROT_180 : Rotation::ROT_0;
		break;
	case Rotation::ROT_180:
		_rotation = dir >= 0 ? Rotation::ROT_270 : Rotation::ROT_90;
		break;
	case Rotation::ROT_270:
		_rotation = dir >= 0 ? Rotation::ROT_0 : Rotation::ROT_180;
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
				x = _pos_x + i * _BLOCK_SIZE;
				y = _pos_y + j * _BLOCK_SIZE;
				SDL_Rect rect = { x, y, _BLOCK_SIZE,
						  _BLOCK_SIZE };
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}