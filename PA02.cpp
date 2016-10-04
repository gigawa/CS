//  Created by Shehryar Khattak for CS302 Spring 2016 class.

#include <iostream>
#include <fstream>

//function declarations
int kSmall(int k, int array [], int first, int last, int & pivot, int length);
void sortFirstMiddleLast(int array [], int first, int mid, int last);
int partition(int array [], int first, int last, int & pivot);

int main(int argc, char * argv[]){

	//Declerations (insert as needed)
	int kSmall_pos;			//For User Input
	int kSmall_val=0;		//Populate using your algorithm implementation
	int pivot = 0;		    	//Pivot position in array
	int * temp = new int[150];	//temporary array to hold initial read
	int length = 0;			//length of the array

	//User Input DO NOT MODIFY
	std::cout<<"Please enter required kth smallest value:";
	std::cin>>kSmall_pos;


	//File Read code (insert) - This code should be able to parse the data in a text file similar to the provided one and store values in an array for processing.
	std::ifstream fin;
	fin.open(argv[1]);
	
	//reads in file to temporary array
	while(fin >> temp[length]) {
		length++;
	}

	//copies temporary array into correctly sized array and deallocates the temporary array
	int * array = new int[length];
	for(int i = 0; i < length; i++) {
		array[i] = temp[i];
	}
	delete[] temp;
	temp = NULL;

	//begins the log file
	std::ofstream fout;
	fout.open("log.txt");

	fin.close();
	
	//kmsall algorithm implementation or function call (insert) - implement using recursion as indicated
	kSmall_val = kSmall(kSmall_pos, array, 0, length-1, pivot, length);


	//Log file output (insert) - preferred in .txt format acoording to instructions posted on assignment page
	fout.close();


	//Output DO NOT MODIFY
	std::cout<<"kth smallest value = "<<kSmall_val<<std::endl;
}

//recursively searches for kth smallest value
int kSmall(int k, int array [], int first, int last, int & pivot, int length) {
	//finds the pivot index of the array along with the pivot value
	int pivotIndex = partition(array, first, last, pivot);

	//appends to the log file
	std::ofstream fout;
	fout.open("log.txt", std::ofstream::out | std::ofstream::app);
	fout << "PivotIndex: " << pivotIndex << std::endl << "Pivot: " << pivot << std::endl;
	for(int i = 0; i < length; i++) {
		fout<< array[i] << std::endl;
	}
	fout << std::endl <<std::endl;

	//begins narrowing down to the kth smallest value
	if(k < pivotIndex - first + 1) {
		return kSmall(k, array, first, pivotIndex-1, pivot, length);
	}else if(k == pivotIndex - first + 1) {
		return pivot;
	}else {
		return kSmall(k - (pivotIndex - first + 1), array, pivotIndex + 1, last, pivot, length);
	}
	fout.close();
}

//sorts the first middle and last values of the array
void sortFirstMiddleLast(int array [], int first, int mid, int last) {
	
	//switches first and mid if first is bigger
	if(array[first] > array[mid]) {
		int temp = array[mid];
		array[mid] = array[first];
		array[first] = temp;
	}

	//switches mid and last if mid is bigger
	if(array[mid] > array[last]) {
		int temp = array[mid];
		array[mid] = array[last];
		array[last] = temp;
	}

	//switches first and mid if first is bigger
	if(array[first] > array[mid]) {
		int temp = array[mid];
		array[mid] = array[first];
		array[first] = temp;
	}
}

//partitions array into two sections to search
int partition(int array [], int first, int last, int & pivot) {
	//finds the middle of the section of the array we are using
	int mid = first + (last - first) / 2;

	//begins sorting first, middle, and last values of the section of the array we are using
	sortFirstMiddleLast(array, first, mid, last);
	
	//switches values at middle and end-1 of section in use
	int temp = array[mid];
	array[mid] = array[last];
	array[last] = temp;

	//selects starting pivot index and pivot value
	int pivotIndex = last;
	pivot = array[pivotIndex];

	//begins narrowing down area in use
	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	//partitions array by closing in on pivot and switching when needed
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

	//switches pivot index and index from left
	temp = array[pivotIndex];
	array[pivotIndex] = array[indexFromLeft];
	array[indexFromLeft] = temp;
	pivot = array[pivotIndex];

	return pivotIndex;
}
