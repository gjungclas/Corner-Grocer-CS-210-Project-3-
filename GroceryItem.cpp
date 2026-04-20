#include <iostream>
#include <iomanip>
#include "GroceryItem.h"

using namespace std;

// GetItemFrequency()
// @brief: returns frequency of item
// @param : passes map as constant reference
// @returns: number of that item or 0 if item not sold that day
int GroceryItem::GetItemFrequency(const string& itemName, const map<string, int>& itemData) {
	// check if item is already in the map
	if (itemData.count(itemName)) {
		return itemData.at(itemName);												// return the frequency at itemName
	}
	return 0;																		// return 0 if Corner Grocer did not sell the item that day
}

// PrintAllFrequencies()
// @brief: outputs item name and it's frequency on one line
// @param: map as const reference
// @return: "[item name] [itemFrequency]" 
void GroceryItem::PrintAllFrequencies(const map<string, int>& itemData) {
	//loop through map to find frequency
	for (auto const& [name, frequency] : itemData) {								// iterate through all of itemData and assign values to name and frequency
		cout << name << " " << frequency << endl;									// output name, a space, and the item's frequency
	}
}

// PrintHistogram()
// @brief: outputs item name & frequency in a histogram of characters on one line
// @param: map as const reference
// @return: "[item name] [+]"
void GroceryItem::PrintHistogram(const map<string, int>& itemData) {
	//loop through map
	for (auto const& [name, frequency] : itemData) {								// iterate through all of itemData and assign values to name and frequency
		cout << left << setw(12) << name << " ";									// format output so name appears on left of screen
		for (int i = 0; i < frequency; ++i) {										// iterate to find frequncy of item
			cout << "+";															// output one character everytime it is found in list to form histogram
		}
		cout << endl;
	}
}