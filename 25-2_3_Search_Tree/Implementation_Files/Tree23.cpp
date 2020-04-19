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
    // cout << "in traverse\t" << root->isLeaf()<< endl;
    // Base Case
    if (root->isLeaf()){
        // cout << "it is leaf" << endl;
        // Print its contents
        cout << root->getSmallItem() << "\t";
        if (root->isThreeNode())
            cout << root->getLargeItem() << "\t";
        return;
    }

    // Not a leaf
    // Print Left
    traverse(root->getLeftChildPtr());

    // Print Smaller Item
    cout <<root->getSmallItem() << "\t";

    // Print Middle
    traverse(root->getMidChildPtr());

    if (root->isThreeNode()) {
        // Print Larger Item
        cout << root->getLargeItem() << "\t";

        // Print Right
        traverse(root->getRightChildPtr());
    }
}

template <class T>
bool Tree23<T>::search(T anItem){
    return search(root, anItem, NULL);
}

template <class T>
bool Tree23<T>::search(TriNode<T>* root, T anItem, TriNode<T>* foundLocation){
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

    return false;
}

template <class T>
void Tree23<T>::insert(T anItem){
    cout << "calling insert" << endl;
    TriNode<T>* newPtr = NULL;
    insert(root, anItem, newPtr);
}

template <class T>
void Tree23<T>::insert(TriNode<T>* cur, T &anItem, TriNode<T>* &newPtr){

    // The tree is empty    
    if (root == NULL){
        cout << "adding to root" << "\t";
        root = new TriNode<T>(anItem);
        cout << root->getSmallItem() << endl;
        return;
    }
    
    // Item is not in the root
    if (!cur->isLeaf()){
        cout << "adding to an inner node" << endl;
        if (anItem < cur->getSmallItem())
            insert(cur->getLeftChildPtr(), anItem, newPtr);
        else {
            // Either middle or right
            if (cur->isTwoNode())
                insert(cur->getMidChildPtr(), anItem, newPtr);
            else {
                if (anItem < cur->getLargeItem())
                    insert(cur->getMidChildPtr(), anItem, newPtr);
                else 
                    insert(cur->getRightChildPtr(), anItem, newPtr);
            }
        }
    }

    cout <<"going to base case - newPtr "<< (newPtr != NULL) << endl;

    // Base Case
    if (cur->isLeaf() || newPtr != NULL){
        cout << "adding to a leaf node" << endl;
        if (cur->isTwoNode()){
            // insert the new item
            if (anItem > cur->getSmallItem())
                cur->setLargeItem(anItem);
            else{
                T temp = cur->getSmallItem();
                cur->setSmallItem(anItem);
                cur->setLargeItem(temp);
            }

            // joining the child if existed (can be separate fcn)
            if (newPtr){
                if (newPtr->getSmallItem() < cur->getSmallItem()){
                    // join to the left
                    
                } else if (newPtr->getSmallItem() < cur->getLargeItem()){
                    // join in the middle
                    TriNode<T>* tmp = cur->getMidChildPtr();
                    cur->setMidChildPtr(newPtr);
                    cur->setRightChildPtr(tmp);
                } else {
                    // join to teh right
                    cur->setRightChildPtr(newPtr);
                }
            }
                
            cout << "added to two node\t small " << cur->getSmallItem() << "  large  " << cur->getLargeItem() <<endl;
            
            newPtr = NULL;
        } 
        else {
            // figure which node to be sent to parent
            if (anItem > cur->getLargeItem()){
                // send the large item to parent
                swapWithChild(cur, anItem, 'L');
            } 
            else if (anItem < cur->getSmallItem()){
                // send the small item to parent
                swapWithChild(cur, anItem, 'S');
            } // end if

            // split into two nodes
            TriNode<T>* separatedNode;
            splitNode(cur, separatedNode, newPtr);
            newPtr = separatedNode;
            cur->setRightChildPtr(NULL);

            cout << "added to Three node\t small " << cur->getSmallItem() << "  large " << cur->getLargeItem() <<endl;
            cout << "node sepatated\t" << newPtr->getSmallItem() << endl;

            if (root == cur){
                cout << "adding item to new root"<< "\t";
                TriNode<T>* tmp = root;
                root = new TriNode<T>(anItem);
                root->setLeftChildPtr(tmp);
                root->setMidChildPtr(newPtr);
                cout << "new root " << root->getSmallItem() << endl;
                return;
            }
        } // end if
    }
    return;
}

template <class T>
void Tree23<T>::swapWithChild(TriNode<T>* root, T &anItem, char which){
    T temp;

    switch (which)
    {
    case 'l':
    case 'L':
        temp = anItem;
        anItem = root->getLargeItem();
        root->setLargeItem(temp);
        break;
    
    case 's':
    case 'S':
        temp = anItem;
        anItem = root->getSmallItem();
        root->setSmallItem(temp);
        break;
    
    default:
        break;
    }
}

template <class T>
void Tree23<T>::splitNode(TriNode<T>* origNode, TriNode<T>* &separatedNode, TriNode<T>* newNode){
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
    return false;
}

int main (){
    Tree23<int>* node = new Tree23<int>();
    node->insert(10);
    node->insert(5);
    node->insert(2);
    node->insert(3);
    node->insert(7);
    node->insert(1);
    node->traverse();
    return 0;
}