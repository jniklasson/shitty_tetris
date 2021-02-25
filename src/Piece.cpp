#include "Piece.hpp"

Piece::Piece()
{
	_pos_x = 0;
	_pos_y = 0;
	_vel_x = 0;
	_vel_y = 0;
}

Piece::Piece(Tetromino type)
{
	_pos_x = 0;
	_pos_y = 0;
	_vel_x = 0;
	_vel_y = 0;
	_type = type;
	switch (type) {
	case Tetromino::I_TETROMINO:
		blocks.append("..#.");
		blocks.append("..#.");
		blocks.append("..#.");
		blocks.append("..#.");
		break;
	case Tetromino::O_TETROMINO:
		blocks.append("....");
		blocks.append(".##.");
		blocks.append(".##.");
		blocks.append("....");
		break;
	case Tetromino::T_TETROMINO:
		blocks.append("....");
		blocks.append("..#.");
		blocks.append(".##.");
		blocks.append("..#.");
		break;
	case Tetromino::J_TETROMINO:
		blocks.append("....");
		blocks.append("..#.");
		blocks.append("..#.");
		blocks.append(".##.");
		break;
	case Tetromino::L_TETROMINO:
		blocks.append("....");
		blocks.append(".#..");
		blocks.append(".#..");
		blocks.append(".##.");
		break;
	case Tetromino::S_TETROMINO:
		blocks.append("....");
		blocks.append("..##");
		blocks.append(".##.");
		blocks.append("....");
		break;
	case Tetromino::Z_TETROMINO:
		blocks.append("....");
		blocks.append(".##.");
		blocks.append("..##");
		blocks.append("....");
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
Piece &Piece::set_x_velocity(int vel_x)
{
	_vel_x = vel_x;
	return *this;
}
Piece &Piece::set_y_velocity(int vel_y)
{
	_vel_y = vel_y;
	return *this;
}
int Piece::get_width()
{
	return _width;
}
int Piece::get_height()
{
	return _height;
}
int Piece::get_x_position()
{
	return _pos_x;
}
int Piece::get_y_position()
{
	return _pos_y;
}

int Piece::get_x_velocity()
{
	return _vel_x;
}
int Piece::get_y_velocity()
{
	return _vel_y;
}
Tetromino Piece::get_type()
{
	return _type;
}