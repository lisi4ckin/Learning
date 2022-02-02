#pragma once
#include "List.h"

class BidirectionalList: public List
{
protected:

	struct Node: public List::Node
	{
		int count;
		Node* next;
		Node* previous;
	};

	typedef Node* ReferneceNodeBi;

private:
	ReferneceNodeBi head;
public:
	BidirectionalList() :List(){
		this->head = nullptr;
	}
	ReferneceNodeBi CreateComponent(int data);
	void AddComponent(ReferneceNodeBi Node);
	void AddComponentAfter(ReferneceNodeBi Where, ReferneceNodeBi Node);
	void ShowAllList();
};

