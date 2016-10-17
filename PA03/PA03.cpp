#include "Map.h"
#include "LinkedStack.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	string * serviceCities = new string[50];
	string * flights = new string[100];
	int * price = new int[100];
	int * flightNumber = new int[100];
	int serveCityLength = 0;
	int numberOfFlights = 0;

	ifstream fin;
	fin.open("cityFile.txt");

	while(getline(fin, serviceCities[serveCityLength], ',')) {
		
		serveCityLength++;
	}

	cout << "Initialize map" << endl;
	Map map(serveCityLength, serviceCities);

	cout << "Close file" << endl;
	fin.close();

	fin.open("flightFile.txt");
	
	cout << "get flights" << endl;
	int i = 0;
	while(getline(fin, flights[numberOfFlights], ',')) {
		numberOfFlights++;
		fin >> flights[numberOfFlights];
		numberOfFlights++;
		fin >> flightNumber[i];
		fin >> price[i];
		i++;
		map.addConnection(flights[numberOfFlights-2], flights[numberOfFlights-1]);
	}

	/*cout << "Flights" << endl;
	for(i = 0; i < numberOfFlights; i++) {
		cout << flights[i] << endl;
	}
	cout << endl;*/	
}
