#include "BidirectionalList.h"

BidirectionalList::ReferneceNodeBi BidirectionalList::CreateComponent(int data) {
	ReferneceNodeBi NewComponent = new Node;
	NewComponent->data = data;
	NewComponent->next = NewComponent->previous= nullptr;
	return NewComponent;
}

void BidirectionalList::AddComponentAfter(ReferneceNodeBi Where, ReferneceNodeBi Node){
	Node->next = Where->next;
	if (Where->next) {
		Where->next->previous = Node;
	}
	Node->previous = Where;
	Where->next = Node;
}

void BidirectionalList::AddComponent(ReferneceNodeBi Node) {
	if (this->head == nullptr) {
		this->head = Node;
	}
	else {
		ReferneceNodeBi refernece = this->head;
		while (refernece->next) {
			refernece = refernece->next;
		}
		AddComponentAfter(refernece, Node);
	}
}

void BidirectionalList::ShowAllList()
{
	ReferneceNodeBi reference = this->head;
	while (reference) {
		std::cout << reference->data << " ";
		reference = reference->next;
	}
}