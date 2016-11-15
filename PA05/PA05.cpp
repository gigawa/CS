#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using namespace std;

struct Event {
	bool arrival;
	int time;
	int length;
};

//processing events
void processArrival(Event arrivalEvent, ArrayQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller);
void processDeparture(Event departureEvent, ArrayQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller);

//simulations
void simulate();
void simulate2();

//sorting
void merge(int theArray[], int first, int mid, int last);
void mergeSort(int theArray[], int first, int last);

void mergeEvent(Event theArray[], int first, int mid, int last);
void mergeSortEvent(Event theArray[], int first, int last);

//variables
bool * tellerAvailable = new bool[3];
int currentTime = 0;
int lineLength = 0;
int maxLineLength = 0;

int main() {
	srand(time(NULL));
	int people = 10;
	int * eventTimes = new int[people];
	int start;
	int stop;
	float simTime;
	ofstream fout;
	fout.open("data.txt");

	for(int i = 0; i < people; i++) {
		eventTimes[i] = rand() % 10;
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
	//cout << "Average Wait: " << waitTime/people << endl;
	cout << "Maximum Length of Line: " << maxLineLength << endl;

	start = clock();
	simulate2();
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	cout << "Simulation Time: " << simTime << endl;
	cout << "Virtual Time: " << currentTime << endl;
	//cout << "Average Wait: " << waitTime/people << endl;
	//cout << "Maximum Length of Line: " << maxLineLength << endl;

	return 0;
}

void simulate() {

	ArrayQueue<Event> bankLineA;
	ArrayQueue<Event> eventQueueA;
	LinkedQueue<Event> bankLineL;
	LinkedQueue<Event> eventQueueL;
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
		eventQueueA.enqueue(arrivalEvent);
		eventQueueL.enqueue(arrivalEvent);
		//created++;
	}
	
	while(!eventQueueA.isEmpty()) {
		Event newEvent = eventQueueA.peekFront();
		//Event newEventL = eventQueueL.peekFront();
		currentTime = newEvent.time;
		if(lineLength > maxLineLength) {
			maxLineLength = lineLength;
		}

		//events++;
		if(newEvent.arrival) {
			processArrival(newEvent, eventQueueA, bankLineA, eventQueueL, bankLineL, 0);
			//cout << "Arrival" << endl;
		} else {
			processDeparture(newEvent, eventQueueA, bankLineA, eventQueueL, bankLineL, 0);
			//cout << "Departure" << endl;
		}
	}
	fin.close();
}

void simulate2() {
	ArrayQueue<Event> * bankLineA = new ArrayQueue<Event>[3];
	ArrayQueue<Event> * eventQueueA = new ArrayQueue<Event>[3];
	LinkedQueue<Event> * bankLineL = new LinkedQueue<Event>[3];
	LinkedQueue<Event> * eventQueueL = new LinkedQueue<Event>[3];
	for(int i = 0; i < 3; i++) {
		tellerAvailable[i] = true;
	}
	//int events = 0;
	//int created = 0;

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
		eventQueueA[currentTeller].enqueue(arrivalEvent);
		eventQueueL[currentTeller].enqueue(arrivalEvent);
		if(currentTeller < 2) {
			currentTeller++;
		}else {
			currentTeller = 0;
		}
	}
	
	for(int i = 0; i < 3; i++) {
		while(!eventQueueA[i].isEmpty()) {
			Event newEvent = eventQueueA[i].peekFront();
			currentTime = newEvent.time;

			if(newEvent.arrival) {
				processArrival(newEvent, eventQueueA[i], bankLineA[i], eventQueueL[i], bankLineL[i], i);
			} else {
				processDeparture(newEvent, eventQueueA[i], bankLineA[i], eventQueueL[i], bankLineL[i], i);
			}
		}
	}
	fin.close();
}

void processArrival(Event arrivalEvent, ArrayQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller) {
	eventQueueA.dequeue();
	
	if(bankLineA.isEmpty() && tellerAvailable[teller]) {
		int departureTime = currentTime + arrivalEvent.length;
		Event newDeparture;
		newDeparture.arrival = false;
		newDeparture.time = departureTime;
		eventQueueA.enqueue(newDeparture);
		tellerAvailable[teller] = false;
		lineLength++;
	} else {
		bankLineA.enqueue(arrivalEvent);
	}
}

void processDeparture(Event departureEvent, ArrayQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller) {
	eventQueueA.dequeue();
	
	if(!bankLineA.isEmpty()) {
		//waitTime += (currentTime - bankLineA.peekFront().length);
		int length = bankLineA.peekFront().length;
		bankLineA.dequeue();
		//lineLength++;
		int departureTime = currentTime + length;
		Event newDeparture;
		newDeparture.arrival = false;
		newDeparture.time = departureTime;
		newDeparture.length = length;
		eventQueueA.enqueue(newDeparture);
	}else {
		tellerAvailable[teller] = true;
		//lineLength--;
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
void mergeEvent(Event theArray[], int first, int mid, int last)
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
      if (theArray[first1].time <= theArray[first2].time)
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
void mergeSortEvent(Event theArray[], int first, int last)
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
