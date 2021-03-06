#include "Tree.h"
#include <iostream>
#include <algorithm> 
#include <string>
#include <fstream>

int Tree::CheckTreeHeight(ReferenceNode reference)
{
	if (!reference) {
		return 0;
	}
	int leftHeightTree = CheckTreeHeight(reference->left);
	if (leftHeightTree == -1) return -1;

	int rightHeightTree = CheckTreeHeight(reference->right);
	if (rightHeightTree == -1) return -1;

	int differenceHeight = leftHeightTree - rightHeightTree;
	if (abs(differenceHeight) > 1) return -1;
	else {
		return std::max(leftHeightTree, rightHeightTree) + 1;
	}
}

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

bool Tree::IsBalanced(ReferenceNode reference)
{
	if (CheckTreeHeight(GetRoot()) == -1)
		return false;
	else
		return true;
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

void Tree::WriteTreeInFile(ReferenceNode reference, std::ofstream &out) {
	if (reference) {
		out << reference->data << " ";
		WriteTreeInFile(reference->right, out);
		WriteTreeInFile(reference->left, out);
	}
}

void Tree::ShowTree(ReferenceNode reference, int height, int &count)
{
	if (reference) {
		ShowTree(reference->right, height + 1, count);
		for (int i = 0; i < 5 * height; i++) {
			std::cout << ' ';
		}
		std::cout << reference->data << std::endl;
		++count;
		ShowTree(reference->left, height + 1, count);
	}
}
