#include "List.h"

List::ReferenceNode List::CreateComponent(int data)
{
    ReferenceNode NewComponent = new Node;
    NewComponent->data = data;
    NewComponent->next = nullptr;
    return NewComponent;
}

List::ReferenceNode List::GetComponentByValue(int data)
{
    ReferenceNode reference = this->head;
    while (reference) {
        if (reference->data == data) {
            return reference;
        }
        reference = reference->next;
    }
    return nullptr;
}

void List::AddComponentAfter(ReferenceNode where, ReferenceNode node){
    node->next = where->next;
    where->next = node;
}

void List::SwapComponents(ReferenceNode first, ReferenceNode second){
    ReferenceNode AuxilaryReference = first;
    first->data = second->data;
    first->next = second;
    second->next = AuxilaryReference;
    second->data = AuxilaryReference->data;
}

void List::AddComponent(ReferenceNode Node)
{
    if (this->head == nullptr) {
        head = Node;
    }
    else {
        ReferenceNode reference = head;
        while (reference->next) {
            reference = reference->next;
        }
        AddComponentAfter(reference, Node);
    }
}

void List::ShowAllList(){
    ReferenceNode reference = this->head;
    while (reference) {
        std::cout << reference->data << " ";
        reference = reference->next;
    }
}
