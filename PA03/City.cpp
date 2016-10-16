#include "City.h"
#include <iostream>

using namespace std;

City::City() {
	cout << "City" << endl;
	name = "None";
	visited = false;
}

City::~City() {
	
}

City::City(string theName) {
	name = theName;
	visited = false;
	connectedCities = new string[10];
}

City::City(string theName, bool hasVisited) {
	name = theName;
	visited = hasVisited;
	connectedCities = new string[10];
}

void City::addConnection(const City & connect) {
	int i = 0;
	while(connectedCities[i] != "None") {
		i++;
	}
	connectedCities[i] = connect.name;
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

