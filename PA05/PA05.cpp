#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "SL_PriorityQueue.h"
#include "Event.h"

using namespace std;

//processing events
void processArrival(Event arrivalEvent, SL_PriorityQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller);
void processDeparture(Event departureEvent, SL_PriorityQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller);

//simulations
//one queue one teller
void simulate();
//3 queues and tellers
void simulate2();
//1 queue 3 tellers
void simulate3();
//arbitrary queue and teller
void simulate4(int tellers);

//sorting
void merge(int theArray[], int first, int mid, int last);
void mergeSort(int theArray[], int first, int last);

//variables
bool * tellerAvailable = new bool[3];
int * currentTime = new int[3];
int * lineLength = new int[3];
int maxLineLength = 0;
int waitTime = 0;
int maxWait = 0;
int idleTime = 0;

int main() {
	srand(time(NULL));
	int people = 99999;
	int * eventTimes = new int[people];
	int start;
	int stop;
	int tellers;
	float simTime;
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

	fout.open("output.txt");

	cout << "Enter number of tellers: ";
	cin >> tellers;

	start = clock();
	simulate();
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	fout << "One Teller with One Queue" << endl;
	fout << "Simulation Time: " << simTime << endl;
	fout << "Virtual Time: " << currentTime[0] << endl;
	fout << "Average Wait: " << waitTime/people << endl;
	fout << "Max Wait: " << maxWait << endl;
	fout << "Maximum Length of Line: " << maxLineLength << endl;
	fout << "Idle Time: " << idleTime << endl << endl;

	start = clock();
	simulate2();
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	fout << "Three Tellers with Three Queues" << endl;
	fout << "Simulation Time: " << simTime << endl;
	fout << "Virtual Time: " << currentTime[0] << endl;
	fout << "Average Wait: " << waitTime/people << endl;
	fout << "Max Wait: " << maxWait << endl;
	fout << "Maximum Length of Line: " << maxLineLength << endl;
	fout << "Idle Time: " << idleTime << endl << endl;

	start = clock();
	simulate3();
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	fout << "Three Tellers with One Queue" << endl;
	fout << "Simulation Time: " << simTime << endl;
	fout << "Virtual Time: " << currentTime[0] << endl;
	fout << "Average Wait: " << waitTime/people << endl;
	fout << "Max Wait: " << maxWait << endl;
	fout << "Maximum Length of Line: " << maxLineLength << endl;
	fout << "Idle Time: " << idleTime << endl << endl;

	start = clock();
	simulate4(tellers);
	stop = clock();
	simTime = (stop-start)/double(CLOCKS_PER_SEC)*1;
	fout << tellers << " Teller with " << tellers << " Queue" << endl;
	fout << "Simulation Time: " << simTime << endl;
	fout << "Virtual Time: " << currentTime[0] << endl;
	fout << "Average Wait: " << waitTime/people << endl;
	fout << "Max Wait: " << maxWait << endl;
	fout << "Maximum Length of Line: " << maxLineLength << endl;
	fout << "Idle Time: " << idleTime << endl << endl;

	return 0;
}

void simulate() {
	ArrayQueue<Event> bankLineA;
	SL_PriorityQueue<Event> eventQueueA;
	LinkedQueue<Event> bankLineL;
	LinkedQueue<Event> eventQueueL;
	tellerAvailable[0] = true;
	waitTime = 0;
	maxWait = 0;
	idleTime = 0;
	maxLineLength = 0;
	lineLength[0] = 0;

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
	}
	fin.close();
	
	while(!eventQueueA.isEmpty()) {
		Event newEvent = eventQueueA.peekFront();
		//Event newEventL = eventQueueL.peekFront();
		
		if(tellerAvailable[0]) {
			idleTime += (newEvent.time - currentTime[0]);
		}

		currentTime[0] = newEvent.time;
		if(lineLength[0] > maxLineLength) {
			maxLineLength = lineLength[0];
		}

		if(newEvent.arrival) {
			lineLength[0]++;
			processArrival(newEvent, eventQueueA, bankLineA, eventQueueL, bankLineL, 0);
			//cout << "Arrival" << endl;
		} else {
			lineLength[0]--;
			processDeparture(newEvent, eventQueueA, bankLineA, eventQueueL, bankLineL, 0);
			//cout << "Departure" << endl;
		}
	}
}

void simulate2() {
	ArrayQueue<Event> * bankLineA = new ArrayQueue<Event>[3];
	SL_PriorityQueue<Event> * eventQueueA = new SL_PriorityQueue<Event>[3];
	LinkedQueue<Event> * bankLineL = new LinkedQueue<Event>[3];
	LinkedQueue<Event> * eventQueueL = new LinkedQueue<Event>[3];
	for(int i = 0; i < 3; i++) {
		tellerAvailable[i] = true;
		lineLength[i] = 0;
	}
	waitTime = 0;
	maxWait = 0;
	maxLineLength = 0;
	idleTime = 0;

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
	fin.close();
	
	for(int i = 0; i < 3; i++) {
		while(!eventQueueA[i].isEmpty()) {
			Event newEvent = eventQueueA[i].peekFront();
			
			if(tellerAvailable[i] && newEvent.time > currentTime[i]) {
				idleTime += (newEvent.time - currentTime[i]);
			}

			if(lineLength[i] > maxLineLength) {
				maxLineLength = lineLength[i];
			}
			currentTime[i] = newEvent.time;
			if(newEvent.arrival) {
				lineLength[i]++;
				processArrival(newEvent, eventQueueA[i], bankLineA[i], eventQueueL[i], bankLineL[i], i);
			} else {
				lineLength[i]--;
				processDeparture(newEvent, eventQueueA[i], bankLineA[i], eventQueueL[i], bankLineL[i], i);
			}
		}
	}
	for(int i = 1; i < 3; i++) {
		if(currentTime[0] < currentTime[i]) {
			currentTime[0] = currentTime[i];
		}
	}
}

