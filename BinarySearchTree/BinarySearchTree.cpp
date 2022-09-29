// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"
#include "BinarySearchTree.h"
#include <list>

using namespace std;

int main()
{
    cout << "Hello World!\n";

	BST bst;
	bst.root = bst.Insert(bst.root, 10, "a");
	bst.Insert(bst.root, 5, "b");
	bst.Insert(bst.root, 6, "c");
	bst.Insert(bst.root, 1, "d");
	bst.Insert(bst.root, 8, "e");
	bst.Insert(bst.root, 3, "f");
	string* itemtype = bst.IterativeLookUp(8);
	cout << *itemtype << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
