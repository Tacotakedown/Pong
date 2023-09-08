#ifndef CENTERDIVIDER_H
#define CENTERDIVIDER_H

#include "SDL.h"

class CenterLine
{
private:
	SDL_Rect mRect;

public:
	CenterLine(int x, int y, int h, int w);

	void onDraw(SDL_Renderer& renderer);
};


#endif // !CENTERDIVIDER_H




