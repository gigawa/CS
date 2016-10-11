//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file Node.h 
    Listing 4-1 */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   
public:
	/** default constructor*/
   Node();

	/** constructor with item value*/
   Node(const ItemType& anItem);

	/** constructor with item value and next pointer*/
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

	/** sets the item value of the node*/
   void setItem(const ItemType& anItem);

	/** sets the pointer to the next node*/
   void setNext(Node<ItemType>* nextNodePtr);

	/** returns the item stored in the node*/
   ItemType getItem() const ;

	/** returns the next node*/
   Node<ItemType>* getNext() const ;
}; // end Node

#include "Node.cpp"
#endif
