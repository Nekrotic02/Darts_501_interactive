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
	// clear the user input so not to overload the input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Declarations and Player Object Creation
	std::string name;
	int accuracy{};
	cout << "Please enter Player 1 name: ";
	getline(cin, name); // asks the user for the player 1 name and stores it into the name variable

	do // Do while loop for error resiliance
	{
		cout << endl;
		cout << "Please enter Player 1 Accuracy: ";
		cin >> accuracy; // takes input from the player for the accuracy and it must bee between 0 and 100
		cout << endl;
	} while (accuracy < 0 || accuracy > 100);

	// creates the player 1 object and accessing it with the pointer
	Player* player_1 = new Player(name, accuracy);

	// clear the user input so not to overload the input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	cout << endl;
	cout << "Please enter Player 2 name: ";
	getline(cin, name); // asks the user for the player 2 name and stores it into the name variable

	do // Do while loop for error resiliance
	{
		cout << endl;
		cout << "Please enter Player 2 Accuracy: ";
		cin >> accuracy; // takes input from the player for the accuracy and it must bee between 0 and 100
		cout << endl;
	} while (accuracy < 0 || accuracy > 100);

	// creates the player 2 object and creates a pointer for accessing
	Player* player_2 = new Player(name, accuracy);

	// clear the user input so not to overload the input
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Number of games to play
	int games{};
	cout << "How many games do you want to play: ";
	cin >> games;
	cout << endl;

	int first{};
	do // Do while loop for error resiliance
	{
		cout << "Who Plays First?" << endl;
		cout << "1) " << player_1->Get_Name() << endl;
		cout << "2) " << player_2->Get_Name() << endl;
		cout << "Answer: ";
		cin >> first; // asks the user who they want to play first and store it into the first variable
		cout << endl;
	} while (first < 1 || first > 2);

	// Who Plays First
	first = first - 1; // decreace the first variables value to be used while accessing the player pointer array
	Results* results = new Results; // create a new object for the results

	player_1->newGame();
	player_2->newGame();
	for (int loop = games; loop > 0; loop--) // create a for loop and a new int to play the number of games indicated by the user without losing the data
	{
		Game* new_game = new Game;
		new_game->First_Player(player_1, 0);
		new_game->First_Player(player_2, 1);
		new_game->Play_Game(results, first);
	}
	results->calculate(games); // calcuate the results
	results->get_results(games, player_1, player_2); // dislpay the results
}

void Playable()
{
	while (true) // loop through for how many times until the user decides otherwise
	{
		int playing{};
		int choice{};
		do // do while loop for error resilience
		{
			std::cout << "Please Choose \n1)SinglePlayer \n2)MultiPlayer \n\nChoice:";
			std::cin >> choice; // choose if they wish to play against AI or with another person at the PC
		} while (choice < 1 || choice > 2);

		switch (choice) // depending on the choice indicated by the user run the correct function.
		{
		case 1:
			SinglePlayer();
			break;
		case 2:
			MultiPlayer();
			break;
		}

		do // do while loop for error resilience
		{
			std::cout << "Would you like to go again? \n1) Yes \n2) No \n\nChoice: ";
			std::cin >> playing; // ask if they wish to keep playing
			if (playing == 2)
			{
				break;
			}
		} while (playing < 1 || playing > 2);
	}
}

int main()
{
	srand((int)time(0));
	while (true) // loop as many times as the user indicates.
	{
		int choice{};
		int playing{};
		do // do while loop for error resilience
		{
			std::cout << "Please Choose \n1) Simulation \n2) Playable \n\nChoice:";
			std::cin >> choice; // ask the user if they wish to play a game or run a simulation
		} while (choice < 1 || choice >2);

		switch (choice) // depending on the choice run the correct function.
		{
		case 1:
			Simulation();
			break;
		case 2:
			Playable();
			break;
		}
		do // do while loop for error resilence
		{
			std::cout << "Would you like to go again? \n1) Yes \n2) No \n\nChoice: ";
			std::cin >> playing; // ask the player if they wish to continue playing
			if (playing == 2)
			{
				break;
			}
		} while (playing < 1 || playing > 2);
	}
}