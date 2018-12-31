/*
 * AllNothing.h
 *
 *  Created on: Jun 19, 2018
 *      Author: cdcon
 */

#ifndef SRC_CLASSES_ALLNOTHING_H_
#define SRC_CLASSES_ALLNOTHING_H_

#include "GameType.h"
#include <cstdlib>
#include <ctime>

class AllNothing: public GameType {
public:
	AllNothing();

	void setup(Gambler& Player);
	// Function to setup the game, allow user to enter wager
	// Post-Condition: Calls play_game to randomly pick 16 numbers and decide if the user
	// wins or loses

	void game_won(Gambler& Player);
	// If the user's guess in setup is correct, game_won is called to
	// give player his wager amount and handle the win.
	void game_lost(Gambler& Player);
	// Handles a player's loss by removing credits
	// If the player goes bankrupt, per the gambler class
	// the gambler function is called.

	void play_game(Gambler& Player);
	// Precondition: Called by setup after user has entered a wager and a guess
	// Generates a random number to then determines if that number is odd or even
	// If that number is the correct guess of the player, then it calls game_won
	// Else it will call game_lost.

	~AllNothing() {}

private:
	int numberpick;
	int tempnbr;
};

#endif /* SRC_CLASSES_ALLNOTHING_H_ */
