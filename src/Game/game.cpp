#include "game.h"
#include "StartScreen/StartScreen.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include<iostream>
#include "DiscordInterface/DiscordInterface.h"

#define ERROR	-1
#define OK	   	 0

Game::Game() : mWindow(nullptr), mRenderer(nullptr), mFont(nullptr), mResolution({ 1000,800 }), mHalfResolution({ mResolution[0] / 2,mResolution[1] / 2 }), mPlayerScore({ 0,0 })
{

}

Game::~Game()
{
	TTF_CloseFont(mFont);
	SDL_DestroyWindow(mWindow);
	TTF_Quit();
	SDL_Quit();
}

void Game::start()
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cerr << "Unable to initalize SDL:" << SDL_GetError() << std::endl;
		return;
	}

	if (TTF_Init() == -1) {
		std::cerr << "Unable to initalize SDL_TTF:" << TTF_GetError() << std::endl;
		return;
	}

	mWindow = SDL_CreateWindow("PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mResolution[0], mResolution[1], SDL_WINDOW_SHOWN);
	if (mWindow == nullptr) {
		std::cerr << "Unable to create SDL Window:" << SDL_GetError() << std::endl;
		return;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == nullptr) {
		std::cerr << "Unable to create SDL renderer:" << SDL_GetError() << std::endl;
		return;
	}

	mFont = TTF_OpenFont(".\\font\\courbd.ttf", 28);
	if (mFont == nullptr) {
		std::cerr <<"Unable to load font:" << TTF_GetError() << std::endl;
	}

	mSmallFont = TTF_OpenFont(".\\font\\courbd.ttf", 12);
	if (mSmallFont == nullptr) {
		std::cerr << "Unable to load font:" << TTF_GetError() << std::endl;
	}

	mLargeFont = TTF_OpenFont(".\\font\\courbd.ttf", 40);
	if (mLargeFont == nullptr) {
		std::cerr << "Unable to load font:" << TTF_GetError() << std::endl;
	}

	DiscordInterface::InitalizeDiscord();

	setScene(std::make_shared<StartScreen>(*this));
	


	auto isRunning = true;
	SDL_Event event;
	while (isRunning)
	{
		Uint64 start = SDL_GetPerformanceCounter();

		while (SDL_PollEvent(&event) != 0) {
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				mScene->onKeyDown(event.key);
				break;
			case SDL_KEYUP:
				mScene->onKeyUp(event.key);
				break;
			}
		}
		

		mScene->onUpdate();

		SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

		mScene->onDraw(*mRenderer);

		Uint64 end = SDL_GetPerformanceCounter();

		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

		const auto& scores = getPlayerScore();
		DiscordInterface::UpdatePresence("Score", std::to_string(scores[0]) + "-" + std::to_string(scores[1]));

		SDL_RenderPresent(mRenderer);

		SDL_Delay(floor(16.666f - elapsedMS));
	}
}

void Game::setScene(ScenePtr scene) {
	if (scene == nullptr) {
		std::cerr << "Unable to set null as the active scene" << std::endl;
		return;
	}
	if (mScene) {
		mScene->onExit();
	}
	mScene = scene;
	
	mScene->onEnter();
}


SDL_Texture* Game::createText(const string& text) {
	SDL_Color color{ 0xff,0xff,0xff,0xff };
	auto surface = TTF_RenderText_Blended(mFont, text.c_str(), color);
	if (surface == nullptr) {
		std::cerr << "Unable to create surface with text: " << TTF_GetError() << std::endl;
		return nullptr;
	}

	auto texture = SDL_CreateTextureFromSurface(mRenderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr) {
		std::cerr << "Unable to create function from a text surface:" << SDL_GetError() << std::endl;
		return nullptr;
	}
	return texture;
}

SDL_Texture* Game::createSmallText(const string& text)
{
	SDL_Color color{ 0xff,0xff,0xff,0xff };
	auto surface = TTF_RenderText_Blended(mSmallFont, text.c_str(), color);
	if (surface == nullptr) {
		std::cerr << "Unable to create surface with text: " << TTF_GetError() << std::endl;
		return nullptr;
	}

	auto texture = SDL_CreateTextureFromSurface(mRenderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr) {
		std::cerr << "Unable to create function from a text surface:" << SDL_GetError() << std::endl;
		return nullptr;
	}
	return texture;
}

SDL_Texture* Game::createLargeText(const string& text)
{
	SDL_Color color{ 0xff,0xff,0xff,0xff };
	auto surface = TTF_RenderText_Blended(mLargeFont, text.c_str(), color);
	if (surface == nullptr) {
		std::cerr << "Unable to create surface with text: " << TTF_GetError() << std::endl;
		return nullptr;
	}

	auto texture = SDL_CreateTextureFromSurface(mRenderer, surface);
	SDL_FreeSurface(surface);
	if (texture == nullptr) {
		std::cerr << "Unable to create function from a text surface:" << SDL_GetError() << std::endl;
		return nullptr;
	}
	return texture;
}

