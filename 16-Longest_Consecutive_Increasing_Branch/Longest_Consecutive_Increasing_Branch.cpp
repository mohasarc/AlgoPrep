// Problem by  : ByteByByte youtube channel
// Link        : https://youtu.be/r2Vn6ztdSP0
//
// solution by : Mohammed S. Yaseen

// Given a tree, write  a function to find the length of the longest
// branch of nodes in increasing consecutive order.

// eg. 
/*
              0
            //  \
           1     2
          / \\  / \
         1   2 1   3

    length : 3
    * longest path denoted with double \
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};


void longestPath(TreeNode* root, int prevVal, int curLength, int &thePath){
    // if hit a NULL firsh check if curLength is greather than
    // thePath, if so update thePath. secondly decrement curLength
    if (root == NULL){
        if (curLength > thePath)
            thePath = curLength;
        return;
    }
        
    // if hit a dead end (this node's value is not the consecutive follow 
    // of the prev value), first check if curLength is greather than the
    // longest path, if so update the longest path. secondly make curLength = 0 to 
    // start a new path
    if (root->data != prevVal + 1){
        if (curLength > thePath)
            thePath = curLength;
        curLength = 1;
    }
    else if (root->data == prevVal + 1)
        curLength++;

    // go deeper
    longestPath(root->left, root->data, curLength, thePath);
    longestPath(root->right, root->data, curLength, thePath);
}

int longestPath(TreeNode* root){
    int thePath = 0;
    if(!root)
        return thePath;
    longestPath(root, root->data, 0, thePath);
    return thePath;
}

int main(){

/*              5
              /   \
             2     7
            / \   / \\
           1   3 4    8
                      \\
                        9
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
    root->right->right->right = new TreeNode;
    root->right->right->right->data = 9;
    root->right->right->right->left = NULL;
    root->right->right->right->right = NULL;

/*              5
              /   \
             2     7
            / \   / \\
           1   3 6    8
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

    cout<< longestPath(root2)<<endl;
    cout<< longestPath(root);
    
    return 0;
}