#ifndef __LISTA_H
#define __LISTA_H

const int max = 500;
typedef int ListItemType;

class listA
{
public:
	listA();
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, ListItemType& dataItem ) const;
	bool insert(int index, ListItemType newItem);
	bool remove(int index);
private:
	ListItemType items[max];
	int size;
	int translate(int index) const;

};




#endif