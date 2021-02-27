#pragma once
#include <string>

enum class Tetromino {
	I_TETROMINO,
	O_TETROMINO,
	T_TETROMINO,
	J_TETROMINO,
	L_TETROMINO,
	S_TETROMINO,
	Z_TETROMINO,
	NUMBER_OF_TETROMINOS,
};

enum class Rotation {
	ROT_0,
	ROT_90,
	ROT_180,
	ROT_270,
};

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
	Tetromino get_type();
	void rotate(int angle);

	std::string blocks;

    private:
	const int _width = 50;
	const int _height = 50;
	Tetromino _type;
	int _pos_x;
	int _pos_y;
	int _vel_x;
	int _vel_y;
};