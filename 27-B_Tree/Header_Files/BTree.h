#ifndef BTREE_H
#define BTREE_H
#include "./BNode.h"

template <class type>
class BTree{
private:
    int degree;
    bool propagateS;
    BNode<type>* root;

    // Private functions
    void insert(type key, BNode<type>* curNode, BNode<type>* parentNode);
    void balance(BNode<type>* child, BNode<type>* parent);
    void split(BNode<type>* child, BNode<type>* parent, int splitIndex);
    void traverse(BNode<type>* curNode, int level);
public:
    BTree(int degree);
    ~BTree();
    void insert(type key);
    void remove(type key);
    bool find(type key);
    void traverse();
};
#endif