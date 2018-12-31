/*
 * HighLow.h
 *
 *  Created on: Jun 17, 2018
 *      Author: cdcon
 */

#ifndef SRC_CLASSES_HIGHLOW_H_
#define SRC_CLASSES_HIGHLOW_H_

#include "GameType.h"
#include <cstdlib>
#include <ctime>

class HighLow: public GameType {
public:
	HighLow();

	void setup(Gambler& Player);
	//

	void game_won(Gambler& Player);
	// If the user's guess in setup is correct, game_won is called to
	// give player his wager amount and handle the win.
	void game_lost(Gambler& Player);
	// Handles a player's loss by removing credits
	// If the player goes bankrupt, per the gambler class
	// the gambler function is called.

	void play_game(Gambler& Player);
	// Precondition: Called by setup after user has entered a wager and a guess
	//

	~HighLow() {}

private:
	int wager;
	int fnumber;
	int snumber;
	char guess;
};

#endif /* SRC_CLASSES_HIGHLOW_H_ */
