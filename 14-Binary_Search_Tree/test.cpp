#include ".\Header_Files\BinaryTree.h"

int main(){

    BinaryTree<int>* mtbin = new BinaryTree<int>();
    // mtbin->insert(55);
    // mtbin->insert(35);
    // mtbin->insert(134);
    // mtbin->insert(1);
    // mtbin->insert(39);
    // mtbin->insert(38);
    // mtbin->insert(37);
    // mtbin->insert(36);
    // mtbin->insert(52);
    // mtbin->insert(973);
    // mtbin->insert(81);
    // mtbin->remove(81, 's'); // leaf
    // mtbin->remove(39, 's'); // one child
    // mtbin->remove(35, 's'); // two children

    // cout << mtbin->traverse() << endl;
    // cout << endl;
    mtbin->constructFromTreeString("{55}({35}({1},{39}({38}({37},{}),{52})),{134})");
    cout << mtbin->toTreeString();
}