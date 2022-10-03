#include <iostream>
#include "BST.h"
#include "BinarySearchTree.h"

using namespace std;



int main()
{
    cout << "Binary Search Tree!\n";

	BST bst;
	bst.root = bst.Insert(bst.root, 100, "First");
	bst.Insert(bst.root, 50, "Second");
	bst.Insert(bst.root, 150, "Third");

	cout << *bst.IterativeLookUp(100) << endl;
	cout << *bst.IterativeLookUp(150) << endl;
	cout << *bst.IterativeLookUp(50) << endl;

	bst.PrintInOrder(bst.root);
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