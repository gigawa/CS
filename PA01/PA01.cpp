#include "LinkedList.h"
#include<iostream>

using namespace std;

int main() {
	char c = 'a';
	LinkedList<char> list;
	for(int i = 0; i < 10; i++) {
		list.insert(i+1, c);
		c++;
	}
	cout << list.getLength() << endl;
	for(int i = 0; i < 10; i++) {
		cout << list.getEntry(i+1);
	}
	cout << endl;
	list.replace(6, 'z');
	for(int i = 0; i < 10; i++) {
		cout << list.getEntry(i+1);
	}
	cout << endl;
	LinkedList<char> list2(list);
	for(int i = 0; i < 10; i++) {
		cout << list2.getEntry(i+1);
	}
	cout << endl;
	return 0;
}
