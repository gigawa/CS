#include<iostream>
#include<fstream>
#include "CountingSort.h"

using namespace std;

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order using a count of each item;
 @param theArray  The given array.
 @param n  The size of theArray. */

template <class ItemType>
CountingSort<ItemType>::CountingSort(ItemType theArray[], int n, long int & c, long int & s) {
	ItemType * count = new ItemType[n+1];
	ItemType * sorted = new ItemType[n+1];

	//sets all counts to 0
	for(int i = 0; i < n; i++) {
		count[i] = 0;
	}

	//counts the times an item occurs
	for(int i = 1; i < n; i++) {
		count[theArray[i]]++;
	}

	//cumulative sums
	for(int i = 1; i < n; i++) {
		count[i] += count[i-1];
	}

	//places items in correct position
	for(int i = n; i > 0; i--) {
		sorted[count[theArray[i]]] = theArray[i];
		count[theArray[i]]--;
	}

	//copies sorted array int array
	for(int i = 0; i < n; i++) {
		theArray[i] = sorted[i];
	}
}
