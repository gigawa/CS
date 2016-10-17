#include "City.h"
#include <iostream>

using namespace std;

City::City() {
	name = "None";
	visited = false;
}

City::~City() {
	
}

City::City(string theName) {
	name = theName;
	visited = false;
}

City::City(string theName, bool hasVisited) {
	name = theName;
	visited = hasVisited;
}

void City::setVisited() {
	visited = true;
}

void City::addConnection(const City & connect) {
	int currConnect = 0;
	while(!connectedCities[currConnect].empty()) {
		currConnect++;
	}
	connectedCities[currConnect] = connect.name;
}

bool City::operator=(const City & city) {
	name = city.name;
	visited = city.visited;
}

bool City::City::operator==(const City & rightCity) const {
	if(name == rightCity.name) {
		return true;
	}else {
		return false;
	}
}

bool City::operator!=(const City & rightCity) const {
	if(name == rightCity.name) {
		return false;
	}else {
		return true;
	}
}


