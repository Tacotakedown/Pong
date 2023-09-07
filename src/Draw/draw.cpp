#include "draw.h"

draw::draw(int x, int y, int w, int h) :mRect({ x,y,w,h })
{
	mBoundingBox.setCenterX(x + w / 2);
	mBoundingBox.setCenterY(y + h / 2);
	mBoundingBox.setExtentX(w / 2);
	mBoundingBox.setExtentY(h / 2);
}

void draw::onDraw(SDL_Renderer& renderer)
{
	SDL_RenderFillRect(&renderer, &mRect);
}