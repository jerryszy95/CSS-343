#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarynode.h"


using namespace std;

template<class ItemType>
class BinarySearchTree
{
public:
    // constructor, empty tree
    BinarySearchTree<ItemType>();
    // constructor, tree with root
    explicit BinarySearchTree<ItemType>(const ItemType& rootItem);
    // copy constructor
    BinarySearchTree<ItemType>(const BinarySearchTree<ItemType>& bst);
    // destructor
    virtual ~BinarySearchTree<ItemType>();
    // true if no nodes
    bool isEmpty() const;
    // 0 if empty, 1 if only root, otherwise
    // max height of subtrees + 1
    int getHeight() const;
    // number of nodes and data in tree
    int getNumberOfNodes() const;
    // add a new item
    // return true if succesasfull
    // false if item already in tree or some other reason to fail
    bool add(const ItemType& item);
    // true if item is in tree
    bool contains(const ItemType& item) const;
    // dispaly a sideways ascii representation of tree
    void displaySideways() const;
    // inorder traversal: left-root-right
    // takes a function that takes a single parameter of ItemType
    // the function can modify the data in tree, but the
    // tree structure is not changed
    void inorderTraverse(void visit(ItemType&)) const;
    // create dynamic array, copy all the items to the array
    // and then read the array to re-create this tree
    void rebalance();
    // delete all nodes in tree and set root to nullptr
    void clear();
    // given an array of length n
    // create this tree to have all items in that array
    // with the minimum height
    bool readTree(ItemType arr[], int n);
    // trees are equal if they have the same structure
    // AND the same item values at all the nodes
    bool operator==(const BinarySearchTree<ItemType> &) const;
    // not == to each other
    bool operator!=(const BinarySearchTree<ItemType> &) const;

private:
    // root of the tree
    BinaryNode<ItemType>* rootPtr {nullptr};
    // add a new node, helper function for add
    BinaryNode<ItemType>* addNodeHelper(BinaryNode<ItemType>* current, BinaryNode<ItemType>* newNodePtr);//placeNode function
    // find the node with given vale, helper function for contains
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* current, const ItemType& target) const;
    
    //other helper function of public funcation
    // helper function for copy construtor to copy the tree
    BinaryNode<ItemType>* copyHelper(const BinaryNode<ItemType> * current) const;
    //Helper function for getHeigtht function
    int getHeightHelper(BinaryNode<ItemType> * current) const;
    //Helper function for getNumberOfNodes function
    int getCountHelper(BinaryNode<ItemType> * current) const;
    //Helper function for inorderTraverse function
    void inorderHelper(void visit(ItemType&), BinaryNode<ItemType> * current) const;
    //Helper function for rebalance function
    void convertToArray(BinaryNode<ItemType> * current, ItemType arr[], int &index);
    //Helper function for readTree function
    BinaryNode<ItemType> * readTreeHelper(int front, int end, ItemType arr[]);
    //Helper function for Clear function
    void deleteNodes(BinaryNode<ItemType>* current);
    //Helper function for displaySideways to work recursively
    void sideways(BinaryNode<ItemType>* current, int level) const;
    //Helper function for == operator
    bool compare(BinaryNode<ItemType> * tree1, BinaryNode<ItemType> * tree2) const;
    
    
};
#include "binarysearchtree.cpp"
#endif // BINARYSEARCHTREE_H
