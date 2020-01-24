// Single linked lists contain nodes which have a data field as well as a 'next' 
// field, which points to the next node in list of nodes.

// ‘a’ -> ‘c’ -> ‘x’ -> ‘q’ -> ‘e’ -> ‘2’ -> NULL

// Node is defined as

// struct Node	
// {
// 	char data;
// 	Node* next;
// };

// Last node in list has next pointer equal to NULL.

// Write a function
// void reverseNodes(Node** head, int indexA, int indexB)
// which should reverse order of nodes in list, starting 
// from node on position indexA until node on position indexB.

// Head node is on position 1.

// Examples:
// input                                          output
// ‘a’ -> ‘c’ -> ‘x’ -> ‘q’ -> ‘e’ -> ‘2’		  ‘a’ -> ‘q’ -> ‘x’ -> ‘c’ -> ‘e’ -> ‘2’
// indexA = 2		                       
// indexB = 4


#include <iostream>
using namespace std;

struct Node	{
	int data;
	Node* next;
};

void reverseNodes(Node** head, int indexA, int indexB){
    int count = 0;
    Node* cur = *head;
    Node* prev;
    Node* next;
    Node* beforeLst;
    while(cur != NULL){
        if (count < indexA | indexA == 0){
            // cout<<"before indexA"<<endl;

            prev = cur;
            beforeLst = prev;
            if(cur->next != NULL){
                cur = cur->next;
                if (cur->next != NULL)
                    next = cur->next;
            }

            // cout<<"prev is : "<<prev->data<<endl;
            // cout<<"cur is : "<<cur->data<<endl;
            // cout<<"next is : "<<next->data<<endl;
            count ++;
        } 
        if(count >= indexA && count <= indexB){
            // cout<<"between indexA & indexB"<<endl;
            if(count == indexA){
                prev = NULL;
            }
            cur->next = prev;
            prev = cur;
            if (count != indexB){
                cur = next;
                next = next -> next;
            }
            count ++;

            // cout<<"prev is : "<<prev->data<<endl;
            // cout<<"cur is : "<<cur->data<<endl;
            // cout<<"next is : "<<next->data<<endl;
            // cout<<"beforeLst is : "<<beforeLst->data<<endl;

        }
        if(count > indexB){
            // cout<<"after indexB"<<endl;

            beforeLst->next = cur;
            while(cur->next != NULL){
                cur = cur->next;
                // cout<<"in while cur's data: "<<cur->data<<endl;
            }
            cur->next = next;
            cur = NULL;
            // cout<<"prev is : "<<prev->data<<endl;
            // cout<<"cur is : "<<cur->data<<endl;
            // cout<<"next is : "<<next->data<<endl;
            // cout<<"beforeLst is : "<<beforeLst->data<<endl;
            //cur = NULL; // to terminate
        }
    }
}

int main(){
    Node* head;
    head = new Node;
    head->data = 0;
    Node* prev = head;

    for(int i = 1; i < 15; i++){
        Node* tmp = new Node;
        tmp->data = i;
        prev->next = tmp;
        prev = prev->next;
    }
    prev->next = NULL;

    reverseNodes(&head, 2, 14);

    for(Node* cur = head; cur != NULL; cur = cur->next)
        cout<<cur->data<<"\t";
}