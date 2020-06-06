#ifndef BNODE_H
#define BNODE_H
#include <vector>
#include <iostream>
using namespace std;

template <class Type>
class BNode {
private:
    vector<Type> keys;
    vector<BNode*> children;
    bool leaf;

public:
    BNode();
    ~BNode();
    void addChild(BNode* aChild, int index);
    void removeChild(BNode* aChild);
    BNode* getChild(int index);
    int getChildNo();
    void addKey(Type key, int index);
    Type getKey(int index);
    int getKeyNo();
    void setLeaf(bool leaf);
    bool isLeaf();
};
#endif