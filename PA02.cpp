//  Created by Shehryar Khattak for CS302 Spring 2016 class.

#include <iostream>
#include <fstream>

int kSmall(int k, int array [], int first, int last, int & pivot);
void sortFirstMiddleLast(int array [], int first, int mid, int last);
int partition(int array [], int first, int last, int & pivot);

int testLength;
int count = 0;

int main(){

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val=0;		//Populate using your algorithm implementation
	int pivot;		    	//Pivot position in array
	int array [100];
	int length = 0;
	char * filename;

	//User Input DO NOT MODIFY
	std::cout<<"Please enter required kth smallest value:";
	std::cin>>kSmall_pos;


	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
	std::ifstream fin;
	fin.open("data.txt");
	
	while(fin >> array[length]) {
		length++;
		//std::cout<<"Here" << std::endl;
	}

	std::cout << "Length: " << length << std::endl << std::endl;

	for(int i = 0; i < length; i++) {
		std::cout<< array[i] << std::endl;
	}
	
	testLength = length;
	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
	kSmall_val = kSmall(kSmall_pos, array, 0, length-1, pivot);


	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page



	//Output DO NOT MODIFY
	std::cout<<"kth smallest value = "<<kSmall_val<<std::endl;
}

int kSmall(int k, int array [], int first, int last, int & pivot) {
	count++;
	if(count < 10) {
	std::cout << "kSmall" << std::endl;	
	for(int i = 0; i < testLength; i++) {
		std::cout<< array[i] << std::endl;
	}
	std::cout << std::endl <<std::endl;

	int pivotIndex = partition(array, first, last, pivot);
	if(k < pivotIndex - first + 1) {
		return kSmall(k, array, first, pivotIndex-1, pivot);
	}else if(k == pivotIndex - first + 1) {
		return pivot;
	}else {
		return kSmall(k - (pivotIndex - first + 1), array, pivotIndex + 1, last, pivot);
	}
	}else {
		return 0;
	}
}

void sortFirstMiddleLast(int array [], int first, int mid, int last) {
	std::cout << "FirstMiddleLast" << std::endl;	
	for(int i = 0; i < testLength; i++) {
		std::cout<< array[i] << std::endl;
	}
	std::cout << std::endl <<std::endl;

	std::cout << "First: " << first << " Middle: " << mid << " Last: " << last << std::endl << std::endl;
	
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
	std::cout << "FirstMiddleLast2" << std::endl;	
	for(int i = 0; i < testLength; i++) {
		std::cout<< array[i] << std::endl;
	}
	std::cout << std::endl <<std::endl;
}

int partition(int array [], int first, int last, int & pivot) {
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

	std::cout << "partition" << std::endl;	
	for(int i = 0; i < testLength; i++) {
		std::cout<< array[i] << std::endl;
	}
	std::cout << std::endl <<std::endl;

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

	std::cout << "partition2" << std::endl;	
	for(int i = 0; i < testLength; i++) {
		std::cout<< array[i] << std::endl;
	}
	std::cout << std::endl <<std::endl;

	temp = array[pivotIndex];
	array[pivotIndex] = array[indexFromLeft];
	array[indexFromLeft] = temp;

	std::cout << "partition3" << std::endl;	
	for(int i = 0; i < testLength; i++) {
		std::cout<< array[i] << std::endl;
	}
	std::cout << std::endl <<std::endl;

	return pivotIndex;
}
