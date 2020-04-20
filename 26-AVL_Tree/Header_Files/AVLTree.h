#ifndef _TREE_23
#define _TREE_23
#include "TreeNode.h"
#include <iostream>
using namespace std;

template <class T> 
class AVLTree{
private:
// Properties
TreeNode<T>* root;

// Functions
void traverse(TreeNode<T>* root);
bool search(TreeNode<T>* root, T anItem, TreeNode<T>* foundLocation);
void insert(TreeNode<T>* root, T &anItem, TreeNode<T>* &newPtr);
bool remove(TreeNode<T>* root, T anItem);
// Make the decidsion on which type of rtation is required
void fixAVLTree(TreeNode<T>* aNode);
// Rotation functions
void rotateR(TreeNode<T>* parent, TreeNode<T>* leftChild);
void rotateL(TreeNode<T>* parent, TreeNode<T>* rightChild);
void rotateRL(TreeNode<T>* parent);
void rotateLR(TreeNode<T>* parent);

public:
AVLTree();
void traverse();
bool search(T anItem);
void insert(T anItem);
bool remove(T anItem);
};
template class AVLTree<int>;
#endif