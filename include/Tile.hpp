#pragma once

class Tile {
    public:
	Tile() = delete;
	Tile(int size);
	~Tile();
	Tile &set_size(int size);
	int get_size(int size);

    private:
	int _size;
};