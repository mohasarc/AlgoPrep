#include "../Header_Files/AVLTree.h"

template <class T>
AVLTree<T>::AVLTree(){
    root = NULL;
}

template <class T>
void AVLTree<T>::traverse(){
    traverse(root);
}

template <class T>
void AVLTree<T>::traverse(TreeNode<T>* root){
    
}

template <class T>
bool AVLTree<T>::search(T anItem){

}

template <class T>
bool AVLTree<T>::search(TreeNode<T>* root, T anItem, TreeNode<T>* foundLocation){
    
}

template <class T>
void AVLTree<T>::insert(T anItem){
    
}

template <class T>
void AVLTree<T>::insert(TreeNode<T>* cur, T &anItem){
    // If empty insert at root
    if (isEmpty()){
        root = new TreeNode<T>(anItem);
        return;
    }

    // Find the location to insert
    // Not Leaf
    if (!cur->isLeaf()){
        if (anItem < cur->getItem()){
            // Smaller, go left
            insert(cur->getLeftChildPtr(), anItem);
        } else {
            // Larger, go right
            insert(cur->getRightChildPtr(), anItem);
        }
    }
    // Leaf OR returning
    else {
        // Leaf node
        if (anItem < cur->getItem())
            cur->setLeftChildPtr(new TreeNode(anItem));
        else 
            cur->setRightChildPtr(new TreeNode(anItem));

        updateHeight(cur, 1);
    }

    // Returning
    updateHeight(cur, 1);
    if (violatesAVL(cur)){
        fixAVLTree(cur);
    }
    
}

template <class T>
bool AVLTree<T>::remove(T anItem){
    return false;
}

template <class T>
bool AVLTree<T>::isEmpty(){
    return !root;
}

template <class T>
void AVLTree<T>::updateHeight(TreeNode<T>* cur, int amount){
    cur->setHeight(cur->getHeight() + amount);
}

template <class T>
bool AVLTree<T>::violatesAVL(TreeNode<T>* cur){
    bool violates = false;

    cur->getRightChildPtr()->getHeight() - cur->getLeftChildPtr()->getHeight() >= 2 ||
    cur->getRightChildPtr()->getHeight() - cur->getLeftChildPtr()->getHeight() <= -2 ? violates = true : violates = false;

    return violates;
}

int main (){
    AVLTree<int>* node = new AVLTree<int>();
    node->insert(10);
    node->insert(5);
    node->insert(2);
    node->insert(3);
    node->insert(7);
    node->insert(1);
    node->traverse();
    return 0;
}