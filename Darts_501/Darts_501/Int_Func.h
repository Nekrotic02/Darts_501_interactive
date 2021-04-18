#pragma once
#include "Interactive.h"

void SinglePlayer()
{
	// AI Object Creation
	std::string name;
	int difficulty{};
	int accuracy{};

	do
	{
		std::cout << "\nPlease choose difficulty \n1)Easy \n2)Medium \n3)Hard \nChoice: ";
		std::cin >> difficulty;
	} while (difficulty < 1 || difficulty > 3);

	switch (difficulty)
	{
	case 3: accuracy = 80; name = "Hard AI"; break;
	case 2: accuracy = 70; name = "Medium AI";  break;
	case 1: accuracy = 60; name = "Easy AI"; break;
	}

	Player* AI = new Player(name, accuracy);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// User Object Creation
	std::cout << "Please enter your name: ";
	std::cin >> name;

	do
	{
		std::cout << "\nPlease Enter your accuracy (0-100): ";
		std::cin >> accuracy;
	} while (accuracy < 0 || accuracy > 100);

	Player* User = new Player(name, accuracy);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Determine how many games they wish to play and who goes first. AI or User
	int games{};
	int first{};

	std::cout << "How many games do you wish to play?: ";
	std::cin >> games;

	do
	{
		std::cout << "\nWho goes first? 1) AI 2) " << User->Get_Name() << ": ";
		std::cin >> first;
	} while (first < 1 || first > 2);
	system("CLS");

	first = first - 1;

	Results* results = new Results;
	std::string winner;
	AI->newGame();
	User->newGame();
	for (int loop = games; loop > 0; loop--)
	{
		Interactive* new_Int = new Interactive;
		new_Int->First_Player(AI, 0);
		new_Int->First_Player(User, 1);
		new_Int->SinglePlayer(results, first);
	}
	results->calculate(games);
	results->get_results(games, AI, User);
}

void MultiPlayer()
{
	int choice{};
	do
	{
		std::cout << "Would you like to modify accuracy? 1) Yes \n2) No: ";
		std::cin >> choice;
	} while (choice < 1 || choice > 2);
	// Object Creation
	std::string name;
	int accuracy{};

	std::cout << "\nPlease enter Player 1 name: ";
	std::cin >> name;

	if (choice == 1)
	{
		do
		{
			std::cout << "\nPlease Enter Player 1 Accuracy: ";
			std::cin >> accuracy;
		} while (accuracy < 0 || accuracy > 100);
	}
	else
	{
		accuracy = 70;
	}

	Player* player_1 = new Player(name, accuracy);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "\nPlease enter Player 2 name: ";
	std::cin >> name;

	if (choice == 1)
	{
		do
		{
			std::cout << "\nPlease Enter Player 2 Accuracy: ";
			std::cin >> accuracy;
		} while (accuracy < 0 || accuracy > 100);
	}
	else
	{
		accuracy = 70;
	}

	Player* player_2 = new Player(name, accuracy);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int games{};
	std::cout << "\nHow many games would you like to play?: ";
	std::cin >> games;

	int first{};
	do
	{
		std::cout << "\nWho goes first? 1) " << player_1->Get_Name() << " 2) " << player_2->Get_Name() << "\nChoice: ";
		std::cin >> first;
	} while (first < 1 || first > 2);
	first = first - 1;

	Results* results = new Results;
	std::string winner;
	player_1->newGame();
	player_2->newGame();
	for (int loop = games; loop > 0; loop--)
	{
		Interactive* new_int = new Interactive;
		new_int->First_Player(player_1, 0);
		new_int->First_Player(player_2, 1);
		new_int->MultiPlayer(results, first);
	}
	results->calculate(games);
	results->get_results(games, player_1, player_2);
}