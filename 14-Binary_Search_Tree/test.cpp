#include ".\Header_Files\BinaryTree.h"

int main(){

    BinaryTree<int>* mtbin = new BinaryTree<int>();
    mtbin->insert(55);
    mtbin->insert(35);
    mtbin->insert(134);
    mtbin->insert(1);
    mtbin->insert(39);
    mtbin->insert(52);
    mtbin->insert(973);
    mtbin->insert(81);

    cout << mtbin->traverse() << endl;
}