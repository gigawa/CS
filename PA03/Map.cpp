//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include "Map.h"
#include "City.h"
#include <string>
#include <iostream>

using namespace std;

Map::Map() {

}

Map::Map(int length, string * theCities) {
	numCities = length;
	serviceCities = new City[numCities];
	for(int i = 0; i < numCities; i++) {
		City city(theCities[i]);
		serviceCities[i] = City(theCities[i]);
	}
}

Map::~Map() {
	
}

void Map::addConnection(string origin, string target) {
	City startCity = searchCity(origin);
	City endCity = searchCity(target);
	endCity.addConnection(startCity);
}

void Map::requestFlight(string origin, string target) {
	cout << "Request Flight" << endl;
	unvisitAll();
	City startCity = searchCity(origin);
	City endCity = searchCity(target);

	cout << "Start isPath" << endl;
	bool hasPath = isPath(startCity, endCity);
	cout << "Flight between: " << origin << " and " << target << " is: " << hasPath << endl;
}

/** Tests whether a sequence of flights exists between two cities.
    Nonrecursive stack version.
 @pre  originCity and destinationCity both exist in the flight map.
 @post  Cities visited during the search are marked as visited
    in the flight map.
 @param  originCity The origin city.
 @param  destinationCity The destination city.
 @return  True if a sequence of flights exists from originCity
    to destinationCity; otherwise returns false. */
bool Map::isPath(City originCity, City destinationCity)
{
   LinkedStack<City> cityStack;
   
   unvisitAll(); // Clear marks on all cities
   
   // Push origin city onto cityStack and mark it as visited
   cityStack.push(originCity);
   markVisited(originCity);
   
   City topCity = cityStack.peek();
   while (!cityStack.isEmpty() && (topCity != destinationCity))
   {
      // The stack contains a directed path from the origin city
      // at the bottom of the stack to the city at the top of the stack
      
      // Find an unvisited city adjacent to the city on the top of the stack
      City nextCity = getNextCity(topCity);
      
      if (nextCity == NO_CITY)
         cityStack.pop(); // No city found; backtrack
      else // Visit city
      {
         cityStack.push(nextCity);
         markVisited(nextCity);
      } // end if
      
      if (!cityStack.isEmpty())
         topCity = cityStack.peek();
   } // end while
   
   return !cityStack.isEmpty();
}  // end isPath

void Map::unvisitAll() {
	for(int i = 0; i < numCities; i++) {
		serviceCities[i].visited = false;
	}
}

void Map::markVisited(City & aCity) {
	aCity.visited = true;  
}

City Map::getNextCity(City fromCity) {
	cout << "start getNextCity" << endl;
	bool atEnd = false;
	bool hasCity = false;
	int index = 0;

	City connectedCity = searchCity(fromCity.connectedCities[index]);
	while(!atEnd) {
		if(index == fromCity.currConnect) {
			atEnd = true;
		}

		if(connectedCity.visited == false) {
			atEnd = true;
			hasCity = true;
		}else {
			index++;
			connectedCity = searchCity(fromCity.connectedCities[index]);
		}
	}

	cout << "End while loop" << endl;
	if(hasCity) {
		return (connectedCity);
	}else {
		return NO_CITY;
	}
}

City Map::searchCity(string theName) {
	int i = 0;
	while(serviceCities[i].name != theName) {
		i++;
	}
	return serviceCities[i];
}
