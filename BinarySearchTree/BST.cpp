#include "BST.h"

//Done
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

	if (currentNode == nullptr) 
	{
		return nullptr;
	}

	return &currentNode->Item;
}

//Done
BST::Node* BST::RecursiveLookUp(BST::KeyType keyType)
{
	return RecursiveLookUpWorker(root, keyType);
}

//Done
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
	else 
	{
		return nullptr;
	}

}

//Done
BST::Node* BST::Insert(BST::Node* node, KeyType keyType, ItemType itemType) 
{
	return this->InsertNode(node, keyType, itemType);
}

//Done
BST::Node* BST::Insert(KeyType keyType, ItemType itemType)
{
	if (root == nullptr) 
	{
		root = this->InsertNode(root, keyType, itemType);
		return root;
	}
	else 
 {
		return this->InsertNode(root, keyType, itemType);
	}
}

//Done
BST::Node* BST::InsertNode(BST::Node* node, KeyType keyType, ItemType itemType)
{
	if (node == nullptr)
	{
		return new BST::Node(keyType, itemType);
	}
	else 
	{
		if (keyType < node->Key)
		{
			node->LeftChild = Insert(node->LeftChild, keyType, itemType);
		}
		else if (keyType > node->Key)
		{
			node->RightChild = Insert(node->RightChild, keyType, itemType);
		}
		else if (keyType == node->Key)
		{
			node->Item = itemType;
		}
	}
	return node;
}

bool BST::Remove(KeyType keyType) {
	root = Remove(root, keyType);
	return true;
}

BST::Node* BST::Remove(BST::Node* node, KeyType keyType) 
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (keyType < node->Key)
	{
		node->LeftChild = Remove(node->LeftChild, keyType);
	}
	else if (keyType > node->Key)
	{
		node->RightChild = Remove(node->RightChild, keyType);
	}

	else 
	{
		if (node->LeftChild == nullptr and node->RightChild == nullptr)
		{
			return nullptr;
		}

		else if (node->LeftChild == nullptr)
		{
			Node* tempNode = node->RightChild;
			
			free(node);
			
			return tempNode;
		}
		else if (node->RightChild == nullptr) 
		{
			Node* tempNode = root->LeftChild;
			
			free(node);
			
			return tempNode;
		}

		Node* tempNode = node;
		while (tempNode && tempNode->LeftChild != nullptr) 
		{
			tempNode = tempNode->LeftChild;
		}

		node->Key = tempNode->Key;

		node->RightChild = Remove(node->RightChild, tempNode->Key);
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

list<BST::ItemType*> BST::GetInOrderItemTypeList()
{
	list<BST::ItemType*> listitemtypes;

	list<Node*> nodes = InOrder(root);

	for (auto const& nodeItem : nodes)
	{
		listitemtypes.push_back(&nodeItem->Item);
	}
	return listitemtypes;
}

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
	for (auto const& n : leftList) 
	{
		nodeList.push_back(n);
	}

	nodeList.push_back(node);
	
	list<Node*> rightList = InOrder(node->RightChild);
	for (auto const& n : rightList) 
	{
		nodeList.push_back(n);
	}
	
	return nodeList;
}

list<BST::ItemType*> BST::GetPreOrderItemTypeList()
{
	list<BST::ItemType*> listitemtypes;

	list<Node*> nodes = PreOrder(root);

	for (auto const& nodeItem : nodes)
	{
		listitemtypes.push_back(&nodeItem->Item);
	}
	return listitemtypes;
}

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
	for (auto const& n : leftList)
	{
		nodeList.push_back(n);
	}

	list<Node*> rightList = PreOrder(node->RightChild);
	for (auto const& n : rightList)
	{
		nodeList.push_back(n);
	}

	return nodeList;
}

list<BST::ItemType*> BST::GetPostOrderItemTypeList()
{
	list<BST::ItemType*> listitemtypes;

	list<Node*> nodes = PostOrder(root);

	for (auto const& nodeItem : nodes)
	{
		listitemtypes.push_back(&nodeItem->Item);
	}
	return listitemtypes;
}

list<BST::Node*> BST::PostOrder(Node* node)
{
	list<int>::iterator iteratorA;
	list<int>::iterator iteratorB;
	list<Node*> nodeList;

	if (node == nullptr)
	{
		return nodeList;
	}

	list<Node*> leftList = PostOrder(node->LeftChild);

	for (auto const& n : leftList)
	{
		nodeList.push_back(n);
	}

	list<Node*> rightList = PostOrder(node->RightChild);

	for (auto const& n : rightList)
	{
		nodeList.push_back(n);
	}

	nodeList.push_back(node);
	return nodeList;
}


// height of the tree
int BST::GetHeight(Node* node)
{
	if (node == NULL) 
	{
		return 0;
	}
	return node->Height;
}