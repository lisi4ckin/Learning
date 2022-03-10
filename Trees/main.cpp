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

	Tree BinTree("input");
	BinTree.ShowTree(BinTree.GetRoot(), 0);

	system("Pause");
	return 0;
}