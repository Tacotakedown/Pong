#ifndef PADDLE_H
#define PADDLE_H

#include "BoundingBox/boundingBox.h"
#include <SDL.h>

class CourtScene;
class Paddle
{

public:
	static const int VELOCITY;
	enum class Movement : int {
		UP    = -1,
		STILL = 0,
		DOWN  = 1,
	};
	Paddle(CourtScene& scene, int x, int y, int w, int h);

	void onDraw(SDL_Renderer& renderer);
	void onUpdate();
	void setMovement(Movement movement)
	{
		mMovement = movement;
	}
	bool isMoving(Movement movement) const
	{
		return mMovement == movement;
	}
	void setX(int x)
	{
		mRect.x = x;
		mBoundingBox.setCenterX(x + mBoundingBox.getExtentX());
	}
	void setY(int y)
	{
		mRect.y = y;
		mBoundingBox.setCenterY(y + mBoundingBox.getExtentY());
	}

	const boundingBox& getBoundingBox() const
	{
		return mBoundingBox;
	}
	boundingBox& getBoundingBox()
	{
		return mBoundingBox;
	}

private:
	CourtScene& mScene;
	SDL_Rect		mRect;
	Movement		mMovement;
	boundingBox		mBoundingBox;

};



#endif // !PADDLE_H


