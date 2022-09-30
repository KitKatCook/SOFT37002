#pragma once
#include <string>

using namespace std; 

class BST
{
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
		};
		KeyType Key;
		ItemType Item;
		Node* LeftChild;
		Node* RightChild;
	};

	public:
		ItemType* Lookup(KeyType keyType);
		Node* Insert(Node* nodeRoot, KeyType keyType, ItemType itemType);
		bool Remove(KeyType keyType);
		Node* root = nullptr;
		ItemType* IterativeLookUp(KeyType keyType);
		Node* RecursiveLookUp(KeyType keyType);
		BST() = default;
		void PrintInOrder(Node* node);

	private:
		struct Node;

	private:
		static Node* Leaf();
		static bool IsLeaf(Node* node);
		Node* RecursiveLookUpWorker(Node* node, KeyType keyType);
};


