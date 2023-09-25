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
mAiPaddle(*this, game.getResolution()[0] - EDGE_OFFSET - BOX_WIDTH, (game.getResolution()[1] / 2) - (PADDLE_HEIGHT / 2), BOX_WIDTH, PADDLE_HEIGHT),
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
	mAiPaddle.onDraw(renderer);
	mBall.onDraw(renderer);
	mLScore.onDraw(renderer);
	mRScore.onDraw(renderer);
}

void CourtScene::onUpdate() {
	if (mRemainingPauseTicks <= 0) {
		mLeftPaddle.onUpdate();
		mAiPaddle.onUpdate();
		mBall.onUpdate();
	}
	else {
		mRemainingPauseTicks--;
	}
}

void CourtScene::onEnter() {
	srand(static_cast<unsigned int>(time(nullptr)));

	mGame.getPlayerScore()[0] = 0;
	mGame.getPlayerScore()[1] = 0;
}

void CourtScene::onExit() {

}

void CourtScene::onKeyDown(SDL_KeyboardEvent& event) {
	switch (event.keysym.sym)
	{
	case SDLK_w:
		mLeftPaddle.setMovement(Paddle::Movement::UP);
		break;
	case SDLK_s:
		mLeftPaddle.setMovement(Paddle::Movement::DOWN);
		break;

	}
}

void CourtScene::onKeyUp(SDL_KeyboardEvent& event) {
	switch (event.keysym.sym){
	case SDLK_w:
		if (mLeftPaddle.isMoving(Paddle::Movement::UP)) {
			mLeftPaddle.setMovement(Paddle::Movement::STILL);
		}
		break;
	case SDLK_s:
		if (mLeftPaddle.isMoving(Paddle::Movement::DOWN)) {
			mLeftPaddle.setMovement(Paddle::Movement::STILL);
		}
		break;
	}
}

void CourtScene::addPlayerScore(int playerIndex) {
	resetEntities();
	auto& scores = mGame.getPlayerScore();
	scores[playerIndex]++;
	if (playerIndex == 0) {
		mLScore.setValue(scores[playerIndex]);
	}
	else {
		mRScore.setValue(scores[playerIndex]);
	}
	mRemainingPauseTicks = PAUSE_TICKS;
	if (scores[playerIndex] > 9) {
		mGame.setScene(std::make_shared<EndScreen>(mGame));
	}
}

void CourtScene::resetEntities() {
	const auto& halfResolution = mGame.getHalfResolution();

	const auto& ballBox = mBall.getBoundingBox();
	mBall.setX(halfResolution[0] - ballBox.getExtentX());
	mBall.setY(halfResolution[1] - ballBox.getExtentY());

	int random = rand() % 4;
	switch (random)
	{
	case 0:
		mBall.setDirection({ 0.5f,0.5f });
		break;
	case 1:
		mBall.setDirection({ 0.5f,-0.5f });
		break;
	case 2:
		mBall.setDirection({ -0.5f,0.5f });
		break;
	case 3:
		mBall.setDirection({ -0.5f,-0.5f });
	}
	mBall.setVelocity(ball::INITAL_V);

	const auto& paddleBox = mLeftPaddle.getBoundingBox();
	mLeftPaddle.setY(halfResolution[1] - paddleBox.getExtentY());
	mAiPaddle.setY(halfResolution[1] - paddleBox.getExtentY());
}