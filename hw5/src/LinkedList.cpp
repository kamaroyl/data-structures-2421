#include "LinkedList.h"
//Default Constructor Node
Node::Node(): data(0), nextPtr(nullptr) {} 

//Default Constructor
LinkedList::LinkedList(): headPtr(nullptr) {}

LinkedList::~LinkedList() {
    Node *tmpPtr;
    //While the linked list isn't empty
    while(nullptr != this->headPtr) {
        // a temp storeage location is the head pointer
        tmpPtr = this->headPtr;
        // head pointer is the next pointer
        this->headPtr = this->headPtr->nextPtr;
        // remove the previous head
        delete tmpPtr;
    }
    tmpPtr = this->headPtr;
    this->headPtr = nullptr;
    delete tmpPtr;
}

/*
 * Insert a node at the front
 */
bool LinkedList::insertAtFront(char value) {
    //store off head
    Node *tmpPtr = this->headPtr;
    //make head a new node
    this->headPtr = new Node();
    //assign previous head to next pointer of head
    this->headPtr->nextPtr = tmpPtr;
    this->headPtr->data = value;
    return true;
}

/*
 * Insert an element at position index - 1
 * index must be greater than 0
 * If list is empty create a new headPtr
 */
bool LinkedList::insertBeforePosition(char value, int index) {
    if(index > 0) {
        
        //empty list create a new node
        if(this->headPtr == nullptr) { 
            this->headPtr = new Node();
            this->headPtr->data = value;
            return true;
        }       

        Node *tmpPtr = this->headPtr;
        
        //interate through list
        while(--index) {
            if(nullptr == tmpPtr) return false;
            tmpPtr = tmpPtr->nextPtr;
        }

        Node *addPtr = new Node();
        addPtr->data = value;

        if(nullptr != tmpPtr->nextPtr){
            addPtr->nextPtr = tmpPtr->nextPtr;
        } else { 
            addPtr->nextPtr = nullptr;
        }
        tmpPtr->nextPtr = addPtr;
        return true;
    }
    return false;
}


/*
 * Iterate through the list and when the nextPtr of the current element is null,
 * add node as next pointer
 */
bool LinkedList::insertAtBack(char value) {
    Node *newNode = new Node();
    newNode->data = value;

    //Empty linked list, create a new node
    if(this->headPtr == nullptr) {
        this->headPtr = newNode;
        return true;
    }
    Node *tmpPtr = this->headPtr;
    
    //iterate through the loop
    while(tmpPtr->nextPtr != nullptr) {
        tmpPtr = tmpPtr->nextPtr;
    }

    tmpPtr->nextPtr = newNode;
    return true;
}

/*
 * Delete the first element in the linked list
 * if list is empty, return false
 */
bool LinkedList::deleteAtFront() {
    if(nullptr == this->headPtr) return false;
    // copy off head pointer
    Node *tmpPtr = this->headPtr;
    // set head pointer to next pointer
    this->headPtr = this->headPtr->nextPtr;
    delete tmpPtr;
    return true;
}


/*
 * Delete at position of linked list. 
 * If linked list is shorter than index return false
 */
bool LinkedList::deletePosition(int index) {
    
    //navigate through the linked list
    Node *prevPtr = this->headPtr;
    while(prevPtr != nullptr) {
        //stop at previous pointer
        if(index == 1) {
            //save off node to be deleted
            Node *tmpPtr = prevPtr->nextPtr;
            
            //link next node to previous node
            prevPtr->nextPtr = prevPtr->nextPtr->nextPtr;
   
            //clean up orphaned node and return
            delete tmpPtr;
            return true;
        }
        //move to next element
        prevPtr = prevPtr->nextPtr;
        
        //move index down
        index--;
    }
    return false;
}

/*
 * Remove the last element of the linked list
 * if list is empty, return false
 */
bool LinkedList::deleteAtBack() {
    if(nullptr == this->headPtr) return false;
    Node *tmpPtr = this->headPtr;
    
    //Special case only one element, delete head
    if(nullptr == this->headPtr->nextPtr) {
        tmpPtr = this->headPtr;
        this->headPtr = nullptr;
        delete tmpPtr;
        return true;
    }

    // iterate through the list until the penultimate element
    while(nullptr != tmpPtr->nextPtr->nextPtr) {
        tmpPtr = tmpPtr->nextPtr;
    }
    Node *newTail = tmpPtr;
    tmpPtr = tmpPtr->nextPtr;
    newTail->nextPtr = nullptr;
    delete tmpPtr;
    return true;
}

/*
 * Remove all elements from linked list
 */
void LinkedList::clear() {
    Node *tmp;
    if(nullptr == this->headPtr) return;
    // while we aren't at the end of the list
    while(nullptr != this->headPtr) {
        tmp = this->headPtr;
        this->headPtr = this->headPtr->nextPtr;
        delete tmp;
    }
}
 
/*
 *       prints LinkedList: [{element}...{element}]
 */
ostream& operator << (ostream &out, LinkedList &list) {
    out << "LinkedList: [";
    Node *tmpPtr = list.headPtr;
    while(nullptr != tmpPtr) {
        out << tmpPtr->data;
        tmpPtr = tmpPtr->nextPtr;
    }
    out << "]";
    return out;
}
