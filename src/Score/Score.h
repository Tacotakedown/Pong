#ifndef SCORE_H
#define SCORE_H

#include "SDL.h"
#include <array>

class Score final
{
public:
	Score(int x, int y, int w, int h);
	void onDraw(SDL_Renderer& renderer);
	void setValue(int value)
	{
		mValue = value;
	}
private:
	int mValue;
	std::array<SDL_Rect, 3> mHlines;
	std::array<SDL_Rect, 5> mVlines;
};


#endif // !SCORE_H


