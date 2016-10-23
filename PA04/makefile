all : PA04

PA03 : PA04.cpp BubbleSort.o MergeSort.o
	g++ -std=c++11 PA04.cpp BubbleSort.o MergeSort.o -o PA04

BubbleSort.o : BubbleSort.cpp BubbleSort.h
	 g++ -c -std=c++11 BubbleSort.cpp BubbleSort.h

MergeSort.o : MergeSort.cpp MergeSort.h
	 g++ -c -std=c++11 MergeSort.cpp MergeSort.h

clean:
	\rm *.o PA04 *.gch
