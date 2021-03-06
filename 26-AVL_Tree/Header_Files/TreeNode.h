// Author: Mohammed S. Yaseen
// Built upon the code from 25-2_3_Search_Tree/Header_Files/TriNode.h

#ifndef _TRI_NODE
#define _TRI_NODE
#include <iostream>

template < class ItemType>
class TreeNode
{
private :
ItemType item; // Data portion
TreeNode<ItemType>* leftChildPtr; // Left-child pointer
TreeNode<ItemType>* rightChildPtr; // Right-child pointer
int height;

public :
TreeNode();
TreeNode( const ItemType& anItem);
TreeNode( const ItemType& anItem, TreeNode<ItemType>* leftPtr, TreeNode<ItemType>* rightPtr);
bool isLeaf() const ;
ItemType getItem() const ;
void setItem( const ItemType& anItem);
TreeNode<ItemType>* getLeftChildPtr() const ;
TreeNode<ItemType>* getRightChildPtr() const ;
void setLeftChildPtr(TreeNode<ItemType>* leftPtr);
void setRightChildPtr(TreeNode<ItemType>* rightPtr);
int getHeight() const ;
void setHeight(const int h);

}; // end TreeNode

// instantiating needed classes 
// not to get a linking time error (undefined reference to)
// read more : https://bytefreaks.net/programming-2/c/c-undefined-reference-to-templated-class-function
template class TreeNode<int>;
// #include "TriNode"
#endif