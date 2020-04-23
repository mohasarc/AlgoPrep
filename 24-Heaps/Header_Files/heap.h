#ifndef MAX_HEAP_1_H
#define MAX_HEAP_1_H

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

template < class T>
class ArrayMaxHeap{
public:
    // Constants
    const int MAX_ITEMS = 2000;  // The maximum capacity of the heap

    // Constructors
    ArrayMaxHeap();
    ArrayMaxHeap(T *inItems, int size);

    // Destructor
    ~ArrayMaxHeap();

    // Methods
    bool isEmpty();
    int getNumberOfNodes();
    int getHeight();
    T peekTop();
    bool add(T newData);
    bool remove();
    void clear();
    void print();
    void print(int root, int level);
    void static sortAsc(T *arr, int size);
    void static sortDesc(T *arr, int size);
    void static sortAsc(ArrayMaxHeap &heap);
    void static sortDesc(ArrayMaxHeap &heap);

    // Implemented Method
    // This method has to be implemented in the header file
    // not to get a linkage error
    /**
     * This function takes a function and its arguments to update all
     * entries using the given function
     * @param fcn The function that will be used to update all entries 
     *            (First argument should always be of the type of the entries)
     * @param args The parameters that the fcn function take (parameter packs)
     * */
    template <typename Function, typename... Args>
    void updateEntries(Function fcn, Args... args){
        updateEntries(rootIndex, fcn, args...);
    }

private:
    // Properties
    T *items;
    int itemCount;
    int rootIndex = 0;

    // Methods
    int getRightChildIndex(int parentI);
    int getLeftChileIndex(int parentI);
    int getParentIndex(int childI);
    void createHeap();
    void fitNewItem(int itemIndex);
    void heapRebuild(int root);
    void swap(T &a, T &b);
    bool isLeaf(int index);

    // Implemented Private Method
    // This method has to be implemented in the header file
    // not to get a linkage error
    /**
     * This function takes a function and its arguments to update all
     * entries using the given function
     * @param cur The index of the current entry (used for the recursive call)
     * @param fcn The function that will be used to update all entries
     * @param args The parameters that the fcn function take (parameter packs)
     * */
    template <typename Function, typename... Args>
    void updateEntries(int  cur, Function fcn, Args... args){
        // Rebuild the heap to keep order
        heapRebuild(rootIndex);

        // if doesn't exist stop
        if (cur >= rootIndex + itemCount){
            return;
        }

        // Apply update to self
        fcn(items[cur], args...);
        
        // Apply for left sub-tree
        updateEntries(getLeftChileIndex(cur), fcn, args...);
        // Apply for right sub-tree
        updateEntries(getRightChildIndex(cur), fcn, args...);
    }
};
// Instantiating the needed classes 
// not to get a linkage error
template class ArrayMaxHeap<int>;

#endif