#ifndef DISCORDINTERFACE_H
#define DISCORDINTERFACE_H


#include "discord_register.h"
#include "discord_rpc.h"
#include "Game/game.h"
#include <Windows.h>
#include <array>

class DiscordInterface {
public:
	static void InitalizeDiscord();
	static void UpdatePresence(const char* state, const string& score);

private:
	Game& mGame;
};

#endif // !DISCORDINTERFACE_H


