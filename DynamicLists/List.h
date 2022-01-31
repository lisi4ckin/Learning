#pragma once
#include <iostream>
struct Node
{
	int data;
	Node* next;
};
typedef Node* ReferenceNode;

class List
{
private:
	ReferenceNode head;
public:
	List() { this->head = nullptr; };
	ReferenceNode CreateComponent(int data);
	ReferenceNode GetComponentByValue(int data);
	void AddComponent(ReferenceNode Node); //Add component to the end of list
	void AddComponentAfter(ReferenceNode where, ReferenceNode node);
	void SwapComponents(ReferenceNode first, ReferenceNode second);
	void ShowAllList();
};

