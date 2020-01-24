// Created by : Mohammed S. Yaseen

#include "Auto_Correct.cpp"

int main(){
    TreeNode* root;
    root = new TreeNode;
    root->data = '\n';
    root->wEnd = false;

    ifstream infile;
    infile.open("./words.txt");

    string x;
    while(infile >> x)
        addToTree(x, root);

    // showTree(root);
    cout<<"\n\n------------\n";
    showTreeWithHint(root, "fric");
}