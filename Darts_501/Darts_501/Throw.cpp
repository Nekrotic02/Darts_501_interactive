#include "Throw.h"
#include "Board.h"
#include <iostream>

int Throw::Throw_Bull(Player* current_player)
{
	int random = rand() % 100 + 1;

	if (random <= current_player->Get_Accuracy())
	{
		return 50;
	}
	else if (random <= 85)
	{
		return 25;
	}
	else
	{
		return rand() % 20 + 1;
	}
}

int Throw::Throw_Single(Player* current_player)
{
	int random = rand() % 100 + 1;

	if (current_player->Get_Target() == 25)
	{
		if (random <= current_player->Get_Accuracy())
		{
			return 25;
		}
		else if (random <= 90)
		{
			return 50;
		}
		else
		{
			return rand() % 20 + 1;
		}
	}
	else
	{
		if (random <= current_player->Get_Accuracy())
		{
			return current_player->Get_Target();
		}
		else if (random <= 92)
		{
			return Board::Board_Layout[0][current_player->Get_Target()];
		}
		else if (random <= 96)
		{
			return Board::Board_Layout[1][current_player->Get_Target()];
		}
		else if (random <= 98)
		{
			return 3 * current_player->Get_Target();
		}
		else
		{
			return 2 * current_player->Get_Target();
		}
	}
}

int Throw::Throw_Double(Player* current_player)
{
	int random = rand() % 100 + 1;

	if (random <= current_player->Get_Accuracy())
	{
		return 2 * current_player->Get_Target();
	}
	else if (random <= 85)
	{
		return 0;
	}
	else if (random <= 90)
	{
		return current_player->Get_Target();
	}
	else if (random <= 93)
	{
		return 2 * Board::Board_Layout[0][current_player->Get_Target()];
	}
	else if (random <= 96)
	{
		return Board::Board_Layout[1][current_player->Get_Target()];
	}
	else if (random <= 98)
	{
		return Board::Board_Layout[0][current_player->Get_Target()];
	}
	else
	{
		return Board::Board_Layout[1][current_player->Get_Target()];
	}
}

int Throw::Throw_Treble(Player* current_player)
{
	int random = rand() % 100 + 1;

	if (random <= current_player->Get_Accuracy())
	{
		return 3 * current_player->Get_Target();
	}
	else if (random <= 90)
	{
		return current_player->Get_Target();
	}
	else if (random <= 93)
	{
		return 3 * Board::Board_Layout[0][current_player->Get_Target()];
	}
	else if (random <= 96)
	{
		return 3 * Board::Board_Layout[1][current_player->Get_Target()];
	}
	else if (random <= 98)
	{
		return Board::Board_Layout[0][current_player->Get_Target()];
	}
	else
	{
		return Board::Board_Layout[1][current_player->Get_Target()];
	}
}

void Throw::Strategy(Player* current_player)
{
	if (current_player->Get_Score() > 61)
	{
		current_player->Set_Target(11);
		current_player->Set_Strat(0);
	}
	else
	{
		if (current_player->Get_Score() % 2 == 0 && current_player->Get_Score() != 0)
		{
			if (current_player->Get_Score() > 50)
			{
				current_player->Set_Target(current_player->Get_Score() - 50);
				current_player->Set_Strat(0);
			}
			else if (current_player->Get_Score() == 50)
			{
				current_player->Set_Target(50);
				current_player->Set_Strat(0);
			}
			else
			{
				if (current_player->Get_Score() > 40)
				{
					current_player->Set_Target(current_player->Get_Score() - 40);
					current_player->Set_Strat(0);
				}
				else
				{
					current_player->Set_Target(current_player->Get_Score() / 2);
					current_player->Set_Strat(0);
				}
			}
		}
		else
		{
			current_player->Set_Target(1);
			current_player->Set_Strat(1);
		}
	}
}