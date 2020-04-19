#include "../Header_Files/Tree23.h"

template <class T>
Tree23<T>::Tree23(){
    root = NULL;
}

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
    if (root->isThreeNode()) {
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
    insert(root, anItem, NULL);
}

template <class T>
void Tree23<T>::insert(TriNode<T>* cur, T anItem, TriNode<T>* newPtr){

    // The tree is empty    
    if (root == NULL){
        root = new TriNode<T>(anItem);
        return;
    }
    
    // Item is not in the root
    if (!cur->isLeaf()){
        if (anItem < cur->getSmallItem())
            insert(cur->getLeftChildPtr(), anItem, NULL);
        else {
            // Either middle or right
            if (cur->isTwoNode())
                insert(cur->getMidChildPtr(), anItem, NULL);
            else {
                if (anItem < cur->getLargeItem())
                    insert(cur->getMidChildPtr(), anItem, NULL);
                else 
                    insert(cur->getRightChildPtr(), anItem, NULL);
            }
        }
    }

    // Base Case
    if (cur->isLeaf() || newPtr != NULL){
        if (cur->isTwoNode()){
            // insert the new item
            cur->setLargeItem(anItem);
            newPtr = NULL;
        } 
        else {
            // figure which node to be sent to parent
            if (anItem > cur->getLargeItem()){
                // send the large item to parent
                // swapWithChild(cur, anItem, 'L');
            } 
            else if (anItem < cur->getSmallItem()){
                // send the small item to parent
                // swapWithChild(cur, anItem, 'S');
            } // end if

            // split into two nodes
            TriNode<T>* separatedNode;
            // splitNode(cur, separatedNode, newPtr);
            newPtr = separatedNode;

            if (root == cur){
                TriNode<T>* tmp = root;
                root = new TriNode<T>(anItem);
                root->setLeftChildPtr(tmp);
                root->setMidChildPtr(newPtr);

                return;
            }
        } // end if
    }
    return;
}

template <class T>
void swapWithChild(TriNode<T>* root, T &anItem, char which){
    T temp = NULL;

    switch (which)
    {
    case which == 'L' || which == 'l':
        temp = anItem;
        anItem = root->getLargeItem();
        root->setLargeItem(temp);
        break;

    case which == 'S' || which == 's':
        temp = anItem;
        anItem = root->getSmallItem();
        root->setSmallItem(temp);
        break;
    
    default:
        break;
    }
}

template <class T>
void splitNode(TriNode<T>* origNode, TriNode<T>* &separatedNode, TriNode<T>* newNode){
    separatedNode = new TriNode<T>();
    separatedNode->setSmallItem(origNode->getLargeItem());

    // Redistribute the children, including the one came from the 
    // separation of on of the children
    if (newNode){
        if (newNode->getSmallItem() < separatedNode->getSmallItem()){
            if (newNode->getSmallItem() < origNode->getMidChildPtr()->getSmallItem()){
                separatedNode->setLeftChildPtr(origNode->getMidChildPtr());
                separatedNode->setMidChildPtr(origNode->getRightChildPtr());

                origNode->setMidChildPtr(newNode);
                origNode->setRightChildPtr(NULL);
            } else {
                separatedNode->setLeftChildPtr(newNode);
                separatedNode->setMidChildPtr(origNode->getRightChildPtr());

                origNode->setMidChildPtr(origNode->getMidChildPtr());
                origNode->setRightChildPtr(NULL);
            }
        }
        else {
            separatedNode->setLeftChildPtr(origNode->getRightChildPtr());
            separatedNode->setMidChildPtr(newNode);

            origNode->setRightChildPtr(NULL);
        }
    }
}

template <class T>
bool Tree23<T>::remove(T anItem){

}

int main (){
    Tree23<int>* node = new Tree23<int>();
    // node->insert(5);
    // node->traverse();
    return 0;
}