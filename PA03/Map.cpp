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
	cout << "Map" << endl;
	numCities = length;
	serviceCities = new City[numCities];
	cout << "Service Cities" << endl;
	for(int i = 0; i < numCities; i++) {
		City city(theCities[i]);
		serviceCities[i] = City(theCities[i]);
		cout << serviceCities[i].name << endl;
	}
}

Map::~Map() {
	
}

void Map::setCities(int length, string * theCities) {
	numCities = length;
	serviceCities = new City[numCities];
	cout << "Service Cities" << endl;
	for(int i = 0; i < numCities; i++) {
		City city(theCities[i]);
		serviceCities[i] = City(theCities[i]);
		cout << serviceCities[i].name << endl;
	}
}

void Map::addConnection(string origin, string target) {
	cout << "Add Connection from " << origin << " to " << target << endl;
	
	int i = 0;
	while(serviceCities[i].name != origin) {
		cout << "Origin " << serviceCities[i].name.size() << " vs " << origin.size() << endl;
		cout << serviceCities[i].name << " vs " << origin << endl;
		i++;
	}

	cout << serviceCities[i].name << endl;

	/*int j = 0;
	while(serviceCities[i].name != target) {
		cout << "Target" << endl;
		j++;
	}

	cout << "From " << serviceCities[i].name << " to " << serviceCities[j].name << endl;
	serviceCities[i].addConnection(serviceCities[j]);*/
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
		cities[i].visited = false;
	}
}

void Map::markVisited(City & aCity) {
	aCity.visited = true;  
}

City Map::getNextCity(City fromCity) {
	int i = 0;
	int j = 0;
	while(serviceCities[i].name != fromCity.connectedCities[j]) {
		cout << "Origin" << endl;
		i++;
	}
	
	City connectedCity = serviceCities[i];
	if(connectedCity.visited == false) {
		return (connectedCity);
	}else {
		return NO_CITY;
	}
}
