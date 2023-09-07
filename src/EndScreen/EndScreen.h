#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include "Game/game.h"
#include "Scene/Scene.h"

class EndScreen final : public Scene
{
public:
	EndScreen(Game& game);
	~EndScreen();

	void onDraw(SDL_Renderer& renderer) override;
	void onUpdate() override;
	void onEnter() override;
	void onExit() override;
	void onKeyDown(SDL_KeyboardEvent& event) override;
	void onKeyUp(SDL_KeyboardEvent& event) override;

private:
	Game&			mGame;
	SDL_Texture*	mTopicTexture;
	SDL_Texture*	mEndgameTexture;
	SDL_Texture*	mWinnerTexture;
	SDL_Texture*	mEndResultTexture;
	SDL_Texture*	mResultScoreTexture;
	SDL_Texture*	mInstructionsTexture;
};


#endif // !ENDSCREEN_H




