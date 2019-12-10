#include <iostream>
#include "listA.h"
using namespace std;

int main(){

	list* anlist = new list();

	cout<< anlist->getLength()<<endl;
	cout<< anlist->isEmpty()<<endl;

	anlist->insert(1, 12);
	anlist->insert(2, 24);
	anlist->insert(2, 15);
	anlist->insert(4, 35);
	anlist->insert(1, 17);
	anlist->remove(3);

	int a, b, c, d, e;
	anlist->retrieve(1, a);
	anlist->retrieve(2, b);
	anlist->retrieve(3, c);
	anlist->retrieve(4, d);
	anlist->retrieve(5, e);

	cout<< a << " "<< b << " "<< c<< " "<< d<< " "<< e;

	return 0;
}