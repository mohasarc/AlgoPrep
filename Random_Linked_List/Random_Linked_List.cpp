#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* random;
};

Node* cloneList(Node* head){
    Node* head2;

    // duplicate each item of original list
    for(Node* cur = head; cur != NULL; cur = cur->next->next){
        Node* tmp = cur->next;
        cur->next = new Node;
        cur->next->data = cur->data;
        cur->next->next = tmp;
    }

    

    // copy the random nodes
    for(Node* cur = head; cur != NULL; cur = cur->next->next){
        // cout<<(cur == NULL)<<"  ";
        // cout<<"at : "<<cur->data<<"\t";
        // cout<<"next : "<<cur->next->data<<"\t";
        // cout<<(cur->random->next == NULL)<< cur->random->next->data <<"\t";
        cur->next->random = cur->random->next;
        // cout<<"reached here "<< (cur->next->next == NULL)<<endl;
    }

    // cout<<"fine till here"<<endl;
    
    head2 = head->next;
    Node* cur2 = head2;
    Node* cur  = head;
    // separate the two lists
    while (cur != NULL){
        if (cur->next != NULL)
            cur->next = cur->next->next;
        cur = cur -> next;
        if (cur2->next){
            cur2->next = cur2->next->next;
            cur2 = cur2->next;
        }
    }

    return head2;
}

int main(){
    Node* head = new Node;
    head->data = 0;
    Node* tmp = head;

    for(int i = 1; i < 5; i++){
        tmp->next = new Node;
        tmp = tmp->next;
        tmp->data = i;
    }
    tmp->next = NULL;

    head->random = head->next->next;
    head->next->random = head->next->next->next->next;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next;

    Node* head2 = cloneList(head);

    for(Node* cur= head; cur != NULL; cur = cur->next){
        cout<<cur->data<<" , "<<cur->random->data<<"\t";
    }

    cout<<endl;

    for(Node* cur= head2; cur != NULL; cur = cur->next){
        cout<<cur->data<<" , "<<cur->random->data<<"\t";
    }
}