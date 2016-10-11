#include<iostream>
#include"stack.h"

using namespace std;

template<class ItemType>
Stack<ItemType>::Stack(int m) {
	top = NULL;
}

template<class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> & stack) {
	top = NULL;
	Node * ptr = stack.top;
	Node * temp = new Node(ptr->data, NULL);
	ptr = ptr->next;
	top = temp;
	//adds nodes opposite of push
	while(ptr != NULL) {
		Node * temp1 = new Node(ptr->data, NULL);
		temp->next = temp1;
		ptr = ptr->next;
		temp = temp1;
	}
}

template<class ItemType>
Stack<ItemType>::~Stack() {
	//deletes nodes until empty
	while(!empty()) {
		Node * nodeptr = top;
		top = top->next;
		delete[] nodeptr;
		nodeptr = NULL;
	}

	delete[] top;
	top = NULL;
}

template<class ItemType>
Stack<ItemType> & Stack::operator=(const Stack<ItemType> & stack) {
	//checks if assigning this stack
	if(this != &stack)
	{
		top = NULL;
		Node * ptr = stack.top;
		Node * temp = new Node(ptr->data, NULL);
		ptr = ptr->next;
		top = temp;
		//adds nodes opposite of push
		while(ptr != NULL) {
			Node * temp1 = new Node(ptr->data, NULL);
			temp->next = temp1;
			ptr = ptr->next;
			temp = temp1;
		}
	}
	return *this;
}

template<class ItemType>
bool Stack<ItemType>::clear() {
	//deletes nodes
	while(!empty()) {
		Node * nodeptr = top;
		top = top->next;
		delete [] nodeptr;
		nodeptr = NULL;
	}

	delete [] top;
	top = NULL;

	return true;
}

template<class ItemType>
bool Stack<ItemType>::push(ItemType c) {
	//makes sure stack is not full
	if(!full()) {	
		Node * nodeptr = new Node(c,top);

		//sets next to null if empty
		if(empty()) {
			nodeptr->next = NULL;
		}

		top = nodeptr;
		return true;
	}else{
		return false;
	}
}

template<class ItemType>
bool Stack<ItemType>::pop(ItemType & c) {
	//checks if empty
	if(!empty()) {
		c = top->data;
		//sets c to data in node and removes node
		if(top->next != NULL) {
			Node * nodeptr = top;
			top = top->next;
			delete[] nodeptr;
			nodeptr = NULL;
		}
		return true;
	}else {
		return false;
	}
}

template<class ItemType>
bool Stack<ItemType>::empty() const{
	//checks if empty
	if(top == NULL) {
		return true;
	}else {
		return false;
	}
}

template<class ItemType>
bool Stack<ItemType>::full() const{
	//never full in scope of this class
	return false;
}

template<class ItemType>
ostream & operator<<(ostream & os, const Stack<ItemType> & stack) {
	Node * ptr = stack.top;

	//prints stack
	while(ptr != NULL) {
		os << ptr->data << " ";
		ptr = ptr->next;
	}

	return os;
}

template<class ItemType>
bool Stack<ItemType>::operator==(const Stack<ItemType> & stack) const{
	bool same = true;
	
	Node * stackptr = stack.top;
	Node * ptr = top;

	//checks if pointers are null
	while(ptr != NULL && stackptr != NULL) {
		//checks if data is the same
		if(ptr->data != stackptr->data) {
			same = false;
		}
		stackptr = stackptr->next;
		ptr = ptr->next;
	}
	return same;
}
