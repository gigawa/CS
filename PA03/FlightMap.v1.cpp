//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Grant Hooks

#include "Map.h"
#include "City.h"
#include <string>
#include <fstream>

using namespace std;

//default constructor
Map::Map() {

}

//constructor with amount of cities and an array of the strings of city names
Map::Map(int length, string * theCities) {
	numCities = length;
	serviceCities = new City[numCities];
	
	//adds cities to the array of cities
	for(int i = 0; i < numCities; i++) {
		City city(theCities[i]);
		serviceCities[i] = City(theCities[i]);
	}
	ofstream fout;
   	fout.open("HPAir.log.txt", ofstream::out | ofstream::app);
}

//destructor
Map::~Map() {
	delete [] serviceCities;
	serviceCities = NULL;
}

//adds flight connections between cities
void Map::addConnection(string origin, string target) {
	City startCity = searchCityIndex(origin);
	City endCity = searchCityIndex(target);
	endCity.addConnection(startCity);
}

//begins checking if there is a path between cities
bool Map::requestFlight(string origin, string target) {
	unvisitAll();
	City startCity = searchCityIndex(origin);
	City endCity = searchCityIndex(target);

	return isPath(startCity, endCity);
}

bool Map::isPath(City & originCity, City & destinationCity)
{
   ofstream fout;
   fout.open("HPAir.log.txt", ofstream::out | ofstream::app);
   fout << endl << "FlightMap.v1.cpp" << endl;
   fout << endl;
   LinkedStack<City> cityStack;
   
   unvisitAll(); // Clear marks on all cities
   
   // Push origin city onto cityStack and mark it as visited
   cityStack.push(originCity);
   fout << "Stack Push originCity: " << originCity.name << endl;
   markVisited(originCity);
   
   City topCity = cityStack.peek();
   while (!cityStack.isEmpty() && (topCity != destinationCity))
   {
      // The stack contains a directed path from the origin city
      // at the bottom of the stack to the city at the top of the stack
      
      // Find an unvisited city adjacent to the city on the top of the stack
      City nextCity = getNextCity(topCity.name);
      if (nextCity == NO_CITY) {
	 fout << "Stack Pop: " << cityStack.peek().name << endl;
         cityStack.pop(); // No city found; backtrack
      } else // Visit city
      {
         cityStack.push(nextCity);
	 fout << "Stack Push: " << nextCity.name << endl;
         markVisited(nextCity);
      } // end if
      
      if (!cityStack.isEmpty())
         topCity = cityStack.peek();
   } // end while

   if(cityStack.isEmpty()) {
	 fout << "Stack is Empty" << endl;
   }else {
	 fout << "Stack Top: " << cityStack.peek().name << endl;
   }

   fout.close();
   
   return !cityStack.isEmpty();
}  // end isPath

//sets all cities visited to false
void Map::unvisitAll() {
	for(int i = 0; i < numCities; i++) {
		serviceCities[i].visited = false;
	}
}

//marks a city as visited
void Map::markVisited(City & aCity) {
	City * theCity = &searchCityIndex(aCity.name);
	theCity->setVisited();
}

//gets the next possible city
City Map::getNextCity(string fromCityName) {
	bool atEnd = false;
	bool hasCity = false;
	int index = 0;

	//finds original city and connecting cities in array of cities
	City fromCity = searchCityIndex(fromCityName);
	City connectedCity = searchCityIndex(fromCity.connectedCities[index]);

	//runs until a non visited city is found or none is possible
	while(!atEnd && !hasCity) {
		if(fromCity.connectedCities[index].empty()) {
			atEnd = true;
		}else {
			if(connectedCity.visited == false) {
				hasCity = true;
			}else {
				index++;
				connectedCity = searchCityIndex(fromCity.connectedCities[index]);
			}
		}
	}

	//returns if a city is found
	if(hasCity) {
		return searchCityIndex(fromCity.connectedCities[index]);
	}else {
		return NO_CITY;
	}
}

//finds a city in array by name
City & Map::searchCityIndex(string theName) {
	int i = 0;
	while(serviceCities[i].name != theName) {
		i++;
	}
	return serviceCities[i];
}
