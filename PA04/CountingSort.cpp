#include<iostream>
#include<fstream>
#include "CountingSort.h"

using namespace std;

template <class ItemType>
CountingSort<ItemType>::CountingSort(ItemType theArray[], int n, int & c, int & s) {
	ItemType * count = new ItemType[n];
	ItemType * sorted = new ItemType[n];

	for(int i = 0; i < n; i++) {
		count[i] = 0;
	}

	//Print array
	cout << "First" << endl;
	for(int i = 0; i < n; i++) {
		cout << count[i] << ", ";
	}
	cout << endl;

	for(int i = 0; i < n; i++) {
		count[theArray[i]]++;
	}

	//Print array
	cout << "Second" << endl;
	for(int i = 0; i < n; i++) {
		cout << count[i] << ", ";
	}
	cout << endl;

	for(int i = 1; i < n; i++) {
		count[i] += count[i-1];
	}

	//Print array
	cout << "Third" << endl;
	for(int i = 0; i < n; i++) {
		cout << count[i] << ", ";
	}
	cout << endl;

	for(int i = n; i > 0; i--) {
		sorted[count[theArray[i]]] = theArray[i];
		count[theArray[i]]--;
	}

	//Print array
	cout << "Fourth" << endl;
	for(int i = 0; i < n; i++) {
		cout << sorted[i] << ", ";
	}

	for(int i = 0; i < n; i++) {
		theArray[i] = sorted[i];
	}
}
