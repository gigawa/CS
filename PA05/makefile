CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA05 : PA05.o PrecondViolatedExcept.o
	$(CC) $(LFLAGS) -std=c++11 PrecondViolatedExcept.o PA05.o -o PA05

PA05.o : PA05.cpp
	$(CC) $(CFLAGS) -std=c++11 PA05.cpp
	
PrecondViolatedExcept.o : PrecondViolatedExcept.cpp PrecondViolatedExcept.h
	$(CC) $(CFLAGS) -std=c++11 PrecondViolatedExcept.cpp

clean:
	\rm *.o PA05
