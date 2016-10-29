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
	int dataNumber = 10;
	int * data = new int[dataNumber];
	int * bubbleData = new int[dataNumber];
	int * mergeData = new int[dataNumber];
	int * countData = new int[dataNumber];

	int start;
	int stop;
	float sortTime;

	for(int attempts = 0; attempts < 1; attempts++) {
		srand(time(NULL));

		for(int i = 0; i < dataNumber; i++) {
			data[i] = rand() % dataNumber;
		}

		for(int i = 0; i < dataNumber; i++) {
			bubbleData[i] = data[i];
			mergeData[i] = data[i];
			countData[i] = data[i];
		}

		cout << "Unsorted" << endl;
		for(int i = 0; i < dataNumber; i++) {
			cout << data << ", ";
		}
		cout << endl;

		/*//Bubble sort
		start = clock();
		BubbleSort<int> bubbleSort(bubbleData, dataNumber, compare, swap);
		stop = clock();
		sortTime = (stop-start)/double(CLOCKS_PER_SEC)*1;

		cout << "Bubble Sort" << endl;
		cout << "Time: " << sortTime << endl;
		cout << "Comparisons: " << compare << endl;
		cout << "Swaps: " << swap << endl << endl;

		//Merge Sort
		start = clock();
		MergeSort<int> mergeSort(mergeData, dataNumber, compare, swap);
		stop = clock();
		sortTime = (stop-start)/double(CLOCKS_PER_SEC)*1;

		cout << "Merge Sort" << endl;
		cout << "Time: " << sortTime << endl;
		cout << "Comparisons: " << compare << endl;
		cout << "Swaps: " << swap << endl << endl;

		*///Counting Sort
		start = clock();
		CountingSort<int> countingSort(countData, dataNumber, compare, swap);
		stop = clock();
		sortTime = (stop-start)/double(CLOCKS_PER_SEC)*1;

		cout << "Counting Sort" << endl;
		cout << "Time: " << sortTime << endl;
		cout << "Comparisons: " << compare << endl;
		cout << "Swaps: " << swap << endl << endl;

		for(int i = 0; i < dataNumber; i++) {
			cout << countData << ", ";
			cout << data << ", ";
		}
		cout << endl;
	}

	return 0;
}
