#ifndef LINK_LIST_H
#define LINK_LIST_H
#include <iostream>

using namespace std;

struct Node
{
    public:
	char data;
	Node* nextPtr;
        Node();
};

class LinkedList
{
private:
	Node *headPtr;
public:
	LinkedList();
	~LinkedList();

	bool insertAtFront(char value);
	bool insertBeforePosition(char value, int index);
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool insertAtBack(char value);

	bool deleteAtFront();
	bool deletePosition(int index);
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool deleteAtBack();
	//false if empty

	void clear(); //frees memory for entire list
	friend ostream& operator<<(ostream &out, LinkedList &list);
};

#endif
