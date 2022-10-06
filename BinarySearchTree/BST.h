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
		ItemType* Lookup(KeyType keyType);
		BST::Node* Insert(BST::Node* nodeRoot, KeyType keyType, ItemType itemType);
		bool Remove(KeyType keyType);
		BST::Node* Remove(BST::Node* node, KeyType keyType);
		BST::Node* root = nullptr;
		ItemType* IterativeLookUp(KeyType keyType);
		BST::Node* RecursiveLookUp(KeyType keyType);
		BST() = default;
		void PrintInOrder(BST::Node* node);

		list<BST::Node*> InOrder(BST::Node* node);

		void PivotRight(KeyType keyType);

		void PivotLeft(KeyType keyType);

		BST::Node* PivotRight(BST::Node* B);

		BST::Node* PivotLeft(BST::Node* A);

		list<BST::Node*> PreOrder(Node* node);

		list<BST::Node*> PostOrder(Node* node);

		int GetHeight(Node* N);

	private:
		static BST::Node* Leaf();
		static bool IsLeaf(Node* node);
		Node* RecursiveLookUpWorker(Node* node, KeyType keyType);
};


