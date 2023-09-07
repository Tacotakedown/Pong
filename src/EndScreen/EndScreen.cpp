#include "EndScreen.h"
#include "StartScreen/StartScreen.h"
#include "SDL.h"
#include <memory>
#include "DiscordInterface/DiscordInterface.h"

EndScreen::EndScreen(Game& game) : mGame(game), mTopicTexture(nullptr), mEndgameTexture(nullptr), mWinnerTexture(nullptr), mEndResultTexture(nullptr), mResultScoreTexture(nullptr), mInstructionsTexture(nullptr)
{
	const auto& scores = mGame.getPlayerScore();

	mTopicTexture = mGame.createText("RESULTS");
	mEndgameTexture = mGame.createText("Game has ended");
	if (scores[0] > 9) {
		mWinnerTexture = mGame.createText("Left player wins");
	}
	else {
		mWinnerTexture = mGame.createText("Right player wins");
	}
	mEndResultTexture = mGame.createText("End results:");
	mResultScoreTexture = mGame.createText(std::to_string(scores[0]) + "-" + std::to_string(scores[1]));
	mInstructionsTexture = mGame.createText("Press Space to continue");
}

EndScreen::~EndScreen() {
	SDL_DestroyTexture(mTopicTexture);
	SDL_DestroyTexture(mEndgameTexture);
	SDL_DestroyTexture(mWinnerTexture);
	SDL_DestroyTexture(mEndResultTexture);
	SDL_DestroyTexture(mResultScoreTexture);
	SDL_DestroyTexture(mInstructionsTexture);
}
void EndScreen::onDraw(SDL_Renderer& renderer)
{
	// draw the topic of the game.
	SDL_Rect rect{ 0, 100, 0, 0 };
	SDL_QueryTexture(mTopicTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mTopicTexture, nullptr, &rect);

	rect.y = 200;
	SDL_QueryTexture(mEndgameTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mEndgameTexture, nullptr, &rect);

	rect.y = 240;
	SDL_QueryTexture(mWinnerTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mWinnerTexture, nullptr, &rect);

	rect.y = 300;
	SDL_QueryTexture(mEndResultTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mEndResultTexture, nullptr, &rect);

	rect.y = 340;
	SDL_QueryTexture(mResultScoreTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mResultScoreTexture, nullptr, &rect);

	rect.y = 500;
	SDL_QueryTexture(mInstructionsTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mInstructionsTexture, nullptr, &rect);
}

void EndScreen::onUpdate() {

}
void EndScreen::onEnter() {

}
void EndScreen::onExit() {

}
void EndScreen::onKeyDown(SDL_KeyboardEvent& event) {

}
void EndScreen::onKeyUp(SDL_KeyboardEvent& event) {
	switch (event.keysym.sym)
	{
	case SDLK_SPACE:mGame.setScene(std::make_shared<StartScreen>(mGame));
		break;
	}
}