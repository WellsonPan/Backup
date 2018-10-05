#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.h"

using namespace std;

// TO DO
// Read a list of integer, string pairs representing a station name and its identifier from a text file
// return a vector of strings containing the stations names indexed by their identifiers
// throw an exception if there was a problem opening or reading the file
vector<string> readStationNames(const string& filename) {
	ifstream theFile(filename.c_str());
	vector<string> stations = vector<string>(400);
	if (!theFile)
	{
		throw invalid_argument("Unable to open file " + filename);
	}
	else
	{
		string stationNames;
		int stationNumber;
		/*while (!theFile.eof())
		{
			getline(theFile, stationNames);
			for (int index = 0; index < s.length(); index++)
			{
				if (s[index] == ',')
				{
					firstName = s.substr(0, index);
					size_t found = s.find_last_of("\r\n");
					int movieLength;
					movieLength = found - (index + 1);
					movie = s.substr(index + 1, movieLength);
					bst->insert(firstName, movie);
					index = s.length();
				}
			}
			//cout << movie << endl;
		}*/
		while (!theFile.eof())
		{
			theFile >> stationNames >> stationNumber;
			stations[stationNumber] = stationNames;
		}
	}
	return stations;
}

// TO DO
// Read a list of (integer, integer) pairs representing station identifiers that are next to each other
// return a graph representing these station links
// throw an exception if there was a problem opening or reading the file
Graph *buildGraphfromDatafile(const string& filename) {

	throw invalid_argument("Unable to open file " + filename);
	return NULL;
}