#include "Game.h"
#include "Throw.h"
#include "Board.h"
#include "Results.h"
#include <iostream>

Game::Game()
{
	players[0] = NULL;
	players[1] = NULL;
	game_type = 501;
}

Game::~Game()
{
}

void Game::Play_Game(Results* results, char first)
{
	short int current_player = first;
	Throw new_Throw;

	for (int i = 0; i < 13; i++) // playing 13 sets per game
	{
		players[0]->Reset_Score();
		players[1]->Reset_Score();
		while (players[0]->Get_Score() != 0 && players[1]->Get_Score() != 0 && players[0]->Get_Wins() != 7 && players[1]->Get_Wins() != 7)
		{
			for (short int shots{}; shots < 2; shots++)
			{
				int temp_score = players[current_player]->Get_Score();
				short int hit = NULL;
				for (short int throws{}; throws < 3; throws++)
				{
					bool score{};

					new_Throw.Strategy(players[current_player]);

					if (players[current_player]->Get_Score() == 50)
					{
						hit = new_Throw.Throw_Bull(players[current_player]);
					}
					else
					{
						switch (players[current_player]->Get_Strat())
						{
						case 0: hit = new_Throw.Throw_Single(players[current_player]); break;
						case 1: hit = new_Throw.Throw_Double(players[current_player]); break;
						case 2: hit = new_Throw.Throw_Treble(players[current_player]); break;
						}
					}

					temp_score = temp_score - hit;
					if (temp_score == 1 || temp_score < 0)
					{
						temp_score = 50;
						break;
					}
					else if (temp_score == 0)
					{
						break;
					}
				}
				players[current_player]->Change_Score(temp_score);
				if (players[current_player]->Get_Score() == 0 && players[current_player]->Get_Strat() != 0)
				{
					break;
				}
			}
			current_player = !current_player;
			// std::cout << "Player 1 Score: " << players[0]->Get_Score() << std::endl;
			// std::cout << "Player 2 Score: " << players[1]->Get_Score() << std::endl;
		}
		if (players[0]->Get_Score() == 0 && players[0]->Get_Strat() != 0)
		{
			players[0]->Add_Win();
		}
		else if (players[1]->Get_Score() == 0 && players[1]->Get_Strat() != 0)
		{
			players[1]->Add_Win();
		}
	}
	bool champ;
	if (players[0]->Get_Wins() > players[1]->Get_Wins())
	{
		champ = false;
	}
	else
	{
		champ = true;
	}
	results->Add_Results(champ, players[0], players[1]);
	players[0]->Reset_Wins();
	players[1]->Reset_Wins();
}
void Game::First_Player(Player* current_player, short int position)
{
	players[position] = current_player;
}

std::string Game::Get_Winner()
{
	return winner;
}
void Game::Set_Winner(std::string player_name)
{
	winner = player_name;
}