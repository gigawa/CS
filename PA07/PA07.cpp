#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "RedBlackTree.h"

using namespace std;
void add(int & c);

RedBlackTree<int> tree;

ofstream fout;

int main() {
	srand(time(NULL));
	int * numberList = new int[100];

	for(int i = 0; i < 100; i++) {
		int j = rand() % 200;
		tree.add(j);
		numberList[i] = j;
	}

	return 0;
}

void add(int & c) {
	fout << c << ", ";
}
