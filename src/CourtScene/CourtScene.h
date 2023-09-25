#ifndef COURTSCENE_H
#define COURTSCENE_H

#include "Ball/ball.h"
#include "CenterDivider/CenterDivider.h"
#include "Goal/Goal.h"
#include "Paddle/Paddle.h"
#include "Draw/draw.h"
#include "Scene/Scene.h"
#include "Score/Score.h"
#include "AiPaddle/AiPaddle.h"

#include <array>

class Game;
class CourtScene : public Scene
{
public:
	static const int BOX_WIDTH = 20;
	static const int WALL_HEIGHT = BOX_WIDTH;
	static const int PADDLE_HEIGHT = 100;
	static const int EDGE_OFFSET = 30;

	CourtScene(Game& game);
	virtual ~CourtScene();

	void onDraw(SDL_Renderer& renderer) override;
	void onUpdate() override;
	void onEnter() override;
	void onExit() override;
	void onKeyDown(SDL_KeyboardEvent& event) override;
	void onKeyUp(SDL_KeyboardEvent& event) override;

	void addPlayerScore(int playerIndex);
	void resetEntities();

	const Game& getGame() const{
		return mGame;
	}
	Game& getGame(){
		return mGame;
	}
	
	const draw& getTopWall() const {
		return mTopWall;
	}
	draw& getTopWall() {
		return mTopWall;
	}

	const draw& getBottomWall() const {
		return mBottomWall;
	}
	draw getBottomWall() {
		return mBottomWall;
	}

	const CenterLine& getCenterDivider() const {
		return mCenterLine;
	}
	CenterLine& getCenterDivider() {
		return mCenterLine;
	}

	const Paddle& getLPaddle() const {
		return mLeftPaddle;
	}
	Paddle& getLPaddle() {
		return mLeftPaddle;
	}

	const AiPaddle& getAiPaddle() const {
		return mAiPaddle;
	}
	AiPaddle& getAiPaddle() {
		return mAiPaddle;
	}

	const Goal& getLeftGoal() const {
		return mLGoal;
	}
	Goal& getLeftGoal() {
		return mLGoal;
	}

	const Goal& getRightGoal() const {
		return mRGoal;
	}
	Goal& getRightGoal() {
		return mRGoal;
	}


private:
	Game&			mGame;
	draw			mBottomWall;
	draw			mTopWall;
	CenterLine		mCenterLine;
	Paddle			mLeftPaddle;
	AiPaddle		mAiPaddle;
	ball			mBall;
	Goal			mLGoal;
	Goal			mRGoal;
	Score			mLScore;
	Score			mRScore;
	int				mRemainingPauseTicks;

};


#endif // !COURTSCENE_H

