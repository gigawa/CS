#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "BubbleSort.h"

using namespace std;

struct Event {
	bool arrival;
	int time;
	int length;
};

void processArrival(Event arrivalEvent, ArrayQueue<Event> & eventQueue, ArrayQueue<Event> & bankLine, int teller);
void processDeparture(Event departureEvent, ArrayQueue<Event> & eventQueue, ArrayQueue<Event> & bankLine, int teller);
void simulate();
void simulate2();

void merge(int theArray[], int first, int mid, int last);

void mergeSort(int theArray[], int first, int last);

bool * tellerAvailable = new bool[3];
int currentTime;
int waitTime = 0;
int lineLength = 0;
int maxLineLength = 0;

int main() {
	srand(time(NULL));
	int people = 10000;
	int * eventTimes = new int[people];
	int start;
	int stop;
	int simTime;
	ofstream fout;
	fout.open("data.txt");

	for(int i = 0; i < people; i++) {
		eventTimes[i] = rand() % 100000;
	}

	mergeSort(eventTimes, 0, people);

	for(int i = 0; i < people; i++) {
		fout << eventTimes[i] << endl;
		fout << (rand() % 100) + 1 << endl;
	}

	delete[] eventTimes;

	fout.close();

	start = clock();
	simulate();
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	cout << "Simulation Time: " << simTime << endl;
	cout << "Virtual Time: " << currentTime << endl;
	cout << "Average Wait: " << waitTime/people << endl;
	cout << "Maximum Length of Line: " << maxLineLength << endl;

	start = clock();
	simulate2();
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	cout << "Simulation Time: " << simTime << endl;
	cout << "Virtual Time: " << currentTime << endl;
	cout << "Average Wait: " << waitTime/people << endl;
	cout << "Maximum Length of Line: " << maxLineLength << endl;

	return 0;
}

void simulate() {
	ArrayQueue<Event> bankLine;
	ArrayQueue<Event> eventQueue;
	tellerAvailable[0] = true;

	ifstream fin;
	fin.open("data.txt");
	
	int temp;
	//reads in file to temporary array
	while(fin >> temp) {
		Event arrivalEvent;
		arrivalEvent.arrival = true;
		arrivalEvent.time = temp;
		fin >> arrivalEvent.length;
		eventQueue.enqueue(arrivalEvent);
	}
	
	while(!eventQueue.isEmpty()) {
		Event newEvent = eventQueue.peekFront();
		currentTime = newEvent.time;
		if(lineLength > maxLineLength) {
			maxLineLength = lineLength;
		}

		if(newEvent.arrival) {
			processArrival(newEvent, eventQueue, bankLine, 0);
			lineLength++;
			//cout << "Arrival" << endl;
		} else {
			processDeparture(newEvent, eventQueue, bankLine, 0);
			lineLength--;
			//cout << "Departure" << endl;
		}
	}
}

void simulate2() {
	ArrayQueue<Event> * bankLine = new ArrayQueue<Event>[3];
	ArrayQueue<Event> * eventQueue = new ArrayQueue<Event>[3];
	for(int i = 0; i < 3; i++) {
		tellerAvailable[i] = true;
	}

	int currentTeller = 0;

	ifstream fin;
	fin.open("data.txt");
	
	int temp;
	//reads in file to temporary array
	while(fin >> temp) {
		Event arrivalEvent;
		arrivalEvent.arrival = true;
		arrivalEvent.time = temp;
		fin >> arrivalEvent.length;
		eventQueue[currentTeller].enqueue(arrivalEvent);
	}
	
	while(!eventQueue[currentTeller].isEmpty()) {
		Event newEvent = eventQueue[currentTeller].peekFront();
		currentTime = newEvent.time;
		if(lineLength > maxLineLength) {
			maxLineLength = lineLength;
		}

		if(newEvent.arrival) {
			processArrival(newEvent, eventQueue[currentTeller], bankLine[currentTeller], currentTeller);
			lineLength++;
			//cout << "Arrival" << endl;
		} else {
			processDeparture(newEvent, eventQueue[currentTeller], bankLine[currentTeller], currentTeller);
			lineLength--;
			//cout << "Departure" << endl;
		}

		if(currentTeller == 2) {
			currentTeller = 0;
		}else {
			currentTeller++;
		}
	}
}

