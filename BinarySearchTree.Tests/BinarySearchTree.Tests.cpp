#define BOOST_TEST_MODULE BinarySearchTreeTest
#include <boost/test/included/unit_test.hpp>
#include "../BinarySearchTree/BST.h"
#include <string>


using namespace std;
struct GlobalFixture {
    GlobalFixture() {
        boost::debug::detect_memory_leaks(false);
    }
    ~GlobalFixture() { }
};
BOOST_GLOBAL_FIXTURE(GlobalFixture);
BOOST_AUTO_TEST_CASE(IterativeLookUp_MultipleNodes_ReturnsCorrectValue)
{
    BST bst = BST();

    bst.root = bst.Insert(bst.root, 10, "A");
    bst.Insert(bst.root, 20, "B");
    bst.Insert(bst.root, 5, "C");
    bst.Insert(bst.root, 8, "D");

    BST::ItemType* itemType = bst.IterativeLookUp(20);

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
