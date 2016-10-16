#ifndef MAP_
#define MAP_

#include "LinkedStack.h"
#include "Node.h"
#include "City.h"
#include<string>

using namespace std;

class Map {
public:
	Map();
	~Map();
	Map(int length, string * theCities);
	void setCities(int length, string * theCities);
	bool isPath(City , City );
	void unvisitAll();
	void markVisited(City &);
	City getNextCity(City );
	void addConnection(string origin, string target);
private:
	int numCities;
	City * serviceCities;
	City * cities;
	City * originCities;
	City * targetCities;
	City NO_CITY;
};

#include "Map.cpp"
#endif