void simulate3() {
	ArrayQueue<Event> bankLineA;
	SL_PriorityQueue<Event> eventQueueA;
	LinkedQueue<Event> bankLineL;
	LinkedQueue<Event> eventQueueL;
	for(int i = 0; i < 3; i++) {
		tellerAvailable[i] = true;
		lineLength[i] = 0;
	}
	waitTime = 0;
	maxWait = 0;
	maxLineLength = 0;
	idleTime = 0;

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
		eventQueueA.enqueue(arrivalEvent);
		eventQueueL.enqueue(arrivalEvent);
		if(currentTeller < 2) {
			currentTeller++;
		}else {
			currentTeller = 0;
		}
	}
	fin.close();
	
	for(int i = 0; i < 3; i++) {
		while(!eventQueueA.isEmpty()) {
			Event newEvent = eventQueueA.peekFront();
			
			if(tellerAvailable[i] && newEvent.time > currentTime[i]) {
				idleTime += (newEvent.time - currentTime[i]);
			}

			if(lineLength[i] > maxLineLength) {
				maxLineLength = lineLength[i];
			}
			currentTime[i] = newEvent.time;
			if(newEvent.arrival) {
				lineLength[i]++;
				processArrival(newEvent, eventQueueA, bankLineA, eventQueueL, bankLineL, i);
			} else {
				lineLength[i]--;
				processDeparture(newEvent, eventQueueA, bankLineA, eventQueueL, bankLineL, i);
			}
		}
	}
	for(int i = 1; i < 3; i++) {
		if(currentTime[0] < currentTime[i]) {
			currentTime[0] = currentTime[i];
		}
	}
}

void simulate4(int tellers) {
	tellerAvailable = new bool[tellers];
	currentTime = new int[tellers];
	lineLength = new int[tellers];
	ArrayQueue<Event> * bankLineA = new ArrayQueue<Event>[tellers];
	SL_PriorityQueue<Event> * eventQueueA = new SL_PriorityQueue<Event>[tellers];
	LinkedQueue<Event> * bankLineL = new LinkedQueue<Event>[tellers];
	LinkedQueue<Event> * eventQueueL = new LinkedQueue<Event>[tellers];
	for(int i = 0; i < tellers; i++) {
		tellerAvailable[i] = true;
		lineLength[i] = 0;
	}
	waitTime = 0;
	maxWait = 0;
	maxLineLength = 0;
	idleTime = 0;

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
		if(currentTeller < tellers-1) {
			currentTeller++;
		}else {
			currentTeller = 0;
		}
	}
	fin.close();
	
	for(int i = 0; i < tellers; i++) {
		while(!eventQueueA[i].isEmpty()) {
			Event newEvent = eventQueueA[i].peekFront();
			
			if(tellerAvailable[i] && newEvent.time > currentTime[i]) {
				idleTime += (newEvent.time - currentTime[i]);
			}

			if(lineLength[i] > maxLineLength) {
				maxLineLength = lineLength[i];
			}
			currentTime[i] = newEvent.time;
			if(newEvent.arrival) {
				lineLength[i]++;
				processArrival(newEvent, eventQueueA[i], bankLineA[i], eventQueueL[i], bankLineL[i], i);
			} else {
				lineLength[i]--;
				processDeparture(newEvent, eventQueueA[i], bankLineA[i], eventQueueL[i], bankLineL[i], i);
			}
		}
	}
	for(int i = 1; i < tellers; i++) {
		if(currentTime[0] < currentTime[i]) {
			currentTime[0] = currentTime[i];
		}
	}
}

void processArrival(Event arrivalEvent, SL_PriorityQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller) {
	eventQueueA.dequeue();
	
	
	
	if(bankLineA.isEmpty() && tellerAvailable[teller]) {
		int departureTime = currentTime[teller] + arrivalEvent.length;
		Event newDeparture;
		newDeparture.arrival = false;
		newDeparture.time = departureTime;
		eventQueueA.enqueue(newDeparture);
		tellerAvailable[teller] = false;
	} else {
		bankLineA.enqueue(arrivalEvent);
	}
}

void processDeparture(Event departureEvent, SL_PriorityQueue<Event> & eventQueueA, ArrayQueue<Event> & bankLineA, LinkedQueue<Event> & eventQueueL, LinkedQueue<Event> & bankLineL, int teller) {
	eventQueueA.dequeue();
	
	if(!bankLineA.isEmpty()) {
		int currWait = 0;
		if(currentTime[teller] > bankLineA.peekFront().time) {
			currWait = (currentTime[teller] - bankLineA.peekFront().time);
		}
		waitTime += currWait;
		if(currWait > maxWait) {
			maxWait = currWait;
		}
		int length = bankLineA.peekFront().length;
		bankLineA.dequeue();
		int departureTime = currentTime[teller] + length;
		Event newDeparture;
		newDeparture.arrival = false;
		newDeparture.time = departureTime;
		newDeparture.length = length;
		eventQueueA.enqueue(newDeparture);
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
