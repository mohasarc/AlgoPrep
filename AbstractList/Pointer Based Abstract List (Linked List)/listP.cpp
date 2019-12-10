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
	if(index > 1 && index <= size+1){
		Node* cur = find(index);
		Node* prev = find(index - 1);
		Node* tmp;
		tmp->data = dataItem;
		tmp->next = cur;
		prev->next = tmp;
	}

	if(index == 1){
		Node* newNode;
		newNode->data = dataItem;
		newNode->next = head;
		head = newNode;
	}

	return false;
}


int main(){



	return 0;
}