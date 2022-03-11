#pragma once
#include <string>
#include <fstream>
class Tree
{
protected:
	struct Node {
		int data;
		Node* right;
		Node* left;
	};
	typedef Node* ReferenceNode;
private:
	ReferenceNode Root;
public:
	Tree() { this->Root = nullptr; }
	Tree(std::string nameOfFile);
	void AddComponent(ReferenceNode Component);
	void DeleteComponent(int key);
	ReferenceNode CreateComponent(int data);
	ReferenceNode GetRoot();
	ReferenceNode GetComponentByValue(int data);
	void WriteTreeInFile(ReferenceNode reference, std::ofstream& out);
	void ShowTree(ReferenceNode reference, int height, int &count);
};

