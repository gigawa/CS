#include<iostream>
#include<fstream>
#include<string>
#include "BubbleSort.h"
#include "MergeSort.h"

using namespace std;

int main() {
	int compare = 0;
	int swap = 0;
	int dataNumber;
	char * fileName = new char[20];
	cout << "Enter number of values to be sorted: ";
	cin >> dataNumber;
	int * data = new int[dataNumber];
	int * bubbleData = new int[dataNumber];
	int * mergeData = new int[dataNumber];
	cout << "Enter the file name: ";
	cin >> fileName;

	ifstream fin;
	fin.open(fileName);
	
	int index = 0;
	while(fin >> data[index])
	{
		index++;
	}

	for(int i = 0; i < dataNumber; i++) {
		bubbleData[i] = data[i];
		mergeData[i] = data[i];
	}

	//Bubble sort
	BubbleSort<int> bubbleSort(bubbleData, dataNumber, compare, swap);

	cout << "Bubble Sort" << endl;
	for(int i = 0; i < dataNumber; i++) {
		cout << bubbleData[i] << ", ";
	}
	cout << "Comparisons: " << compare << endl;
	cout << "Swaps: " << swap << endl << endl;

	//Merge Sort
	MergeSort<int> mergeSort(mergeData, dataNumber, compare, swap);

	cout << "Merge Sort" << endl;
	for(int i = 0; i < dataNumber; i++) {
		cout << mergeData[i] << ", ";
	}
	cout << "Comparisons: " << compare << endl;
	cout << "Swaps: " << swap << endl << endl;

	return 0;
}
