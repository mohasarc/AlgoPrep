#include "..\Header_Files\heap.h"

/**
 * The default constructor
 * */
ArrayMaxHeap::ArrayMaxHeap(){
    itemCount = 0;
    items = new int[MAX_ITEMS];
}

/**
 * The constructor
 * @param inItems the array of items to be added to heap
 * @param size the size of the array
 * */
ArrayMaxHeap::ArrayMaxHeap(int *inItems, int size) {
    itemCount = size;
    items = new int[MAX_ITEMS];

    // Populate the heap with items from the array
    for (int i = 0; i < size; i++)
        items[i] = inItems[i];

    // Create the heap by ordering the items
    createHeap();
}

ArrayMaxHeap::~ArrayMaxHeap(){
    delete [] items;
    itemCount = 0;
}


/**
 * @return boolean whether the heap is empty
 * */
bool ArrayMaxHeap::isEmpty(){
    return !itemCount;
}

/**
 * 
 * */
int ArrayMaxHeap::getNumberOfNodes(){

}

/**
 * 
 * */
int ArrayMaxHeap::getHeight(){

}

/**
 * retrieves the top item of the heap
 * */
int ArrayMaxHeap::peekTop(){
    // retrieving the root item
    return items[rootIndex];
}

/**
 * To add a new item to the heap
 * @param newData The item to be added
 * */
bool ArrayMaxHeap::add(int newData){
    // If heap is already full
    if (itemCount >= MAX_ITEMS)
        return false;

    // Add the item to the bottom of the heap tree
    items[rootIndex + itemCount++];
    // Fit the newly added item in its position
    fitNewItem(rootIndex + itemCount - 1);

    return true;
}

/**
 * 
 * */
bool ArrayMaxHeap::remove(){
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
void ArrayMaxHeap::clear(){

}

/**
 * Rebuilds the heap recursively by pushing the item with less 
 * value down the tree
 * @param root the index in which is the item that is out of place
 * */
void ArrayMaxHeap::heapRebuild(int root){

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
void ArrayMaxHeap::swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @param parentI the index of the parent
 * @return the index of its right child
 * */
int ArrayMaxHeap::getRightChildIndex(int parentI){
    return parentI * 2 + 2;
}

/**
 * @param parentI the inde of the parent
 * @return the index of its left child
 * */
int ArrayMaxHeap::getLeftChileIndex(int parentI){
    return parentI * 2 + 1;
}

/**
 * @param childI The index of the child
 * @return the index of its parent
 * */
int ArrayMaxHeap::getParentIndex(int childI){
    return (childI - 1) / 2;
}

/**
 * Creates the heap
 * */
void ArrayMaxHeap::createHeap(){
    for (int i = (rootIndex + itemCount)/2; i >= 0; i--)
        heapRebuild(i);
}

/**
 * 
 * */
void ArrayMaxHeap::fitNewItem(int itemIndex){
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
bool ArrayMaxHeap::isLeaf(int index){
    int lastParent = getParentIndex(rootIndex + itemCount - 1);
    bool leaf;

    index > lastParent && index < (rootIndex + itemCount) ? leaf = 1 : leaf = 0;

    return leaf;
}

/**
 * 
 * */
void ArrayMaxHeap::print(){
    print(0, 0);
}

/**
 * 
 * */
void ArrayMaxHeap::print(int root, int level){
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

void ArrayMaxHeap::sortAsc(int *arr, int size){
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

void ArrayMaxHeap::sortDesc(int *arr, int size){
    // to be implemented with minHeap
}

void ArrayMaxHeap::sortAsc(ArrayMaxHeap &heap){

}

void ArrayMaxHeap::sortDesc(ArrayMaxHeap &heap){

}