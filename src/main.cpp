/*
 ______________________________________________________________________________________________________
| Program to include several games for user to gamble funds provided at an initial set amount.         |
|                                                                                                      |
| Program will track Total funds lost/gained in each game and                                          |
| more.                                                                                                |
|                                                                                                      |
|                              Created 5/27/18   By: Cdconn00                                          |
|______________________________________________________________________________________________________|

 */

#include <iostream>
#include <assert.h>
#include "Classes//Gambler.h"
#include "Classes//GameType.h"
#include "Classes//FiftyFifty.h"
#include "Classes//HighLow.h"
#include "Classes//AllNothing.h"

int entrance();
void selectgame(Gambler Player);
int useroptions(Gambler Player);


int main ()
{
	int select = entrance();
	bool validplayer = false;

	assert(select == 1 || select == 0);

	if (select == 1)
	{
		Gambler Player;

		validplayer = true;

		selectgame(Player);
	}
	else
	{
		std::string filename;
		std::cout << "Please enter the username of your player exactly as when created: \n";
		std::cin >> filename;

		Gambler Player(filename);

		validplayer = true;

		selectgame(Player);
	}

	assert(validplayer);

	return 0;
}

int entrance() // function determining if user is new or returning and displays a welcome message
{

	bool selected = false;
	int select;

	std::cout << "Welcome to the Gambler Game, created by Cdconn00! \n";
	std::cout << "Are you are new or returning user?";

	while (!selected)
	{
		std::cout << "Please enter a 1 if you are a new user or a 0 if you are an existing user\n";
		std::cin >> select;

		if (select == 0 || select == 1)
		{
			selected = true;
		}
	}

	return select;
}

void selectgame(Gambler Player) // Function that displays the main menu for players and calls the appropriate objects/functions accordingly
{
	int select = 0;
	bool keepplaying = true;

	std::cout << "Welcome,  " << Player.showname() << " you have " << Player.showcredits() << " credits!\n" << std::endl;

	// Initially on the main menu it tells the player who they are and how many credits they have

	while (keepplaying)
	{
		std::cout << "---- Main Menu ---- \n" << std::endl;
		std::cout << "You have: " << Player.showcredits() << " credits.\n" << std::endl;
		std::cout << "Please select a game to play by entering the number before the game: \n";
		std::cout << "1 - FiftyFifty \n";
		std::cout << "2- All or Nothing \n";
		std::cout << "3 - Find the Ace \n";
		std::cout << "4 - High/Low \n";
		std::cout << "5 - User Options (not a game) \n";
		std::cout << "6 - Exit \n";

		while (select > 7 || select <= 0)  // While loop to handle a valid choice
			std::cin >> select;

		switch (select)
	{
		case 1: // Calls FiftyFifty to be played
		{
			FiftyFifty Fifty;

			Fifty.setup(Player);

			select = 0;
			break;
		}
		case 2:
		{
			AllNothing All;

			All.setup(Player);

			select = 0;

			break;
		}
		case 3:
		{
			select = 0;
			break;
		}
		case 4:
		{
			HighLow High;

			High.setup(Player);

			select = 0;

			break;
		}
		case 5: // opens user options menu
		{
			if (useroptions(Player) == -1) // If user options returns a name change (-1) the program will exit
				return;
			else
			{
				select = 0;
				break;
			}
		}
		case 6: // Game will exit
		{
			Player.end_session();
			keepplaying = false;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

int useroptions(Gambler Player)
{
	int select = 0;
	bool keeplaying = true;

	while (keeplaying)
	{
		std::cout << "Player options menu, please select one of the options below: \n";
		std::cout << "1 - Exit Menu\n";
		std::cout << "2 - Change Username\n";
		std::cout << "3 - Show my name\n";
		std::cout << "4 - Show my credits\n";

		while (select >= 5 || select <= 0)
			std::cin >> select;



		switch (select)
		{
			case 1:
			{
				keeplaying = false;
				return 0;
				break;
			}
			case 2:
			{
				Player.ChangeName();
				return -1;
				break;
			}
			case 3:
			{
				std::cout << "Your name is: " << Player.showname() << std::endl;
				select = 0;
				break;
			}
			case 4:
			{
				std::cout << "Your have: " << Player.showcredits() << " credits." << std::endl;
				select = 0;
				break;
			}
			default:
			{
				return 0;
				break;
			}
		}
	}

	return 0;
}
