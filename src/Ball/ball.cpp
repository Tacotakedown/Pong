#include "ball.h"
#include "CourtScene/CourtScene.h"
#include <iostream>

const float ball::INITAL_V = 8.0f;
const float ball::V_INCREASE = 1.0f;
const float ball::M_VELOCITY = 15.0f;

ball::ball(CourtScene& scene, int x, int y, int w, int h) : mScene(scene), mRect({ x,y,w,h }), mVelocity(INITAL_V), mDirection({ -0.5f, 0.5f })
{
	auto halfWidth = (w / 2);
	auto halfHeight = (h / 2);

	mBoundingBox.setCenterX(x + halfWidth);
	mBoundingBox.setCenterY(y + halfHeight);
	mBoundingBox.setExtentX(halfWidth);
	mBoundingBox.setExtentY(halfHeight);
}

void ball::onDraw(SDL_Renderer& renderer)
{
	SDL_RenderFillRect(&renderer, &mRect);
}

void ball::onUpdate()
{
	auto movement = std::array<int, 2>();
	movement[0] = static_cast<int>(mDirection[0] * mVelocity);
	movement[1] = static_cast<int>(mDirection[1] * mVelocity);

	mRect.x += movement[0];
	mRect.y += movement[1];

	mBoundingBox.setCenterX(mBoundingBox.getCenterX() + movement[0]);
	mBoundingBox.setCenterY(mBoundingBox.getCenterY() + movement[1]);
	mScene.getAiPaddle().setY(mBoundingBox.getCenterY()- 40);

	const auto& bottomWallBox = mScene.getBottomWall().getBoundingBox();
	const auto& topWallBox = mScene.getTopWall().getBoundingBox();
	const auto& leftPaddleBox = mScene.getLPaddle().getBoundingBox();
	const auto& rightPaddleBox = mScene.getAiPaddle().getBoundingBox();
	const auto& leftGoalBox = mScene.getLeftGoal().getBoundingBox();
	const auto& rightGoalBox = mScene.getRightGoal().getBoundingBox();

	if (mBoundingBox.collision(bottomWallBox)) {
		mRect.y = bottomWallBox.getCenterY();
		mRect.y -= bottomWallBox.getExtentY();
		mRect.y -= mRect.h;

		mBoundingBox.setCenterX(mRect.x + mBoundingBox.getExtentX());
		mBoundingBox.setCenterY(mRect.y + mBoundingBox.getExtentY());

		mDirection[1] = -mDirection[1];
	}
	else if (mBoundingBox.collision(topWallBox)) {
		mRect.y = topWallBox.getCenterY();
		mRect.y += topWallBox.getExtentY();

		mBoundingBox.setCenterX(mRect.x + mBoundingBox.getExtentX());
		mBoundingBox.setCenterY(mRect.y + mBoundingBox.getExtentY());

		mDirection[1] = -mDirection[1];
	}
	else if (mBoundingBox.collision(leftPaddleBox)) {
		mRect.x = leftPaddleBox.getCenterX();
		mRect.x += leftPaddleBox.getCenterX();

		mBoundingBox.setCenterX(mRect.x + mBoundingBox.getExtentX());
		mBoundingBox.setCenterY(mRect.y + mBoundingBox.getExtentY());

		

		mDirection[0] = -mDirection[0];

		mVelocity += V_INCREASE;
		mVelocity = std::min(mVelocity, M_VELOCITY);
	}
	else if (mBoundingBox.collision(rightPaddleBox))
	{
		mRect.x = rightPaddleBox.getCenterX();
		mRect.x -= rightPaddleBox.getExtentX();
		mRect.x -= mRect.w;

		mBoundingBox.setCenterX(mRect.x + mBoundingBox.getExtentX());
		mBoundingBox.setCenterY(mRect.y + mBoundingBox.getExtentY());

		mDirection[0] = -mDirection[0];

		mVelocity += V_INCREASE;
		mVelocity = std::min(mVelocity, M_VELOCITY);
	}
	else if (mBoundingBox.collision(rightGoalBox)) {
		mScene.addPlayerScore(0);
	}
	else if (mBoundingBox.collision(leftGoalBox)) {
		mScene.addPlayerScore(1);
	}
}