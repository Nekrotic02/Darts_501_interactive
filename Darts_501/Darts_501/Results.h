#pragma once
#include "Game.h"
class Game;
class Results
{
private:
	float playerOne[7] = { 0 };
	float playerTwo[7] = { 0 };
	float frequencies[14] = { 0 };
public:

	Results();
	~Results();
	void Add_Results(bool champ, Player* player_1, Player* player_2);
	void calculate(int games);
	void get_results(int games, Player* player_1, Player* player_2);
};
