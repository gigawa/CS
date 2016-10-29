all : PA04

PA04 : PA04.cpp
	g++ -std=c++11 PA04.cpp BubbleSort.h MergeSort.h CountingSort.h -o PA04

BubbleSort.o : BubbleSort.h
	 g++ -c -std=c++11 BubbleSort.h

MergeSort.o : MergeSort.h
	 g++ -c -std=c++11 MergeSort.h

CountingSort.o : CountingSort.h
	 g++ -c -std=c++11 CountingSort.h

clean:
	\rm *.o PA04 *.gch
