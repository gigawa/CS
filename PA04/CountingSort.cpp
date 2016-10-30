#include<iostream>
#include<fstream>
#include "CountingSort.h"

using namespace std;

template <class ItemType>
CountingSort<ItemType>::CountingSort(ItemType theArray[], int n, int & c, int & s) {
	ItemType * count = new ItemType[n+1];
	ItemType * sorted = new ItemType[n+1];

	for(int i = 0; i < n; i++) {
		count[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		count[theArray[i]]++;
	}

	for(int i = 1; i < n; i++) {
		count[i] += count[i-1];
	}

	for(int i = n; i > 0; i--) {
		sorted[count[theArray[i]]] = theArray[i];
		count[theArray[i]]--;
	}

	for(int i = 0; i < n; i++) {
		theArray[i] = sorted[i];
	}
}
