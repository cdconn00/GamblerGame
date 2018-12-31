/*
 * HighLow.cpp
 *
 *  Created on: Jun 17, 2018
 *      Author: cdcon
 */

#include "HighLow.h"

HighLow::HighLow() {
	wager = 0;
	fnumber =0;
	snumber = 0;
	guess = ' ';
}

void HighLow::setup(Gambler& Player)
{
	bool wagervalid = false;

	std::cout << "Welcome to High Low! We give you a number (0-100), you guess if the next number will"
			<< " be higher or lower. If you are right you win your wager amount.\n";

	std::cout << "Ready to play? Let's start with a wager amount, please enter an integer amount to wager. \n";


	while (!wagervalid)
	{
		std::cout << "Enter wager amount: " << std::endl;

		std::cin >> wager;

		if (wager > 0 && wager < Player.showcredits())
		{
			wagervalid = true;
		}
	}


	std::cout << "A wager of " << wager << " credits was entered." << std::endl;

	play_game(Player);
}

void HighLow::play_game(Gambler& Player)
{
	bool validpick = false;
	srand(time(NULL));  // seeding rand

	fnumber = rand() % 100;
	snumber = rand() % 100;

	std::cout << "Time to play!\n The first number is: " << fnumber << std::endl;
	std::cout << "Will the next number be higher or lower? Enter (H/h or L/l): \n";

	while (!validpick)
	{
		std::cout << "Enter your pick: " << std::endl;

		std::cin >> guess;

		if (guess == 'H' || guess == 'h' || guess == 'L' || guess == 'l')
		{
			validpick = true;
		}
	}

	std::cout << "The second number is: " << snumber << std::endl;

	if (fnumber > snumber)
	{
		if (guess == 'H' || guess == 'h')
		{
			game_lost(Player);
		}
		else
		{
			game_won(Player);
		}
	}
	else if(fnumber < snumber)
	{
		if (guess == 'L' || guess == 'l')
		{
			game_lost(Player);
		}
		else
			game_won(Player);
	}
	else
	{
		std::cout << "Wow the numbers are the same... very lucky";
		game_won(Player);
	}

}

void HighLow::game_won(Gambler& Player)
{
	std::cout << "Congrats! You correctly guessed! \n";
	std::cout << "You are awarded " << wager << " credits! \n";

	Player.AddCredits(wager);
}

void HighLow::game_lost(Gambler& Player)
{
	std::cout << "Sorry! You have not guessed correctly.\n";
	std::cout << "You are penalized " << wager << " credits." << std::endl;

	Player.RmvCredits(wager);

	if (Player.showcredits() <= 0)
	{
		Player.Bankrupt();
	}
}
