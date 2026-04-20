#ifndef DISPLAY_H
#define	DISPLAY_H

#include <iostream>
#include <string>
using namespace std;

class Display {
public:
	Display();
	void DisplayWelcome();			// outputs welcome message
	void DisplayInstructions();		// outputs instructions and menu options
	string GetSearchTerm();			// handles user input for menu option 1 
	int GetMenuChoice();			// handles user input of menu options

private:
	int userVal;					// variable declaration

};

#endif // DISPLAY_H