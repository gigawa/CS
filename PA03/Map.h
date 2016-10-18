/** Map Class
@file Map.h
@brief Header file for Map
@details establishes Map and Map operations
@note Created by Grant Hooks
*/

#ifndef MAP_
#define MAP_

#include "LinkedStack.h"
#include "Node.h"
#include "City.h"
#include<string>

using namespace std;

class Map {
public:
	/** default constructor */
	Map();

	/** default destructor */
	~Map();

	/** parameterized constructor 
	sets the length and cities of the map*/
	Map(int length, string * theCities);

	/** Tests whether a sequence of flights exists between two cities.
    	Nonrecursive stack version.
 	@pre  originCity and destinationCity both exist in the flight map.
 	@post  Cities visited during the search are marked as visited in the flight map.
 	@param  originCity The origin city.
 	@param  destinationCity The destination city.
 	@return  True if a sequence of flights exists from originCity to destinationCity; otherwise returns false. */
	bool isPath(City &, City &);

	/** sets all cities visited variable to false
	@pre cities may have a true visited bool
	@post all cities have false visited bool */
	void unvisitAll();

	/** sets a given city as visited 
	@pre city has false visited bool
	@post city has true visited bool*/
	void markVisited(City &);

	/** gets the next city to check for path 
	@pre given city to search for paths from
	@post has a city that hasn't been visited yet that may be part of the path
	@return if found, an unvisited city, otherwise NO_CITY*/
	City getNextCity(string);

	/** calls addConnection for a city giving it a city it has a flight to
	@pre cities are not linked
	@post cities are linked*/
	void addConnection(string origin, string target);

	/** finds a city in serviceCities when given the name
	@pre given string containing city name
	@post has the city object of given name
	@return returns the city of the given name*/
	City & searchCityIndex(string);

	/** initializes search for a path
	@pre given string name of origin city and the target city
	@post isPath is called
	@return true if a flight path exists between the two cities*/
	bool requestFlight(string , string);
private:
	//number of cities serviced
	int numCities;
	
	//the cities serviced
	City * serviceCities;

	//arbitrary city returned if none is found
	City NO_CITY;
};

#endif
