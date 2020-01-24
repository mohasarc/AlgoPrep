#include "listA.h"
#include <iostream>
using  namespace std;

list::list() :size(0){}

bool list::isEmpty() const {
	return size == 0;
}

int list::getLength() const{
	return size;
}

bool list::retrieve(int index, ListItemType& dataItem ) const{
	if (index >= 1 && index <= size){
		dataItem = items[translate(index)];
		return true;
	}
	return false;
}

bool list::insert(int index, ListItemType newItem){
	if (index >= 1 && index <= size + 1 && size < maxVal){
		// empty a space for the item by shifting others
			shiftItems(translate(index), size);
			// add the item
			items[translate(index)] = newItem;
			size ++;
	}

	return false;
}

bool list::remove(int index){
	if(index >= 1 && index <= size){
		shiftItems(size, translate(index));
		size --;
		return true;
	}
	return false;
}

int list::translate(int index) const{
	return index - 1;
}

bool list::shiftItems(int from, int to){
if (from <= size && from >= 0 && to <= size && to >= 0){
	if (to > from) { // shift right
		for (int i = to; i > from; i--){
			items[i] = items[i-1];

		}
	} else { // shift left
		for (int i = to; i < from; i++)
			items[i] = items[i+1];
	}

	return true;
}
	
return false;
}