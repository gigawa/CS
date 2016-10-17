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

	while(getline(fin, serviceCities[serveCityLength])) {
		if(serviceCities[serveCityLength].back() == '\0') {
			serviceCities[serveCityLength].pop_back();
		}
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
		cout << "has first flight" << endl;
		numberOfFlights++;
		fin >> flights[numberOfFlights];
		cout << "Second Flight " << flights[numberOfFlights] << endl;
		char peekedChar;
		fin >> ws;
		peekedChar = fin.peek();
		cout << "Has peeked: " << peekedChar << endl;
		while(!isdigit(peekedChar)) {
			string extraName;
			fin >> extraName;
			flights[numberOfFlights].append(" ");
			flights[numberOfFlights].append(extraName);
			fin >> ws;
			peekedChar = fin.peek();
		}
		if(flights[numberOfFlights].back() == '\0') {
			flights[numberOfFlights].pop_back();
		}
		cout << "finished while loop" << endl;
		numberOfFlights++;
		fin >> flightNumber[i];
		fin >> price[i];
		i++;
		cout << "From " << flights[numberOfFlights-2] << " to " << flights[numberOfFlights-1] << endl;
		map.addConnection(flights[numberOfFlights-2], flights[numberOfFlights-1]);
	}

	cout << "Flights" << endl;
	for(i = 0; i < numberOfFlights; i++) {
		cout << flights[i] << endl;
	}
	cout << endl;
}
