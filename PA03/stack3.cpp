#include<iostream>
#include"stackN.h"

using namespace std;

Node::Node(char c, Node * n) {
	data = c;
	next = n;
}

Stack::Stack(int m) {
	top = NULL;
}

Stack::Stack(const Stack & stack) {
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

Stack::~Stack() {
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

Stack & Stack::operator=(const Stack & stack) {
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

bool Stack::clear() {
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

bool Stack::push(char c) {
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

bool Stack::pop(char & c) {
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

bool Stack::empty() const{
	//checks if empty
	if(top == NULL) {
		return true;
	}else {
		return false;
	}
}

bool Stack::full() const{
	//never full in scope of this class
	return false;
}

ostream & operator<<(ostream & os, const Stack & stack) {
	Node * ptr = stack.top;

	//prints stack
	while(ptr != NULL) {
		os << ptr->data << " ";
		ptr = ptr->next;
	}

	return os;
}

bool Stack::operator==(const Stack & stack) const{
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
