#include <iostream>
#include <iomanip>
#include "Display.h"

using namespace std;

// Constructor definition
Display::Display() {
	userVal = 0;																								// instantiate variable
}

// @purpose: display a welcome message
// @param: none
// @return: none
void Display::DisplayWelcome() {
	cout << left << setw(25) << setfill(' ') << " " << "Welcome to The Corner Grocer Application" << endl;		// formatting: Title Cenetered
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << "This program analyzes the daily generated text records "
		<< "(A list of items purchased in" << endl;
	cout << "chronological order from the time the store opens to the time it closes)." << endl;
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
}

// @purpose: Output instructions with UI-friendly formatting
// @param: none
// @return: none
void Display::DisplayInstructions() {

	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << left << setw(38) << setfill(' ') << " "<< "Instructions:" << endl;									// formatting: header centered
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << "Please choose from the following options and enter the corresponding number (1-4)" << endl;
	cout << "The program will continue to ask you to choose from the menu until you type '4' to exit." << endl;
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << left << setw(41) << setfill(' ') << " " << "Menu" << endl;															// formatting: center menu
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	// --- Option 1: Item Frequency ---
	cout << "1: Find the amount of one item." << endl;
	cout << setw(3) << setfill(' ') << " " << "For example: your input = Bananas. Program output: [number of bananas]" << endl;
	// --- Option 2: Print List ---
	cout << "2: Print a list of all items purchased and their frequencies." << endl;
	cout << setw(3) << setfill(' ') << " " << "For example: Bananas 2" << endl;									// formatting: align text
	cout << setw(13) << " " << "Potatoes 10" << endl;															// formatting: align text
	cout << setw(13) << " " << "Pumpkins 4" << endl;															// formatting: algin text 
	// --- Option 3: Print Histogram list ---
	cout << "3: Print a list in histogram format for all items purchased." << endl;
	cout << setw(3) << setfill(' ') << " " << "For example: Bananas ++" << endl;								// formatting: align text
	cout << setw(13) << " " << "Potatoes ++++++++++" << endl;													// formatting: align text
	cout << setw(13) << " " << "Pumpkins ++++" << endl;															// formatting: algin text 
	// --- Option 4: Exit Program ---
	cout << "4: Exit" << endl;
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border
	cout << setw(90) << setfill('-') << " " << endl;															// formatting: border

	cout << setfill(' ') << " ";																				// formatting/best practice: reset fill
}

// @purpose: takes user input and stores in variable for easy return and minimizing main()
// @param: none
// @return: string searchTerm: name of grocery item user is looking for
string Display::GetSearchTerm() {
	string searchTerm;														// variable declaration

	cout << "Enter the item you wish to count: " << endl;					// prompt user for item they are searching for
	cin >> searchTerm;														// assign input into variable
	cin.ignore(100, '\n');													// clear the rest of the line for next input
	return searchTerm;														// return the item name
}

// @purpose: handle menu choices and check for error
// @param: none
// @return: none
int Display::GetMenuChoice() {
	int choice = 0;																// declare and initialize choice variable
	// loop forever
	while (true) {
		DisplayInstructions();													// output instructions and show menu options 1-4
		cout << "Please enter which menu option and then press 'enter': ";		// prompt user for input 
		if (cin >> choice) {													// get input (in single read) and check if input is 1-4
			cin.ignore(100, '\n');												// clear the rest of the line for next input
			
			if (choice >= 1 && choice <= 4) { return choice; }					// valid input			
		}
		// if this is reached, input not vailid (either cin failed or number out of range) 
		cout << "Invalid input. Please enter 1, 2, 3, or 4." << endl;		// inform user that input is invalid
		cin.clear();														// clear invalid input
		cin.ignore(100, '\n');												// clear the rest of the line
	}																		// will automatically return if else case is reached so no return needed
}