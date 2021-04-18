#pragma once
// #include "Game.h"
#include "Player.h"
class Throw
{
public:
	int Throw_Bull(Player* current_player);
	int Throw_Single(Player* current_player);
	int Throw_Double(Player* current_player);
	int Throw_Treble(Player* current_player);
	void Strategy(Player* current_player);
};
