#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>
#include <map>

using namespace std;

class GroceryItem
{
public:
	int GetItemFrequency(const string& itemName, const map<string, int>& itemData); // Returns frequency for a single item
	void PrintAllFrequencies(const map<string, int>& itemData);						// Prints the full list (Name 4)
	void PrintHistogram(const map<string, int>& itemData);							// Prints the Histogram (Name ++++)
};

#endif // GROCERYITEM_H