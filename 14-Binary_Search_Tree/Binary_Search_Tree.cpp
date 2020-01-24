// Given a binary tree, write a function to test if the
// tree is a binary search tree
// EX:          5
/*            /   \
             2     7
            / \   / \
           1   3 6   8
*/
// source : https://youtu.be/dB9aikwZttY

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

bool isBinTree(TreeNode* root, int min, int max ){
    bool binTree = false;
    if (root == NULL){
        return true;
    }
    else if (root->data <= min | root->data > max){
        return false;
    }

    // check left
    binTree = isBinTree(root->left, min, root->data);
    return binTree && isBinTree(root->right, root->data, max);
}

bool isBinTree(TreeNode* root){
    return isBinTree(root, -999999999, 999999999); // using largest possible int
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
    root2->right->left->data = 4; // not valid tree because of this
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

    cout<<isBinTree(root);

}