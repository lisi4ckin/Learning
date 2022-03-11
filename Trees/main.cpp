#include <iostream>
#include <ctime>
#include "Tree.h"

using namespace std;

int main() {
	srand(time(0));
	int count = 0;
	Tree BinaryTree;
	for (int i = 0; i < 5; i++) {
		BinaryTree.AddComponent(BinaryTree.CreateComponent(rand() % 100));
	}
	BinaryTree.AddComponent(BinaryTree.CreateComponent(29));
	if (!BinaryTree.GetComponentByValue(29)){
	    cout << "Component not found!" << endl;
	}
	BinaryTree.ShowTree(BinaryTree.GetRoot(), 0, count);
	std::cout << "List count is: " << count << std::endl;
	
	if (BinaryTree.IsBalanced(BinaryTree.GetRoot()))
		cout << "Is balanced" << endl;
	else
		cout << "Not balanced" << endl;

	count = 0;
	Tree BinTree("output");
	BinTree.ShowTree(BinTree.GetRoot(), 0, count);
	std::cout << "List count is: " << count << std::endl;

	ofstream out("output");
	BinTree.WriteTreeInFile(BinTree.GetRoot(), out);

	system("Pause");
	return 0;
}