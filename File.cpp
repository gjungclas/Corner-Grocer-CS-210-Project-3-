// @author: Grace J
// @date created: 2026-04-16
// @brief: Creates a file, reads data from a file, counts items and writes the item and its frequency to the created file.
//
// This program defines a File class to create a file for backup purposes.
// It reads items from "InputFile.txt", counts the number of those items,
// and writes the results to "frequency.dat". The program also includes error
// handling for file operations and prints the results to the console for verification.
//
#include "File.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Constructor definition
File::File() {
	fileName = "frequency.dat";													// initialize string
};

// Function to read data from input file
// @ param: none
// @ return: none
bool File::ReadFile() {
	itemData.clear();															// make sure map is clear before reading a new file
	
	// --- STEP 1: Open the Input File ---
	inFS.open("InputFile.txt");													// actual opening of file

	if (!inFS.is_open()) {														// check if the file opened successfully
		return false;															// return to menu if not opened
	}

	string currentItem;															// initialize local variable
	// --- STEP 2: Read and add to map---
	while (inFS >> currentItem) {												// loop as long as cin succesfully reads an item
		itemData[currentItem]++;												// if the item exists, increment. If not, create item
	}

	// --- Step 3: If end of file is not reached, return ---
	if (!inFS.eof()) {															// check if end of file is reached
		return false; // return to main due to error
	}

	inFS.close(); 																// close inFS
	return true;																// signal return to main program
}

// Writes item names and frequencies to a new file
// @param: none
// @return: only if error in writing file
bool File::WriteNewFile() {
	// --- STEP 4: Open New File---
	outFS.open(fileName);

	if (!outFS.is_open()) {														// check if the file was created 
		return false;															// exit to main due to error
	}
	
	// --- STEP 5: Write to New File ---
	if (outFS.is_open()) {														// check if the file opened successfully
		for (auto const& [name, frequency] : itemData) {						// iterate through vectors to write to file
			outFS << name << " " << frequency << endl;							// write item name, a space, and the item frequency
		}
	}
	else {																		// handles exceptions and errors
		return false;															// exit to main due to error
	}

	// --- Step 6: Close Files ---
	outFS.close();
	return true;																// return to main 
}