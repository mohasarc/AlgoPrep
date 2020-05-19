#include "../Header_Files/BinaryTree.h"

template <class T>
BinaryTree<T>::BinaryTree(){
    this->root = NULL;
}

template <class T>
string BinaryTree<T>::traverse(){
    string outStr = "";
    this->traverse(this->root, outStr);
    return outStr;
}

template <class T>
bool BinaryTree<T>::search(T anItem){
    return this->search(root, anItem);
}

template <class T>
bool BinaryTree<T>::insert(T anItem){
    if (this->root == NULL){
        this->root = new TreeNode<T>(anItem);
        return true;
    }
    else {
        this->insert(this->root, anItem);
        return true;
    }
}

template <class T>
bool BinaryTree<T>::remove(T anItem){
    return this->remove(this->root, anItem);
}

template <class T>
bool BinaryTree<T>::isEmpty(){
    return root == NULL;
}

template <class T>
void BinaryTree<T>::constructFromTreeString(const string treeString){
}

template <class T>
string BinaryTree<T>::toTreeString(){
    string treeStr = "";
    this->toTreeString(this->root, treeStr);
    return treeStr;
}

// Private Methods
template <class T>
void BinaryTree<T>::traverse(TreeNode<T>* root, string &outStr){
    // Stopping case -- reached leaf node or NULL node
    if (root == NULL)
        return;
    // print left subtree
    traverse(root->getLeftChildPtr(), outStr);

    // print selt
    ostringstream oss;
    oss << root->getItem();
    outStr += oss.str() + "\t";
    oss.str("");
    oss.clear();

    // print right subtree
    traverse(root->getRightChildPtr(), outStr);


}

template <class T>
bool BinaryTree<T>::search(TreeNode<T>* root, T anItem){
    if (root == NULL)
        return false;

    if (anItem == root->getItem())
        return true;

    if (anItem < root->getItem())
        search(root->getLeftChildPtr(), anItem);
    else 
        search(root->getRightChildPtr(), anItem);
}

template <class T>
void BinaryTree<T>::insert(TreeNode<T>* root, T &anItem){
    // Base case -- if leaf node insert at it
    if (root->isLeaf()){
        if (anItem < root->getItem()){
            root->setLeftChildPtr(new TreeNode<T>(anItem));
        } else {
            root->setRightChildPtr(new TreeNode<T>(anItem));
        }

        return;
    }

    // cout << "left child : " << (root->getLeftChildPtr() != NULL ? root->getLeftChildPtr()->getItem() : 0) 
    //      << "  rightChild   " << (root->getRightChildPtr() != NULL? root->getRightChildPtr()->getItem() : 0)  << endl; 

    // Either go left or make new node there
    if (anItem < root->getItem()){
        if (root->getLeftChildPtr() != NULL)
            insert(root->getLeftChildPtr(), anItem);
        else
            root->setLeftChildPtr(new TreeNode<T>(anItem));
    }
    // Either go right or make new node there
    else {
        if (root->getRightChildPtr() != NULL)
            insert(root->getRightChildPtr(), anItem);
        else
            root->setRightChildPtr(new TreeNode<T>(anItem));
    }
}

template <class T>
bool BinaryTree<T>::remove(TreeNode<T>* root, T anItem){

}

template <class T>
void BinaryTree<T>::toTreeString(TreeNode<T>* root, string &output){

}

template <class T>
void BinaryTree<T>::insert(TreeNode<T> *child, TreeNode<T> *parent){

}

template class BinaryTree<int>;