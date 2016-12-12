#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "RedBlackTree.h"

using namespace std;
void addAll(int & c);

RedBlackTree<int> tree;

ofstream fout;

int main() {
	srand(time(NULL));
	int * numberList = new int[100];

	for(int i = 0; i < 5; i++) {
		cout << "Add" << endl;
		int j = rand() % 200;
		tree.add(j);
		cout << "Tree height: " << tree.getHeight() << endl;
		numberList[i] = j;
	}

	cout << "Tree height: " << tree.getHeight() << endl;
	cout << boolalpha << tree.isEmpty() << endl;

	return 0;
}

void addAll(int & c) {
	fout << c << ", ";
}
