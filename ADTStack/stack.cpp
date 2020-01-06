#include "stack.h"

Stack::Stack(): topPtr(NULL){}

Stack::Stack(const Stack& aStack);{
	// if the same item return and nothing else
	if (aStack == *this)
		return;

	// check if topPtr is not null
	if(aStack.topPtr == NULL){
		topPtr = NULL;
	} else {
		// copy the topPtr
		topPtr = new StackNode;
		topPtr->item = aStack.topPtr->item;
		StackNode* prev = topPtr;

		// copy everything else
		for(StackNode* cur = aStack.topPtr->next; cur != NULL; cur = cur->next){
			prev->next = new StackNode;
			prev = prev->next;
			prev->item = cur->item;
		}

		// put NULL for last item's next
		if(prev != NULL)
			prev->next = NULL;
	}
}

Stack::~Stack(){
	while(topPtr != NULL){
		StackNode* tmp = topPtr;
		topPtr = topPtr->next;
		delete tmp;
	}
}

bool Stack::isEmpty() const{
	return (topPtr == NULL);
}

bool Stack::push(StackItemType newItem){
	if (newItem == NULL)
		return false;
	else{
		StackNode* tmp = new StackNode;
		tmp->item = newItem;
		tmp->next = topPtr;
		topPtr = tmp;
		return true;
	}
}

bool Stack::pop(){
	if(topPtr == NULL)
		return false;
	else{
		StackNode* tmp = topPtr;
		topPtr = topPtr->next;
		delete tmp;
		return true;
	}
}

bool Stack::pop(StackItemType& stackTop){
	if(topPtr == NULL)
		return false;
	else{
		StackNode* tmp = topPtr;
		topPtr = topPtr->next;
		tmp->next = NULL;
		stackTop = tmp;
		return true;
	}
}

bool Stack::getTop(StackItemType& stackTop) const{
	if(topPtr == NULL)
		return false;
	else{
		StackNode* tmp = new StackNode;
		tmp->item = topPtr->item;
		tmp->next = NULL;
		stackTop = tmp;
		return true;
	}
}