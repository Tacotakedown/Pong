#include "Score.h"

// horizontal line draw instruction indices.
#define HLINE_TOP     0
#define HLINE_MIDDLE  1
#define HLINE_BOTTOM  2

// vertical line draw instruction indices.
#define VLINE_LEFT_TOP      0
#define VLINE_LEFT_BOTTOM   1
#define VLINE_RIGHT_TOP     2
#define VLINE_RIGHT_BOTTOM  3
#define VLINE_CENTER        4

inline void drawLine(SDL_Renderer& renderer, const SDL_Rect& rect) {
	SDL_RenderFillRect(&renderer, &rect);
}

Score::Score(int x, int y, int w, int h) : mValue(0)
{
	auto thickness = h / 5;

	mHlines[HLINE_TOP] = { x, y, w, thickness };
	mHlines[HLINE_MIDDLE] = { x, y + (h / 2) - thickness / 2, w, thickness };
	mHlines[HLINE_BOTTOM] = { x, y + (h - thickness), w, thickness };

	mVlines[VLINE_LEFT_TOP] = { x, y, thickness, h / 2 };
	mVlines[VLINE_LEFT_BOTTOM] = { x, y + h / 2, thickness, h / 2 };
	mVlines[VLINE_RIGHT_TOP] = { x + w - thickness, y, thickness, h / 2 };
	mVlines[VLINE_RIGHT_BOTTOM] = { x + w - thickness, y + h / 2,thickness, h / 2 };
	mVlines[VLINE_CENTER] = { x + w / 2 - thickness, y, thickness, h };
}

void Score::onDraw(SDL_Renderer& renderer)
{
	switch (mValue)
	{
	case 0:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 1:
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_CENTER]);
		break;
	case 2:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		break;
	case 3:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 4:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 5:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 6:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 7:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 8:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;
	case 9:
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_TOP]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_MIDDLE]);
		SDL_RenderFillRect(&renderer, &mHlines[HLINE_BOTTOM]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_LEFT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_TOP]);
		SDL_RenderFillRect(&renderer, &mVlines[VLINE_RIGHT_BOTTOM]);
		break;

	}
}