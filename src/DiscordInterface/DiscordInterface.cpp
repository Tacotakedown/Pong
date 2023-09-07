#include "DiscordInterface.h"


void DiscordInterface::InitalizeDiscord() {
	DiscordEventHandlers Handles;
	memset(&Handles, 0, sizeof(Handles));
	Discord_Initialize("1149362769062269018", &Handles, 1, NULL);

}
void DiscordInterface::UpdatePresence( const char* state, const string& score)  {
    DiscordRichPresence discordPresence;
    const char* c = score.c_str();
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = c ? c : "";
    discordPresence.details = state;
    discordPresence.largeImageText = "PONG";
    discordPresence.smallImageText = "PONG";
    discordPresence.smallImageKey = "large";
    discordPresence.largeImageKey = "large";
    Discord_UpdatePresence(&discordPresence);
}