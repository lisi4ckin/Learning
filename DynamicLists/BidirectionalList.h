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

	typedef Node* ReferenceNodeBi;

private:
	ReferenceNodeBi head;
public:
	BidirectionalList() :List(){
		this->head = nullptr;
	}
	ReferenceNodeBi CreateComponent(int data) override;
	ReferenceNodeBi GetComponentByValue(int data) override;
	void AddComponent(ReferenceNodeBi Node);
	void AddComponentAfter(ReferenceNodeBi Where, ReferenceNodeBi Node);
	void DeleteComponent(ReferenceNodeBi BeingDeletedReference);
	void ShowAllList();
};

