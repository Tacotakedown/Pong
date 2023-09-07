#ifndef CENTERDIVIDER_H
#define CENTERDIVIDER_H

#include "SDL.h"

class CenterDivider
{
private:
	SDL_Rect mRect;

public:
	CenterDivider(int x, int y, int h, int w);

	void onDraw(SDL_Renderer& renderer);
};


#endif // !CENTERDIVIDER_H




