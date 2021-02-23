#pragma once
class Block {
    public:
	Block();
	Block(int x, int y);
	Block(int width, int height, int pos_x, int pos_y);
	~Block();
	Block &set_width(int width);
	Block &set_height(int height);
	Block &set_x_position(int pos_x);
	Block &set_y_position(int pos_y);
	Block &set_x_velocity(int vel_x);
	Block &set_y_velocity(int vel_y);
	int get_width();
	int get_height();
	int get_x_position();
	int get_y_position();
	int get_x_velocity();
	int get_y_velocity();

    private:
	int _width;
	int _height;
	int _pos_x;
	int _pos_y;
	int _vel_x;
	int _vel_y;
};