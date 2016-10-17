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
	bool isPath(City &, City &);
	void unvisitAll();
	void markVisited(City &);
	City getNextCity(string);
	void addConnection(string origin, string target);
	City & searchCityIndex(string);
	bool requestFlight(string , string);
private:
	int numCities;
	City * serviceCities;
	City NO_CITY;
};

#include "Map.cpp"
#endif
