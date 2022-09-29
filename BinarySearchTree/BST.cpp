#include "BST.h"

BST::ItemType* BST::IterativeLookUp(BST::KeyType keyType)
{	
	Node* currentNode = root;

	while (currentNode->Key == keyType && currentNode != nullptr)
	{

		if (currentNode->Key < keyType)
		{
			currentNode = currentNode->LeftChild;
		}
		else if (currentNode->Key > keyType)
		{
			currentNode = currentNode->RightChild;
		}
	}

	return &currentNode->Item;
}


BST::ItemType* BST::RecursiveLookUp(BST::KeyType keyType)
{
	return RecursiveLookUpWorker(root, keyType);
}

BST::ItemType* BST::RecursiveLookUpWorker(BST::Node* node, BST::KeyType keyType)
{

	if (node->Key == keyType)
	{
		return &node->Item;
	}
	else if (node->Key <= keyType)
	{
		RecursiveLookUpWorker(node->LeftChild, keyType);
	}
	else if (node->Key >= keyType)
	{
		RecursiveLookUpWorker(node->RightChild, keyType);
	}
	
}

BST::ItemType* BST::Lookup(KeyType keyType)
{
	return nullptr;
}

void BST::Insert(KeyType keyType, ItemType itemType)
{
}

bool BST::Remove(KeyType keyType)
{
	return false;
}


BST::Node* BST::Leaf()
{
	return nullptr;
}

bool BST::IsLeaf(Node* node)
{
	return (node == nullptr);
}