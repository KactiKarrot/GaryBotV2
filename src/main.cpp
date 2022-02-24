#include "../deps/sleepy-discord/include/sleepy_discord/sleepy_discord.h"
#include "Constants.hpp"
#include "Token.hpp"
#include <iostream>

class MyClientClass : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;

	SleepyDiscord::Channel loganDMChannel = createDirectMessageChannel("472719099349434379");
	
	void onMessage(SleepyDiscord::Message message) override {
		if (message.content.find("<@!" + Constants::kKarrotID + ">") != std::string::npos) {
			SleepyDiscord::Server server = getServer(message.serverID);
			sendMessage(loganDMChannel, "You were mentioned in " + server.name + " by " + 
				message.author.username + message.author.discriminator + ": " + message.content);
		}
	}
};

int main() {
	MyClientClass client(Token::TOKEN, SleepyDiscord::USER_CONTROLED_THREADS);
	client.setIntents(SleepyDiscord::Intent::SERVER_MESSAGES);
	client.run();
}