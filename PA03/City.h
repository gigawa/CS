#ifndef CITY_
#define CITY_

#include <string>

using namespace std;

class City {
public:
	City();
	~City();
	City(string);
	City(string, bool);
	void addConnection(const City & connect);
	bool visited;
	bool operator=(const City & city);
	bool operator==(const City & rightCity) const;
	bool operator!=(const City & rightCity) const;
	string * connectedCities;
	string name;
private:

};

#include "City.cpp"
#endif
