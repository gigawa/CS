#ifndef MAP_
#define MAP_

#include "LinkedStack.h"

class Map {
public:
	Map();
	~Map();
	bool isPath(City , City );
	void unvisitAll();
	void markVisited(City );
	City getNextCity(City );
};
