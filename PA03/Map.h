#ifndef MAP_
#define MAP_

#include "LinkedStack.h"
#include "Node.h"
#include "City.h"

class Map {
public:
	Map();
	Map(const City * serve, const City * origin, City * target, int length);
	~Map();
	bool isPath(City , City );
	void unvisitAll();
	void markVisited(City &);
	City getNextCity(City );
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
