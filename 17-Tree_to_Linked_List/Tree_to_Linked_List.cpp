 // problem by : ByteByByte Youtube channel
 // Link       : https://youtu.be/Dte6EF1nHNo

 // solution by : Mohammed S. Yaseen

 // Problem :
 // Given a tree, write a function to  convert it into
 // a circular doubly linked list from left to right by
 // only modifying the existing pointers.

/*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
*/

// output : <-4<->2<->5<->1<->6<->3<->7->

#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

void toLinkedList(TreeNode* root, TreeNode* latestL, TreeNode* latestR, TreeNode* &head, TreeNode* &tail){
    if(root->left == NULL){
        // cout<<"a null was hit root: "<<root->data;
        root->left = latestR;
        if (latestR){
            latestR->right = root;
            // cout<<" R : "<< latestR->data;
        } else {
            head = root; // will reach here only once at the deepest left of tree
                         // (having both next left and the latest right = NULL)
        }

        root->right = latestL;
        if (latestL){
            latestL->left = root;
            // cout<<" L : "<<latestL->data<<endl;
        } else {
            tail = root; // will reach here only once at deepest right of tree
                         // (having both next left and the latest left = NULL)
        }
    } else 
    {
            toLinkedList(root->left, root, latestR, head, tail);
            toLinkedList(root->right, latestL, root, head, tail);
    }
}

void toLinkedList(TreeNode* root, TreeNode* &head, TreeNode* &tail){
    toLinkedList(root, NULL, NULL, head, tail);
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

    TreeNode* head;
    TreeNode* tail;
    toLinkedList(root, head, tail);

    cout<<endl;
    for (TreeNode* cur = head; cur != NULL; cur = cur->right){
        cout<<cur->data<<"\t";
    }

    cout<<endl;
    for (TreeNode* cur = tail; cur != NULL; cur = cur->left){
        cout<<cur->data<<"\t";
    }

    return 0;
}