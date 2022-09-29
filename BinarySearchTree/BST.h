#pragma once
#include <string>

using namespace std; 

class BST
{
	public:
		using KeyType = int;
		using ItemType = string;

		ItemType* Lookup(KeyType keyType);
		void Insert(KeyType keyType, ItemType itemType);
		bool Remove(KeyType keyType);

		ItemType* IterativeLookUp(KeyType keyType);
		ItemType* RecursiveLookUp(KeyType keyType);

	private:
		struct Node;
		Node* root = nullptr;

	private:
		static Node* Leaf();
		static bool IsLeaf(Node* node);
		ItemType* RecursiveLookUpWorker(Node* node, KeyType keyType);


	struct Node
	{
		Node(KeyType key, ItemType item)
		{
			Key = key;
			Item = item;
		};
		
		KeyType Key;
		ItemType Item;
		Node* LeftChild;
		Node* RightChild;
	};

	BST() = default;
};