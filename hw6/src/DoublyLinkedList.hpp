#ifndef DOUBLY_LINK_LIST_H
#define DOUBLY_LINK_LIST_H
#include <iostream>
#include "DictEntry.h"

struct Node
{
    public:
	DictEntry data;
	Node *nextPtr;
        Node *prevPtr;
        Node();
};

class DoublyLinkedList
{
private:
	Node *headPtr;
        Node *tailPtr;
        Node *currentPtr;
        int length;
        
        Node *getElementAtIndex(int index);
public:
	DoublyLinkedList();
	~DoublyLinkedList();

	bool insertAtFront(DictEntry value);
	bool insertAtPosition(DictEntry value, int index);
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool insertAtBack(DictEntry value);

	bool deleteAtFront();
	bool deleteAtPosition(int index);
	//first Node after headptr is 1
	//false if pos zero or out of range
	bool deleteAtBack();
        Node *partition(Node *low, Node *high);
        void quickSort(Node *low, Node *high);
        void sort();
        int getLength();
        void swap(int a, int b);
        void swap(DictEntry *a, DictEntry *b);
	void clear(); //frees memory for entire list

        bool next();
        bool prev();
        DictEntry current();
        void end();
        void begin();
        
      
	friend std::ostream& operator<<(std::ostream &out, DoublyLinkedList &list);
      
};

#endif
