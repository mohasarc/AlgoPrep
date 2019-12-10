#include "listP.h"

List::List(): size(0), head(NULL) {};
List::~List(){
	// if(head)
	// 	remove(1); idea -- make it recursive

	while(!isEmpty())
		remove(1);
} // end destructor

List::List(const List& alist):size(alist.size){
	if(! alist->head)
		// do nothing (the original list is empty)
	else{
		head = new Node;
		head->data = alist->head->data;
		Node* iter = head;
		for(Node* cur = alist->head->next; cur != NULL; cur = cur->next){
			Node tmp = new Node;
			tmp->data = cur->data;
			iter->next = tmp;
			iter = iter->next;
		}
		iter->next = NULL;
	}

}


int main(){



	return 0;
}