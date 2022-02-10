#include "Tree.h"

#include <iostream>

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

Tree::ReferenceNode Tree::CreateComponent(int data)
{
	ReferenceNode component = new Node;
	component->left = component->right = nullptr;
	component->data = data;
	return component;
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
