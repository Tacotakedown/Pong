#include "Paddle.h"
#include "scene/Scene.h"
#include <iostream>

const int Paddle::VELOCITY = 8;

Paddle::Paddle(CourtScene& scene, int x, int y, int w, int h) : mScene(scene), mRect({ x,y,w,h }), mMovement(Movement::STILL)
{
	auto halfWidth = (w / 2);
	auto halfHeight = (h / 2);

	mBoundingBox.setCenterX(x + halfWidth);
	mBoundingBox.setCenterY(y + halfHeight);
	mBoundingBox.setExtentX(halfWidth);
	mBoundingBox.setExtentY(halfHeight);
}

void Paddle::onDraw(SDL_Renderer& renderer)
{
	SDL_RenderFillRect(&renderer, &mRect);
}

void Paddle::onUpdate()
{
	if (mMovement != Movement::STILL)
	{
		auto movement = (int)mMovement * VELOCITY;
		mRect.y += movement;
		mBoundingBox.setCenterY(mBoundingBox.getCenterY() + movement);
		if (mMovement == Movement::UP)
		{
			const auto& wallBox = 1;//need to find wall position to prevent the ball from going into the next dimension
		}
	}
}