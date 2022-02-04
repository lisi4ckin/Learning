#include "BidirectionalList.h"

BidirectionalList::ReferenceNodeBi BidirectionalList::CreateComponent(int data) {
	ReferenceNodeBi NewComponent = new Node;
	NewComponent->data = data;
	NewComponent->next = NewComponent->previous= nullptr;
	return NewComponent;
}

BidirectionalList::ReferenceNodeBi BidirectionalList::GetComponentByValue(int data)
{
	ReferenceNodeBi reference = this->head;
	while (reference) {
		if (reference->data == data) {
			return reference;
		}
		reference = reference->next;
	}
	return nullptr;
}


void BidirectionalList::DeleteComponent(ReferenceNodeBi BeingDeletedReference)
{
	ReferenceNodeBi reference = this->head;
	if (BeingDeletedReference == reference) {
		this->head = BeingDeletedReference->next;
	}
	else {
		while (reference) {
			if (reference->next == BeingDeletedReference) {
				if (BeingDeletedReference->next) {
					reference->next = BeingDeletedReference->next;
					reference->next->previous = reference;
				}
				else {
					reference->next = reference->next->previous = nullptr;
				}
				delete BeingDeletedReference;
			}
			reference = reference->next;
		}
	}
}

void BidirectionalList::AddComponentAfter(ReferenceNodeBi Where, ReferenceNodeBi Node){
	Node->next = Where->next;
	if (Where->next) {
		Where->next->previous = Node;
	}
	Node->previous = Where;
	Where->next = Node;
}

void BidirectionalList::AddComponent(ReferenceNodeBi Node) {
	if (this->head == nullptr) {
		this->head = Node;
	}
	else {
		ReferenceNodeBi refernece = this->head;
		while (refernece->next) {
			refernece = refernece->next;
		}
		AddComponentAfter(refernece, Node);
	}
}

void BidirectionalList::ShowAllList()
{
	ReferenceNodeBi reference = this->head;
	while (reference) {
		std::cout << reference->data << " ";
		reference = reference->next;
	}
}