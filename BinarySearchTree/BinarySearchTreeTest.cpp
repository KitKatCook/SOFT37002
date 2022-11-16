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


struct BSTTester {
    BSTTester();      
    ~BSTTester();     
    void setup();          
    void teardown();
    void ConsolePrint(string message);

    BST BinarySearchTree;

};


BOOST_FIXTURE_TEST_SUITE(Insert, BSTTester)

BOOST_AUTO_TEST_CASE(GivenEmptyTree_WhenInsertingNode_ThenCheckRootNodeIsValueSet)
{
    BST bst = BST();
    bst.Insert(10, "A");
    BOOST_CHECK_EQUAL(bst.root->item, "A");
    BOOST_CHECK_EQUAL(bst.root->key, 10);
}
BOOST_AUTO_TEST_CASE(GivenTree_WhenInsertingKeyLessThanRoot_ThenCheckNewNodeIsInLeftSubtree)
{
    BST bst = BST();
    bst.insert_wrapper(10, "A");
    bst.insert_wrapper(5, "B");
    BOOST_CHECK_EQUAL(bst.root->leftChild->key, 5);
    BOOST_CHECK_EQUAL(bst.root->leftChild->item, "B");
}
BOOST_AUTO_TEST_CASE(GivenTree_WhenInsertingKeyGreaterThanRoot_ThenCheckNewNodeIsInRightSubtree)
{
    BST bst = BST();
    bst.insert_wrapper(10, "A");
    bst.insert_wrapper(15, "B");
    BOOST_CHECK_EQUAL(bst.root->rightChild->key, 15);
    BOOST_CHECK_EQUAL(bst.root->rightChild->item, "B");
}
BOOST_AUTO_TEST_CASE(GivenTree_WhenInsertingKeySameAsRoot_ThenCheckRootValue)
{
    BST bst = BST();
    bst.insert_wrapper(10, "A");
    bst.insert_wrapper(10, "B");
    BOOST_CHECK_EQUAL(bst.root->item, "B");
    BOOST_CHECK_EQUAL(bst.root->key, 10);
}
BOOST_AUTO_TEST_CASE(GivenTree_WhenInsertingKeys_ThenCheckKeysAreCorrectSubtrees)
{
    BST bst = BST();
    bst.insert_wrapper(10, "A");
    bst.insert_wrapper(5, "B");
    bst.insert_wrapper(12, "C");
    bst.insert_wrapper(11, "D");
    BOOST_CHECK_EQUAL(bst.root->item, "A");
    BOOST_CHECK_EQUAL(bst.root->leftChild->key, 5);
    BOOST_CHECK_EQUAL(bst.root->leftChild->item, "B");
    BOOST_CHECK_EQUAL(bst.root->rightChild->key, 12);
    BOOST_CHECK_EQUAL(bst.root->rightChild->item, "C");
    BOOST_CHECK_EQUAL(bst.root->rightChild->leftChild->key, 11);
    BOOST_CHECK_EQUAL(bst.root->rightChild->leftChild->item, "D");

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(s, BSTTester)

    BOOST_AUTO_TEST_CASE(IterativeLookUp_MultipleNodes_ReturnsCorrectValue)
    {
        BST::ItemType* itemType = BinarySearchTree.IterativeLookUp(10);
        BOOST_CHECK_EQUAL(*itemType, "A");

        itemType = BinarySearchTree.IterativeLookUp(20);
        BOOST_CHECK_EQUAL(*itemType, "B");
    }

BOOST_AUTO_TEST_SUITE_END()

BSTTester::BSTTester()
{
}

BSTTester::~BSTTester()
{
}

void BSTTester::setup()
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

void BSTTester::teardown()
{
    ConsolePrint("teardown");
}

void BSTTester::ConsolePrint(string message) 
{
    cout << message << endl;
}