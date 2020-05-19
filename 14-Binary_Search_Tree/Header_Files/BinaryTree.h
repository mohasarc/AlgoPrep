#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "TreeNode.h"
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

template <class T> 
class BinaryTree{
private:
// Properties
TreeNode<T>* root;

// Functions
void traverse(TreeNode<T>* root, string &outStr);
TreeNode<T>* search(TreeNode<T>* root, TreeNode<T>* &parent, T anItem);
void insert(TreeNode<T>* root, T &anItem);
bool removeWithSuccessor(TreeNode<T>* root, TreeNode<T>* parent);
void toTreeString(TreeNode<T>* root, string &output);
void insert(TreeNode<T> *child, TreeNode<T> *parent);
TreeNode<T>* getMostLeft(TreeNode<T>* root, TreeNode<T>* &parent);

public:
BinaryTree();
string traverse();
bool search(T anItem);
bool insert(T anItem);
bool remove(T anItem, char type);
bool isEmpty();
void constructFromTreeString(const string treeString);
string toTreeString();
};

#endif