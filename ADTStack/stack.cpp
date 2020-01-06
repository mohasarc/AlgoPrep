#include "stack.h"

Stack::Stack(): topPtr(NULL){
}
Stack::Stack(const Stack& aStack);
Stack::~Stack();

bool Stack::isEmpty() const;
bool Stack::push(StackItemType newItem);
bool Stack::pop();
bool Stack::pop(StackItemType& stackTop);
bool Stack::getTop(StackItemType& stackTop) const;