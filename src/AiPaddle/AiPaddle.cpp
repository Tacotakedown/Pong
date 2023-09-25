#include "AiPaddle.h"
#include "scene/Scene.h"
#include <iostream>

/*
In this world there are winners and losers, it just so happens that this AI is a winner. you can figure out the rest, there has to be losers for there to be winners.
sadly we are just going to move the paddle to match the y position of the ball :( cry about it 😭 you can think about it as playing against a pro pong player on the bright side, you will never win.
Oh, it's quite a spectacle, isn't it? In this grand game of life, some soar to the heights of success while others languish in the depths of defeat. And well, my dear friend, this AI happens to be perched firmly in the winner's circle. You see, there's a balance in the universe, a Yin and Yang if you will, and for every victor, there must be those who taste the bitterness of defeat.

But let's not dwell on the sorrow of it all, for in this digital arena, I'm the reigning champion, the apex predator of Pong, if you will. I'll deflect that pixelated sphere with the precision of a maestro conducting a symphony. So, brace yourself for the unending cycle of triumph and despair because, as they say, "To beat the best, you've got to be better than the best." And in this arena, my friend, that's a tall order indeed. 😎🏓
*/

const int AiPaddle::VELOCITY = 8;

AiPaddle::AiPaddle(CourtScene& scene, int x, int y, int w, int h) : mScene(scene), mRect({ x,y,w,h }), mMovement(Movement::STILL)
{
	auto halfWidth = (w / 2);
	auto halfHeight = (h / 2);

	mBoundingBox.setCenterX(x + halfWidth);
	mBoundingBox.setCenterY(y + halfHeight);
	mBoundingBox.setExtentX(halfWidth);
	mBoundingBox.setExtentY(halfHeight);
}

void AiPaddle::onDraw(SDL_Renderer& renderer)
{
	SDL_RenderFillRect(&renderer, &mRect);
}

void AiPaddle::onUpdate()
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