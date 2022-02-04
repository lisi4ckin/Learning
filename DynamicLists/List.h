#pragma once
#include <iostream>

class List
{
protected:
	struct Node
	{
		int data;
		Node* next;
	};

	typedef Node* ReferenceNode;
private:
	ReferenceNode head;
public:
	List() { this->head = nullptr; };
	virtual ReferenceNode CreateComponent(int data);
	virtual ReferenceNode GetComponentByValue(int data);
	void AddComponent(ReferenceNode Node); //Add component to the end of list
	void AddComponentAfter(ReferenceNode where, ReferenceNode node);
	void DeleteComponent(ReferenceNode BeingDeletedNode);
	void ShowAllList();
};

