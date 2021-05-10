#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string name;
	short int score;
	short int accuracy;
	int wins;
	short int target;
	short int round_wins;

	char strat;

public:
	Player(std::string PlayerName, short int accuracy);
	~Player();

	std::string Get_Name();
	short int Get_Accuracy();
	int Get_Score();
	void Change_Score(int hit);
	void Set_Target(short int Target);
	short int Get_Target();
	void newGame();
	void Add_Win();
	int Get_Wins();

	void Reset_Score();

	void Set_Strat(char strat);
	char Get_Strat();

	void Reset_Wins();

	void Increase_Round_Win();
	void Reset_Round_Wins();
	int Get_Round_Wins();
};
