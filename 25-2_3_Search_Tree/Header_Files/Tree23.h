#ifndef _TREE_23
#define _TREE_23
#include "TriNode.h"
#include <iostream>
using namespace std;

template <class T> class Tree23{
private:
// Properties
TriNode<T>* root;

// Functions
void traverse(TriNode<T>* root);
bool search(TriNode<T>* root, T anItem, TriNode<T>* foundLocation);
void insert(TriNode<T>* root, T anItem, TriNode* newPtr);
bool remove(TriNode<T>* root, T anItem);

public:
void traverse();
bool search(T anItem);
void insert(T anItem);
bool remove(T anItem);
};

#endif