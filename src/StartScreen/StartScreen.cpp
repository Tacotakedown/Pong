#include "StartScreen.h"
#include "Game/game.h"
#include "CourtScene/CourtScene.h"

#include "SDL.h"

StartScreen::StartScreen(Game& game) : mGame(game), mTopicTexture(nullptr), mVeryMotivationalText(nullptr), mLeftPlayerKeybinds(nullptr), mVeryMotivationalTextLine2(nullptr), mVeryMotivationalTextLine3(nullptr), mVeryMotivationalTextLine4(nullptr), mContinueInstructions(nullptr)
{
	mTopicTexture = mGame.createLargeText("PONG");
	mLeftPlayerKeybinds = mGame.createText("Use W and S to control your Paddle (Left)");
	mContinueInstructions = mGame.createText("Press space to start");
	mVeryMotivationalText = mGame.createSmallText("In this world there are winners and losers, it just so happens that this AI is a winner. there has to be losers for there to be winners.");
	mVeryMotivationalTextLine2 = mGame.createSmallText("I mean, sure, you can call it a game, but let's be real, you're basically just a glorified ball chaser in this scenario.");
	mVeryMotivationalTextLine3 = mGame.createSmallText("And hey, think of it this way: you're getting the unique privilege of playing against a Pong legend.");
	mVeryMotivationalTextLine4 = mGame.createSmallText("It's like your own personal masterclass in losing. Don't cry too hard about it though.");
}

StartScreen::~StartScreen()
{
	SDL_DestroyTexture(mTopicTexture);
	SDL_DestroyTexture(mLeftPlayerKeybinds);
	SDL_DestroyTexture(mContinueInstructions);
	SDL_DestroyTexture(mVeryMotivationalText);
	SDL_DestroyTexture(mVeryMotivationalTextLine2);
	SDL_DestroyTexture(mVeryMotivationalTextLine3);
	SDL_DestroyTexture(mVeryMotivationalTextLine4);
}

void StartScreen::onDraw(SDL_Renderer& renderer)
{
	SDL_Rect rect{ 0, 100, 0, 0 };
	SDL_QueryTexture(mTopicTexture, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	SDL_RenderCopy(&renderer, mTopicTexture, nullptr, &rect);

	SDL_QueryTexture(mLeftPlayerKeybinds, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	rect.y = 200;
	SDL_RenderCopy(&renderer, mLeftPlayerKeybinds, nullptr, &rect);

	SDL_QueryTexture(mContinueInstructions, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	rect.y = 400;
	SDL_RenderCopy(&renderer, mContinueInstructions, nullptr, &rect);

	SDL_QueryTexture(mVeryMotivationalText, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	rect.y = 500;
	SDL_RenderCopy(&renderer, mVeryMotivationalText, nullptr, &rect);

	SDL_QueryTexture(mVeryMotivationalTextLine2, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	rect.y = 520;
	SDL_RenderCopy(&renderer, mVeryMotivationalTextLine2, nullptr, &rect);

	SDL_QueryTexture(mVeryMotivationalTextLine3, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	rect.y = 540;
	SDL_RenderCopy(&renderer, mVeryMotivationalTextLine3, nullptr, &rect);

	SDL_QueryTexture(mVeryMotivationalTextLine4, nullptr, nullptr, &rect.w, &rect.h);
	rect.x = (500 - (rect.w / 2));
	rect.y = 560;
	SDL_RenderCopy(&renderer, mVeryMotivationalTextLine4, nullptr, &rect);
}

void StartScreen::onUpdate() {

}
void StartScreen::onEnter() {

}
void StartScreen::onExit() {

}
void StartScreen::onKeyDown(SDL_KeyboardEvent& event) {

}


void StartScreen::onKeyUp(SDL_KeyboardEvent& event)
{
	switch (event.keysym.sym)
	{
	case SDLK_SPACE:
		mGame.setScene(std::make_shared<CourtScene>(mGame));
		break;
	}
}