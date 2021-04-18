#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Game.h"
#include "Throw.h"
#include "Results.h"
#include "Int_Func.h"
using namespace std;

void Simulation()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Declarations and Player Object Creation
	std::string name;
	int accuracy{};
	cout << "Please enter Player 1 name: ";
	getline(cin, name);

	do
	{
		cout << endl;
		cout << "Please enter Player 1 Accuracy: ";
		cin >> accuracy;
		cout << endl;
	} while (accuracy < 0 || accuracy > 100);

	Player* player_1 = new Player(name, accuracy);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << endl;
	cout << "Please enter Player 2 name: ";
	getline(cin, name);
	do
	{
		cout << endl;
		cout << "Please enter Player 2 Accuracy: ";
		cin >> accuracy;
		cout << endl;
	} while (accuracy < 0 || accuracy > 100);

	Player* player_2 = new Player(name, accuracy);

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Number of games to play
	int games{};
	cout << "How many games do you want to play: ";
	cin >> games;
	cout << endl;

	int first{};
	do
	{
		cout << "Who Plays First?" << endl;
		cout << "1) " << player_1->Get_Name() << endl;
		cout << "2) " << player_2->Get_Name() << endl;
		cout << "Answer: ";
		cin >> first;
		cout << endl;
	} while (first < 1 || first > 2);

	// Who Plays First
	first = first - 1;
	Results* results = new Results;
	std::string winner;
	player_1->newGame();
	player_2->newGame();
	for (int loop = games; loop > 0; loop--)
	{
		Game* new_game = new Game;
		new_game->First_Player(player_1, 0);
		new_game->First_Player(player_2, 1);
		new_game->Play_Game(results, first);
	}
	results->calculate(games);
	results->get_results(games, player_1, player_2);
}

void Playable()
{
	while (true)
	{
		int playing{};
		int choice{};
		do
		{
			std::cout << "Please Choose \n1)SinglePlayer \n2)MultiPlayer \n\nChoice:";
			std::cin >> choice;
		} while (choice < 1 || choice > 2);

		switch (choice)
		{
		case 1:
			SinglePlayer();
			break;
		case 2:
			MultiPlayer();
			break;
		}

		do
		{
			std::cout << "Would you like to go again? \n1) Yes \n2) No \n\nChoice: ";
			std::cin >> playing;
			if (playing == 2)
			{
				break;
			}
		} while (playing < 1 || playing > 2);
	}
}

int main()
{
	while (true)
	{
		int choice{};
		int playing{};
		do
		{
			std::cout << "Please Choose \n1) Simulation \n2) Playable \n\nChoice:";
			std::cin >> choice;
		} while (choice < 1 || choice >2);

		switch (choice)
		{
		case 1:
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Simulation();
			break;
		case 2:
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Playable();
			break;
		}
		do
		{
			std::cout << "Would you like to go again? \n1) Yes \n2) No \n\nChoice: ";
			std::cin >> playing;
			if (playing == 2)
			{
				break;
			}
		} while (playing < 1 || playing > 2);
	}
}