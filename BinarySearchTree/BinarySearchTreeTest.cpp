#define BOOST_TEST_MODULE BinarySearchTreeTest
#include <boost/test/included/unit_test.hpp>
#include "../BinarySearchTree/BST.h"

using namespace std;

struct GlobalFixture {
    GlobalFixture() {
        boost::debug::detect_memory_leaks(false);
    }
    ~GlobalFixture() { }
};
BOOST_GLOBAL_FIXTURE(GlobalFixture);

//Searching for items using iteration
//Searching for Entries using Recursive Functions
//Inserting items into a BST


struct BstTester {
    BstTester();      
    ~BstTester();     
    void setup();          
    void teardown();
    void ConsolePrint(string message);

    BST BinarySearchTree;

};

BOOST_FIXTURE_TEST_SUITE(s, BstTester)

    BOOST_AUTO_TEST_CASE(IterativeLookUp_MultipleNodes_ReturnsCorrectValue)
    {
        BST::ItemType* itemType = BinarySearchTree.IterativeLookUp(20);

        BOOST_CHECK_EQUAL(*itemType, "B");
    }

    BOOST_AUTO_TEST_CASE(IterativeLookUp_SingleNode_ReturnsCorrectValue)
    {
        BST bst = BST();

        bst.root = bst.Insert(bst.root, 10, "A");

        BST::ItemType* itemType = bst.IterativeLookUp(10);

        BOOST_CHECK_EQUAL(*itemType, "A");
    }

    BOOST_AUTO_TEST_CASE(RecursiveLookUp_SingleNode_ReturnsCorrectValue)
    {
        BST bst = BST();

        bst.root = bst.Insert(bst.root, 10, "A");

        BST::Node* node = bst.RecursiveLookUp(10);

        BOOST_CHECK_EQUAL(node->Item, "A");
    }

    BOOST_AUTO_TEST_CASE(RecursiveLookUp_MultipleNode_ReturnsCorrectValue)
    {
        BST bst = BST();

        bst.root = bst.Insert(bst.root, 10, "A");
        bst.Insert(bst.root, 20, "B");
        bst.Insert(bst.root, 5, "C");
        bst.Insert(bst.root, 8, "D");

        BST::Node* node = bst.RecursiveLookUp(10);

        BOOST_CHECK_EQUAL(node->Item, "A");


        node = bst.RecursiveLookUp(8);

        BOOST_CHECK_EQUAL(node->Item, "D");


        node = bst.RecursiveLookUp(5);

        BOOST_CHECK_EQUAL(node->Item, "C");


        node = bst.RecursiveLookUp(20);

        BOOST_CHECK_EQUAL(node->Item, "B");
    }

BOOST_AUTO_TEST_SUITE_END()

BstTester::BstTester()
{
}

BstTester::~BstTester()
{
}

void BstTester::setup()
{
    ConsolePrint("set up");
    
    BinarySearchTree = BST();

    BinarySearchTree.root = BinarySearchTree.Insert(BinarySearchTree.root, 10, "A");
    BinarySearchTree.Insert(BinarySearchTree.root, 20, "B");
    BinarySearchTree.Insert(BinarySearchTree.root, 5, "C");
    BinarySearchTree.Insert(BinarySearchTree.root, 8, "D");
    BinarySearchTree.Insert(BinarySearchTree.root, 18, "E");
    BinarySearchTree.Insert(BinarySearchTree.root, 7, "F");
    BinarySearchTree.Insert(BinarySearchTree.root, 99, "G");
    BinarySearchTree.Insert(BinarySearchTree.root, 1, "H");
    BinarySearchTree.Insert(BinarySearchTree.root, 4, "I");
    BinarySearchTree.Insert(BinarySearchTree.root, 26, "J");
    BinarySearchTree.Insert(BinarySearchTree.root, 54, "K");
    BinarySearchTree.Insert(BinarySearchTree.root, 37, "L");
}

void BstTester::teardown()
{
    ConsolePrint("teardown");
}

void BstTester::ConsolePrint(string message) 
{
    cout << message << endl;
}