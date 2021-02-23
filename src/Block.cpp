#include "Block.hpp"

Block::Block()
{
	_width = 1;
	_height = 1;
	_pos_x = 0;
	_pos_y = 0;
	_vel_x = 0;
	_vel_y = 0;
}
Block::Block(int width, int height)
{
	_width = width;
	_height = height;
	_pos_x = 0;
	_pos_y = 0;
	_vel_x = 0;
	_vel_y = 0;
}
Block::Block(int width, int height, int pos_x, int pos_y)
{
	_width = width;
	_height = height;
	_pos_x = pos_x;
	_pos_y = pos_y;
	_vel_x = 0;
	_vel_y = 0;
}

Block::~Block()
{
}

Block &Block::set_width(int width)
{
	_width = width;
	return *this;
}
Block &Block::set_height(int height)
{
	_height = height;
	return *this;
}
Block &Block::set_x_position(int pos_x)
{
	_pos_x = pos_x;
	return *this;
}
Block &Block::set_y_position(int pos_y)
{
	_pos_y = pos_y;
	return *this;
}
Block &Block::set_x_velocity(int vel_x)
{
	_vel_x = vel_x;
	return *this;
}
Block &Block::set_y_velocity(int vel_y)
{
	_vel_y = vel_y;
	return *this;
}
int Block::get_width()
{
	return _width;
}
int Block::get_height()
{
	return _height;
}
int Block::get_x_position()
{
	return _pos_x;
}
int Block::get_y_position()
{
	return _pos_y;
}

int Block::get_x_velocity()
{
	return _vel_x;
}
int Block::get_y_velocity()
{
	return _vel_y;
}