#include "binarysearchtree.h"


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
    //ctor
}
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    clear();
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) {
    rootPtr=copyHelper(bst.rootPtr);
}//end copy-constructor

//copy helper : recursive copy node from tree.
template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::
copyHelper(const BinaryNode<ItemType> * current) const {
    BinaryNode<ItemType> * copynode;
    if(current==nullptr)
        return nullptr;
    copynode = new BinaryNode<ItemType>(current->getItem());
    copynode->setLeftChildPtr(copyHelper(current->getLeftChildPtr()));
    copynode->setRightChildPtr(copyHelper(current->getRightChildPtr()));
    return copynode;
}// end copyHelper

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
    if (rootPtr == nullptr)
        return true;
    else
        return false;
}//end isEmpty


template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}//end getHeight

//getHeighthelpter: recursively compare left and right leave nodes deepth, return the (larger deepth +1)
template<class ItemType>
int BinarySearchTree<ItemType>::getHeightHelper(BinaryNode<ItemType> * current) const {
    int leftlength = 0;
    if (current->getLeftChildPtr() != nullptr)
        leftlength = getHeightHelper(current->getLeftChildPtr());
    
    int rightlength = 0;
    if (current->getRightChildPtr() != nullptr)
        rightlength = getHeightHelper(current->getRightChildPtr());
    
    if (leftlength > rightlength)
        return leftlength + 1;
    else
        return rightlength + 1;
}//end getHeightHelper

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return getCountHelper(rootPtr);
}//end getNumberOfNodes

//getCountHelper: recursively count the node in the tree.
template<class ItemType>
int BinarySearchTree<ItemType>::getCountHelper(BinaryNode<ItemType> * current) const {
    if(current == nullptr)  //if current node doesn't exist,then there are no child nodes.
        return 0;
    else //add the nodes counts of the left and right leaves, then add 1 (which is the current node)
        return getCountHelper(current->getLeftChildPtr()) + getCountHelper(current->getRightChildPtr()) + 1;

}//end getCountHelper


template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item) {
    if (rootPtr == nullptr)
        rootPtr = new BinaryNode<ItemType>(item);
    else {
    
        if (contains(item))
            return false;
        else{
            BinaryNode<ItemType> * NewNode = new BinaryNode<ItemType>(item);
            addNodeHelper(rootPtr, NewNode);
        }
    }
    return true;
}//end add

//clean Helper: recursively delete Nodes in the tree
template<class ItemType>
void BinarySearchTree<ItemType>::deleteNodes(BinaryNode<ItemType>* current)
{
    if (current != nullptr) {
        deleteNodes(current->getLeftChildPtr());
        deleteNodes(current->getRightChildPtr());
        delete current;
    }
}//end deleteNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
    deleteNodes(rootPtr);
    rootPtr = nullptr;
}//end clear

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const {
    if(findNode(rootPtr,item)!=nullptr)
        return true;
    else
        return false;
}//end contains

//addNodeHelper: recursively find the place for new node
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
addNodeHelper(BinaryNode<ItemType>* current, BinaryNode<ItemType>* newNodePtr) {
    //add to right
    if (newNodePtr->getItem()> current->getItem()) {
        if (current->getRightChildPtr() == nullptr)
            current->setRightChildPtr(newNodePtr);
        else
            addNodeHelper(current->getRightChildPtr(), newNodePtr);
    }
    //add to left
    if (newNodePtr->getItem() < current->getItem()) {
        if (current->getLeftChildPtr() == nullptr)
            current->setLeftChildPtr(newNodePtr);
        else
            addNodeHelper(current->getLeftChildPtr(), newNodePtr);
    }
    if (newNodePtr->getItem() == current->getItem())
        return nullptr;
    
    return current;
}  // end addNodeHelper

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::
findNode(BinaryNode<ItemType>* current, const ItemType& target) const {
    // Broot is null or key is present at root
    if (current == nullptr || current->getItem() == target)
        return current;
    
    // target is greater than Node item
    if (current->getItem() < target)
        return findNode(current->getRightChildPtr(), target);
    
    // target is smaller than Node item
    return findNode(current->getLeftChildPtr(), target);
}  // end findNode

