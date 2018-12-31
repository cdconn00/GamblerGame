/*
 * GameType.h
 *
 *  Created on: Jun 2, 2018
 *      Author: cdcon
 */

#ifndef SRC_CLASSES_GAMETYPE_H_
#define SRC_CLASSES_GAMETYPE_H_

#include "Gambler.h"

class GameType {
public:
	GameType()
	{
		wager = 0;
		wins = 0;
		losses = 0;
		amt = 0;
	}
	// Constructor initializes all counters and wager amounts
	// Precondition: must pass object of Gambler to constructor
	// to allow constructor to have a player to reward/penalize.


	virtual ~GameType() {} ;



protected:
	int wager;
	int wins;
	int losses;
	int amt;
};

#endif /* SRC_CLASSES_GAMETYPE_H_ */
