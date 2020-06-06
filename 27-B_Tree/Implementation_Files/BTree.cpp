#include "../Header_Files/BTree.h"

// Plublic functions implementations
/**
 * The constructor
 * */
template <class type>
BTree<type>::BTree(int degree){
    this->degree = degree;
    this->root = NULL;
    this->propagateS = false;
}

/**
 * The destructor
 * */
template <class type>
BTree<type>::~BTree(){

}

/**
 * @param key The key to be inserted
 * */
template <class type>
void BTree<type>::insert(type key){
    if (this->root == NULL){
        cout << "creating root" << endl;
        this->root = new BNode<type>();
        this->root->setLeaf(true);
    }

    this->insert(key, this->root, NULL);
}

/**
 * @param key The key to be removed
 * */
template <class type>
void BTree<type>::remove(type key){

}

/**
 * @param key The key to be found
 * */
template <class type>
bool BTree<type>::find(type key){

}

/**
 * Traverses the whole tree
 * */
template <class type>
void BTree<type>::traverse(){
    this->traverse(this->root, 0);
}

// Private functions implementations
/**
 * 
 * */
template <class type>
void BTree<type>::insert(type key, BNode<type>* curNode, BNode<type>* parentNode){
    cout << "in recursive insert" << endl;
    // Base case
    // -- If leaf insert at it --
    if (curNode->isLeaf()){
        cout << "it is leaf & trying to insert " << key << endl;
        for (int i = 0; i < curNode->getKeyNo(); i++) {
            if (key < curNode->getKey(i)) {
                // insert at it
                curNode->addKey(key, i);
            } else if ( i ==  curNode->getKeyNo() - 1) {
                // insert at it
                cout << "inserting " << key << " at " << i+1 << endl;
                curNode->addKey(key, i + 1);
                break;
            }
        }

        if (curNode->getKeyNo() == 0)
            curNode->addKey(key, 0);

        // May become unbalanced so check balance
        this->balance(curNode, parentNode);

        return;
    }
    
    cout << "not a leaf" << endl;

    // Not leaf
    // Go through current node's children and decide to 
    // which one to go
    for (int i = 0; i < curNode->getKeyNo(); i++) {
        if (key < curNode->getKey(i)) {
            // insert in the tree just before the key greater than it
            insert(key, curNode->getChild(i), curNode);
        }
        else if (i == curNode->getKeyNo() - 1) {
            // Greater than the last key
            insert(key, curNode->getChild(i+1), curNode);
            break;
        }
    }

    // Somewhere at the bottom of the tree balance might have been disrupted
    // so check balance again here (when returning)
    balance(curNode, parentNode);
}

/**
 * Checks if the child node follows the tree rulesand if not balances it
 * @param child The node to be balanced
 * @param parent Its parent node
 * */
template <class type>
void BTree<type>::balance(BNode<type>* child, BNode<type>* parent){
    // Local variables
    int splitIndex;
    int childKeyNo = child->getKeyNo();

    cout << "at balance with " << childKeyNo << " keys " << endl;

    // if the child has more than or equal to degree number of keys it is not balanced
    if (childKeyNo > this->degree - 1){
        cout << "not balanced" << endl;
        // Need to perform a split
        // ## calculate the index at which split is performed ##
        // case 1 : having even keys (2 items at the middle)
        if (childKeyNo % 2 == 0) {
            if (this->propagateS){
                // picking the smaller one to propagate upwards
                splitIndex = childKeyNo / 2 - 1;
            } else {
                // picking the larger one to split
                splitIndex = childKeyNo / 2; 
            }
        }
        // case 2 : having odd kids (1 item at the middle)
        else {
            splitIndex = childKeyNo / 2;
        }

        // ## Perform the split ##
        this->split(child, parent, splitIndex);
    }
}

/**
 * Splits the child node at splitIndex, propagates item at splitIndex
 * to parent, and link the 2 new nodes to the parent
 * @param child The node to be balanced
 * @param parent Its parent node
 * @param splitIndex The index at which split will be performed
 * */
