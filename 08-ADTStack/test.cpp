#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);

	int a, b;

	// myStack.getTop(a);
	myStack.pop(a);
	myStack.pop(b);
	myStack.pop();
	myStack.pop();
	// myStack.getTop(b);

	cout<<a<<"\t"<<b;
	
	/*code*/
	return 0;
}