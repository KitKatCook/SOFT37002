#include "BST.h"
#include <iostream>
#include <iterator>
#include <list>

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

BST::Node* BST::RecursiveLookUp(BST::KeyType keyType)
{
	return RecursiveLookUpWorker(root, keyType);
}

BST::Node* BST::RecursiveLookUpWorker(BST::Node* node, BST::KeyType keyType)
{
	if (node == nullptr)
		return nullptr;

	if (node->Key == keyType)
	{
		return node;
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
	//neither child of the node is a leaf.

	Node* node = RecursiveLookUp(keyType);

	if (node == nullptr) {
		return false;
	}

	//both children of the node are leaves;
	if (node->LeftChild == nullptr && node->RightChild == nullptr) 
	{
		free(node);
		return true;
	}
	
	//one child of the node is a leaf;
	if (curr->leftChild == nullptr || curr->rightChild == nullptr) {
		Node* temp;

		if (curr->leftChild == nullptr)
			temp = curr->rightChild;
		else
			temp = curr->leftChild;

		//root node, shallow delete
		if (prev == nullptr)
			return temp;

		if (curr == prev->leftChild)
			prev->leftChild = temp;
		else
			prev->rightChild = temp;

		free(curr);
	}



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

void BST::PrintInOrder(Node* node)
{
	if (node == NULL)
		return;

	PrintInOrder(node->LeftChild);

	cout << node->Item << " ";

	PrintInOrder(node->RightChild);
}

//In-order traversal
list<BST::Node*> BST::InOrder(BST::Node* nr)
{
	list<int>::iterator it1;
	list<int>::iterator it2;
	list<Node*> listg;
	if (nr == nullptr) 
	{
		return listg;
	}

	list<Node*> leftList = InOrder(nr->leftChild);
	for (auto const& i : leftList) {
		listg.push_back(i);
	}
	listg.push_back(nr);
	list<Node*> rightList = InOrder(nr->rightChild);
	for (auto const& i : rightList) {
		listg.push_back(i);
	}
	return listg;
}

void BST::PivotRight(KeyType key) 
{
	Node* curr = root;
	Node* prev = root;

	while (curr != nullptr && curr->key != key) {
		prev = curr;
		if (key < curr->key)
			curr = curr->leftChild;
		else
			curr = curr->rightChild;
	}

	if (curr == nullptr)
		return;
	Node* nr = pivot_right(curr);
	if (curr = prev->leftChild)
		prev->leftChild = nr;
	else
		prev->rightChild = nr;
}

void BST::PivotLeft(KeyType key) {
	Node* curr = root;
	Node* prev = root;

	while (curr != nullptr && curr->key != key) {
		prev = curr;
		if (key < curr->key)
			curr = curr->leftChild;
		else
			curr = curr->rightChild;
	}

	if (curr == nullptr)
		return;
	Node* nr = pivot_left(curr);
	if (curr = prev->leftChild)
		prev->leftChild = nr;
	else
		prev->rightChild = nr;
}

BST::Node* BST::PivotRight(BST::Node* B)
{
	Node* A = B->leftChild;
	if (A == nullptr)
		return B;
	Node* beta = A->rightChild;
	A->rightChild = B;
	B->leftChild = beta;
	return A;
}

BST::Node* BST::PivotLeft(BST::Node* A)
{
	Node* B = A->rightChild;
	if (B == nullptr)
		return A;
	Node* beta = B->leftChild;
	B->leftChild = A;
	A->rightChild = beta;

	return B;
}

//Pre-order traversal
list<BST::Node*> BST::PreOrder(Node* nr)
{
	list<int>::iterator it1;
	list<int>::iterator it2;
	list<Node*> listg;
	if (nr == nullptr)
		return listg;
	listg.push_back(nr);
	list<Node*> leftList = preorder(nr->leftChild);
	for (auto const& node : leftList)
		listg.push_back(node);
	list<Node*> rightList = preorder(nr->rightChild);
	for (auto const& node : rightList)
		listg.push_back(node);
	return listg;
}

//Post-order traversal
list<BST::Node*> BST::PostOrder(Node* nr)
{
	list<int>::iterator it1;
	list<int>::iterator it2;
	list<Node*> listg;
	if (nr == nullptr)
		return listg;
	list<Node*> leftList = preorder(nr->leftChild);
	for (auto const& node : leftList)
		listg.push_back(node);
	list<Node*> rightList = preorder(nr->rightChild);
	for (auto const& node : rightList)
		listg.push_back(node);
	listg.push_back(nr);
	return listg;
}