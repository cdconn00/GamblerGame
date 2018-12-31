/*
 * Gambler.h
 *
 *  Created on: May 27, 2018
 *      Author: cdcon
 */

#ifndef SRC_CLASSES_GAMBLER_H_
#define SRC_CLASSES_GAMBLER_H_

#include <string>
#include <fstream>
#include <iostream>
#include "stdio.h"

class Gambler {
public:
	Gambler();
	// Constructor that initiates user input for a user name.

	Gambler(std::string filename);
	// Uses a username to lookup a user and load previous data.
	// Precondition: string filename which should be the username that the user created

	void AddCredits(int amt);
	// Function to add credits, usually after a player wins a wager
	// Precondition: amount to increase players credits by.
	// Postconditions: players credit total is set to credits + increased amount

	void RmvCredits(int amt);
	// Function to remove credits, usually after a player loses a wager
	// Precondition: amount to decrease players credits by.
	// Postconditions: players credit total is set to credits - decreased amount
	// if credits drop at or below zero the Bankrupt function is called

	int showcredits()
	{
		return credits;
	}

	std::string showname()
	{
		return name;
	}


	void Bankrupt();
	// Function that allows players to continue playing by resetting credits to 100
	// Postcondition: sets player to 'bankrupt' and resets his/her credits to 100

	void ChangeName();
	// Function that allows the player to change his/her username
	// Postcondition: changes player's filename and username to replicate change
	// will close the program to allow for a new object to be created with the new name
	// upon reloading of the application

	void printg()
	{
		std::cout << name << ", " << credits << std::endl;
	}
	// Temp function to debug and test

	void end_session();
	// Function that updates user file to reflect any changes from the games he has played upon exit

	~Gambler() {}
	// Destructor

private:
	int credits;
	std::string name;

};

#endif /* SRC_CLASSES_GAMBLER_H_ */
