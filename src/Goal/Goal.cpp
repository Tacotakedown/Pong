#include "Goal.h"

Goal::Goal(int x, int y, int w, int h) : mRect({ x,y,w,h })
{
	auto sizeX = (w / 2);
	auto sizeY = (h / 2);

	mBoundingBox.setCenterX(x + sizeX);
	mBoundingBox.setCenterY(y + sizeY);
	mBoundingBox.setExtentX(sizeX);
	mBoundingBox.setExtentY(sizeY);
}