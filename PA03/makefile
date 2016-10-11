CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA01 : PA03.o 
	$(CC) $(LFLAGS) -std=c++11 PA03.o -o PA03

PA01.o : PA03.cpp
	$(CC) $(CFLAGS) -std=c++11 PA03.cpp

clean:
	\rm *.o PA03
