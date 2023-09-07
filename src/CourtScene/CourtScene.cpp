#include "CourtScene.h"
#include "EndScreen/EndScreen.h"
#include "Game/game.h"
#include "Draw/draw.h"
#include "SDL.h"

#include <time.h>
#include <stdlib.h>

#define PAUSE_TICKS 30

CourtScene::CourtScene(Game& game) : mGame(game),
mTopWall(0, 0, game.getResolution()[0], BOX_WIDTH),
mBottomWall(0, (game.getResolution()[1] - BOX_WIDTH), game.getResolution()[0], BOX_WIDTH),
mCenterLine((game.getResolution()[0] / 2) - BOX_WIDTH / 2, BOX_WIDTH, BOX_WIDTH, game.getResolution()[1]),
mLeftPaddle(*this, EDGE_OFFSET, (game.getResolution()[1] / 2) - (PADDLE_HEIGHT / 2), BOX_WIDTH, PADDLE_HEIGHT),
mRightPaddle(*this, game.getResolution()[0] - EDGE_OFFSET - BOX_WIDTH, (game.getResolution()[1] / 2) - (PADDLE_HEIGHT / 2), BOX_WIDTH, PADDLE_HEIGHT),
mBall(*this, game.getResolution()[0] / 2 - (BOX_WIDTH / 2), game.getResolution()[1] / 2 - (BOX_WIDTH / 2), BOX_WIDTH, BOX_WIDTH),
mLGoal(-1000, 0, 1000 - BOX_WIDTH, game.getResolution()[1]),
mRGoal(game.getResolution()[0] + BOX_WIDTH, 0, 1000, game.getResolution()[1]),
mLScore(game.getHalfResolution()[0] - (70 + (game.getResolution()[0] / 10)), game.getResolution()[1] / 10, game.getResolution()[0] / 10, game.getResolution()[1] / 6),
mRScore(game.getHalfResolution()[0] + 70, game.getResolution()[1] / 10, game.getResolution()[0] / 10, game.getResolution()[1] / 6),
mRemainingPauseTicks(PAUSE_TICKS) {

}
CourtScene::~CourtScene() {

}

void CourtScene::onDraw(SDL_Renderer& renderer) {
	mTopWall.onDraw(renderer);
	mBottomWall.onDraw(renderer);
	mCenterLine.onDraw(renderer);
	mLeftPaddle.onDraw(renderer);
	mRightPaddle.onDraw(renderer);
	mBall.onDraw(renderer);
	mLScore.onDraw(renderer);
	mRScore.onDraw(renderer);
}

