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
	//opens the file to log the averages
	ofstream fout;
	fout.open("output.txt");
	long int compare = 0;
	long int swap = 0;
	//length of the array to be sorted
	int dataNumber = 1000;

	//starting time
	int start;
	//stopping time
	int stop;

	//sorting times
	float bubbleSortTime = 0;
	float mergeSortTime = 0;
	float countSortTime = 0;
	float bubbleSortTime2 = 0;
	float mergeSortTime2 = 0;
	float countSortTime2 = 0;

	/**sorts data ranging from 1000 integers to 100000 integers using bubble sort, merge sort, and counting sort*/
	for(int i = 0; i < 3; i++) {
		int attemptNumber = 10;
		//arrays of data to be sorted
		int * data = new int[dataNumber];
		int * sortedData = new int[dataNumber];
		int * bubbleData = new int[dataNumber];
		int * mergeData = new int[dataNumber];
		int * countData = new int[dataNumber];

		//amount of compares and sorts
		float bubbleC = 0;
		float bubbleS = 0;
		float mergeC = 0;
		float mergeS = 0;
		float countC = 0;
		float countS = 0;

		//runs 10 times
		for(int attempts = 0; attempts < attemptNumber; attempts++) {
			srand(time(NULL));

			for(int i = 0; i < dataNumber; i++) {
				data[i] = rand() % dataNumber;
				sortedData[i] = i;
			}

			//copies data into arrays to be sorted
			for(int i = 0; i < dataNumber; i++) {
				bubbleData[i] = data[i];
				mergeData[i] = data[i];
				countData[i] = data[i];
			}

			//Bubble sort
			compare = 0;
			swap = 0;
			start = clock();
			BubbleSort<int> bubbleSort(bubbleData, dataNumber, compare, swap);
			stop = clock();
			bubbleSortTime += (stop-start)/double(CLOCKS_PER_SEC)*1;

			bubbleC += compare;
			bubbleS += swap;

			cout << "Bubble Sort" << endl;
			cout << "Time: " << (stop-start)/double(CLOCKS_PER_SEC)*1 << endl;
			cout << "Comparisons: " << compare << endl;
			cout << "Swaps: " << swap << endl << endl;

			//Merge Sort
			compare = 0;
			swap = 0;
			start = clock();
			MergeSort<int> mergeSort(mergeData, dataNumber, compare, swap);
			stop = clock();
			mergeSortTime += (stop-start)/double(CLOCKS_PER_SEC)*1;

			mergeC += compare;
			mergeS += swap;

			cout << "Merge Sort" << endl;
			cout << "Time: " << (stop-start)/double(CLOCKS_PER_SEC)*1 << endl;
			cout << "Comparisons: " << compare << endl;
			cout << "Swaps: " << swap << endl << endl;

			//Counting Sort
			compare = 0;
			swap = 0;
			start = clock();
			CountingSort<int> countingSort(countData, dataNumber, compare, swap);
			stop = clock();
			countSortTime += (stop-start)/double(CLOCKS_PER_SEC)*1;

			countC += compare;
			countS += swap;

			cout << "Counting Sort" << endl;
			cout << "Time: " << (stop-start)/double(CLOCKS_PER_SEC)*1 << endl;
			cout << "Comparisons: " << compare << endl;
			cout << "Swaps: " << swap << endl << endl;

			cout << "Pre-Sorted array:" << endl;
			//Sorted Bubble sort
			compare = 0;
			swap = 0;
			start = clock();
			BubbleSort<int> bubbleSort2(sortedData, dataNumber, compare, swap);
			stop = clock();
			bubbleSortTime2 += (stop-start)/double(CLOCKS_PER_SEC)*1;

			cout << "Bubble Sort" << endl;
			cout << "Time: " << (stop-start)/double(CLOCKS_PER_SEC)*1 << endl;
			cout << "Comparisons: " << compare << endl;
			cout << "Swaps: " << swap << endl << endl;

			//Sorted Merge Sort
			compare = 0;
			swap = 0;
			start = clock();
			MergeSort<int> mergeSort2(sortedData, dataNumber, compare, swap);
			stop = clock();
			mergeSortTime2 += (stop-start)/double(CLOCKS_PER_SEC)*1;

			cout << "Merge Sort" << endl;
			cout << "Time: " << (stop-start)/double(CLOCKS_PER_SEC)*1 << endl;
			cout << "Comparisons: " << compare << endl;
			cout << "Swaps: " << swap << endl << endl;

			//Sorted Counting Sort
			compare = 0;
			swap = 0;
			start = clock();
			CountingSort<int> countingSort2(sortedData, dataNumber, compare, swap);
			stop = clock();
			countSortTime2 += (stop-start)/double(CLOCKS_PER_SEC)*1;

			cout << "Counting Sort" << endl;
			cout << "Time: " << (stop-start)/double(CLOCKS_PER_SEC)*1 << endl;
			cout << "Comparisons: " << compare << endl;
			cout << "Swaps: " << swap << endl << endl;
		}
		
		//displays averages for the sorts run
		cout << "For " << dataNumber << " integers: " << endl;
		cout << "Average Bubble Sort Time: " << bubbleSortTime/10 << endl;
		cout << "Average Bubble Sort Comparisons: " << bubbleC/10 << " Swaps: " << bubbleS/10 << endl;
		cout << "Average Merge Sort Time: " << mergeSortTime/10 << endl;
		cout << "Average Merge Sort Comparisons: " << mergeC/10 << " Swaps: " << mergeS/10 << endl;
		cout << "Average Counting Sort Time: " << countSortTime/10 << endl;
		cout << "Average Counting Sort Comparisons: " << countC/10 << " Swaps: " << countS/10 << endl;
		cout << "Using a sorted array: " << endl;
		cout << "Average Bubble Sort Time: " << bubbleSortTime2/10 << endl;
		cout << "Average Merge Sort Time: " << mergeSortTime2/10 << endl;
		cout << "Average Counting Sort Time: " << countSortTime2/10 << endl;

		fout << "For " << dataNumber << " integers: " << endl;
		fout << "Average Bubble Sort Time: " << bubbleSortTime/10 << endl;
		fout << "Average Bubble Sort Comparisons: " << bubbleC/10 << " Swaps: " << bubbleS/10 << endl;
		fout << "Average Merge Sort Time: " << mergeSortTime/10 << endl;
		fout << "Average Merge Sort Comparisons: " << mergeC/10 << " Swaps: " << mergeS/10 << endl;
		fout << "Average Counting Sort Time: " << countSortTime/10 << endl;
		fout << "Average Counting Sort Comparisons: " << countC/10 << " Swaps: " << countS/10 << endl << endl;
		fout << "Using a sorted array: " << endl;
		fout << "Average Bubble Sort Time: " << bubbleSortTime2/10 << endl;
		fout << "Average Merge Sort Time: " << mergeSortTime2/10 << endl;
		fout << "Average Counting Sort Time: " << countSortTime2/10 << endl << endl;

		//increases the number of items to be sorted
		dataNumber *= 10;
		delete[] data;
		delete[] countData;
		delete[] mergeData;
		delete[] bubbleData;

	}

	//closes file
	fout.close();

	return 0;
}