//inorderHelper: recursively output the node inorder
template<class ItemType>
void BinarySearchTree<ItemType>::
inorderHelper(void visit(ItemType&), BinaryNode<ItemType> * current) const {
    if (current != nullptr)
    {
        inorderHelper(visit, current->getLeftChildPtr());
        ItemType Item = current->getItem();
        visit(Item); // main uses displayItem()
        inorderHelper(visit, current->getRightChildPtr());
    }
}//end inorderHelper

template<class ItemType>
void BinarySearchTree<ItemType>::
inorderTraverse(void visit(ItemType&)) const {
    inorderHelper(visit, rootPtr);
}//end inorderTraverse

//convertToArray: recursively store the item into to array inorder
template<class ItemType>
void BinarySearchTree<ItemType>::
convertToArray(BinaryNode<ItemType> * current, ItemType arr[], int &index){
    if(current!=nullptr)
    {
        convertToArray(current->getLeftChildPtr(), arr, index);
        arr[index] = current->getItem();
        index++;
        convertToArray(current->getRightChildPtr(), arr, index);
    }
}// end convertToArray


template<class ItemType>
void BinarySearchTree<ItemType>::rebalance() {
    int size = getNumberOfNodes();
    ItemType * arrPtr = new ItemType[size];
    int index=0;// set the index
    convertToArray(rootPtr, arrPtr, index);//store tree items to array
    readTree(arrPtr, size);// call readTree to create tree from array
    delete[] arrPtr;
}//end rebalance

//readTreeHelper: recursively divide array by two and passing the data in to BST
template<class ItemType>
BinaryNode<ItemType> * BinarySearchTree<ItemType>::
readTreeHelper(int front, int end, ItemType arr[]) {
    if (front > end)
        return nullptr;
    else    // divide the array in to two parts until front bigger than end
    {
        int mid = (front + end+1) / 2;
        BinaryNode<ItemType> * current = new BinaryNode<ItemType>(arr[mid]);
        current->setLeftChildPtr(readTreeHelper(front, (mid - 1), arr));
        current->setRightChildPtr(readTreeHelper((mid + 1), end, arr));
        return current;
    }
}//end readTreeHelper

template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n) {
    //Assume the input array is sorted from small to large
    clear(); //clear the current tree
    
    rootPtr= readTreeHelper(0,n-1,arr);// call readTreehelper to create a binary search tree from arr
    if(rootPtr!=nullptr)
        return true;
    else
        return false;
}//end readTree


template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const {
    sideways(rootPtr, 0);
}//end displaySideways

template<class ItemType>
void BinarySearchTree<ItemType>::
sideways(BinaryNode<ItemType>* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->getRightChildPtr(), level);
        
        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }
        
        cout << current->getItem() << endl;        // display information of object
        sideways(current->getLeftChildPtr(), level);
    }
}//end sideways


template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const {
    return compare(rootPtr,other.rootPtr);
}//end ==operator

//== operator Helper: compare two tree by each node.
template<class ItemType>
bool BinarySearchTree<ItemType>::compare(BinaryNode<ItemType> * tree1, BinaryNode<ItemType> * tree2) const {
    if (tree1 == nullptr && tree2 == nullptr)
        return true;
    else if (tree1 == nullptr || tree2 == nullptr)
        return false;
    else
        return ((tree1->getItem() == tree2->getItem()) && compare(tree1->getLeftChildPtr(), tree2->getLeftChildPtr())
                && compare(tree1->getRightChildPtr(), tree2->getRightChildPtr()));
}//end compare


template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const {
    if (other == *this)
        return false;
    else
        return true;
}//end !=operator



