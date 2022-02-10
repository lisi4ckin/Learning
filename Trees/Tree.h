#pragma once
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
	void AddComponent(ReferenceNode Component);
	ReferenceNode CreateComponent(int data);
	ReferenceNode GetRoot();
	void ShowTree(ReferenceNode reference, int height);
};

