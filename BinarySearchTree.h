#pragma once
#include <string>

using namespace std;

class BinarySearchTree
{
	public:
		using KeyType = int;
		using ItemType = string;

		ItemType* Lookup(KeyType);
		void Insert(KeyType, ItemType);
		bool Remove(KeyType);

	private:
		struct Node;
		Node* root;
		static Node* Leaf();
		static bool IsLeaf(Node*);


	struct Node
	{
		KeyType Key;
		ItemType Item;
		Node* LeftChild;
		Node* RightChild;

		BinarySearchTree::Node(KeyType key, ItemType item) {
			Key = key;
			Item = item;
		};
	};

	Node* root = Leaf();

	BinarySearchTree() = default;

};