void processArrival(Event arrivalEvent, ArrayQueue<Event> & eventQueue, ArrayQueue<Event> & bankLine, int teller) {
	eventQueue.dequeue();
	
	if(bankLine.isEmpty() && tellerAvailable[teller]) {
		int departureTime = currentTime + arrivalEvent.length;
		Event newDeparture;
		newDeparture.arrival = false;
		newDeparture.time = departureTime;
		eventQueue.enqueue(newDeparture);
		tellerAvailable[teller] = false;
	} else {
		bankLine.enqueue(arrivalEvent);
	}
}

void processDeparture(Event departureEvent, ArrayQueue<Event> & eventQueue, ArrayQueue<Event> & bankLine, int teller) {
	eventQueue.dequeue();
	
	if(!bankLine.isEmpty()) {
		waitTime += (currentTime - bankLine.peekFront().length);
		int length = bankLine.peekFront().length;
		bankLine.dequeue();
		int departureTime = currentTime + length;
		Event newDeparture;
		newDeparture.arrival = false;
		newDeparture.time = departureTime;
		newDeparture.length = length;
		eventQueue.enqueue(newDeparture);
	}else {
		tellerAvailable[teller] = true;
	}
}

/** Merges two sorted array segments theArray[first..mid] and
    theArray[mid+1..last] into one sorted array.
 @pre  first <= mid <= last. The subarrays theArray[first..mid] and
    theArray[mid+1..last] are each sorted in increasing order.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the beginning of the first segment in
    theArray.
 @param mid  The index of the end of the first segment in theArray;
    mid + 1 marks the beginning of the second segment.
 @param last  The index of the last element in the second segment in
    theArray.
 @note  This function merges the two subarrays into a temporary
    array and copies the result into the original array theArray. */
void merge(int theArray[], int first, int mid, int last)
{
   int tempArray[100000]; // Temporary array
                                 // Initialize the local indices to indicate the subarrays
   int first1 = first;           // Beginning of first subarray
   int last1 = mid;              // End of first subarray
   int first2 = mid + 1;         // Beginning of second subarray
   int last2 = last;             // End of second subarray
   
   // While both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;           // Next available location in tempArray
   while ((first1 <= last1) && (first2 <= last2))
   {
      // At this point, tempArray[first..index–1] is in order
      if (theArray[first1] <= theArray[first2])
      {
         tempArray[index] = theArray[first1];
         first1++;
      }
      else
      {
         tempArray[index] = theArray[first2];
         first2++;
      }  // end if
      
      index++;
   }  // end while
   
   // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
      // At this point, tempArray[first..index–1] is in order
      tempArray[index] = theArray[first1];
      first1++;
      index++;
   }  // end while
   
   // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      // At this point, tempArray[first..index–1] is in order
      tempArray[index] = theArray[first2];
      first2++;
      index++;
   }  // end for
   
   // Copy the result back into the original array
   for (index = first; index <= last; index++)
      theArray[index] = tempArray[index];
}  // end merge

/** Sorts the items in an array into ascending order.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted in ascending order.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
void mergeSort(int theArray[], int first, int last)
{
   if (first < last)
   {
      // Sort each half
      int mid = first + (last - first) / 2; // Index of midpoint
      
      // Sort left half theArray[first..mid]
      mergeSort(theArray, first, mid);
      
      // Sort right half theArray[mid+1..last]
      mergeSort(theArray, mid + 1, last);
      
      // Merge the two halves
      merge(theArray, first, mid, last);
   }  // end if
}  // end mergeSort
