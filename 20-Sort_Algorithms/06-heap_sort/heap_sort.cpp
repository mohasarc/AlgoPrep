#include "../../19-inOeder_Print/inorder_print.cpp"

// struct TreeNode{
//     int data;
//     TreeNode* left;
//     TreeNode* right;
// };

void makeTree(TreeNode* head, int* arr, int l, int r){
    if (!head)
        return;

    head->data = arr[l];
    head->left = NULL;
    head->right = NULL;

    if( (2*l) + 1 < r){
        head->left = new TreeNode;
        head->left->data = arr[(2*l) + 1];
        makeTree(head->left, arr, (2*l) + 1, r);
    }

    if( (2*l) + 2 < r){
        head->right = new TreeNode;
        head->right->data = arr[(2*l) + 2];
        makeTree(head->right, arr, (2*l) + 2, r);
    }
}

void makeTree(TreeNode* &head, int* arr, int size){
    head = new TreeNode;
    makeTree(head, arr, 0, size);
}

int main(){
    const int size = 10;
    int arr[size] = {5, 4, 3, 7, 2, 0, 7, 5, 3, 2};

    TreeNode* head;
    makeTree(head, arr, size);

    printInOrder(head);

    return 0;
}