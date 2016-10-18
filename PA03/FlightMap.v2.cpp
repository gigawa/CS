//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Grant Hooks

#include "Map2.h"
#include "City.h"
#include <string>
#include <fstream>

using namespace std;

//default constructor
Map2::Map2() {

}

//constructor with amount of cities and an array of the strings of city names
Map2::Map2(int length, string * theCities) {
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
Map2::~Map2() {
	delete [] serviceCities;
	serviceCities = NULL;
}

//adds flight connections between cities
void Map2::addConnection(string origin, string target) {
	City startCity = searchCityIndex(origin);
	City endCity = searchCityIndex(target);
	endCity.addConnection(startCity);
}

//begins checking if there is a path between cities
bool Map2::requestFlight(string origin, string target) {
	unvisitAll();
	City startCity = searchCityIndex(origin);
	City endCity = searchCityIndex(target);

	return isPath(startCity, endCity);
}

bool Map2::isPath(City & originCity, City & destinationCity)
{
   ofstream fout;
   fout.open("HPAir.log.txt", ofstream::out | ofstream::app);
   fout << endl << "FlightMap.v2.cpp" << endl;
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
void Map2::unvisitAll() {
	for(int i = 0; i < numCities; i++) {
		serviceCities[i].visited = false;
		serviceCities[i].currConnectCity = 0;
	}
}

//marks a city as visited
void Map2::markVisited(City & aCity) {
	City * theCity = &searchCityIndex(aCity.name);
	theCity->setVisited();
}

//gets the next possible city
City Map2::getNextCity(string fromCityName) {
	bool atEnd = false;
	bool hasCity = false;
	int index = 0;

	ofstream fout;
   	fout.open("HPAir.log.txt", ofstream::out | ofstream::app);

	//finds original city and connecting cities in array of cities
	City * fromCity = &searchCityIndex(fromCityName);
	index = fromCity->currConnectCity;
	City connectedCity = searchCityIndex(fromCity->connectedCities[index]);

	fout << "getNextCity Start Index: " << index << endl;

	//runs until a non visited city is found or none is possible
	while(!atEnd && !hasCity) {
		if(fromCity->connectedCities[index].empty()) {
			atEnd = true;
		}else {
			if(connectedCity.visited == false) {
				hasCity = true;
			}else {
				index++;
				connectedCity = searchCityIndex(fromCity->connectedCities[index]);
			}
		}
	}

	
	fromCity->currConnectCity = index;
	fout.close();
	//returns if a city is found
	if(hasCity) {
		return searchCityIndex(fromCity->connectedCities[index]);
	}else {
		return NO_CITY;
	}
}

//finds a city in array by name
City & Map2::searchCityIndex(string theName) {
	int i = 0;
	while(serviceCities[i].name != theName) {
		i++;
	}
	return serviceCities[i];
}
