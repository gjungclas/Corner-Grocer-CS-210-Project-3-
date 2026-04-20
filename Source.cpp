/* CS 210 Corner Grocer project
* @author: Grace Jungclas, MA, AT Ret
* @created: April 2026
* @purpose: uses a file that includes a list of items sold that day, creates a back-up file
* without prompting, then shows the user a menu of choices to either (1) find the number of times
* one item appears in the file, or (2) print a list of the unique items with their frequencies, or
* (3) print a list of the unique items with their frequencies in histogram format, or (4) Quit program.
* 
* @Classes: 
*		-Display: (Presentation Tier) handles output and user input
*		-File: (Data Tier) handles #1 above (file processes and populates a map of items [name, frequency])
*		-GroceryItem: (Logic Tier) handles #2 and 3 (counts the map from file, outputs list, outputs histogram
* 
*/
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
using namespace std;

// # include ".h"
#include "GroceryItem.h"
#include "File.h"
#include "Display.h"

int main() {
	Display display;														// instatntiate Display object
	File groceryFile;														// instatinate File object 
	GroceryItem processor;													// instantiate GroceryItem object to handle math and printing

	// --- STEP 1: File Process: backup file and populate map ---	
	if (!groceryFile.ReadFile()) {											// handle error if input file is missing
		return 1;															// exit if input file is missing
	};				
	groceryFile.WriteNewFile(); 											// create backup file 
	
	map<string, int> frequencyData = groceryFile.GetItemMap();				// get map from file object for future use
	
	// --- STEP 2: Display Welcome, Instructions, and Menu ---
	int userChoice = 0;														// initialize variable
	display.DisplayWelcome();												// call welcome message function
	do {
		userChoice = display.GetMenuChoice();								// call function to handle user input
		// switch/case statments
		switch (userChoice) {												// cases for menu options
		// --- Option 1: Item Frequency ---
		case 1:
		{
			string item = display.GetSearchTerm();							// initialize & assign variable by calling function to get item name
			int count = processor.GetItemFrequency(item, frequencyData);	// initialize & assing variable by calling functions to get item frequency
			cout << item << " " << count << endl << endl;					// output the item and its frequency
		}
			break;

		// --- Option 2: Print List ---
		case 2:
			cout << endl;													// formatting: insert empty line
			processor.PrintAllFrequencies(frequencyData);					// use GroceryItem function to print, passing the map data
			cout << endl;													// formatting: insert empty line
			break;

			// --- Option 3: Print Histogram list ---
		case 3:
			cout << endl;													// formatting: insert empty line
			processor.PrintHistogram(frequencyData);						// use GroceryItem function to print histogram, passing the map data
			cout << endl;													// formatting: insert empty line
			break;

			// --- Option 4: Exit ---
		case 4:
			cout << "Thank you for visiting Corner Grocer. Goodbye.";
			break;

		default:
			cout << "Invalid input. Please enter a number between 1 and 4"; // safety net: Functions should handle errors
			break;
		}
	} while (userChoice != 4);
	
	// FIXME: Remove output from File.cpp 
		
	return 0;
}