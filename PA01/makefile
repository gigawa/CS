CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA01 : PA01.o PrecondViolatedExcept.o
	$(CC) $(LFLAGS) -std=c++11 PrecondViolatedExcept.o PA01.o -o PA01

PA01.o : PA01.cpp
	$(CC) $(CFLAGS) -std=c++11 PA01.cpp
	
PrecondViolatedExcept.o : PrecondViolatedExcept.cpp PrecondViolatedExcept.h
	$(CC) $(CFLAGS) -std=c++11 PrecondViolatedExcept.cpp

clean:
	\rm *.o PA01
