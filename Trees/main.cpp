#include <iostream>
#include <ctime>
#include "Tree.h"

using namespace std;

int main() {
	srand(time(0));
	Tree BinaryTree;
	for (int i = 0; i < 5; i++) {
		BinaryTree.AddComponent(BinaryTree.CreateComponent(rand() % 100));
	}
	BinaryTree.AddComponent(BinaryTree.CreateComponent(29));
	if (!BinaryTree.GetComponentByValue(29)){
	    cout << "Component not found!" << endl;
	}
	BinaryTree.ShowTree(BinaryTree.GetRoot(), 0);
	return 0;
}