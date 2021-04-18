#include "Interactive.h"
#include "Throw.h"
#include "Player.h"

Interactive::Interactive()
{
}
Interactive::~Interactive()
{
}
void Interactive::SinglePlayer(Results* results, char first)
{
	short int current_player = first;
	Throw new_Throw;

	for (int i{}; i < 13; i++)
	{
		players[0]->Reset_Score();
		players[1]->Reset_Score();
		while (players[0]->Get_Score() != 0 && players[1]->Get_Score() != 0 && players[0]->Get_Wins() != 7 && players[1]->Get_Wins() != 7)
		{
			int temp_score = players[current_player]->Get_Score();
			for (short int shots{}; shots < 2; shots++)
			{
				for (short int throws{}; throws < 3; throws++)
				{
					int hit{};
					int strat{};
					switch (current_player)
					{
					case 0:
						new_Throw.Strategy(players[current_player]);
						std::cout << "AI TURN!!!   SCORE: " << temp_score;
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
						}; break;

					case 1:
						std::cout << players[current_player]->Get_Name() << " YOUR TURN!!\n";
						std::cout << "SCORE: " << temp_score << "\n\n" << "AI SCORE: " << players[0]->Get_Score() << "\n\n";

						do
						{
							std::cout << "Would you like to Throw for \n1) Single \n2) Double \n3) Triple \n4) Bull \nChoice: ";
							std::cin >> strat;
							std::cout << std::endl;
						} while (strat < 1 || strat > 4);
						std::cout << std::endl;
						strat--;
						players[current_player]->Set_Strat(strat);

						int target{};

						if (strat != 3)
						{
							do
							{
								std::cout << "Please enter your target: ";
								std::cin >> target;
								std::cout << std::endl;
							} while (target < 1 || target > 20);

							players[current_player]->Set_Target(target);
						}
						strat--;

						switch (players[current_player]->Get_Strat())
						{
						case 0: hit = new_Throw.Throw_Single(players[current_player]); break;
						case 1: hit = new_Throw.Throw_Double(players[current_player]); break;
						case 2: hit = new_Throw.Throw_Treble(players[current_player]); break;
						case 3: hit = new_Throw.Throw_Bull(players[current_player]); break;
						}; break;
					}

					int strat_check = players[current_player]->Get_Strat() + 1;
					if (hit == (players[current_player]->Get_Target() * strat_check))
					{
						std::cout << "\nTarget Hit!!" << std::endl;
						system("Pause");
					}
					else if (players[current_player]->Get_Strat() == 3 && hit == 50)
					{
						std::cout << "\nTarget Hit!!" << std::endl;
						system("Pause");
					}
					else
					{
						std::cout << "\nTarget Missed!!";
						std::cout << "\nHit: " << hit << std::endl;
						system("Pause");
					}
					// score = players[current_player]->Check_Score(hit);

					temp_score = temp_score - hit;
					if (temp_score == 1 || temp_score < 0)
					{
						std::cout << "\nBust!\n";
						temp_score = 50;
						break;
					}
					else if (temp_score == 0 && players[current_player]->Get_Strat() != 0)
					{
						break;
					}
				}

				players[current_player]->Change_Score(temp_score);
				if (players[current_player]->Get_Score() == 0 && players[current_player]->Get_Strat() != 0)
				{
					break;
				}
				system("CLS");
			}

			current_player = !current_player;

			if (players[0]->Get_Score() == 0 && players[0]->Get_Strat() != 0)
			{
				players[0]->Add_Win();

				std::cout << "Winner!!: " << players[0]->Get_Name() << "\n\n";
			}
			else if (players[1]->Get_Score() == 0 && players[1]->Get_Strat() != 0)
			{
				players[1]->Add_Win();
				std::cout << "Winner!!: " << players[1]->Get_Name() << "\n\n";
			}
			system("Pause");
			system("CLS");
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
void Interactive::MultiPlayer(Results* results, char first)
{
	short int current_player = first;
	Throw new_Throw;

	for (int i{}; i < 13; i++)
	{
		players[0]->Reset_Score();
		players[1]->Reset_Score();
		while (players[0]->Get_Score() != 0 && players[1]->Get_Score() != 0 && players[0]->Get_Wins() != 7 && players[1]->Get_Wins() != 7)
		{
			for (short int shots{}; shots < 2; shots++)
			{
				int temp_score = players[current_player]->Get_Score();
				for (short int throws{}; throws < 3; throws++)
				{
					int hit{};
					int strat{};
					std::cout << players[current_player]->Get_Name() << " YOUR TURN!!\n";
					std::cout << "SCORE: " << temp_score << "\n\n" << players[!current_player]->Get_Name() << " SCORE: " << players[!current_player]->Get_Score() << "\n\n";

					do
					{
						std::cout << "Would you like to Throw for \n1) Single \n2) Double \n3) Triple \n4) Bull \nChoice: ";
						std::cin >> strat;
						std::cout << std::endl;
					} while (strat < 1 || strat > 4);
					strat--;
					players[current_player]->Set_Strat(strat);

					int target{};

					if (strat != 3)
					{
						do
						{
							std::cout << "Please enter your target: ";
							std::cin >> target;
							std::cout << std::endl;
						} while (target < 1 || target > 20);

						players[current_player]->Set_Target(target);
					}
					strat--;

					switch (players[current_player]->Get_Strat())
					{
					case 0: hit = new_Throw.Throw_Single(players[current_player]); break;
					case 1: hit = new_Throw.Throw_Double(players[current_player]); break;
					case 2: hit = new_Throw.Throw_Treble(players[current_player]); break;
					case 3: hit = new_Throw.Throw_Bull(players[current_player]); break;
					}
					int strat_check = players[current_player]->Get_Strat() + 1;
					if (hit == (players[current_player]->Get_Target() * strat_check))
					{
						std::cout << "\nTarget Hit!!" << std::endl;
						system("Pause");
					}
					else if (players[current_player]->Get_Strat() == 3 && hit == 50)
					{
						std::cout << "\nTarget Hit!!" << std::endl;
						system("Pause");
					}
					else
					{
						std::cout << "\nTarget Missed!!";
						std::cout << "\nHit: " << hit << std::endl;
						system("Pause");
					}
					// score = players[current_player]->Check_Score(hit);

					temp_score = temp_score - hit;
					if (temp_score == 1 || temp_score < 0)
					{
						std::cout << "\nBust!\n";
						temp_score = 50;
						break;
					}
					else if (temp_score == 0 && players[current_player]->Get_Strat() != 0)
					{
						break;
					}
				}
				players[current_player]->Change_Score(temp_score);
				//system("Pause");
				if (players[current_player]->Get_Score() == 0 && players[current_player]->Get_Strat() != 0)
				{
					break;
				}
				system("CLS");
			}
			current_player = !current_player;
		}
		if (players[0]->Get_Score() == 0 && players[0]->Get_Strat() != 0)
		{
			players[0]->Add_Win();

			std::cout << "Winner!!: " << players[0]->Get_Name() << "\n\n";
		}
		else if (players[1]->Get_Score() == 0 && players[1]->Get_Strat() != 0)
		{
			players[1]->Add_Win();
			std::cout << "Winner!!: " << players[1]->Get_Name() << "\n\n";
		}
		system("Pause");
		system("CLS");
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
}
void Interactive::First_Player(Player* current_player, char position)
{
	players[position] = current_player;
}
void Interactive::Set_Winner(std::string player_name)
{
	winner = player_name;
}