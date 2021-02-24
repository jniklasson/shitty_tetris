#pragma once
#include <string>
#include <stdexcept>

enum Tetromino {
	BEGIN,
	I_TETROMINO = BEGIN,
	O_TETROMINO,
	T_TETROMINO,
	J_TETROMINO,
	L_TETROMINO,
	S_TETROMINO,
	Z_TETROMINO,
	NUMBER_OF_TETROMINOS,
};

Tetromino &operator++(Tetromino &t);

class Piece {
    public:
	Piece();
	Piece(Tetromino type);
	~Piece();
	Piece &set_x_position(int pos_x);
	Piece &set_y_position(int pos_y);
	Piece &set_x_velocity(int vel_x);
	Piece &set_y_velocity(int vel_y);
	int get_width();
	int get_height();
	int get_x_position();
	int get_y_position();
	int get_x_velocity();
	int get_y_velocity();

    private:
	const int _width = 4;
	const int _height = 4;
	std::string _blocks;
	Tetromino _type;
	int _pos_x;
	int _pos_y;
	int _vel_x;
	int _vel_y;
};