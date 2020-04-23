#include "..\Header_Files\heap.h"

/**
 * The default constructor
 * */
template < class T>
ArrayMaxHeap<T>::ArrayMaxHeap(){
    itemCount = 0;
    items = new T[MAX_ITEMS];
}

/**
 * The constructor
 * @param inItems the array of items to be added to heap
 * @param size the size of the array
 * */
template < class T>
ArrayMaxHeap<T>::ArrayMaxHeap(T *inItems, int size) {
    itemCount = size;
    items = new T[MAX_ITEMS];

    // Populate the heap with items from the array
    for (int i = 0; i < size; i++)
        items[i] = inItems[i];

    // Create the heap by ordering the items
    createHeap();
}

template < class T>
ArrayMaxHeap<T>::~ArrayMaxHeap(){
    delete [] items;
    itemCount = 0;
}


/**
 * @return boolean whether the heap is empty
 * */
template < class T>
bool ArrayMaxHeap<T>::isEmpty(){
    return !itemCount;
}

/**
 * 
 * */
template < class T>
int ArrayMaxHeap<T>::getNumberOfNodes(){
    
}

/**
 * 
 * */
template < class T>
int ArrayMaxHeap<T>::getHeight(){

}

/**
 * retrieves the top item of the heap
 * */
template < class T>
T ArrayMaxHeap<T>::peekTop(){
    // retrieving the root item
    return items[rootIndex];
}

/**
 * To add a new item to the heap
 * @param newData The item to be added
 * */
template < class T>
bool ArrayMaxHeap<T>::add(T newData){
    // If heap is already full
    if (itemCount >= MAX_ITEMS)
        return false;

    // Add the item to the bottom of the heap tree
    items[rootIndex + itemCount++] = newData;
    // Fit the newly added item in its position
    fitNewItem(rootIndex + itemCount - 1);

    return true;
}

/**
 * 
 * */
template < class T>
bool ArrayMaxHeap<T>::remove(){
    if (isEmpty())
        return false;

    // Replacing the root with the last item
    items[rootIndex] = items[rootIndex + itemCount - 1];
    itemCount--;
    heapRebuild(rootIndex);
    return true;
}

/**
 * 
 * */
template < class T>
void ArrayMaxHeap<T>::clear(){
    
}

/**
 * Rebuilds the heap recursively by pushing the item with less 
 * value down the tree
 * @param root the index in which is the item that is out of place
 * */
template < class T>
void ArrayMaxHeap<T>::heapRebuild(int root){

    // Local variables
    int leftChild = getLeftChileIndex(root);
    int rightChild = getRightChildIndex(root);
    bool greaterThanL = false;
    bool greaterThanR = false;

    leftChild < rootIndex + itemCount && items[root] >= items[leftChild] ? greaterThanL = true: greaterThanL = false;
    rightChild < rootIndex + itemCount && items[root] >= items[rightChild] ? greaterThanR = true: greaterThanR = false;

    // Base Case
    if (greaterThanL && greaterThanR)
        return;

    // Recursive step
    if (leftChild < rootIndex + itemCount && items[leftChild] >= items[rightChild]){
        // Swap parent value with left child
        swap(items[leftChild], items[root]);
        heapRebuild(leftChild);
    }
    else if (rightChild < rootIndex + itemCount){
        // Swap parent value with right child
        swap(items[rightChild], items[root]);
        heapRebuild(rightChild);
    }

}

/**
 * Swaps a with b
 * @param a the first item to be swapped
 * @param b the second item to be swapped 
 * */
template < class T>
void ArrayMaxHeap<T>::swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

/**
 * @param parentI the index of the parent
 * @return the index of its right child
 * */
template < class T>
int ArrayMaxHeap<T>::getRightChildIndex(int parentI){
    return parentI * 2 + 2;
}

/**
 * @param parentI the inde of the parent
 * @return the index of its left child
 * */
template < class T>
int ArrayMaxHeap<T>::getLeftChileIndex(int parentI){
    return parentI * 2 + 1;
}

/**
 * @param childI The index of the child
 * @return the index of its parent
 * */
template < class T>
int ArrayMaxHeap<T>::getParentIndex(int childI){
    return (childI - 1) / 2;
}

/**
 * Creates the heap
 * */
template < class T>
void ArrayMaxHeap<T>::createHeap(){
    for (int i = (rootIndex + itemCount)/2; i >= 0; i--)
        heapRebuild(i);
}

/**
 * 
 * */
template < class T>
void ArrayMaxHeap<T>::fitNewItem(int itemIndex){
    int parentIndex = getParentIndex(itemIndex);

    // Base case
    // - On root already, or
    // - Less or equal to parent
    if (itemIndex <= rootIndex || items[itemIndex] <= items[parentIndex])
        return;
    else {
        // Swap child with parent
        swap(items[itemIndex] , items[parentIndex]);
        // Continue checking up the tree
        fitNewItem(parentIndex);
    }
}

/**
 * 
 * */
template < class T>
bool ArrayMaxHeap<T>::isLeaf(int index){
    int lastParent = getParentIndex(rootIndex + itemCount - 1);
    bool leaf;

    index > lastParent && index < (rootIndex + itemCount) ? leaf = 1 : leaf = 0;

    return leaf;
}

/**
 * 
 * */
template < class T>
void ArrayMaxHeap<T>::print(){
    print(0, 0);
}

/**
 * 
 * */
template < class T>
void ArrayMaxHeap<T>::print(int root, int level){
    // if doesn't exist stop
    if (root >= rootIndex + itemCount)
        return;

    // print self
    for (int i = 0; i < level; i++)
        cout << "\t";
    cout << items[root] << endl;

    // print left
    print(getLeftChileIndex(root), level + 1);
    // print right
    print(getRightChildIndex(root), level + 1);
}

template < class T>
void ArrayMaxHeap<T>::sortAsc(T *arr, int size){
    ArrayMaxHeap heap;
    heap.items = arr;
    heap.itemCount = size;
    heap.createHeap();

    while( heap.itemCount > 0){
        heap.heapRebuild(heap.rootIndex);
        // swapping the max with the last leaf
        heap.swap(heap.items[heap.rootIndex], heap.items[heap.itemCount - 1]);
        heap.itemCount--;
    }

    // Not to be destrcuted
    heap.items = NULL;
}

template < class T>
void ArrayMaxHeap<T>::sortDesc(T *arr, int size){
    // to be implemented with minHeap
}

template < class T>
void ArrayMaxHeap<T>::sortAsc(ArrayMaxHeap &heap){

}

template < class T>
void ArrayMaxHeap<T>::sortDesc(ArrayMaxHeap &heap){

}