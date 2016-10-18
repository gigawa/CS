all : PA03

PA03 : PA03.cpp City.o Map.o Map2.o
	g++ -std=c++11 PA03.cpp City.o FlightMap.v1.o FlightMap.v2.o -o PA03

City.o : City.cpp City.h
	 g++ -c -std=c++11 City.cpp City.h

Map.o : FlightMap.v1.cpp Map.h
	g++ -c -std=c++11 FlightMap.v1.cpp Map.h

Map2.o : FlightMap.v2.cpp Map2.h
	g++ -c -std=c++11 FlightMap.v2.cpp Map2.h

clean:
	\rm *.o PA03 *.gch
