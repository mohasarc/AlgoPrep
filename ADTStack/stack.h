#ifndef STACK_H
#define STACK_H

typedef desired-type-of-stack-item StackItemType;

class Stack{

public:
   Stack();
   Stack(const Stack& aStack);
   ~Stack();

   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;

private:
   struct StackNode {            // a node on the stack
      StackItemType item;        // a data item on the stack
      StackNode    *next;        // pointer to next node
   };

   StackNode *topPtr;     // pointer to first node in the stack
};

#endif