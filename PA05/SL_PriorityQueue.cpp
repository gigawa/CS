template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue() {

}

template<class ItemType>
SL_PriorityQueue<ItemType>::SL_PriorityQueue(const SL_PriorityQueue& pq) {

}

template<class ItemType>
SL_PriorityQueue<ItemType>::~SL_PriorityQueue() {

}

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool SL_PriorityQueue<ItemType>::enqueue(const ItemType& newEntry)
{ 
   return slistPtr->insertSorted(newEntry);
}  // end enqueue
   
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool SL_PriorityQueue<ItemType>::dequeue()
{
   // The highest-priority item is at the end of the sorted list
   return slistPtr->removeSorted(slistPtr->getLength());
}  // end dequeue

template<class ItemType>
bool SL_PriorityQueue<ItemType>::isEmpty() const {
	return slistPtr->isEmpty();
}

template<class ItemType>
ItemType SL_PriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept) {
	if (isEmpty())
		throw PrecondViolatedExcept("peekFront() called with empty queue");
	
	return slistPtr->getEntry(slistPtr->getLength());
}
