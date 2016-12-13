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

	for(int i = 0; i < 1000; i++) {
		cout << "Add" << endl;
		int j = rand() % 200;
		tree.add(j);
		cout << "Tree height: ";
		cout << tree.getHeight() << endl;
		tree.inorderTraverse(addAll);
		cout << endl;
	}

	cout << "Tree height: " << tree.getHeight() << endl;
	cout << boolalpha << tree.isEmpty() << endl;

	return 0;
}

void addAll(int & c) {
	cout << c << ", ";
}
