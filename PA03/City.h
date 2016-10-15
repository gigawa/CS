#ifndef CITY_
#define CITY_

class City {
public:
	City();
	City(char *);
	City(char *, bool);
	char * name;
	bool visited;
	bool operator=(const City & city);
	bool operator==(const City & rightCity) const;
	bool operator!=(const City & rightCity) const;
	City * connectedCity;
private:
	
};

#include "City.cpp"
#endif
