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
    TreeNode<T>* notUsed;
    return this->search(root, notUsed, anItem);
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
bool BinaryTree<T>::remove(T anItem, char type){
    switch (type)
    {
    case 's':
    case 'S':
        TreeNode<T>* toBeDeleted;
        TreeNode<T>* toBeDeletedParent;
        toBeDeleted = search(this->root, toBeDeletedParent, anItem);
        return this->removeWithSuccessor(toBeDeleted, toBeDeletedParent);
    break;
    
    case 'p':
    case 'P':
        return false;
    break;

    default:
        return false;
        break;
    }
}

template <class T>
bool BinaryTree<T>::isEmpty(){
    return root == NULL;
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
TreeNode<T>* BinaryTree<T>::search(TreeNode<T>* root, TreeNode<T>* &parent, T anItem){
    if (root == NULL)
        return NULL;

    if (anItem == root->getItem())
        return root;

    parent = root;
    if (anItem < root->getItem())
        search(root->getLeftChildPtr(), parent, anItem);
    else 
        search(root->getRightChildPtr(), parent, anItem);

    // For compiler to be happy
    return NULL;
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
bool BinaryTree<T>::removeWithSuccessor(TreeNode<T>* root, TreeNode<T>* parent){
    // if leaf just remove it
    if (root->isLeaf()){
        delete root;
        if (parent->getLeftChildPtr() == root){
            // delete the child to the left
            parent->setLeftChildPtr(NULL);
        } else {
            // delete the child to the left
            parent->setRightChildPtr(NULL);
        }
        return true;
    }

    // if has one child, make parent point to child
    if (root->getLeftChildPtr() == NULL || root->getRightChildPtr() == NULL){
        TreeNode<T>* tmp = root;
        if (parent->getLeftChildPtr() == root){
            // delete the child to the left
            parent->setLeftChildPtr((root->getLeftChildPtr() != NULL 
                                    ? root->getLeftChildPtr() 
                                    : root->getRightChildPtr()));
        } else {
            // delete the child to the right
            parent->setRightChildPtr((root->getLeftChildPtr() != NULL 
                                    ? root->getLeftChildPtr() 
                                    : root->getRightChildPtr()));
        }
        return true;
    }

    // if has both children, replace with inorder successor
    // and delete it from there leaf node
    TreeNode<T>* inSuccParent = NULL;
    TreeNode<T>* inorderSuccessor = root->getRightChildPtr()->getLeftChildPtr() == NULL 
                                    ? root->getRightChildPtr() 
                                    : getMostLeft(root->getRightChildPtr(), inSuccParent);
    if (inSuccParent == NULL) inSuccParent = root;

    // replace with inorder successor
    T tmpItem = root->getItem();
    root->setItem(inorderSuccessor->getItem());
    removeWithSuccessor(inorderSuccessor, inSuccParent);

    // for compiler to be happy
    return false;
}

template <class T>
void BinaryTree<T>::toTreeString(TreeNode<T>* root, string &output){
    std::ostringstream oss;
    // Base case 1
    if (root == NULL){
        // Empty node {}
        oss << "{";
        oss << "}";
        output += oss.str();
        oss.str("");
        oss.clear();
        return;
    }

    // Base Case 2
    if (root->isLeaf()){
        // wrap its contents with {}
        oss << "{";
        oss << root->getItem();
        oss << "}";
        output += oss.str();
        oss.str("");
        oss.clear();
        return;
    }

    // Not a leaf
    // *** add self ***
    oss << "{";
    oss << root->getItem();
    oss << "}";

    // add Left child
    oss << "(";
    output += oss.str();
    oss.str("");
    oss.clear();
    toTreeString(root->getLeftChildPtr(), output);

    // add Right child
    oss << ",";
    output += oss.str();
    oss.str("");
    oss.clear();
    toTreeString(root->getRightChildPtr(), output);

    oss << ")";
    output += oss.str();
    oss.str("");
    oss.clear();
}

template <class T>
void BinaryTree<T>::insert(TreeNode<T> *child, TreeNode<T> *parent){
    if (parent == NULL){
        this->root = child;
        return;
    }

    if (parent->getLeftChildPtr() == NULL && !parent->doesLeftChildExist()){
        parent->setLeftChildPtr(child);
        parent->leftChildExistance(true);
    } else if (parent->getRightChildPtr() == NULL){
        parent->setRightChildPtr(child);
    }
}

template <class T>
void BinaryTree<T>::constructFromTreeString(const string treeString){
    stack<TreeNode<T>*> parentsStack;
    TreeNode<T>* tmpNode;

    for (int i = 0; i < treeString.length(); i++){
        switch (treeString.at(i))
        {
        case '{':
        tmpNode = new TreeNode<T>();
        // it it was constructed add it to tree, other wise do nothing
        if ( tmpNode->construct(treeString.substr(i))){
            if (root == NULL){
                insert(tmpNode, NULL);
            } else {
                insert(tmpNode, parentsStack.top());
            }
        }

        // update stack
        parentsStack.push(tmpNode);
        break;

        case '}':
            // if node has no children pop it from parents
            if (treeString[i+1] != '('){
                parentsStack.pop();
            }
            break;

        case '(':
            break;

        case ',':
            /* code */
            break;

        case ')':
            // node has finished so pop it from parents stack
            parentsStack.pop();
            break;

        default:
            break;
        }
    }
}

template <class T>
TreeNode<T>* BinaryTree<T>::getMostLeft(TreeNode<T>* root, TreeNode<T>* &parent){
    // Base case -- if left is null
    if (root->getLeftChildPtr() == NULL){
        return root;
    }

    parent = root;
    return getMostLeft(root->getLeftChildPtr(), parent);
}

template class BinaryTree<int>;