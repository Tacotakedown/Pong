#ifndef GAME_H
#define GAME_H

#include "Scene/Scene.h"
#include <array>
#include <string>

using std::string;

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
struct _TTF_Font;

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	Game(Game&&) = delete;

	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;

	~Game();

	void start();

	void setScene(ScenePtr scene);

	SDL_Texture* createText(const string& text);

	const std::array<int, 2>& getResolution() const {
		return mResolution;
	}
	
	const std::array<int, 2>& getHalfResolution() const {
		return mHalfResolution;
	}

	const std::array<int, 2>& getPlayerScore() {
		return mPlayerScore;
	}

private:
	SDL_Window*			mWindow;
	SDL_Renderer*		mRenderer;
	_TTF_Font*			mFont;
	ScenePtr			mScene;
	std::array<int, 2>	mResolution;
	std::array<int, 2>	mHalfResolution;
	std::array<int, 2>	mPlayerScore;
};

#endif