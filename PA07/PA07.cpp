#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "RedBlackTree.h"

using namespace std;
void addAll(int & c);

RedBlackTree<int> tree;
long int total = 0;

ofstream fout;

int main() {
	fout.open("output.txt");
	srand(time(NULL));

	for(int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		tree.add(j);
		tree.inorderTraverse(addAll);
	}

	fout << "Tree height: " << tree.getHeight() << endl;
	fout << "Sum of all Values: " << total << endl;
	fout << "Tree is Empty: " << boolalpha << tree.isEmpty() << endl;
	tree.clear();
	fout << "Tree is Empty: " << boolalpha << tree.isEmpty() << endl;

	return 0;
}

void addAll(int & c) {
	total += c;
}
