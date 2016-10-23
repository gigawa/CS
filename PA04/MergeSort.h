#ifndef MERGE_SORT_
#define MERGE_SORT_

template <class ItemType>
class MergeSort {
public:
	MergeSort(ItemType theArray[], int size, int & compare, int & swap);
	void mergeSort(ItemType theArray[], int first, int last, int & compare, int & swap);
	void merge(ItemType theArray[], int first, int mid, int last, int & compare, int & swap);
private:
	int MAX_SIZE;
};

#include "MergeSort.cpp"
#endif