template <class type>
void BTree<type>::split(BNode<type>* child, BNode<type>* parent, int splitIndex){
    cout << "at split with split index " << splitIndex << endl;
    // Local variables
    BNode<type>* tmpL;
    BNode<type>* tmpR;
    type childMidKey;
    int midKeyinsertIndex;

    // ## split child into 2 nodes ##
    // 1. Create the 2 nodes
    tmpL = new BNode<type>();
    tmpR = new BNode<type>();
    tmpL->setLeaf(child->isLeaf());
    tmpR->setLeaf(child->isLeaf());

    cout << "created new nodes" << endl;

    // 2. Populate the 2 nodes with keys
    for (int i = 0; i < child->getKeyNo(); i++){
        if (i < splitIndex){
            tmpL->addKey(child->getKey(i), tmpL->getKeyNo());
        } else if ( i == splitIndex){
            childMidKey =child->getKey(i);
        } else {
            tmpR->addKey(child->getKey(i), tmpR->getKeyNo());
        }
    }

    cout << "populated with keys" << endl;

    // 3. Populate the 2 nodes with children
    for (int i = 0; i < child->getChildNo(); i++){
        if (i <= splitIndex){
            tmpL->addChild(child->getChild(i), tmpL->getChildNo());
        } else {
            tmpR->addChild(child->getChild(i), tmpR->getChildNo());
        }
    }

    // 4.a. Insert the middle key of child to parent if not null
    if (parent){
        for (int i = 0; i < parent->getKeyNo(); i++){
            if (childMidKey < parent->getKey(i)){
                // insert at i so stays before the one greater than it
                parent->addKey(childMidKey, i);
                midKeyinsertIndex = i;
            } else if ( i == parent->getKeyNo() - 1) {
                // not less than the last node, insert at the end
                parent->addKey(childMidKey, i + 1);
                midKeyinsertIndex = i + 1;
                break;
            }
        }
    } 
    // 4.b. If parent is null, make a new parent and insert child middle key into it
    else {
        cout << "creating a new parent " << endl;
        parent = new BNode<type>();
        parent->setLeaf(false);
        parent->addKey(childMidKey, 0);
        midKeyinsertIndex = 0;
        // No worries here, old root is kept by child here and this case won't happen
        // anywhere other than at the root
        this->root = parent;
    }

    cout << "removing the child from parent" << endl;
    // 5. Remove the old child from parent and delete it
    parent->removeChild(child);

    cout << "removed the child from parent" << endl;

    // 6. Insert the two new nodes to parent
    parent->addChild(tmpL, midKeyinsertIndex);
    parent->addChild(tmpR, midKeyinsertIndex + 1);
}

/**
 * Traverses the whole tree and prints it out
 * @param curNode The node being processed
 * @param level The level at which is the node
 * */
template <class type>
void BTree<type>::traverse(BNode<type>* curNode, int level){
    // Base case - NULL return
    if (!curNode){
        return;
    }

    // print self
    for(int i = 0; i < level; i ++){
        cout << "\t";
    }
    for (int i = 0; i < curNode->getKeyNo(); i++){
        cout << curNode->getKey(i) << " , " ;
    }
    cout << endl;

    // print children
    for (int i = 0; i < curNode->getChildNo(); i++){
        traverse(curNode->getChild(i), level + 1);
    }
}

// template class BTree<int>;


int main(){
    // BNode<int>* node1 = new BNode<int>();
    // BNode<int>* node2 = new BNode<int>();
    // BNode<int>* node3 = new BNode<int>();
    // BNode<int>* node4 = new BNode<int>();
    // BNode<int>* node5 = new BNode<int>();

    // node1->addKey(1, 0);
    // node1->addKey(2, 0);
    // node1->addKey(3, 0);
    // node1->addKey(4, 0);

    // node2->addKey(22, 0);
    // node3->addKey(33, 0);
    // node4->addKey(44, 0);


    // cout << node1->getKey(0) << endl;
    // cout << node1->getKey(1) << endl;
    // cout << node1->getKey(2) << endl;
    // cout << node1->getKey(3) << endl;

    // // node1->addChild(node2, 0);
    // // node1->addChild(node3, 0);
    // // node1->addChild(node4, 1);
    // // node1->removeChild(node3);

    // cout << node1->getChild(0)->getKey(0) << endl;
    // cout << node1->getChild(1)->getKey(0) << endl;
    // // cout << node1->getChild(2)->getKey(0) << endl;

    BTree<int>* tree1 = new BTree<int>(7);
    tree1->insert(1);
    tree1->insert(2);
    tree1->insert(3);
    tree1->insert(4);
    tree1->insert(5);
    tree1->insert(6);
    tree1->insert(7);
    tree1->insert(8);
    tree1->insert(9);
    tree1->insert(10);
    tree1->insert(11);
    tree1->insert(12);
    tree1->insert(13);
    tree1->insert(14);
    tree1->insert(15);

    tree1->traverse();

    return 0;
}