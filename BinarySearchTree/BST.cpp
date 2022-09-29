#include "BST.h"
#include <iostream>

BST::ItemType* BST::IterativeLookUp(BST::KeyType keyType)
{	
	Node* currentNode = root;

	while (currentNode != nullptr && currentNode->Key != keyType)
	{
		if (currentNode->Key > keyType)
		{
			currentNode = currentNode->LeftChild;
		}
		else if (currentNode->Key < keyType)
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
	if (node == nullptr)
		return nullptr;

	if (node->Key == keyType)
	{
		return &node->Item;
	}
	else if (node->Key > keyType)
	{
		return RecursiveLookUpWorker(node->LeftChild, keyType);
	}
	else if (node->Key < keyType)
	{
		return RecursiveLookUpWorker(node->RightChild, keyType);
	}
	
}

BST::ItemType* BST::Lookup(KeyType keyType)
{
	return nullptr;
}

BST::Node* BST::Insert(Node* nodeRoot, KeyType keyType, ItemType itemType)
{
	if (nodeRoot == nullptr) 
	{
		Node* node = new Node(keyType, itemType);
		return node;
	}
	else 
	{
		if (keyType > nodeRoot->Key) 
		{
			nodeRoot->RightChild = Insert(nodeRoot->RightChild, keyType, itemType);
		}
		else if (keyType < nodeRoot->Key) 
		{
			nodeRoot->LeftChild = Insert(nodeRoot->LeftChild, keyType, itemType);
		}
		else if (keyType == nodeRoot->Key)
		{
			nodeRoot->Item = itemType;
		}
	}
	return nodeRoot;
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