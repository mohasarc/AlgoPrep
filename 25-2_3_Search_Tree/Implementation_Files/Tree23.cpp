#include "../Header_Files/Tree23.h"

template <class T>
void Tree23<T>::traverse(){
    traverse(root);
}

template <class T>
void Tree23<T>::traverse(TriNode<T>* root){
    // Base Case
    if (root->isLeaf()){
        // Print its contents
        cout << root->getSmallItem() << "\t";
        cout << root->getLargeItem() << "\t";
        return;
    }

    // Not a leaf
    // Print Left
    traverse(root->getLeftChildPtr());

    // Print Smaller Item
    cout << root->getSmallItem();

    // Print Middle
    traverse(root->getMidChildPtr());
    if (root->isThreeNode) {
        // Print Larger Item
        cout << root->getLargeItem();

        // Print Right
        traverse(root->getRightChildPtr());
    }
}

template <class T>
bool Tree23<T>::search(T anItem){
    return search(root, anItem, NULL);
}

template <class T>
bool search(TriNode<T>* root, T anItem, TriNode<T>* foundLocation){
    // update foundlocation
    foundLocation = root;

    // If the item at the root
    if (root->getSmallItem() == anItem)
        return true;
    if (root->isThreeNode() && root->getLargeItem() == anItem)
        return true;

    // Base Case
    if (root->isLeaf()){
        return false;
    }

    // Item is not in the root
    if (anItem < root->getSmallItem())
        search(root->getLeftChildPtr(), anItem, NULL);
    else {
        // Either middle or right
        if (root->isTwoNode())
            search(root->getMidChildPtr(), anItem, NULL);
        else {
            if (anItem < root->getLargeItem())
                search(root->getMidChildPtr(), anItem, NULL);
            else 
                search(root->getRightChildPtr(), anItem, NULL);
        }
    }
}

template <class T>
void Tree23<T>::insert(T anItem){

}


template <class T>
bool Tree23<T>::remove(T anItem){

}