CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

PA05 : PA05.o PrecondViolatedExcept.o
	$(CC) $(LFLAGS) -std=c++14 PrecondViolatedExcept.o PA06.o -o PA06

PA05.o : PA05.cpp
	$(CC) $(CFLAGS) -std=c++14 PA06.cpp
	
PrecondViolatedExcept.o : PrecondViolatedExcept.cpp PrecondViolatedExcept.h
	$(CC) $(CFLAGS) -std=c++14 PrecondViolatedExcept.cpp

clean:
	\rm *.o PA05
