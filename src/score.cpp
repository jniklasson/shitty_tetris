#include "score.hpp"
#include <string>
#include <iostream>

Score::Score(int w, int h)
{
	_width = w;
	_height = h;
	_score = 0;
	_font = TTF_OpenFont(
		"/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-Regular.ttf",
		64);
	if (!_font) {
		std::cout << TTF_GetError() << std::endl;
	}
}
Score &Score::add(int val)
{
	_score += val;
	return *this;
}

uint32_t Score::get_score()
{
	return _score;
}

void Score::render(SDL_Renderer *renderer)
{
	SDL_Color White = { 255, 255, 255, 255 };
	SDL_Surface *surfaceMessage = TTF_RenderText_Solid(
		_font, ("Score: " + std::to_string(_score)).c_str(), White);
	SDL_Texture *Message =
		SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect Message_rect;
	Message_rect.x = 15 * 32;
	Message_rect.y = 1 * 32;
	Message_rect.w = 120;
	Message_rect.h = 60;

	SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}