#include "Game.h"
#include "Throw.h"
#include "Board.h"
#include "Results.h"
#include <iostream>

Game::Game()
{
	// object creation initialisation of variables
	players[0] = NULL;
	players[1] = NULL;
	game_type = 501;
}

Game::~Game()
{
}

void Game::Play_Game(Results* results, char first)
{
	short int current_player = first; // take who ever is first and store it as the current player value to access the pointer array
	Throw new_Throw; // create a new throw object to throw the darts

	for (int i = 0; i < 13; i++) // playing 13 sets per game
	{
		players[0]->Reset_Score(); // reset the score upon successful complettion of a game
		players[1]->Reset_Score();
		while (players[0]->Get_Score() != 0 && players[1]->Get_Score() != 0 && players[0]->Get_Wins() != 7 && players[1]->Get_Wins() != 7) // break if a player has won the significant amount of games over the other
		{
			while (players[0]->Get_Round_Wins() != 3 && players[1]->Get_Round_Wins() != 3) // playing for who gets the best of 5 rounds
			{
				for (short int shots{}; shots < 2; shots++) // for two sets of 3 darts to throw
				{
					int temp_score = players[current_player]->Get_Score(); // takes the current player score and stores it into a temp score to work with incase they bust
					short int hit = NULL; // initialise the hit variable to subtract from the temp score
					for (short int throws{}; throws < 3; throws++) // throws three darts
					{
						new_Throw.Strategy(players[current_player]); // calculate the current player AI strategy to set the single, double or triple target as well as the target value

						if (players[current_player]->Get_Score() == 50) // if the player score is = 50 throw a bull
						{
							hit = new_Throw.Throw_Bull(players[current_player]);
						}
						else
						{
							switch (players[current_player]->Get_Strat()) // depending on the multiplier that has been targetted throw for the value targetted
							{
							case 0: hit = new_Throw.Throw_Single(players[current_player]); break;
							case 1: hit = new_Throw.Throw_Double(players[current_player]); break;
							case 2: hit = new_Throw.Throw_Treble(players[current_player]); break;
							}
						}

						temp_score = temp_score - hit; // take the hit away from the temp score for checking if it was valid
						if (temp_score == 1 || temp_score < 0) // bust if the player is in the negative or has a value of 1 and set the score to 50
						{
							temp_score = temp_score + hit;
							break;
						}
						else if (temp_score == 0) // valid if they won
						{
							break;
						}
					}
					players[current_player]->Change_Score(temp_score); // to the current temp score
					if (players[current_player]->Get_Score() == 0 && players[current_player]->Get_Strat() != 0 && players[current_player]->Get_Strat() != 2) // break the loop if the player has won the game on a double
					{
						players[current_player]->Increase_Round_Win();
						break;
					}
				}
				if (players[current_player]->Get_Score() == 0)
				{
					players[0]->Reset_Score();
					players[1]->Reset_Score();
					break;
				}
				current_player = !current_player; // swap the current player value to access the other pointer in the array
			}
		}
		if (players[0]->Get_Round_Wins() >= 3) // if player 1 won then add the win
		{
			players[0]->Add_Win();
		}
		else if (players[1]->Get_Round_Wins() >= 3) // if player 2 won then add the win
		{
			players[1]->Add_Win();
		}
		players[0]->Reset_Round_Wins();
		players[1]->Reset_Round_Wins();
	}
	bool champ;
	if (players[0]->Get_Wins() > players[1]->Get_Wins()) // check who was the winner player 1 or 2 to pass into the results
	{
		champ = false;
	}
	else
	{
		champ = true;
	}
	results->Add_Results(champ, players[0], players[1]); // add the results by passing in the players and who was the winner into the add results function
	players[0]->Reset_Wins(); // reset wins for a new game
	players[1]->Reset_Wins();
}
void Game::First_Player(Player* current_player, short int position)
{
	players[position] = current_player; // sets the players position into the array
}

std::string Game::Get_Winner()
{
	return winner; // return the winner
}
void Game::Set_Winner(std::string player_name)
{
	winner = player_name; // sets the player name as the winner
}