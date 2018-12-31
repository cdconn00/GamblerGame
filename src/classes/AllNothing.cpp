/*
 * AllNothing.cpp
 *
 *  Created on: Jun 19, 2018
 *      Author: cdcon
 */

#include "AllNothing.h"

AllNothing::AllNothing() {numberpick = 0, tempnbr = 0;}

void AllNothing::setup(Gambler& Player)
{
	bool isvalid;

	std::cout << "Welcome to all or nothing! You wager a amount 0-100! \n";
	std::cout << "We then print 16 numbers 0-100 if your number is not present \n";
	std::cout << "You win that amount!";

	while (!isvalid)   // Logic to handle wager entry and ensure the player has enough credits
	{
		std::cout << "Please enter a valid wager amount: \n";
		std::cin >> wager;

		if (wager <= Player.showcredits() && wager <= 100)
			isvalid = true;
		else
			std::cout << "Sorry, that wager amount isnt valid";
	}

	play_game(Player);

}

void AllNothing::play_game(Gambler& Player)
{
	int i = 0;
	bool win = true;

	srand(time(NULL));

	for (i = 0; i < 17; i++)
	{
		numberpick = rand() % 100;

		std::cout << numberpick << " ";

		if (wager == numberpick)
		{
			win = false;
		}
	}

	if (win == true)
		game_won(Player);
	else
		game_lost(Player);
}


void AllNothing::game_won(Gambler& Player)
{
	std::cout << "Congrats! You correctly guessed! \n";
	std::cout << "You are awarded " << wager << " credits! \n";

	Player.AddCredits(wager);
}

void AllNothing::game_lost(Gambler& Player)
{
	std::cout << "Sorry! You have not guessed correctly.\n";
	std::cout << "You are penalized " << wager << " credits." << std::endl;

	Player.RmvCredits(wager);

	if (Player.showcredits() <= 0)
	{
		Player.Bankrupt();
	}
}
