#pragma once
#include <string>
#include <iterator>
#include <list>
#include <iostream>

using namespace std; 

class BST
{
	public:
		using KeyType = int;
		using ItemType = string;
	
	struct Node
	{
		Node(KeyType key, ItemType item)
		{
			Key = key;
			Item = item;
			LeftChild = nullptr;
			RightChild = nullptr;
			Height = 0;
		};
		KeyType Key;
		ItemType Item;
		Node* LeftChild;
		Node* RightChild;
		int Height;
	};

	public:
		BST::Node* Insert(BST::Node* nodeRoot, KeyType keyType, ItemType itemType);
		BST::Node* Insert(KeyType keyType, ItemType itemType);
		
		bool Remove(KeyType keyType);
		BST::Node* Remove(BST::Node* node, KeyType keyType);
		
		BST::Node* root = nullptr;
		
		ItemType* IterativeLookUp(KeyType keyType);
		BST::Node* RecursiveLookUp(KeyType keyType);
		
		BST() = default;
		
		list<BST::ItemType*> GetInOrderItemTypeList();
		list<BST::ItemType*> GetPreOrderItemTypeList();
		list<BST::ItemType*> GetPostOrderItemTypeList();

		int GetHeight(Node* N);

	private:
		static BST::Node* Leaf();
		static bool IsLeaf(BST::Node* node);
		BST::Node* RecursiveLookUpWorker(BST::Node* node, KeyType keyType);
		Node* InsertNode(Node*, KeyType, ItemType);

		list<BST::Node*> InOrder(BST::Node* node);

		list<BST::Node*> PreOrder(Node* node);

		list<BST::Node*> PostOrder(Node* node);
};


