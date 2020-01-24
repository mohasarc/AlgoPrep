// Created by : Mohammed S. Yaseen

#include "Words_Tree.cpp"

void showTree(TreeNode* root, string wordSoFar, string hint){
    if (!root)
        return;

    // concatenate the current letter to the word so far
    wordSoFar = wordSoFar + root->data;

    // word end reached. print it
    if (root->wEnd == true && hint.length() < 1)
        cout<<wordSoFar<<"\t";
    
    // go deeper
    for(int i = 0; i < root->children.size(); i++){
        TreeNode* child = root->children[i];
        if (hint.length() > 0){
            if (hint.at(0) == child->data){
                showTree(child, wordSoFar, hint.substr(1, hint.length()-1));
            }
        }
        else
            showTree(child, wordSoFar, hint);
    }
}

void showTreeWithHint(TreeNode* root, string hint){
    showTree(root, "", hint);
}