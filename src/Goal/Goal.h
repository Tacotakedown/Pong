#ifndef GOAL_H
#define GOAL_H

#include <SDL.h>
#include "BoundingBox/boundingBox.h"

class Goal
{
private:
	SDL_Rect	mRect;
	boundingBox mBoundingBox;

public:
	Goal(int x, int y, int w, int h);

	void setX(int x)
	{
		mRect.x = x;
		mBoundingBox.setCenterX(x + mBoundingBox.getExtentX());
	}
	void setY(int y)
	{
		mRect.y = y;
		mBoundingBox.setCenterY(y + mBoundingBox.getCenterY());
	}

	const boundingBox& getBoundingBox() const
	{
		return mBoundingBox;
	}
	boundingBox& getBoundingBox()
	{
		return mBoundingBox;
	}

};

#endif // !GOAL_H



