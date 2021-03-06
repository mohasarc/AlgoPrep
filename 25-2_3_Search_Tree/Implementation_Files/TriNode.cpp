#include "../Header_Files/TriNode.h"

template < class ItemType>
TriNode<ItemType>::TriNode(){
    leftChildPtr = NULL;
    midChildPtr = NULL;
    rightChildPtr = NULL;
    twoNode = true;
}

template < class ItemType>
TriNode<ItemType>::TriNode( const ItemType& anItem){
    smallItem = anItem;
    leftChildPtr = NULL;
    midChildPtr = NULL;
    rightChildPtr = NULL;
    twoNode = true;
}

template < class ItemType>
TriNode<ItemType>::TriNode( const ItemType& anItem, TriNode<ItemType>* leftPtr, 
                            TriNode<ItemType>* midPtr, TriNode<ItemType>* rightPtr){
    smallItem = anItem;
    leftChildPtr = leftPtr;
    midChildPtr = midPtr;
    rightChildPtr = rightPtr;
    if (rightPtr == NULL)
        twoNode = true;
}

template < class ItemType>
bool TriNode<ItemType>::isLeaf() const {
    // Leaf if has no children
    return !leftChildPtr && !midChildPtr && !rightChildPtr;
}

template < class ItemType>
bool TriNode<ItemType>::isTwoNode() const {
    // two node if right ptr is not occupied
    return twoNode;
}

template < class ItemType>
bool TriNode<ItemType>::isThreeNode() const {
    // three node if right ptr is occupied
    return !twoNode;
}

template < class ItemType>
ItemType TriNode<ItemType>::getSmallItem() const {
    return smallItem;
}

template < class ItemType>
ItemType TriNode<ItemType>::getLargeItem() const {
    return largeItem;
}

template < class ItemType>
void TriNode<ItemType>::setSmallItem( const ItemType& anItem){
    smallItem = anItem;
}

template < class ItemType>
void TriNode<ItemType>::setLargeItem( const ItemType& anItem){
    twoNode = false;
    largeItem = anItem;
}

template < class ItemType>
TriNode<ItemType>* TriNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template < class ItemType>
TriNode<ItemType>* TriNode<ItemType>::getMidChildPtr() const {
    return midChildPtr;
}

template < class ItemType>
TriNode<ItemType>* TriNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

template < class ItemType>
void TriNode<ItemType>::setLeftChildPtr(TriNode<ItemType>* leftPtr){
    leftChildPtr = leftPtr;
}

template < class ItemType>
void TriNode<ItemType>::setMidChildPtr(TriNode<ItemType>* midPtr){
    midChildPtr = midPtr;
}

template < class ItemType>
void TriNode<ItemType>::setRightChildPtr(TriNode<ItemType>* rightPtr){
    if (rightPtr == NULL)
        twoNode = true;
    else
        twoNode = false;
        
    rightChildPtr = rightPtr;
}

// instantiating needed classes 
// not to get a linking time error (undefined reference to)
// read more : https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
template class TriNode<int>;
template class TriNode<string>;