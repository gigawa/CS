#include "Map.h"
#include "Map2.h"
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
	ofstream fout;
	fin.open("cityFile.txt");
	fout.open("HPAir.log.txt");
	fout.close();

	//reads in all serviced cities
	while(getline(fin, serviceCities[serveCityLength])) {
		serveCityLength++;
	}

	//initializes maps
	Map map(serveCityLength, serviceCities);
	Map2 map2(serveCityLength, serviceCities);

	fin.close();

	fin.open("flightFile.txt");
	
	//reads in flight paths
	int i = 0;
	while(getline(fin, flights[numberOfFlights], ',')) {
		numberOfFlights++;
		fin >> flights[numberOfFlights];
		char peekedChar;
		fin >> ws;
		peekedChar = fin.peek();
		//checks if reading int or string
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
		//adds flight connections to map
		map.addConnection(flights[numberOfFlights-2], flights[numberOfFlights-1]);
		map2.addConnection(flights[numberOfFlights-2], flights[numberOfFlights-1]);
	}

	fin.close();

	//reads in flight requests
	fin.open("requestFile.txt");
	while(getline(fin, requests[requestNumber], ',')) {
		requestNumber++;
		fin >> ws;
		getline(fin, requests[requestNumber]);
		requestNumber++;
		//checks if there is a route
		bool hasRoute = map.requestFlight(requests[requestNumber-2], requests[requestNumber-1]);
		bool hasRoute2 = map2.requestFlight(requests[requestNumber-2], requests[requestNumber-1]);

		//prints if a path exists or not
		if(hasRoute) {
			cout << "HPAir flies from " << requests[requestNumber-2] << " to " << requests[requestNumber-1] << endl;
		}else {
			cout << "HPAir does not fly from " << requests[requestNumber-2] << " to " << requests[requestNumber-1] << endl;
		}
	}
	
	return 0;
}
