#ifndef __LISTP_H
#define __LISTP_H

typedef int ListItemType;

class List{
public:
	List(); // default constructor
	~List(); // destructor
	List(const List& alist); // copy constructor
	bool isEmpty() const;
	int getLength() const;
	bool retrieve(int index, ListItemType& dataItem) const;
	bool insert(int index, ListItemType newItem);
	bool remove(int index);

private:
	struct Node{
		ListItemType data;
		Node* next;
	};

	int size;
	Node* head;

	Node* find(int index) const; // finding an item using index

};





#endif