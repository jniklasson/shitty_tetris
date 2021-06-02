#include "Tile.hpp"

Tile::Tile(int size)
{
	_size = size;
}
Tile::~Tile()
{
}
Tile &Tile::set_size(int size)
{
	_size = size;
	return *this;
}
int Tile::get_size(int size)
{
	return _size;
}