#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    vector<TreeNode*> neigbors;
};

void bfSearch(TreeNode* root){
    if (!root)
        return;
    if(root->neigbors.size() != 0){
        for(int i = 0; i < root->neigbors.size(); i++)
            cout<<root->neigbors[i]->data<<"\t";

        for(int i = 0; i < root->neigbors.size(); i++)
            bfSearch(root->neigbors[i]);
    }
}

int main(){
    return 0;
}