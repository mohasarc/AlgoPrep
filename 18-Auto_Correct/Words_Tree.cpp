// Created by : Mohammed S. Yaseen

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct TreeNode{
    char data;
    vector<TreeNode*> children;
    bool wEnd; // the end of an existing word
};

// given a string construct a tree branch, having 
// each letter on a different node
void addToTree(string word, TreeNode* root){
    for(int i = 0; i < root->children.size(); i++){
        TreeNode* child = root->children[i];
        if(word.at(0) == child->data){
            if (word.length() > 1)
                addToTree(word.substr(1, word.length()-1), child);
            else if (word.length() == 1)
                child->wEnd = true;
            return;
        }
    }

    // if it doesn't exist make it
    TreeNode* newChild = new TreeNode;
    root->children.insert(root->children.begin(), newChild);
    newChild->data = word.at(0);
    if (word.length() == 1)
        newChild->wEnd = true;
    else {
        newChild->wEnd = false;
        addToTree(word.substr(1, word.length()-1), newChild);
    }
}

void showTree(TreeNode* root, string wordSoFar){
    if (!root)
        return;

    wordSoFar = wordSoFar + root->data;

    // new word
    if (root->wEnd == true)
        cout<<wordSoFar<<"\t";
    
    // go deeper
    for(int i = 0; i < root->children.size(); i++){
        showTree(root->children[i], wordSoFar);
    }
}

void showTree(TreeNode* root){
    showTree(root, "");
}