#include <iostream>
#include <vector>
#include "utilities.h"
#include "Graph.h"

using namespace std;

int main() {
	try {
		Graph *g = buildGraphfromDatafile("station_route.txt"); // build a graph of the London Underground tube routes
		vector<string> stationNames = readStationNames("station_names.txt"); // read the station names

		{
			int from = 313; // station id=313 represents Whitechapel
			int destination = 55; // station id=55 represents Charing_Cross
			cout << "Going from " << stationNames[from] << " to " << stationNames[destination] << "?" << endl;
			vector<int> stations = g->getPath(from, destination);
			cout << "There are " << stations.size() << " stations in between: " << endl;
			for (unsigned int i = 0; i < stations.size(); i++)
				cout << stationNames[stations[i]] << endl;
			// One possible path: Whitechapel -> Aldgate_East -> Liverpool_Street -> Bank -> Monument -> Cannon_Street -> Mansion_House -> Blackfriars -> Temple -> Embankment -> Charing_Cross
		}
		{// another example
			int from = 15; // station id=15 represents Barbican
			int destination = 137; // station id=137 represents Holborn
			cout << "Going from " << stationNames[from] << " to " << stationNames[destination] << "?" << endl;
			vector<int> stations = g->getPath(from, destination);
			cout << "There are " << stations.size() << " stations in between: " << endl;
			for (unsigned int i = 0; i < stations.size(); i++)
				cout << stationNames[stations[i]] << endl;
		}

	}
	catch (exception &e) {
		cout << e.what() << endl;
	}
	system("pause");
}