#include "Map.h"
#include "LinkedStack.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	string * serviceCities = new string[50];
	string * flights = new string[100];
	int * price;
	int * flightNumber;
	int serveCityLength = 0;
	int numberOfFlights = 0;

	ifstream fin;
	fin.open("cityFile.txt");

	while(fin >> serviceCities[serveCityLength]) {
		serveCityLength++;
	}

	fin.close();
	fin.open("flightFile.txt");
	
	int i = 0;
	while(fin >> flights[numberOfFlights]) {
		numberOfFlights++;
		fin >> flights[numberOfFlights];
		numberOfFlights++;
		fin >> flightNumber[i];
		fin >> price[i];
		i++;
	}

	Map map(serveCityLength, serviceCities);
}
