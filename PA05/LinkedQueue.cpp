#include "LinkedQueue.h"

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() {
	frontPtr = NULL;
	backPtr = NULL;
}

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue) {
	
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue() {

}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
	if(frontPtr != backPtr) {
		return false;
	}else {
		return true;
	}	
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept) {
	if (isEmpty())
		throw PrecondViolatedExcept("peekFront() called with empty queue");

	return frontPtr->item;
}

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
   bool result = false;
   if (!isEmpty())
   {
      // Queue is not empty; remove front
      auto nodeToDeletePtr = frontPtr;
      if (frontPtr == backPtr)
      {  // Special case: one node in queue
         // Set frontPtr and backPtr to nullptr
         frontPtr.reset();
         backPtr.reset();
      }
      else
         frontPtr = frontPtr->getNext();
      
      // Maintain an accurate reference count for first node
      nodeToDeletePtr->setNext(nullptr);
      
      // Removed node will be deallocated when method ends
      result = true;
   }  // end if
   
   return result;
}  // end dequeue

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
   
   // Insert the new node
   if (isEmpty())
      frontPtr = newNodePtr;        // The queue was empty
   else
      backPtr->setNext(newNodePtr); // The queue was not empty
   
   backPtr = newNodePtr;            // New node is at back
   return true;
}  // end enqueue

