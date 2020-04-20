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
void AVLTree<T>::insert(TreeNode<T>* cur, T &anItem, TreeNode<T>* &newPtr){

}

template <class T>
bool AVLTree<T>::remove(T anItem){
    return false;
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