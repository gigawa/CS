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
	City startCity = searchCityIndex(origin);
	City endCity = searchCityIndex(target);
	endCity.addConnection(startCity);
}

bool Map::requestFlight(string origin, string target) {
	unvisitAll();
	City startCity = searchCityIndex(origin);
	City endCity = searchCityIndex(target);

	return isPath(startCity, endCity);
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
bool Map::isPath(City & originCity, City & destinationCity)
{
   LinkedStack<City> cityStack;
   
   unvisitAll(); // Clear marks on all cities
   
   // Push origin city onto cityStack and mark it as visited
   cityStack.push(originCity);
   markVisited(originCity);
   
   City topCity = cityStack.peek();
   while (!cityStack.isEmpty() && (topCity != destinationCity))
   {
		//cout << " from " << topCity.name << endl;
      // The stack contains a directed path from the origin city
      // at the bottom of the stack to the city at the top of the stack
      
      // Find an unvisited city adjacent to the city on the top of the stack
      City nextCity = getNextCity(topCity.name);
      if (nextCity == NO_CITY) {
		//cout << " Back Track ";
         cityStack.pop(); // No city found; backtrack
      } else // Visit city
      {
		//cout << " to " << nextCity.name << endl;
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
	City * theCity = &searchCityIndex(aCity.name);
	theCity->setVisited();
}

City Map::getNextCity(string fromCityName) {
	bool atEnd = false;
	bool hasCity = false;
	int index = 0;

	City fromCity = searchCityIndex(fromCityName);

	//cout << "Connected Cities: ";
	for(int i = 0; i < 5; i++) {
		//cout << fromCity.connectedCities[i] << ", ";
	}
	//cout << endl;

	//cout << "Index Start: " << index << endl;

	City connectedCity = searchCityIndex(fromCity.connectedCities[index]);
	//cout << "From City: " << fromCity.name << endl;

	while(!atEnd && !hasCity) {
		//cout << "While Loop Attempt" << endl;
		if(fromCity.connectedCities[index].empty()) {
			//cout << "At End" << endl;
			atEnd = true;
		}else {
			if(connectedCity.visited == false) {
				//cout << "Has City" << endl;
				hasCity = true;
			}else {
				//cout << "Has Visited" << endl;
				index++;
				connectedCity = searchCityIndex(fromCity.connectedCities[index]);
			}
		}
	}
	if(hasCity) {
		//cout << searchCityIndex(fromCity.connectedCities[index]).name << endl;
		return searchCityIndex(fromCity.connectedCities[index]);
	}else {
		//cout << "NO_CITY Index: " << index << endl;
		return NO_CITY;
	}
}

City & Map::searchCityIndex(string theName) {
	int i = 0;
	while(serviceCities[i].name != theName) {
		i++;
	}
	return serviceCities[i];
}
