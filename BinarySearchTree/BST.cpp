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

bool BST::Remove(KeyType keyType) {
	root = Remove(root, keyType);
	return true;
}

BST::Node* BST::Remove(BST::Node* node, KeyType keyType) {
	Node* curr = root;
	Node* prev = nullptr;

	while (curr != nullptr && curr->Key != keyType) {
		prev = curr;
		if (keyType < curr->Key)
			curr = curr->LeftChild;
		else
			curr = curr->RightChild;
	}

	if (curr == nullptr) {
		return nullptr;
	}

	if (curr->LeftChild == nullptr || curr->RightChild == nullptr) {
		Node* temp;

		if (curr->LeftChild == nullptr)
			temp = curr->RightChild;
		else
			temp = curr->LeftChild;

		//root node, shallow delete
		if (prev == nullptr)
			return temp;

		if (curr == prev->LeftChild)
			prev->LeftChild = temp;
		else
			prev->RightChild = temp;

		free(curr);
	}
	else //Has two children
	{
		Node* parent = nullptr;
		Node* temp = curr->RightChild;
		while (temp->LeftChild != nullptr) {
			parent = temp;
			temp = temp->LeftChild;
		}

		if (parent != nullptr)
			parent->LeftChild = temp->RightChild;
		else
			curr->RightChild = temp->LeftChild;

		curr->Key = temp->Key;
		curr->Item = temp->Item;

		free(temp);
	}
	return node;
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
list<BST::Node*> BST::InOrder(BST::Node* node)
{
	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<Node*> nodeList;

	if (node == nullptr)
	{
		return nodeList;
	}

	list<Node*> leftList = InOrder(node->LeftChild);
	
	for (auto const& i : leftList) 
	{
		nodeList.push_back(i);
	}

	nodeList.push_back(node);
	
	list<Node*> rightList = InOrder(node->RightChild);
	
	for (auto const& i : rightList) 
	{
		nodeList.push_back(i);
	}
	
	return nodeList;
}

void BST::PivotRight(KeyType keyType) 
{
	Node* curr = root;
	Node* prev = root;

	while (curr != nullptr && curr->Key != keyType) {
		prev = curr;
		if (keyType < curr->Key)
			curr = curr->LeftChild;
		else
			curr = curr->RightChild;
	}

	if (curr == nullptr)
		return;
	Node* node = PivotRight(curr);
	if (curr = prev->LeftChild)
		prev->LeftChild = node;
	else
		prev->RightChild = node;
}

void BST::PivotLeft(KeyType keyType) {
	Node* curr = root;
	Node* prev = root;

	while (curr != nullptr && curr->Key != keyType) {
		prev = curr;
		if (keyType < curr->Key)
			curr = curr->LeftChild;
		else
			curr = curr->RightChild;
	}

	if (curr == nullptr)
		return;
	Node* node = PivotLeft(curr);
	if (curr = prev->LeftChild)
		prev->LeftChild = node;
	else
		prev->RightChild = node;
}

BST::Node* BST::PivotRight(BST::Node* B)
{
	Node* A = B->LeftChild;
	if (A == nullptr)
		return B;
	Node* beta = A->RightChild;
	A->RightChild = B;
	B->LeftChild = beta;
	return A;
}

BST::Node* BST::PivotLeft(BST::Node* A)
{
	Node* B = A->RightChild;
	if (B == nullptr)
		return A;
	Node* beta = B->LeftChild;
	B->LeftChild = A;
	A->RightChild = beta;

	return B;
}

//Pre-order traversal
list<BST::Node*> BST::PreOrder(Node* node)
{
	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<Node*> nodeList;
	
	if (node == nullptr)
	{
		return nodeList;
	}
	
	nodeList.push_back(node);
	list<Node*> leftList = PreOrder(node->LeftChild);
	
	for (auto const& node : leftList)
	{
		nodeList.push_back(node);
	}

	list<Node*> rightList = PreOrder(node->RightChild);
	
	for (auto const& node : rightList)
	{
		nodeList.push_back(node);
	}

	return nodeList;
}

//Post-order traversal
list<BST::Node*> BST::PostOrder(Node* node)
{
	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<Node*> nodeList;
	
	if (node == nullptr)
	{
		return nodeList;
	}
	
	list<Node*> leftList = PreOrder(node->LeftChild);
	
	for (auto const& node : leftList) 
	{
		nodeList.push_back(node);
	}
	
	list<Node*> rightList = PreOrder(node->RightChild);
	
	for (auto const& node : rightList)
	{
		nodeList.push_back(node);
	}
	
	nodeList.push_back(node);
	return nodeList;
}

// height of the tree
int BST::GetHeight(Node* node)
{
	if (node == NULL)
		return 0;
	return node->Height;
}