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

BST::Node* BST::Insert(Node* nr, KeyType keyType, ItemType itemType)
{
	if (nr == nullptr) 
	{
		// Insert the first node, if nr is NULL.
		Node* node = new Node(keyType, itemType);
		return node;
	}
	else 
	{
		// Insert data.
		if (keyType > nr->Key) 
		{
			// Insert right node data, if the 'value'
			// to be inserted is greater than 'nr' node data.

			// Process right nodes.
			nr->RightChild = Insert(nr->RightChild, keyType, itemType);
		}
		else if (keyType < nr->Key) 
		{
			// Insert left node data, if the 'value'
			// to be inserted is smaller than 'nr' node data.

			// Process left nodes.
			nr->LeftChild = Insert(nr->LeftChild, keyType, itemType);
		}
		else if (keyType == nr->Key)
		{
			nr->Item = itemType;
		}
	}
	return nr;
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