//  Created by Shehryar Khattak for CS302 Spring 2016 class.

#include <iostream>
#include <fstream>

int main(){

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val=0;		//Populate using your algorithm implementation
	int pivot;		    	//Pivot position in array

	//User Input DO NOT MODIFY
	std::cout<<"Please enter required kth smallest value:";
	std::cin>>kSmall_pos;


	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.



	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated



	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page



	//Output DO NOT MODIFY
	std::cout<<"kth smallest value = "<<kSmall_val<<std::endl;
}

int kSmall(int k, int array [], int first, int last) {
	int pivotIndex = partition;
	if(k < pivotIndex - first + 1) {
		return kSmall(k, array, first, pivotIndex-1);
	}else if(k == pivotIndex - first + 1) {
		return p;
	}else {
		return kSmall(k - (pivotIndex - first + 1), array, pivotIndex + 1, last);
	}
}

void sortFirstMiddleLast(int array [], int first, int mid, int last) {
	if(array[first] > array[mid]) {
		int temp = array[mid];
		array[mid] = array[first];
		array[first] = temp;
	}

	if(array[mid] > array[last]) {
		int temp = array[mid];
		array[mid] = array[last];
		array[last] = temp;
	}

	if(array[first] > array[mid]) {
		int temp = array[mid];
		array[mid] = array[first];
		array[first] = temp;
	}
}

int partition(int array [], int first, int last) {
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(array, first, mid, last);
	
	int temp = array[mid];
	array[mid] = array[last-1];
	array[last-1] = temp;

	int pivotIndex = last - 1;
	pivot = array[pivotIndex];

	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	bool done = false;

	while(!done) {
		while(array[indexFromLeft] < pivot) {
			indexFromLeft++;
		}

		while(array[indexFromRight] > pivot) {
			indexFromRight--;
		}

		if(indexFromLeft < indexFromRight) {
			temp = array[indexFromLeft];
			array[indexFromLeft] = array[indexFromRight];
			array[indexFromRight] = temp;
			indexFromLeft++;
			indexFromRight--;
		}else {
			done = true;
		}
	}
	temp = array[pivotIndex];
	array[pivotIndex] = arra[indexFromLeft];
	array[indexFromLeft] = array[pivotIndex];

	return pivotIndex;
}
