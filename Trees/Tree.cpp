#include "Tree.h"
#include <iostream>
#include <string>
#include <fstream>

Tree::Tree(std::string nameOfFile) {
	this->Root = nullptr;
	std::ifstream input("in.txt");
	if (!input.is_open()) {
		std::cout << "Error! \n";
		return;
	}
	while (!input.eof()) {
		int Element;
		input >> Element;
		AddComponent(CreateComponent(Element));
	}
}

void Tree::AddComponent(ReferenceNode Component)
{
	ReferenceNode reference = this->Root;
	ReferenceNode parentReference = nullptr;
	if (!reference) {
		this->Root = Component;
	}
	else {
		while (reference) {
			parentReference = reference;
			if (Component->data > reference->data) {
				reference = reference->right;
			}
			else {
				reference = reference->left;
			}
		}
		if (Component->data > parentReference->data) {
			parentReference->right = Component;
		}
		else {
			parentReference->left = Component;
		}
	}
}

Tree::ReferenceNode Tree::GetComponentByValue(int data)
{
	ReferenceNode reference = this->Root;
	std::string path = "Root ";
	while (reference) {
		if (reference->data == data) {
		    std::cout << path << std::endl;
			return reference;
		}
		else {
		    path += (data > reference->data) ? "right " : "left ";
			reference = (data > reference->data) ? reference->right : reference->left;
		}
	}
	return nullptr;
}

Tree::ReferenceNode Tree::CreateComponent(int data)
{
	ReferenceNode component = new Node;
	component->left = component->right = nullptr;
	component->data = data;
	return component;
}

void Tree::DeleteComponent(int key)
{
    ReferenceNode reference = this->Root;
    ReferenceNode parentReference = nullptr;
    while(reference && reference->data != key){
        parentReference = reference;
        if (reference->data > key){
            reference = reference->left;
        }
        else{
            reference = reference->right;
        }
    }
    if (!reference){
        return;
    }
    if (!reference->left){
        if (parentReference && parentReference->left == reference){
            parentReference->left = reference->right;
        }
        if (parentReference && parentReference->right == reference){
            parentReference->right = reference->right;
        }
        delete reference;
        return;
    }
}

Tree::ReferenceNode Tree::GetRoot()
{
	return this->Root;
}

void Tree::ShowTree(ReferenceNode reference, int height)
{
	if (reference) {
		ShowTree(reference->right, height + 1);
		for (int i = 0; i < 5 * height; i++) {
			std::cout << ' ';
		}
		std::cout << reference->data << std::endl;
		ShowTree(reference->left, height + 1);
	}
}
