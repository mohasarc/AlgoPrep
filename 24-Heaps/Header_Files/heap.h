#ifndef ARRAYMAXHEAP_H
#define ARRAYMAXHEAP_H

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class ArrayMaxHeap{
public:
    // the constructor
    ArrayMaxHeap();
    ArrayMaxHeap(int *inItems, int size);
    bool isEmpty();
    int getNumberOfNodes();
    int getHeight();
    int peekTop();
    bool add(int newData);
    bool remove();
    void clear();
    void print();
    void print(int root, int level);

private:
    // Properties
    int *items;
    int itemCount;

    // Constants
    const int ROOT_INDEX = 0;
    int MAX_ITEMS = 50000;  // the maximum capacity of the heap

    // Functions
    int getRightChildIndex(int parentI);
    int getLeftChileIndex(int parentI);
    int getParentIndex(int childI);
    void createHeap();
    void fitNewItem(int itemIndex);
    void heapRebuild(int root);
    void swap(int &a, int &b);
    bool isLeaf(int index);
};

#endif