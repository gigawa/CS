#ifndef MAP_
#define MAP_

#include "LinkedStack.h"
#include "Node.h"
#include "City.h"

class Map {
public:
	Map();
	~Map();
	bool isPath(City , City );
	void unvisitAll();
	void markVisited(City &);
	City getNextCity(City );
private:
	int numCities;
	City * cities;
	City NO_CITY;
};

#include "Map.cpp"
#endif
