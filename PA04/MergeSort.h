#ifndef MERGE_SORT_
#define MERGE_SORT_

template <class ItemType>
class MergeSort {
public:
	MergeSort(ItemType theArray[], int size, long int & compare, long int & swap);
	void mergeSort(ItemType theArray[], int first, int last, long int & compare, long int & swap);
	void merge(ItemType theArray[], int first, int mid, int last, long int & compare, long int & swap);
private:
	int MAX_SIZE;
};

#include "MergeSort.cpp"
#endif
