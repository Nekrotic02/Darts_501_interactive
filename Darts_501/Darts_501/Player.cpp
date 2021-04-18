#include "Player.h"
#include "Board.h"

Player::Player(std::string PlayerName, short int Accuracy)
{
	score = 501;
	name = PlayerName;
	accuracy = Accuracy;
	wins = 0;
	target = 0;
	strat = 0;
}
Player::~Player()
{
}
std::string Player::Get_Name()
{
	return name;
}

short int Player::Get_Accuracy()
{
	return accuracy;
}

int Player::Get_Score()
{
	return score;
}

void Player::Change_Score(int x)
{
	score = x;
}

void Player::Set_Target(short int ideal_target)
{
	target = ideal_target;
}

short int Player::Get_Target()
{
	return target;
}

void Player::newGame()
{
	target = NULL;
}

void Player::Add_Win()
{
	wins++;
}

float Player::Get_Wins()
{
	return wins;
}

bool Player::Check_Score(short int hit)
{
	int check = score - hit;

	if (check == 1 || check < 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

char Player::Get_Strat()
{
	return strat;
}

void Player::Set_Strat(char x)
{
	strat = x;
}

void Player::Reset_Wins()
{
	wins = 0;
}

void Player::Reset_Score()
{
	score = 501;
}