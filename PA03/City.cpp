#include "City.h"
#include <iostream>

using namespace std;

//default constructor
City::City() {
	name = "None";
	visited = false;
	connectedCities = new string[10];
}

//destructor
City::~City() {
	connectedCities = NULL;
}

//constructor with city name
City::City(string theName) {
	name = theName;
	visited = false;
	connectedCities = new string[10];
}

//constructor with name and if it has been visited
City::City(string theName, bool hasVisited) {
	name = theName;
	visited = hasVisited;
	connectedCities = new string[10];
}

//sets the city to have been visited
void City::setVisited() {
	visited = true;
}

//adds connecting city to connectedCities array
void City::addConnection(const City & connect) {
	int currConnect = 0;
	while(!connectedCities[currConnect].empty()) {
		currConnect++;
	}
	connectedCities[currConnect] = connect.name;
}

//assignment operator
bool City::operator=(const City & city) {
	name = city.name;
	visited = city.visited;

	return true;
}

//compare operator
bool City::City::operator==(const City & rightCity) const {
	if(name == rightCity.name) {
		return true;
	}else {
		return false;
	}
}

//not compare operator
bool City::operator!=(const City & rightCity) const {
	if(name == rightCity.name) {
		return false;
	}else {
		return true;
	}
}


