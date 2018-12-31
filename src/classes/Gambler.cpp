/*
 * Gambler.cpp
 *
 *  Created on: May 27, 2018
 *      Author: cdcon
 */

#include "Gambler.h"
#include <assert.h>

Gambler::Gambler()
{
	std::string filename; // creates filename to store user info
	bool namevalid = false;

	credits = 100;   // default amount of credits


	while (!namevalid)
	{
		std::cout << "Please enter a username (less 16 characters): \n";    // sets username and creates a filename for the user

		std::cin >> name;

		if (name.size() < 16)
		{
			filename = name + ".dat";
			namevalid = true;
		}
	}

	std::ofstream ofile;           // creates an output file for the user before saving his/her intial data

	ofile.open(filename);

	ofile << name << std::endl;
	ofile << credits << std::endl;


}

Gambler::Gambler(std::string filename)
{
	std::ifstream ifile;

	filename = filename + ".dat";    // finds file with the username player specified at creation

	ifile.open(filename);

	if (!ifile) // if it is unable to be found this error is thrown
	{
		std::cout << "Unable to find that user, please ensure the username was entered correctly";

		return;
	}
	else // if file is found it will create the new object with the old data from the file
	{
		std::string tempn;
		int tempc;

		ifile >> tempn;
		name = tempn;
		ifile.ignore(999, '\n');
		ifile >> tempc;
		credits = tempc;
	}

}

void Gambler::AddCredits(int amt)
{
	credits = credits + amt;  // function used by game won to add credits to a victorious player
}
void Gambler::RmvCredits(int amt)
{
	credits = credits - amt;

	if (credits <= 0)
	{
		Bankrupt();
	}
}
void Gambler::Bankrupt()
{
	credits = 100;

	std::cout << "Oh no, you\'ve lost it all! You are now bankrupt! \n";
	std::cout << "Setting status to 'Bankrupt'! Credits Set to " << credits << " .\n";
}
void Gambler::ChangeName()
{
	std::ofstream ofile;
	std::string newfilename, oldfilename, newname; // creates variables to store filenames and the new username
	bool namevalid;

	oldfilename = name + ".dat"; // oldfile name is set as it already is

	while (!namevalid) // While loop to allow user to enter a new name, under sixteen characters
	{
		std::cout << "Username change, note: application will close upon change\n";
		std::cout << "Please enter a new username, under 16 characters: \n";

		std::cin >> newname;

		if (newfilename.size() < 16) // when the name is under 16 characters it is set and the name is valid
		{
			newfilename = newname + ".dat";
			namevalid = true;
		}
	}

	int result = rename( oldfilename.c_str() , newfilename.c_str() ); // renames the file to the newfilename
	  if ( result == 0 )
	    puts ( "File successfully renamed" );
	  else
	    perror( "Error renaming file" );

	ofile.open (newfilename.c_str() , std::ofstream::trunc);

	ofile << newname << std::endl;  // writes data into the newfile
	ofile << credits << std::endl;

	ofile.close(); // closes the file


	if(!remove(oldfilename.c_str())) // Deletes the old file so that the name change is complete
		std::cout << "Failed to remove old name file";

}

void Gambler::end_session() // Updates the user file to reflect changes made during session before exiting the program
{
	std::ofstream ofile;
	std::string filename;

	filename = name + ".dat";

	ofile.open(filename.c_str(), std::ofstream::trunc);

	assert(ofile);

	ofile << name << std::endl;
	ofile << credits << std::endl;
}

