#pragma once
#include "Player.h"
#include "Results.h"
#include <iostream>
class Results;
class Game
{
private:
	int game_type = 501;
	std::string winner;
public:
	Player* players[2];
public:
	Game();
	~Game();
	void Play_Game(Results* results, char first);
	void First_Player(Player* current_player, short int position);
	void Set_Winner(std::string player_name);
	std::string Get_Winner();
};
