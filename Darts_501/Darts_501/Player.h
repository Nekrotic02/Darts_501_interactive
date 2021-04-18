#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string name;
	short int score;
	short int accuracy;
	short int throws;
	float wins;
	short int target;

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
	float Get_Wins();

	void Reset_Score();

	void Set_Strat(char strat);
	char Get_Strat();

	bool Check_Score(short int hit);

	void Reset_Wins();
};
