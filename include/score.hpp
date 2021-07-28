#pragma once
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

class Score {
    public:
	Score() = delete;
	Score(int w, int h);
	void render(SDL_Renderer *renderer);
	Score &add(int val);
	uint32_t get_score();

    private:
	uint32_t _score;
	int _width;
	int _height;
	TTF_Font *_font;
};