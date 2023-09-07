#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "Scene/Scene.h"

struct SDL_Texture;

class Game;
class StartScreen : public Scene
{
public:
	StartScreen(Game& game);
	virtual ~StartScreen();

	void onDraw(SDL_Renderer& renderer) override;
	void onUpdate() override;
	void onEnter() override;
	void onExit() override;
	void onKeyDown(SDL_KeyboardEvent& event) override;
	void onKeyUp(SDL_KeyboardEvent& event) override;

private:
	Game& mGame;
	SDL_Texture* mTopicTexture;
	SDL_Texture* mLeftPlayerKeybinds;
	SDL_Texture* mRightPlayerKeybinds;
	SDL_Texture* mContinueInstructions;
};


#endif // !STARTSCREEN_H



