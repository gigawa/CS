#include "Map.h"
#include "LinkedStack.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	string * serviceCities = new string[50];
	string * flights = new string[100];
	string * requests = new string[100];
	int * price = new int[100];
	int * flightNumber = new int[100];
	int serveCityLength = 0;
	int numberOfFlights = 0;
	int requestNumber = 0;

	ifstream fin;
	fin.open("cityFile.txt");

	while(getline(fin, serviceCities[serveCityLength])) {
		serveCityLength++;
	}

	Map map(serveCityLength, serviceCities);

	fin.close();

	fin.open("flightFile.txt");
	
	int i = 0;
	while(getline(fin, flights[numberOfFlights], ',')) {
		numberOfFlights++;
		fin >> flights[numberOfFlights];
		char peekedChar;
		fin >> ws;
		peekedChar = fin.peek();
		while(!isdigit(peekedChar)) {
			string extraName;
			fin >> extraName;
			flights[numberOfFlights].append(" ");
			flights[numberOfFlights].append(extraName);
			fin >> ws;
			peekedChar = fin.peek();
		}
		numberOfFlights++;
		fin >> flightNumber[i];
		fin >> price[i];
		fin >> ws;
		i++;
		map.addConnection(flights[numberOfFlights-2], flights[numberOfFlights-1]);
	}

	fin.close();

	fin.open("requestFile.txt");
	while(getline(fin, requests[requestNumber], ',')) {
		requestNumber++;
		fin >> ws;
		getline(fin, requests[requestNumber]);
		requestNumber++;
		bool hasRoute = map.requestFlight(requests[requestNumber-2], requests[requestNumber-1]);

		if(hasRoute) {
			cout << "HPAir flies from " << requests[requestNumber-2] << " to " << requests[requestNumber-1] << endl;
		}else {
			cout << "HPAir does not fly from " << requests[requestNumber-2] << " to " << requests[requestNumber-1] << endl;
		}
	}
	
	return 0;
}
