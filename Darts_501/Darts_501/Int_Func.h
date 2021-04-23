#pragma once
#include "Interactive.h"

void SinglePlayer()
{
	// AI Object Creation
	std::string name;
	int difficulty{};
	int accuracy{};

	do // do while loop for erorr resilience
	{
		std::cout << "\nPlease choose difficulty \n1)Easy \n2)Medium \n3)Hard \nChoice: ";
		std::cin >> difficulty; // asks what difficulty they wish this will determine the accuracy of the AI
	} while (difficulty < 1 || difficulty > 3);

	switch (difficulty) // depending on the choice of the player will determine the accuracy of the AI
	{
	case 3: accuracy = 80; name = "Hard AI"; break;
	case 2: accuracy = 60; name = "Medium AI";  break;
	case 1: accuracy = 40; name = "Easy AI"; break;
	}
	// create the AI player object

	Player* AI = new Player(name, accuracy);

	// clear the input as not to overflow into the next object creation
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// User Object Creation
	std::cout << "Please enter your name: ";
	std::cin >> name;

	do // do while loop for error resiliance
	{
		std::cout << "\nPlease Enter your accuracy (0-100): ";
		std::cin >> accuracy; // asks for the accuracy of the player that they wish between 0 and 100
	} while (accuracy < 0 || accuracy > 100);

	// create the player pointer object
	Player* User = new Player(name, accuracy);

	// clear the input as not to overflow the next inputs
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Determine how many games they wish to play and who goes first. AI or User
	int games{};
	int first{};

	std::cout << "How many games do you wish to play?: ";
	std::cin >> games; // asks how many games the user wishes to play

	do // do while loop for error resiliance
	{
		std::cout << "\nWho goes first? 1) AI 2) " << User->Get_Name() << ": ";
		std::cin >> first; // asks for who they wish to play first
	} while (first < 1 || first > 2);
	system("CLS"); // clear the console

	first = first - 1; // decrease the first value to access the array

	Results* results = new Results; // create the results object and pointer

	AI->newGame();
	User->newGame();
	for (int loop = games; loop > 0; loop--) // play the game the number of times indicated by the user
	{
		Interactive* new_Int = new Interactive; //  create the interactive object
		new_Int->First_Player(AI, 0); // assign  the players to the pointer array
		new_Int->First_Player(User, 1);
		new_Int->SinglePlayer(results, first); // play the single player function
		delete new_Int; // delete the old objects as not to fill the heap with junk
	}
	results->calculate(games); // calculate the results
	results->get_results(games, AI, User); // display the statistics
	delete AI, User, results; // delete the old objects as not to fill the heap with junk
}

void MultiPlayer()
{
	int choice{};
	do // do while loop for error resiliance
	{
		std::cout << "Would you like to modify accuracy? 1) Yes \n2) No: ";
		std::cin >> choice; // ask if the user wishes to modify the accuracy
	} while (choice < 1 || choice > 2);

	// Object Creation
	std::string name;
	int accuracy{};

	std::cout << "\nPlease enter Player 1 name: ";
	std::cin >> name; // input the name of the player into the player variable

	if (choice == 1) // depending on if they chose they want to modify accuracy ask for the accuracy
	{
		do // do while loop for error resiliance
		{
			std::cout << "\nPlease Enter Player 1 Accuracy: ";
			std::cin >> accuracy; // input the accuracy
		} while (accuracy < 0 || accuracy > 100);
	}
	else
	{
		accuracy = 70; // defualt accuracy will be 70%
	}

	// create the player object and pointer
	Player* player_1 = new Player(name, accuracy);

	// clear the input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "\nPlease enter Player 2 name: ";
	std::cin >> name; // ask for player 2 name

	if (choice == 1)  // depending on if they chose they want to modify accuracy ask for the accuracy
	{
		do // do while loops for error resilience
		{
			std::cout << "\nPlease Enter Player 2 Accuracy: ";
			std::cin >> accuracy; // input the accuracy
		} while (accuracy < 0 || accuracy > 100);
	}
	else
	{
		accuracy = 70; // default accuracy is 70%
	}

	// player 2 object creation and pointer creation
	Player* player_2 = new Player(name, accuracy);

	// clear the input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int games{};
	std::cout << "\nHow many games would you like to play?: ";
	std::cin >> games; // input the number of game they wish to play

	int first{};
	do // do while loop for error resilience
	{
		std::cout << "\nWho goes first? 1) " << player_1->Get_Name() << " 2) " << player_2->Get_Name() << "\nChoice: ";
		std::cin >> first; // ask who wants to go first
	} while (first < 1 || first > 2);

	first = first - 1; // decrease the first value to access the pointer array

	Results* results = new Results;

	player_1->newGame();
	player_2->newGame();
	for (int loop = games; loop > 0; loop--) // play the game the number of times the user indicated
	{
		Interactive* new_int = new Interactive;
		new_int->First_Player(player_1, 0); // store into the correct position in the array
		new_int->First_Player(player_2, 1);
		new_int->MultiPlayer(results, first); // play the multiplayer function game
		delete new_int; // delete the old interactive object as not to fill the heap with too much junk
	}
	results->calculate(games); // calculate the results
	results->get_results(games, player_1, player_2); // display the results
	delete player_1, player_2, results; // delete the old player objects to not fill the heap with junk
}