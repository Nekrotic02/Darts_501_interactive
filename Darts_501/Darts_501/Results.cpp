#include "Results.h"
#include "Player.h"
#include "Game.h"

Results::Results()
{
}
Results::~Results()
{
}
void Results::Add_Results(bool winner, Player* player_1, Player* player_2)
{
	if (winner == 0)
	{
		// dependong on if the winner is player 1 the add the number of wins that player 2 got to the playerTwo array
		if (player_2->Get_Wins() == 0)
		{
			playerTwo[0]++;
		}
		else if (player_2->Get_Wins() == 1)
		{
			playerTwo[1]++;
		}
		else if (player_2->Get_Wins() == 2)
		{
			playerTwo[2]++;
		}
		else if (player_2->Get_Wins() == 3)
		{
			playerTwo[3]++;
		}
		else if (player_2->Get_Wins() == 4)
		{
			playerTwo[4]++;
		}
		else if (player_2->Get_Wins() == 5)
		{
			playerTwo[5]++;
		}
		else if (player_2->Get_Wins() == 6)
		{
			playerTwo[6]++;
		}
	}
	else if (winner == 1)
	{
		// if player 2 has won the game then check to see how many games player 1 won the game in relation
		if (player_1->Get_Wins() == 0)
		{
			playerOne[6]++;
		}
		else if (player_1->Get_Wins() == 1)
		{
			playerOne[5]++;
		}
		else if (player_1->Get_Wins() == 2)
		{
			playerOne[4]++;
		}
		else if (player_1->Get_Wins() == 3)
		{
			playerOne[3]++;
		}
		else if (player_1->Get_Wins() == 4)
		{
			playerOne[2]++;
		}
		else if (player_1->Get_Wins() == 5)
		{
			playerOne[1]++;
		}
		else if (player_1->Get_Wins() == 6)
		{
			playerOne[0]++;
		}
	}
}

void Results::calculate(int games)
{
	// loop for player 2 wins
	// calculate the success rate depending on the number of games played and the number of games that were won at that frequencies
	for (int i{}; i <= 6; i++)
	{
		float result = (playerTwo[i] / games) * 100.f;
		frequencies[i] = result;
	}
	int freq = 7;
	for (int i{}; i <= 6; i++)
	{
		float result = (playerOne[i] / games) * 100.f;
		frequencies[freq] = result;
		freq++;
	}
}
void  Results::get_results(int games, Player* player_1, Player* player_2)
{
	// display the % results of those frequencies
	std::cout << "Results from " << games << " Simulations:\n\n";
	std::cout << player_1->Get_Name() << ":" << player_2->Get_Name() << "    Frequency    \n";
	std::cout << "   6:7        " << frequencies[0] << "%\n";
	std::cout << "   5:7        " << frequencies[1] << "%\n";
	std::cout << "   4:7        " << frequencies[2] << "%\n";
	std::cout << "   3:7        " << frequencies[3] << "%\n";
	std::cout << "   2:7        " << frequencies[4] << "%\n";
	std::cout << "   1:7        " << frequencies[5] << "%\n";
	std::cout << "   0:7        " << frequencies[6] << "%\n";
	std::cout << "   7:0        " << frequencies[7] << "%\n";
	std::cout << "   7:1        " << frequencies[8] << "%\n";
	std::cout << "   7:2        " << frequencies[9] << "%\n";
	std::cout << "   7:3        " << frequencies[10] << "%\n";
	std::cout << "   7:4        " << frequencies[11] << "%\n";
	std::cout << "   7:5        " << frequencies[12] << "%\n";
	std::cout << "   7:6        " << frequencies[13] << "%\n\n";
}