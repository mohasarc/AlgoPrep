// Given a tree, write a function that prints out
// the nodes of the tree in level order.
// problem source : https://youtu.be/eltLoCIDIes
// eg.
/*
    tree: 
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    traverse(root): 1 2 3 4 5 6 7
*/

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

void traverseTree(TreeNode* root){
    // stopping case: if NULL
    if (root == NULL)
        return;

    // print its left
    if (root->left != NULL)
        traverseTree(root->left);
    
    // print itselt
    cout<<root->data<<"\t";

    // print right
    if (root->right != NULL)
        traverseTree(root->right);
}


int main(){
/*              5
              /   \
             2     7
            / \   / \
           1   3 6   8
*/
    TreeNode* root2 = new TreeNode;
    root2->data = 5;
    root2->left = new TreeNode;
    root2->left->data = 2;
    root2->right = new TreeNode;
    root2->right->data = 7;
    root2->left->left = new TreeNode;
    root2->left->left->data = 1;
    root2->left->left->left = NULL;
    root2->left->left->right = NULL;
    root2->left->right = new TreeNode;
    root2->left->right->data = 3;
    root2->left->right->left = NULL;
    root2->left->right->right = NULL;
    root2->right->left = new TreeNode;
    root2->right->left->data = 4; 
    root2->right->left->left = NULL;
    root2->right->left->right = NULL;
    root2->right->right = new TreeNode;
    root2->right->right->data = 8;
    root2->right->right->left = NULL;
    root2->right->right->right = NULL;

/*              5
              /   \
             2     7
            / \   / \
           1   3 4   8
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

    traverseTree(root);
    cout<<endl;
    traverseTree(root2);

    return 0;
}