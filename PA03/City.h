/** City Class
@file City.h
@brief Header file for city
@details establishes city and city operations
@note Created by Grant Hooks
*/

#ifndef CITY_
#define CITY_

#include <string>

using namespace std;

class City {
public:
	/** default constructor */
	City();
	
	/** default destructor */
	~City();

	/** parameterized constructor 
	sets the city name */
	City(string);

	/** parameterized constructor 
	sets the city name and visited */
	City(string, bool);

	/** adds the name of a connected city
	@post connectedCities contains the name of a city that can be flown to*/
	void addConnection(const City & connect);

	/** sets the city as visited
	@pre bool visited may be false
	@post vool visited is true*/
	void setVisited();

	/**sets a city equal to other city*/
	bool operator=(const City & city);

	/**compares if city is equal
	@return True if cities are the same otherwise false*/
	bool operator==(const City & rightCity) const;

	/**compares if city is not equal
	@return False if cities are the same otherwise true*/
	bool operator!=(const City & rightCity) const;

	//if the city has been visited
	bool visited;

	//array of connecting cities
	string * connectedCities;

	//name of the city
	string name;

	int currConnectCity;
	int * flightNumber;
	int * flightPrice;
private:
	
};
#endif
