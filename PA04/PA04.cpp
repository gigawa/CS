#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "BubbleSort.h"
#include "MergeSort.h"
#include "CountingSort.h"

using namespace std;

int main() {
	int compare = 0;
	int swap = 0;
	int dataNumber = 100000;
	int * data = new int[dataNumber];
	int * bubbleData = new int[dataNumber];
	int * mergeData = new int[dataNumber];
	int * countData = new int[dataNumber];

	int start;
	int stop;
	float bubbleSortTime = 0;
	float mergeSortTime = 0;
	float countSortTime = 0;

	for(int attempts = 0; attempts < 10; attempts++) {
		srand(time(NULL));

		for(int i = 0; i < dataNumber; i++) {
			data[i] = rand() % dataNumber;
		}

		for(int i = 0; i < dataNumber; i++) {
			bubbleData[i] = data[i];
			mergeData[i] = data[i];
			countData[i] = data[i];
		}

		//Bubble sort
		start = clock();
		BubbleSort<int> bubbleSort(bubbleData, dataNumber, compare, swap);
		stop = clock();
		bubbleSortTime += (stop-start)/double(CLOCKS_PER_SEC)*1;

		cout << "Bubble Sort" << endl;
		cout << "Time: " << bubbleSortTime << endl;
		cout << "Comparisons: " << compare << endl;
		cout << "Swaps: " << swap << endl << endl;

		//Merge Sort
		start = clock();
		MergeSort<int> mergeSort(mergeData, dataNumber, compare, swap);
		stop = clock();
		mergeSortTime += (stop-start)/double(CLOCKS_PER_SEC)*1;

		cout << "Merge Sort" << endl;
		cout << "Time: " << mergeSortTime << endl;
		cout << "Comparisons: " << compare << endl;
		cout << "Swaps: " << swap << endl << endl;

		//Counting Sort
		start = clock();
		CountingSort<int> countingSort(countData, dataNumber, compare, swap);
		stop = clock();
		countSortTime += (stop-start)/double(CLOCKS_PER_SEC)*1;

		cout << "Counting Sort" << endl;
		cout << "Time: " << countSortTime << endl;
		cout << "Comparisons: " << compare << endl;
		cout << "Swaps: " << swap << endl << endl;
	}

	cout << "Average Bubble Sort Time: " << bubbleSortTime/10 << endl;
	cout << "Average Merge Sort Time: " << mergeSortTime/10 << endl;
	cout << "Average Counting Sort Time: " << countSortTime/10 << endl;

	delete[] data;
	delete[] countData;
	delete[] mergeData;
	delete[] bubbleData;

	return 0;
}
