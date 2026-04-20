#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>	

using namespace std;

class File {
public:
	File();																// default constructor
	bool ReadFile();													// Reads the input file and populates map
	bool WriteNewFile();												// creates a new file and writes to that file
	// returns a reference to avoid copying the list everytime function is called
	const map<string, int>& GetItemMap() const { return itemData; };	// function taking a map object and returns its information
	

private:
	string fileName;													// declare variable
	map<string, int> itemData;											// Key: Name, Value: Frequency
	ifstream inFS;														// declare variable
	ofstream outFS;														// declare variable
};

#endif // !FILE_H