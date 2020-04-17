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
    return items[0];
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
    items[itemCount++];
    // Fit the newly added item in its position
    fitNewItem(itemCount - 1);

    return true;
}

/**
 * 
 * */
bool ArrayMaxHeap::remove(){
    if (isEmpty())
        return false;

    // Replacing the root with the last item
    items[0] = items[itemCount - 1];
    itemCount--;
    heapRebuild(0);
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

    // Base Case
    if (items[root] >= items[leftChild] && items[root] >= items[rightChild])
        return;

    // Recursive step
    if (leftChild < itemCount && items[leftChild] >= items[rightChild]){
        // Swap parent value with left child
        swap(items[leftChild], items[root]);
        heapRebuild(leftChild);
    }
    else if (rightChild < itemCount){
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
    for (int i = itemCount/2; i >= 0; i--)
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
    if (itemIndex <= ROOT_INDEX || items[itemIndex] <= items[parentIndex])
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
    int lastParent = getParentIndex(itemCount - 1);
    bool leaf;

    index > lastParent && index < itemCount ? leaf = 1 : leaf = 0;

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
    if (root >= itemCount)
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
