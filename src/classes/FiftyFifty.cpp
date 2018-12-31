/*
 * FiftyFifty.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: cdcon
 */

#include "FiftyFifty.h"

FiftyFifty::FiftyFifty()
{
	randnbr = 0;
	userpick = ' ';
}

void FiftyFifty::setup(Gambler& Player)
{
	bool isvalid = false;  // variable to handle correct user input
	std::string pickname;  // variable to tell user if their choice is even or odd

	std::cout << "You've selected Fifty-Fifty, the game where you always have a 50% chance to win\n";    // Intro to game
	std::cout << "Select even or odd, if the number drawn is the correct type you selected you win your wager amount\n";

	while (!isvalid)   // Logic to handle wager entry and ensure the player has enough credits
	{
		std::cout << "Please enter a valid wager amount: \n";
		std::cin >> wager;

		if (wager <= Player.showcredits())
			isvalid = true;
		else
			std::cout << "Sorry, you don't have enough credits to wager that much, try a lower amount \n";
	}

	isvalid = false; // reset is valid to handle logic for next user input
	std::cout << "Wager entered... Will the number drawn be even or odd?\n";

	while (!isvalid) // while loop to handle input of guess
	{
		std::cout << "Please Type E/e or O/o: to enter your guess: \n";
		std::cin >> userpick;

		if (userpick == 'E' || userpick == 'e' || userpick == 'O' || userpick == 'o')
			isvalid = true;
	}

	if (userpick == 'E' || userpick == 'e')  // Sets user pick to what they selected
	{
		pickname = "Even";
	}
	else
		pickname = "Odd";

	std::cout << "You have selected: " << pickname << ". Time to play! \n";

	play_game(Player);

}

void FiftyFifty::play_game(Gambler& Player)
{
	std::string nbrtype;

	srand(time(NULL));  // seeding rand

	randnbr = rand() % 100;  // picks a random number for the game

	if (((randnbr % 2) == 0))  // determines if the number is even or odd
		nbrtype = "Even";
	else if ((randnbr % 2) != 0)
		nbrtype = "Odd";

	std::cout << "The number is: " << randnbr << ". Which is " << nbrtype << std::endl;

	if (nbrtype == "Even")   // Logic to handle if the user chose correctly and call the appropriate function
	{
		if (userpick == 'E' || userpick == 'e')
			game_won(Player);
		else
			game_lost(Player);
	}
	else if (nbrtype == "Odd")
	{
		if (userpick == 'O' || userpick == 'o')
			game_won(Player);
		else
			game_lost(Player);
	}
}

void FiftyFifty::game_won(Gambler& Player)
{
	std::cout << "You have guessed the number correctly, congrats! \n";
	std::cout << "You are awarded " << wager << " credits." << std::endl;
	Player.AddCredits(wager);
}

void FiftyFifty::game_lost(Gambler& Player)
{
	std::cout << "Sorry! You have not guessed the number correctly.\n";
	std::cout << "You are penalized " << wager << " credits." << std::endl;

	Player.RmvCredits(wager);

	if (Player.showcredits() <= 0)
	{
		Player.Bankrupt();
	}
}
