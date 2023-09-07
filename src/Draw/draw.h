#ifndef DRAW_H
#define DRAW_H

#include "BoundingBox/boundingBox.h"
#include <SDL.h>

class draw
{
private:
	SDL_Rect mRect;
	boundingBox mBoundingBox;

public:
	draw(int x, int y, int w, int h);
	void onDraw(SDL_Renderer& renderer);

	const boundingBox& getBoundingBox() const
	{
		return mBoundingBox;
	}
	const boundingBox& getBoundingBox()
	{
		return mBoundingBox;
	}

};



#endif // DRAW_H

