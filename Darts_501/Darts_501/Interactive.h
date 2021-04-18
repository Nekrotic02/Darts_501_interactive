#pragma once
#include "Player.h"
#include "Results.h"
#include <iostream>

class Interactive
{
private:
	int game_type = 501;
	std::string winner;
public:
	Player* players[2] = { 0 };
public:
	Interactive();
	~Interactive();
	void SinglePlayer(Results* results, char first);
	void MultiPlayer(Results* results, char first);
	void First_Player(Player* current_player, char position);
	void Set_Winner(std::string player_name);
};
