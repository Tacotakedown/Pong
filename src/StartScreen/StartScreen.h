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
	SDL_Texture* mContinueInstructions;
	SDL_Texture* mVeryMotivationalText;
	SDL_Texture* mVeryMotivationalTextLine2;
	SDL_Texture* mVeryMotivationalTextLine3;
	SDL_Texture* mVeryMotivationalTextLine4;
};


#endif // !STARTSCREEN_H



