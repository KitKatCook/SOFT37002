#define BOOST_TEST_MODULE BinarySearchTreeTest
#include <boost/test/included/unit_test.hpp>
#include "../BinarySearchTree/BST.h"

using namespace std;

struct GlobalFixture 
{
    GlobalFixture() 
    {
        boost::debug::detect_memory_leaks(false);
    }
    ~GlobalFixture() { }
};
BOOST_GLOBAL_FIXTURE(GlobalFixture);

struct BSTTester
{
    BSTTester();      
    ~BSTTester();     
    void setup();          
    void teardown();
    void ConsolePrint(string message);

    BST BinarySearchTree;
};

BOOST_FIXTURE_TEST_SUITE(Insert, BSTTester)

    BOOST_AUTO_TEST_CASE(NoRootNode_InsertRootNode_CreatesNewNodeAsTheRootOfTheTree)
    {
        BST bst = BST();
        bst.Insert(100, "B");

        BOOST_CHECK_EQUAL(bst.root->Item, "B");
        BOOST_CHECK_EQUAL(bst.root->Key, 100);
    }

    BOOST_AUTO_TEST_CASE(RootNodeExists_InsertValueLessThanRootNode_CreatesNewNodeOnTheLeftSubTree)
    {
        BST bst = BST();
        bst.Insert(100, "B");
        bst.Insert(50, "I");

        BOOST_CHECK_EQUAL(bst.root->LeftChild->Key, 50);
        BOOST_CHECK_EQUAL(bst.root->LeftChild->Item, "I");
    }

    BOOST_AUTO_TEST_CASE(RootNodeExists_InsertValueGreaterThanRootNode_CreatesNewNodeOnTheRightSubTree)
    {
        BST bst = BST();
        bst.Insert(100, "B");
        bst.Insert(150, "N");

        BOOST_CHECK_EQUAL(bst.root->RightChild->Key, 150);
        BOOST_CHECK_EQUAL(bst.root->RightChild->Item, "N");
    }

    BOOST_AUTO_TEST_CASE(RootNodeExists_InsertValueSameAsRootNode_RootNodeReplaces)
    {
        BST bst = BST();
        bst.Insert(100, "B");

        BOOST_CHECK_EQUAL(bst.root->Key, 100);
        BOOST_CHECK_EQUAL(bst.root->Item, "B");

        bst.Insert(100, "Y");

        BOOST_CHECK_EQUAL(bst.root->Key, 100);
        BOOST_CHECK_EQUAL(bst.root->Item, "Y");
    }

    BOOST_AUTO_TEST_CASE(RootNodeExists_InsertValueLessThanLeftChild_CreatesNewNodeOnTheLeftSubTree)
    {
        BST bst = BST();
        bst.Insert(100, "B");
        bst.Insert(50, "I");
        bst.Insert(150, "N");
        bst.Insert(25, "A");

        BOOST_CHECK_EQUAL(bst.root->Item, "B");

        BOOST_CHECK_EQUAL(bst.root->LeftChild->Key, 50);
        BOOST_CHECK_EQUAL(bst.root->LeftChild->Item, "I");

        BOOST_CHECK_EQUAL(bst.root->RightChild->Key, 150);
        BOOST_CHECK_EQUAL(bst.root->RightChild->Item, "N");

        BOOST_CHECK_EQUAL(bst.root->LeftChild->LeftChild->Key, 25);
        BOOST_CHECK_EQUAL(bst.root->LeftChild->LeftChild->Item, "A");
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(IterativeLookUp, BSTTester)

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_IterativeLookUp_KeyExistsReturnsValue)
    {
        BST::ItemType* itemType = BinarySearchTree.IterativeLookUp(50);
        BOOST_CHECK_EQUAL(*itemType, "I");
    }

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_IterativeLookUp_KeyDoesntExistsReturnsNull)
    {
        BST::ItemType* itemType = BinarySearchTree.IterativeLookUp(51);
        BOOST_CHECK_EQUAL(itemType, nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(RecursiveLookUp, BSTTester)

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_RecursiveLookUp_KeyExistsReturnsValue)
    {
        BST::Node* node = BinarySearchTree.RecursiveLookUp(50);
        BOOST_CHECK_EQUAL(node->Item, "I");
    }

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_RecursiveLookUp_KeyDoesntExistsReturnsNull)
    {
        BST::Node* node = BinarySearchTree.RecursiveLookUp(51);
        BOOST_CHECK_EQUAL(node, nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(Remove, BSTTester)

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_Remove_RemoveLeftChildOfRootNode)
    {
        BST::Node* nodeExists = BinarySearchTree.RecursiveLookUp(50);
        BOOST_CHECK_EQUAL(nodeExists->Item, "I");

        BinarySearchTree.Remove(50);

        BST::Node* node = BinarySearchTree.RecursiveLookUp(50);
        BOOST_CHECK_EQUAL(node, nullptr);
    }

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_Remove_RemoveRightChildOfRootNode)
    {
        BST::Node* nodeExists = BinarySearchTree.RecursiveLookUp(150);
        BOOST_CHECK_EQUAL(nodeExists->Item, "N");

        BinarySearchTree.Remove(150);

        BST::Node* node = BinarySearchTree.RecursiveLookUp(150);
        BOOST_CHECK_EQUAL(node, nullptr);
    }

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_Remove_NodeHasOneChildRemoveNodeAndReplaceWithChild)
    {
        BST::Node* nodeExists = BinarySearchTree.RecursiveLookUp(-100);
        BOOST_CHECK_EQUAL(nodeExists->Item, "C");

        BinarySearchTree.Remove(-100);

        BST::Node* node = BinarySearchTree.root->LeftChild->LeftChild->LeftChild->LeftChild;
        BOOST_CHECK_EQUAL(node->Key, -50);

    }

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_Remove_NodeHasTwoChildrenRemoveNodeAndReplaceWithChildInOrderSucessor)
    {
        BST::Node* nodeExists = BinarySearchTree.RecursiveLookUp(200);
        BOOST_CHECK_EQUAL(nodeExists->Item, "Y");

        BinarySearchTree.Remove(200);

        BST::Node* node = BinarySearchTree.root->RightChild->RightChild;
        BOOST_CHECK_EQUAL(node->Key, 175);

    }

    BOOST_AUTO_TEST_CASE(BinarySearchTreeExists_Remove_RemoveRootNode)
    {
        BST::Node* nodeExists = BinarySearchTree.RecursiveLookUp(100);
        BOOST_CHECK_EQUAL(nodeExists->Item, "B");

        BinarySearchTree.Remove(100);

        BST::Node* node = BinarySearchTree.RecursiveLookUp(100);
        BOOST_CHECK_EQUAL(node, nullptr);
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
    BinarySearchTree = BST();

    BinarySearchTree.Insert(100, "B");
    BinarySearchTree.Insert(50, "I");
    BinarySearchTree.Insert(150, "N");
    BinarySearchTree.Insert(25, "A");
    BinarySearchTree.Insert(75, "R");
    BinarySearchTree.Insert(200, "Y");
    BinarySearchTree.Insert(225, "S");
    BinarySearchTree.Insert(0, "E");
    BinarySearchTree.Insert(125, "A");
    BinarySearchTree.Insert(175, "R");
    BinarySearchTree.Insert(-100, "C");
    BinarySearchTree.Insert(-50, "H");
}

void BSTTester::teardown()
{
}

void BSTTester::ConsolePrint(string message) 
{
    cout << message << endl;
}