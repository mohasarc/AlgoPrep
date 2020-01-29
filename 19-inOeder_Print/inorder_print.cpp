// Given a binary search tree, print out the elements of the
// tree in order without using recursion

// eg.

/*
               5
             /   \
            3     7
           / \   / \
          1   4 6   8
    
    output : 1 3 4 5 6 7 8
*/

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

void printInOrder(TreeNode* root){
    if(root == NULL)
        return;
    
    if(root->left)
        printInOrder(root->left);

    cout<<root->data<<"\t";

    if(root->right)
        printInOrder(root->right);
}

int main(){
/*              5
              /   \
             2     7
            / \   / \
           1   3 6   8
*/
    TreeNode* root = new TreeNode;
    root->data = 5;
    root->left = new TreeNode;
    root->left->data = 2;
    root->right = new TreeNode;
    root->right->data = 7;
    root->left->left = new TreeNode;
    root->left->left->data = 1;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = new TreeNode;
    root->left->right->data = 3;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left = new TreeNode;
    root->right->left->data = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = new TreeNode;
    root->right->right->data = 8;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    printInOrder(root);

    return 0;
}