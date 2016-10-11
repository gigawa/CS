#include "City.h"
#include <iostream>

City::City() {
	name = NULL;
	visited = false;
}

City::City(char * theName) {
	name = theName;
}

City::City(char * theName, bool hasVisited) {
	name = theName;
	visited = hasVisited;
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


