#ifndef BALL_H
#define BALL_H

#include "BoundingBox/boundingBox.h"
#include <array>
#include <SDL.h>

class CourtScene;
class ball
{
private:
	CourtScene& mScene;
	SDL_Rect				mRect;
	boundingBox				mBoundingBox;
	float					mVelocity;
	std::array<float, 2>	mDirection;

public:
	static const float INITAL_V, V_INCREASE, M_VELOCITY;
	ball(CourtScene& scene, int x, int y, int w, int h);

	void onDraw(SDL_Renderer& renderer);
	void onUpdate();
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
	void setDirection(const std::array<float, 2>& direction)
	{
		mDirection = direction;
	}
	void setVelocity(float velocity)
	{
		mVelocity = velocity;
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

#endif // !BALL_H


