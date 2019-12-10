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

bool List::isEmpty(){
	return !size; // may be problem
} // end isEmpty

int List::getLength(){
	return size;
} // end getLength

Node* List::find(int index) const{
	if (index < 1 || index > size)
		return NULL;

		else {
		Node* cur = head;
		for (int pos = 1; pos < index; pos++)
			cur = cur->next;
		return cur;
	}
}

bool List::retrieve(int index, ListItemType& dataItem) const{
	if(index >= 1; index <= size){
		dataItem = find(index)->data;
		return true;
	}

	return false;
} // end retrieve

bool List::insert(int index; ListItemType dataItem){
	int newlength = size + 1;
	if(index < 1 || index > newlength)
		return false;

	Node* tmp;
	tmp->data = dataItem;
	size = newlength;

	if(index == 1){
		tmp->next = head;
		head = tmp;
	}
	else {
		Node* prev = find(index - 1);
		tmp->next = prev->next;
		prev->next = tmp;
	}

	return true;
} //end insert


int main(){



	return 0;
}